PORTNAME=	libzmq3
PORTVERSION=	3.2.5
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://github.com/zeromq/zeromq3-x/releases/download/${DISTVERSIONFULL}/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 3)
WWW=		https://www.zeromq.org/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

MAKE_ENV=	V=1
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFLICTS=	zmq libzmq[^3]

OPTIONS_DEFINE=		DEBUG PGM
OPTIONS_DEFAULT=	PGM

PGM_DESC=	Reliable multicast transport using PGM via OpenPGM

DEBUG_CONFIGURE_ON=	--enable-debug
PGM_LIB_DEPENDS=	libpgm.so:net/openpgm
PGM_USES=		pkgconfig
PGM_CONFIGURE_ON=	--with-system-pgm

.include <bsd.port.options.mk>

.if ${ARCH} == armv7
CPPFLAGS+=	-Wno-error=unaligned-access
.endif

.include <bsd.port.mk>
