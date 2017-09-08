# $FreeBSD$

PORTNAME=	libzmq4
PORTVERSION=	4.2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net
MASTER_SITES=	https://github.com/zeromq/libzmq/releases/download/${DISTVERSIONFULL}/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 4)

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	zmq-[0-9]* libzmq[^4]-[0-9]*

USES=	gmake libtool pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=			DEBUG MANPAGES
OPTIONS_RADIO=			CURVE
OPTIONS_RADIO_CURVE=		SODIUM TWEETNACL
OPTIONS_GROUP=			MULTICAST
OPTIONS_GROUP_MULTICAST=	NORM PGM
OPTIONS_DEFAULT=		MANPAGES NORM PGM TWEETNACL
OPTIONS_SUB=		yes

CURVE_DESC=	CURVE security backend
MULTICAST_DESC=	Reliable Multicast Transports
TWEETNACL_DESC=	Use tweetnacl
SODIUM_DESC=	Use libsodium
PGM_DESC=	Enable PGM transport via OpenPGM
NORM_DESC=	Enable NORM via NRL

DEBUG_CONFIGURE_ENABLE=	debug
DEBUG_VARS=		WITH_DEBUG=yes

PGM_CONFIGURE_WITH=	pgm
PGM_LIB_DEPENDS=	libpgm.so:net/openpgm

MANPAGES_BUILD_DEPENDS=		xmlto:textproc/xmlto \
				asciidoc:textproc/asciidoc
MANPAGES_CONFIGURE_WITH=	docs

NORM_CONFIGURE_WITH=	norm=${PREFIX}
NORM_LIB_DEPENDS=	libnorm.so:net/norm

SODIUM_CONFIGURE_WITH=	libsodium
SODIUM_LIB_DEPENDS=	libsodium.so:security/libsodium
SODIUM_PLIST_FILES=	bin/curve_keygen

TWEETNACL_PLIST_FILES=	bin/curve_keygen

CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

CFLAGS+=	-Wno-long-long
CPPFLAGS+=	-Wno-error
MAKE_ENV=	V=1

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MSODIUM} && !${PORT_OPTIONS:MTWEETNACL}
CONFIGURE_ARGS+=	--disable-curve
.endif

.include <bsd.port.mk>
