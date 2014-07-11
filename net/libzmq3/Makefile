# $FreeBSD$

PORTNAME=	libzmq3
PORTVERSION=	3.2.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.zeromq.org/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 3)

LICENSE=	LGPL3

CONFLICTS=	zmq-[0-9]* libzmq[^3]-[0-9]*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG PGM
PGM_DESC=	Reliable multicast transport using PGM via OpenPGM

DEBUG_CONFIGURE_ON=	--enable-debug
PGM_CONFIGURE_ON=	--with-system-pgm
PGM_LIB_DEPENDS=	libpgm.so:${PORTSDIR}/net/openpgm
PGM_USES=		pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
