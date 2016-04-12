# $FreeBSD$

PORTNAME=	vortex
DISTVERSION=	2.9.0-59
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	SF/${PORTNAME}-ids/${PORTNAME}/2.9.0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Network surveillance engine

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libnids.a:net/libnids
LIB_DEPENDS=	libnet.so:net/libnet

WRKSRC=		${WRKDIR}/${PORTNAME}-2.9.0
USE_GNOME=	glib20

do-build:
	cd ${WRKSRC} && ${CC} -c vortex.c -I${LOCALBASE}/include
	cd ${WRKSRC} && ${CC} -v -o vortex vortex.o -L${LOCALBASE}/lib ${LOCALBASE}/lib/libnids.a -lnet -lglib-2.0 -lgthread-2.0 -lpcap -pthread
	cd ${WRKSRC} && ${CC} -o xpipes xpipes.c -pthread

do-install:
	${INSTALL_DATA}	${WRKSRC}/vortex.conf ${STAGEDIR}${PREFIX}/etc/vortex.conf.sample
	${INSTALL_PROGRAM} ${WRKSRC}/vortex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xpipes ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
