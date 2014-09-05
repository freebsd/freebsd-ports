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

BUILD_DEPENDS=	${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids-libnet11
LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

LIBNET_CONFIG=	${LOCALBASE}/bin/libnet11-config

WRKSRC=		${WRKDIR}/${PORTNAME}-2.9.0
USE_GNOME=	glib20

do-build:
	cd ${WRKSRC} && ${CC} -c vortex.c -I${LOCALBASE}/include
	cd ${WRKSRC} && ${CC} -v -o vortex vortex.o -L${LOCALBASE}/lib ${LOCALBASE}/lib/libnids.a `${LIBNET_CONFIG} --libs` -lglib-2.0 -lgthread-2.0 -lpcap -pthread
	cd ${WRKSRC} && ${CC} -o xpipes xpipes.c -pthread

do-install:
	${INSTALL_DATA}	${WRKSRC}/vortex.conf ${STAGEDIR}${PREFIX}/etc/vortex.conf.sample
	${INSTALL_PROGRAM} ${WRKSRC}/vortex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xpipes ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
