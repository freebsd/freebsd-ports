# $FreeBSD$

PORTNAME=	libzmq4
PORTVERSION=	4.1.2
CATEGORIES=	net
MASTER_SITES=	http://download.zeromq.org/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 4)

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	zmq-[0-9]* libzmq[^4]-[0-9]*

USES=		libtool pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		CURVE DEBUG PGM
OPTIONS_DEFAULT=	CURVE PGM

CURVE_DESC=	CURVE security mechanism via libsodium
PGM_DESC=	Reliable multicast transport using PGM via OpenPGM

CURVE_CONFIGURE_WITH=	libsodium
CURVE_LIB_DEPENDS=	libsodium.so:${PORTSDIR}/security/libsodium

DEBUG_CONFIGURE_ENABLE=	debug

PGM_CONFIGURE_WITH=	pgm
PGM_LIB_DEPENDS=	libpgm.so:${PORTSDIR}/net/openpgm

CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

CFLAGS+=	-Wno-long-long
MAKE_ENV=	V=1
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
