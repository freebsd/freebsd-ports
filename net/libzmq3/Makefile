# $FreeBSD$

PORTNAME=	libzmq3
PORTVERSION=	3.2.4
CATEGORIES=	net
MASTER_SITES=	http://download.zeromq.org/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 3)

LICENSE=	LGPL3

USES=		pathfix
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

GNU_CONFIGURE=	yes

CONFLICTS=	zmq-[0-9]* libzmq[^3]-[0-9]*

regression-test: build
	cd ${WRKSRC} && ${MAKE}	check

.include <bsd.port.mk>
