# New ports collection makefile for:	net/udpxy
# Date created:				2 January 2009
# Whom:					Alex Deiter <Alex.Deiter@Gmail.COM>
#
# $FreeBSD$
#

PORTNAME=	udpxy
PORTVERSION=	1.0.14
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${RELEASE_MASCOT}-${PORTVERSION:R}
DISTNAME=	${PORTNAME}.${PORTVERSION:R}-${RELEASE_MASCOT}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	UDP-to-HTTP multicast traffic relay daemon

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}-${RELEASE_MASCOT}-${PORTVERSION:E}
USE_RC_SUBR=	udpxy
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
RELEASE_MASCOT=	Chipmunk

PLIST_FILES=	sbin/udpxy \
		sbin/udpxrec

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/udpxy ${PREFIX}/sbin/
	@${LN} -s ${PREFIX}/sbin/udpxy ${PREFIX}/sbin/udpxrec

.include <bsd.port.mk>
