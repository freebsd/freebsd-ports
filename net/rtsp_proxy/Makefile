# New ports collection makefile for: 	rtsp_proxy
# Version required: 			1.0
# Date created:				8 June 1999
# Whom:					Richard Kiss <richard@homemail.com>
#
# $FreeBSD$
#

DISTNAME=	SS1.0.1
PKGNAME=	rtsp_proxy-1.0
CATEGORIES=	net
MASTER_SITES=	http://www.streamingserver.org/priss/
EXTRACT_SUFX=   .tgz

MAINTAINER=	richard@homemail.com

WRKSRC=		${WRKDIR}/${DISTNAME}/QTProxy/proxy_unix
ALL_TARGET=

proxyunix =     ${WRKSRC}/proxy_unix.c

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/rtsp_proxy ${PREFIX}/sbin
	@ ${INSTALL_SCRIPT} ${FILESDIR}/rtsp_proxy.sh ${PREFIX}/etc/rc.d
	@ ${INSTALL_DATA} ${WRKSRC}/../qts_proxy.conf ${PREFIX}/etc/

post-install:
	@ ${CAT} ${PKGMESSAGE} | ${SED} -e 's,@PREFIX@,${PREFIX},g'

.include <bsd.port.mk>
