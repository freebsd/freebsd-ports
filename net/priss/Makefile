# New ports collection makefile for: 	priss
# Version required: 			1.0.2
# Date created:				13 September 1999
# Whom:					Richard Kiss <richard@homemail.com>
#
# $FreeBSD$
#

DISTNAME=	SS1.0.2
PKGNAME=	priss-1.0
CATEGORIES=	net
MASTER_SITES=	http://www.streamingserver.org/priss/
EXTRACT_SUFX=	.tgz

MAINTAINER=	richard@homemail.com

WRKSRC=		${WRKDIR}/${DISTNAME}

do-build:
	cd ${WRKSRC}; ./doit

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/RhapServer/QuickTimeStreamingServer ${PREFIX}/sbin
	@ ${INSTALL_SCRIPT} ${FILESDIR}/qtss.sh ${PREFIX}/etc/rc.d
	@ ${INSTALL_DATA} ${WRKSRC}/RhapServer/QTSS.conf ${PREFIX}/etc/
	${MKDIR} ${PREFIX}/movies/

.include <bsd.port.mk>
