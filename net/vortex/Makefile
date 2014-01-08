# $FreeBSD$

PORTNAME=	vortex
DISTVERSION=	2.9.0-59
CATEGORIES=	net ipv6
MASTER_SITES=	SF/${PORTNAME}-ids/${PORTNAME}/2.9.0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Network surveillance engine

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids-libnet11 \
		${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

LIBNET_CONFIG=	${LOCALBASE}/bin/libnet11-config

WRKSRC=		${WRKDIR}/${PORTNAME}-2.9.0
USE_GNOME=	glib20

NO_STAGE=	yes

do-build:
	cd ${WRKSRC} && ${CC} -c vortex.c -I${LOCALBASE}/include
	cd ${WRKSRC} && ${CC} -v -o vortex vortex.o -L${LOCALBASE}/lib ${LOCALBASE}/lib/libnids.a `${LIBNET_CONFIG} --libs` -lglib-2.0 -lgthread-2.0 -lpcap
	cd ${WRKSRC} && ${CC} -o xpipes xpipes.c ${PTHREAD_LIBS}

do-install:
	${INSTALL_DATA}	${WRKSRC}/vortex.conf ${PREFIX}/etc/vortex.conf.sample
	if [ ! -f ${PREFIX}/etc/vortex.conf ]; then \
		${CP} -p ${PREFIX}/etc/vortex.conf.sample ${PREFIX}/etc/vortex.conf; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/vortex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xpipes ${PREFIX}/bin

.include <bsd.port.mk>
