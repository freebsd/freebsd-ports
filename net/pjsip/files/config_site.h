/*
 * Custom options imported from asterisk provided customizations.
 *
 * $FreeBSD$
 */

#include <sys/select.h>

#define PJ_MAX_HOSTNAME			(256)
#define PJSIP_MAX_URL_SIZE		(512)
#define PJ_IOQUEUE_MAX_HANDLES		(FD_SETSIZE)

#define PJ_SCANNER_USE_BITWISE		0

#define PJ_LOG_MAX_LEVEL		6

#define PJSIP_MAX_TSX_COUNT		((64*1024)-1)
#define PJSIP_MAX_DIALOG_COUNT		((64*1024)-1)
#define PJSIP_UDP_SO_SNDBUF_SIZE	(512*1024)
#define PJSIP_UDP_SO_RCVBUF_SIZE	(512*1024)

#define PJSIP_MAX_PKT_LEN		32000

/* Defaults too low for WebRTC */
#define PJ_ICE_MAX_CAND			32
#define PJ_ICE_MAX_CHECKS		(PJ_ICE_MAX_CAND * PJ_ICE_MAX_CAND)

/* Increase limits to allow more formats */
#define PJMEDIA_MAX_SDP_FMT		64
#define PJMEDIA_MAX_SDP_BANDW		4
#define PJMEDIA_MAX_SDP_ATTR		(PJMEDIA_MAX_SDP_FMT*2 + 4)
#define PJMEDIA_MAX_SDP_MEDIA		16

/*
 * Turn off the periodic sending of CRLNCRLN.  Default is on (90 seconds),
 * which conflicts with the global section's keep_alive_interval option in
 * pjsip.conf in asterisk.
 */
#define PJSIP_TCP_KEEP_ALIVE_INTERVAL	0
#define PJSIP_TLS_KEEP_ALIVE_INTERVAL	0
