# New ports collection makefile for:	libnids
# Version required:	1.12
# Date created:		08 Jan 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$

DISTNAME=	libnids-1.12
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnids/dist/

MAINTAINER=	kris@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

do-install:
		${INSTALL_DATA} ${WRKSRC}/src/nids.h ${PREFIX}/include
		${INSTALL_DATA} ${WRKSRC}/src/libnids.a ${PREFIX}/lib
		${MKDIR} ${PREFIX}/share/doc/libnids
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libnids
		${INSTALL_DATA} ${WRKSRC}/MISC ${PREFIX}/share/doc/libnids
		${INSTALL_DATA} ${WRKSRC}/doc/API ${PREFIX}/share/doc/libnids
		${INSTALL_DATA} ${WRKSRC}/doc/TESTS ${PREFIX}/share/doc/libnids

.include <bsd.port.mk>
