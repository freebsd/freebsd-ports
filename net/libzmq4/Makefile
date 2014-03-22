# $FreeBSD$

PORTNAME=	libzmq4
PORTVERSION=	4.0.4
CATEGORIES=	net
MASTER_SITES=	http://download.zeromq.org/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 4)

LICENSE=	LGPL3

USES=		pathfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	CURVE DEBUG PGM
CURVE_DESC=	CURVE security mechanism via libsodium
PGM_DESC=	Reliable multicast transport using PGM via OpenPGM

CURVE_CONFIGURE_ON=	--with-libsodium=${LOCALBASE}
CURVE_LIB_DEPENDS=	libsodium.so:${PORTSDIR}/security/libsodium
DEBUG_CONFIGURE_ON=	--enable-debug
PGM_CONFIGURE_ON=	--with-system-pgm
PGM_LIB_DEPENDS=	libpgm.so:${PORTSDIR}/net/openpgm
PGM_USES=		pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-long-long

CONFLICTS=	zmq-[0-9]* libzmq[^4]-[0-9]*

regression-test: build
	cd ${WRKSRC} && ${MAKE}	check

.include <bsd.port.mk>
