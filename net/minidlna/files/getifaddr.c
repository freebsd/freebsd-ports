/* $Id: getifaddr.c,v 1.12 2010/11/11 23:48:13 jmaggard Exp $ */
/* MiniUPnP project
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 *
 * Copyright (c) 2006, Thomas Bernard
 * All rights reserved.
 * 
 * Adapted to BSD by jayp and Mikhail T. -- 2010
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * The name of the author may not be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <arpa/inet.h>
#include <net/route.h>
#include <err.h>
#include <netinet/if_ether.h>

#include <ifaddrs.h>
#include <sys/param.h>
#include <net/if_dl.h>

#include "getifaddr.h"
#include "log.h"

int
getifaddr(const char * ifname, char * buf, int len)
{
	/* SIOCGIFADDR struct ifreq *  */
	int s;
	struct ifreq ifr;
	int ifrlen;
	struct sockaddr_in * addr;
	ifrlen = sizeof(ifr);
	s = socket(PF_INET, SOCK_DGRAM, 0);
	if(s < 0)
	{
		DPRINTF(E_ERROR, L_GENERAL, "socket(PF_INET, SOCK_DGRAM): %s\n", strerror(errno));
		return -1;
	}
	strncpy(ifr.ifr_name, ifname, IFNAMSIZ);
	if(ioctl(s, SIOCGIFADDR, &ifr, &ifrlen) < 0)
	{
		DPRINTF(E_ERROR, L_GENERAL, "ioctl(s, SIOCGIFADDR, ...): %s\n", strerror(errno));
		close(s);
		return -1;
	}
	addr = (struct sockaddr_in *)&ifr.ifr_addr;
	if(!inet_ntop(AF_INET, &addr->sin_addr, buf, len))
	{
		DPRINTF(E_ERROR, L_GENERAL, "inet_ntop(): %s\n", strerror(errno));
		close(s);
		return -1;
	}
	close(s);
	return 0;
}

int
getsysaddr(char * buf, int len)
{
	int rv=-1;
	struct ifaddrs *ifap = NULL;
	struct ifaddrs *ifnr;

	if (getifaddrs(&ifap) != 0)
		err(1, "getifaddrs");

	for (ifnr = ifap; ifnr != NULL; ifnr = ifnr->ifa_next) {
		if (ifnr->ifa_addr->sa_family == AF_INET) {
			struct sockaddr_in *addr_in =
			    (struct sockaddr_in *)ifnr->ifa_addr;

			unsigned a =
			    (htonl(addr_in->sin_addr.s_addr) >> 0x18) & 0xFF;

			if (a==127)
				continue;

			if(!inet_ntop(AF_INET, &addr_in->sin_addr, buf, len)) {
				warn("inet_ntop()");
				break;
			}
			rv=0;
			break;
		}
		rv=0;
	}
	freeifaddrs(ifap);
	return rv;
}

static int
getsysifname(char * buf, size_t len)
{
	int rv=-1;
	struct ifaddrs *ifap = NULL;
	struct ifaddrs *ifnr;

	if (getifaddrs(&ifap) != 0)
		err(1, "getifaddrs");

	for (ifnr = ifap; ifnr != NULL; ifnr = ifnr->ifa_next) {
		if (ifnr->ifa_addr->sa_family == AF_INET) {
			char *ifname=ifnr->ifa_name;
			struct sockaddr_in *addr_in =
			    (struct sockaddr_in *)ifnr->ifa_addr;

			unsigned a =
			    (htonl(addr_in->sin_addr.s_addr) >> 0x18) & 0xFF;

			if (a == 127)
				continue;

			if(!inet_ntop(AF_INET, &addr_in->sin_addr, buf, len)) {
				warn("inet_ntop()");
				break;
			}
			strncpy(buf, ifname, len);
			break;
		}
		rv=0;
	}

	freeifaddrs(ifap);
	return rv;
}

int
getsyshwaddr(char *buf, int len)
{
	struct ifaddrs *ifap;
	char sysifname[256];
	int rv=-1;
	uint8_t node[6];
        struct ifaddrs *p;

	if (getsysifname(sysifname, sizeof(sysifname)) != 0)
		return rv;

	if (getifaddrs(&ifap) != 0)
		err(1, "getifaddrs");

	for (p = ifap; p != NULL; p = p->ifa_next) {
		if (p->ifa_addr->sa_family == AF_LINK) {
			char *ifname=p->ifa_name;
			struct sockaddr_dl* sdp;

			if (strncmp(sysifname, ifname, sizeof(sysifname)))
				continue;

			sdp = (struct sockaddr_dl*) p->ifa_addr;
			memcpy(node, sdp->sdl_data + sdp->sdl_nlen, 6);
			if (len>12)
				sprintf(buf, "%02x%02x%02x%02x%02x%02x",
				    node[0], node[1], node[2],
				    node[3], node[4], node[5]);
			else
				memmove(buf, node, 6);
			rv=0;
			break;
		}
	}
        freeifaddrs(ifap);
	return rv;
}

int
get_remote_mac(struct in_addr ip_addr, unsigned char *mac)
{
        int     found_entry=0;
        int mib[6];
        size_t needed;
        char *lim, *buf, *next;
        struct rt_msghdr *rtm;
        struct sockaddr_inarp *sin;
        struct sockaddr_dl *sdl;
        extern int h_errno;

        mib[0] = CTL_NET;
        mib[1] = PF_ROUTE;
        mib[2] = 0;
        mib[3] = AF_INET;
        mib[4] = NET_RT_FLAGS;
        mib[5] = RTF_LLINFO;
        if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0)
                err(1, "route-sysctl-estimate");
        if ((buf = malloc(needed)) == NULL)
                err(1, "malloc");
        if (sysctl(mib, 6, buf, &needed, NULL, 0) < 0)
                err(1, "actual retrieval of routing table");
        lim = buf + needed;
        for (next = buf; next < lim; next += rtm->rtm_msglen) {
                rtm = (struct rt_msghdr *)next;
                sin = (struct sockaddr_inarp *)(rtm + 1);
                sdl = (struct sockaddr_dl *)(sin + 1);
                if (ip_addr.s_addr != sin->sin_addr.s_addr)
                        continue;
                if (sdl->sdl_alen) {
                        found_entry = 1;
                        memmove(mac, (u_char *)LLADDR(sdl), 6);
                        break;
                }
        }

        if(!found_entry)
		memset(mac, 0xFF, 6);
        free(buf);
        return !found_entry;
}
