# $FreeBSD$

PORTNAME=	libzmq3
PORTVERSION=	3.2.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.zeromq.org/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 3)

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

CONFLICTS=	zmq-[0-9]* libzmq[^3]-[0-9]*

USES=		libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
TEST_TARGET=	check

OPTIONS_DEFINE=		DEBUG PGM
OPTIONS_DEFAULT=	PGM

PGM_DESC=	Reliable multicast transport using PGM via OpenPGM

DEBUG_CONFIGURE_ON=	--enable-debug
PGM_CONFIGURE_ON=	--with-system-pgm
PGM_LIB_DEPENDS=	libpgm.so:net/openpgm
PGM_USES=		pkgconfig

MAKE_ENV=	V=1
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
