/* fakeroute (c) 1996 Julian Assange <proff at iq dot org>
 * All Rights Reserved
 *
 * config file ("hops" by default) contains tuples like thus:

Dest IP         Hop     Fake router     ms latency
203.4.184.222    0      204.70.10.250   5
203.4.184.222    1      204.70.10.250   10
203.4.184.222    2      198.32.136.88   15
203.4.184.222    3      137.209.200.202 20
203.4.184.222    4      137.209.60.1    25
203.4.184.222    5      198.26.127.26   30
203.4.184.222   -1      203.4.184.222   35
203.4.184.217    0      204.70.10.250   5
203.4.184.217    1      204.70.10.250   10
203.4.184.217    2      198.32.136.88   15
203.4.184.217    3      137.209.200.202 20
203.4.184.217    4      137.209.60.1    25
203.4.184.217    5      198.26.127.26   30
203.4.184.217   -1      203.4.184.222   35
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>

#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>

#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>

#include <arpa/inet.h>

#include <pcap.h>

#define bool int
#define TRUE 1
#define FALSE 0

#define ENDIAN_RAW_BUG 1

typedef u_short port_t;

pcap_t *pd;
struct bpf_program fcode;
u_char *pcap_userdata;
struct in_addr localnet, netmask;
char ebuf[PCAP_ERRBUF_SIZE];
int raw;
int a_max_ttl = 1;
int a_timeout = 300;
int a_verbose = 0;

void ether_if_print(u_char *user, const struct pcap_pkthdr *h, const u_char *p);
void ppp_if_print(u_char *user, const struct pcap_pkthdr *h, const u_char *p);
void analyze_udp(struct ip *ip);

struct hop
{
        struct hop *next;
        struct in_addr dst, hop;
        int latency; /* delay */
        int ttl;
};
struct hop *hops;

struct udp_state
{
        struct udp_state *next;
        struct in_addr src, dst;
        port_t sport;
        time_t last_packet;
};

struct udp_state *state;
struct udp_state *queue;

void
pexit(char *err)
{
        perror(err);
        exit(1);
}

void
eexit(char *err)
{
        fprintf(stderr, "fatal error: %s\n", err);
        exit(1);
}

void *
xmalloc(int n)
{
        void *p=malloc(n);
        if (!p)
                pexit("malloc");
        return p;
}

u_short
fast_icmp_cksum(struct icmp *icmp)      /* well, for C anyway.. */
{
        register u_short *u = (u_short *)icmp;
        register int sum = 0;

        sum =  *u++;
                u++;            /* skip checksum */
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u++;
        sum += *u;
        sum = (sum >> 16) + (sum & 0xffff);     /* fold accumulated carries */
        sum += sum>>16;
        return (u_short) ~sum;
}

struct printer
{
        pcap_handler f;
        int type;
};

/* XXX needed if using old bpf.h */
#ifndef DLT_ATM_RFC1483
#define DLT_ATM_RFC1483 11
#endif

static struct printer printers[] =
{
        { ether_if_print,       DLT_EN10MB },
        { ether_if_print,       DLT_IEEE802 },
/*
        { sl_if_print,          DLT_SLIP },
*/
        { ppp_if_print,         DLT_PPP },
/*
        { fddi_if_print,        DLT_FDDI },
        { null_if_print,        DLT_NULL },
        { atm_if_print,         DLT_ATM_RFC1483 },
*/
        { NULL,                 0 },
};

static pcap_handler
lookup_printer(int type)
{
        struct printer *p;

        for (p = printers; p->f; ++p)
                if (type == p->type)
                        return p->f;

        fprintf(stderr, "unknown data link type 0x%x", type);
        exit(1);
        /* NOTREACHED */
}

void
open_pcap(char *dev, bool f_promisc, char *filt, int usec)
{
        if (!dev)
        {
                dev = pcap_lookupdev(ebuf);
                if (!dev)
                        eexit(ebuf);
        }
        pd = pcap_open_live(dev, 96, f_promisc, usec, ebuf);
        if (!pd)
                eexit(ebuf);
        if (pcap_lookupnet(dev, &localnet.s_addr, &netmask.s_addr, ebuf) < 0)
                eexit(ebuf);
        if (pcap_compile(pd, &fcode, filt, 1, (u_long)netmask.s_addr) < 0)
                eexit(pcap_geterr(pd));
        if (pcap_setfilter(pd, &fcode) < 0)
                eexit(pcap_geterr(pd));
}

void
ether_if_print(u_char *user, const struct pcap_pkthdr *h, const u_char *p)
{
        p += 14;
        analyze_udp((struct ip *)p);
}

void
ppp_if_print(u_char *user, const struct pcap_pkthdr *h, const u_char *p)
{
        p += 4;
        analyze_udp((struct ip *)p);
}


struct hop *
find_hop(struct in_addr dst, int ttl)
{
        struct hop *p, *ret=NULL;
        for (p = hops; p; p=p->next)
        {
                if (p->dst.s_addr == dst.s_addr)
                {
                        if (p->ttl == ttl)
                                return p;
                        if (p->ttl == -1)
                                ret = p;
                }
        }
        return ret;
}

