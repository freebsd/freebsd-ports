# New ports collection makefile for: 	rtsp_proxy
# Version required: 			1.0
# Date created:				8 June 1999
# Whom:					Richard Kiss <richard@homemail.com>
#
# $Id: $
#

DISTNAME=	rtsp_proxy
PKGNAME=	${DISTNAME}-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.apple.com/Quicktime/developers/
EXTRACT_SUFX=	.src.sh

MAINTAINER=	richard@homemail.com

NO_CDROM=       "Apple has a complex license for this software."
WRKSRC=		${WRKDIR}/${DISTNAME}/proxy_unix
ALL_TARGET=

proxyunix =     ${WRKSRC}/proxy_unix.c

post-patch:
	@ ${MV} ${proxyunix} ${proxyunix}.bak
	@ ${SED} -e 's#/etc#${PREFIX}/etc#' < ${proxyunix}.bak > ${proxyunix}

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && yes "I AGREE" | ${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/rtsp_proxy ${PREFIX}/sbin
	@ ${INSTALL_SCRIPT} ${FILESDIR}/rtsp_proxy.sh ${PREFIX}/etc/rc.d
	@ ${INSTALL_DATA} ${WRKSRC}/../qts_proxy.conf ${PREFIX}/etc/

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
