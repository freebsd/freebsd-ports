# New ports collection makefile for:	libnids
# Date created:		08 Jan 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libnids
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/projects/libnids/dist/

MAINTAINER=	roam@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes

MAN3=		libnids.3

do-install:
		${INSTALL_DATA} ${WRKSRC}/src/nids.h ${PREFIX}/include
		${INSTALL_DATA} ${WRKSRC}/src/libnids.a ${PREFIX}/lib
		${INSTALL_DATA} ${WRKSRC}/src/libnids.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
