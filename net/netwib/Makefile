# New ports collection makefile for:	lcrzo
# Date created:		Wed Apr 10 02:42:20 CEST 2002
# Whom:			king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	lcrzo
PORTVERSION=	4.17.0
CATEGORIES=	security
MASTER_SITES=	http://www.laurentconstantin.com/common/lcrzo/download/v4/ \
		http://www.mirrors.wiretapped.net/security/packet-construction/lcrzo/ \
		ftp://ftp.mirrors.wiretapped.net/sd3a/security/packet-construction/lcrzo/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	king@v2project.com

WRKSRC=		${WRKDIR}/${PKGNAME}-src/src
ONLY_FOR_ARCHS=	i386 alpha

MAN3=	lcrzo.3 lcrzo_address.3 lcrzo_conf.3 lcrzo_data.3 lcrzo_device.3 \
	lcrzo_error.3 lcrzo_file.3 lcrzo_global.3 lcrzo_header.3 \
	lcrzo_icmp.3 lcrzo_ipc.3 lcrzo_ipopt.3 lcrzo_list.3 lcrzo_misc.3 \
	lcrzo_obso.3 lcrzo_packet.3 lcrzo_print.3 lcrzo_process.3 \
	lcrzo_record.3 lcrzo_sniff.3 lcrzo_sock.3 lcrzo_spoof.3 \
	lcrzo_string.3 lcrzo_tcpopt.3 lcrzo_time.3 lcrzo_types.3 lcrzo_wait.3

post-patch:
	cd ${WRKSRC} && ${SH} ${WRKSRC}/genemake

.include <bsd.port.mk>