void
icmp_reply(struct ip *iip, struct hop *hop)
{
        char buf[sizeof(struct ip) + sizeof(struct icmp) + 8];
        struct ip *ip =(struct ip *)buf;
        struct icmp *i =(struct icmp *)(buf+sizeof(struct ip));
        static u_short ip_id;
        bool f_dest = (hop->ttl == -1);
        struct sockaddr_in in;
        int len = sizeof (struct ip) + sizeof (struct icmp) + 8; /* don't bother with the options  */
        memset(&in, 0, sizeof in);
        in.sin_family = AF_INET;
        ip->ip_hl = sizeof (struct ip) / 4;
        ip->ip_v = 4;
        ip->ip_tos = 0;
        ip->ip_len = ENDIAN_RAW_BUG? len: htons(len);
        ip->ip_id = htons(ip_id++);
        ip->ip_off = 0;
        ip->ip_ttl = 255;
        ip->ip_p = IPPROTO_ICMP;
        ip->ip_dst = in.sin_addr = iip->ip_src;
        ip->ip_src = hop->hop;
        ip->ip_sum = 0; /* let the os calculate it */
        i->icmp_type = f_dest? ICMP_UNREACH: ICMP_TIMXCEED;
        i->icmp_code = f_dest? ICMP_UNREACH_PORT: ICMP_TIMXCEED_INTRANS;
        memcpy(&i->icmp_ip, iip, sizeof (struct ip)+8);
        i->icmp_cksum = fast_icmp_cksum(i);
        if (a_verbose>0)
        {
                printf("rotorouter: sending %s %s",
                        f_dest? "ICMP_UNREACH_PORT": "ICMP_TIMXCEED",
                        inet_ntoa(ip->ip_src));
                printf(" -> %s for ttl %d\n",
                        inet_ntoa(ip->ip_dst),
                        iip->ip_ttl);
        }
        usleep(hop->latency);
        if (sendto (raw, ip, len, 0, (struct sockaddr *)&in, sizeof in)!=len)
                pexit("sendto");
}

void
analyze_udp(struct ip *ip)
{
        struct udphdr *u;
        struct hop *hop;
        struct udp_state *p;
        static time_t lastclean;
        time_t t;
        u = (struct udphdr *)((char *)ip+ip->ip_hl*4);
        hop = find_hop(ip->ip_dst, ip->ip_ttl);
        if (!hop)
                return;
        for (p = state; p; p = p->next)
        {
                if (p->src.s_addr == ip->ip_src.s_addr &&
                    p->sport == u->uh_sport &&
                    p->dst.s_addr == ip->ip_dst.s_addr)
                    goto found;
        }
        if (ip->ip_ttl > a_max_ttl)
                return;
        p = xmalloc(sizeof *p);
        p->next = state;
        p->src = ip->ip_src;
        p->dst = ip->ip_dst;
        p->sport = u->uh_sport;
        state = p;
found:
        p->last_packet = t = time(NULL);
        icmp_reply(ip, hop);
        if (t > lastclean+10)
        {
                struct udp_state *prev = NULL;
                for (p=state; p;)
                {
                        if (t > p->last_packet + a_timeout)
                        {
                                struct udp_state *p2 = p->next;
                                if (prev)
                                        prev->next = p->next;
                                else
                                        state = NULL;
                                free (p);
                                p = p2;
                        } else
                        {
                                prev = p;
                                p = p->next;
                        }
                }
        }
}

void
open_raw()
{
        int yes = 1;
        raw = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
        if (raw<0)
                pexit("socket");
        if (setsockopt(raw, IPPROTO_IP, IP_HDRINCL, (char *)&yes, sizeof(yes)) < 0)
                pexit("IP_HDRINCL");
}

void
populate_hops(char *fn)
{
        FILE *fh;
        char host[32];
        char hop[32];
        struct hop *p;
        int latency;
        int ttl;
        int rules;
        fh = fopen(fn, "r");
        if (!fh)
                pexit(fn);
        for (rules = 0; fscanf(fh, "%16s %d %16s %d%*[^\r\n]", host, &ttl, hop, &latency) == 4; rules++)
        {
                struct in_addr hostaddr, hopaddr;
                hostaddr.s_addr = inet_addr(host);
                if (hostaddr.s_addr == 0xffffffff)
                {
                        fprintf(stderr, "bad address: %s\n", host);
                        exit(1);
                }
                hopaddr.s_addr = inet_addr(hop);
                if (hopaddr.s_addr == 0xffffffff)
                {
                        fprintf(stderr, "bad address: %s\n", hop);
                        exit(1);
                }
                p = malloc(sizeof *p);
                p->dst = hostaddr;
                p->hop = hopaddr;
                p->ttl = ttl;
                p->latency = latency;
                p->next = hops;
                hops = p;

        }
        fprintf(stderr, "%d rotorouter rules loaded\n", rules);
}

void
usage(char *av0)
{
        exit(1);
}

int
main(int argc, char **argv)
{
        int c;
        pcap_handler printer;
        char *a_iface = NULL;
        char *a_filter = "udp";
        char *a_hops = "hops";
        int a_usec = 50;
        bool f_promisc = TRUE;
        while ((c=getopt(argc, argv, "i:ph:u:n:v"))!=-1)
        {
                switch(c)
                {
                case 'i':
                        a_iface = optarg;
                        break;
                case 'p':
                        f_promisc = FALSE;
                        break;
                case 'h':
                        a_hops = optarg;
                        break;
                case 'u':
                        a_usec = atoi(optarg);
                        break;
                case 't':
                        a_max_ttl = atoi(optarg);
                        break;
                case 'n':
                        a_timeout = atoi(optarg);
                        break;
                case 'v':
                        a_verbose++;
                        break;
                default:
                        usage(argv[0]);
                        /* NOT REACHED */
                }
        }
        populate_hops(a_hops);
        open_pcap(a_iface, f_promisc, a_filter, a_usec);
        printer = lookup_printer(pcap_datalink(pd));
        open_raw();
        if (pcap_loop(pd, 0, printer, NULL) < 0)
        {
                fprintf(stderr, "%s: pcap_loop: %s\n",
                    argv[0], pcap_geterr(pd));
                exit(1);
        }
        pcap_close(pd);
        exit(0);
}
