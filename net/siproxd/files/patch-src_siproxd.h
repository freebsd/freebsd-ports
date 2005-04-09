--- src/siproxd.h.orig	Sat Jan  8 11:05:13 2005
+++ src/siproxd.h	Tue Mar  1 22:36:48 2005
@@ -18,7 +18,7 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */
 
-/* $Id: siproxd.h,v 1.48 2005/01/08 10:05:13 hb9xar Exp $ */
+/* $Id: siproxd.h,v 1.51 2005/03/01 21:36:48 hb9xar Exp $ */
 
 #ifdef DMALLOC
  #include <dmalloc.h>
@@ -60,6 +60,7 @@
    int debugport;
    char *inbound_if;
    char *outbound_if;
+   char *outbound_host;
    int sip_listen_port;
    int daemonize;
    int silence_log;
@@ -147,6 +148,7 @@
 int  get_ip_by_host(char *hostname, struct in_addr *addr);		/*X*/
 void secure_enviroment (void);
 int  get_ip_by_ifname(char *ifname, struct in_addr *retaddr);		/*X*/
+int  get_interface_ip(int interface, struct in_addr *retaddr);		/*X*/
 char *utils_inet_ntoa(struct in_addr in);
 int  utils_inet_aton(const char *cp, struct in_addr *inp);
 
@@ -159,8 +161,6 @@
 int  is_sipuri_local (sip_ticket_t *ticket);				/*X*/
 int  check_rewrite_rq_uri (osip_message_t *sip);			/*X*/
 int  sip_gen_response(sip_ticket_t *ticket, int code);			/*X*/
-#define IF_OUTBOUND 0
-#define IF_INBOUND  1
 int  sip_add_myvia (sip_ticket_t *ticket, int interface);		/*X*/
 int  sip_del_myvia (sip_ticket_t *ticket);				/*X*/
 int  sip_rewrite_contact (sip_ticket_t *ticket, int direction);		/*X*/
@@ -176,7 +176,7 @@
 int  rtpproxy_init( void );						/*X*/
 int  rtp_start_fwd (osip_call_id_t *callid, char *client_id,            /*X*/
                     int direction, int media_stream_no,
-		    struct in_addr outbound_ipaddr, int *outboundport,
+                    struct in_addr outbound_ipaddr, int *outboundport,
                     struct in_addr lcl_client_ipaddr, int lcl_clientport);
 int  rtp_stop_fwd (osip_call_id_t *callid, int direction);		/*X*/
 void rtpproxy_kill( void );						/*X*/
@@ -201,6 +201,12 @@
                    struct in_addr local_ipaddr, int local_port,
                    struct in_addr remote_ipaddr, int remote_port);
 
+/* sip_layer.c */
+int sip_message_parse(osip_message_t * sip, const char *buf, int len);
+int sip_message_to_str(osip_message_t * sip, char **dest, int *len);
+int sip_body_to_str(const osip_body_t * body, char **dest, int *len);
+int sip_message_set_body(osip_message_t * sip, const char *buf, int len);
+
 
 /*
  * some constant definitions
@@ -236,8 +242,8 @@
 #define SEC_MINLEN	16	/* minimum received length */
 #define SEC_MAXLINELEN	1024	/* maximum acceptable length of one line
 				   in the SIP telegram (security check)
-                                   Careful: Proxy-Authorization lines may
-                                   get quite long */
+				   Careful: Proxy-Authorization lines may
+				   get quite long */
 
 /* symbols for access control */
 #define ACCESSCTL_SIP	1	/* for access control - SIP allowed	*/
@@ -253,6 +259,10 @@
 /* symbolic direction of data */
 #define DIR_INCOMING	1
 #define DIR_OUTGOING	2
+
+/* Interfaces */
+#define IF_OUTBOUND 0
+#define IF_INBOUND  1
 
 /* various */
 #ifndef satoi
