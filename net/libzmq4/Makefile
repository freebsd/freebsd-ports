PORTNAME=	libzmq4
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.4
CATEGORIES=	net
MASTER_SITES=	https://github.com/zeromq/libzmq/releases/download/${DISTVERSIONFULL}/
DISTNAME=	zeromq-${DISTVERSION}

PATCH_SITES=	https://github.com/zeromq/libzmq/commit/
PATCHFILES=	438d5d88392baffa6c2c5e0737d9de19d6686f0d.patch:-p1

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 4)
WWW=		https://www.zeromq.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-silent-rules \
			--disable-Werror \
			--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CFLAGS+=	-Wno-long-long

CONFLICTS=	libzmq[^4] zmq

OPTIONS_DEFINE=			LIBUNWIND MANPAGES STATIC
OPTIONS_DEFAULT=		MANPAGES NORM PGM TWEETNACL STATIC
OPTIONS_GROUP=			MULTICAST
OPTIONS_GROUP_MULTICAST=	NORM PGM
OPTIONS_RADIO=			CURVE
OPTIONS_RADIO_CURVE=		SODIUM TWEETNACL
OPTIONS_SUB=			yes

CURVE_DESC=	CURVE security backend
LIBUNWIND_DESC=	Use libunwind to print stack trace in case of error
MULTICAST_DESC=	Reliable Multicast Transports
NORM_DESC=	Enable NORM via NRL
PGM_DESC=	Enable PGM transport via OpenPGM
SODIUM_DESC=	Use libsodium
TWEETNACL_DESC=	Use tweetnacl

LIBUNWIND_LIB_DEPENDS=		libunwind.so:devel/libunwind
LIBUNWIND_CONFIGURE_ENABLE=	libunwind
MANPAGES_BUILD_DEPENDS=		asciidoc:textproc/asciidoc \
				xmlto:textproc/xmlto
MANPAGES_CONFIGURE_WITH=	docs
NORM_LIB_DEPENDS=		libnorm.so:net/norm
NORM_CONFIGURE_WITH=		norm=${PREFIX}
PGM_LIB_DEPENDS=		libpgm.so:net/openpgm
PGM_CONFIGURE_WITH=		pgm
SODIUM_LIB_DEPENDS=		libsodium.so:security/libsodium
SODIUM_CONFIGURE_WITH=		libsodium
SODIUM_PLIST_FILES=		bin/curve_keygen
STATIC_CONFIGURE_OFF=		--disable-static
TWEETNACL_PLIST_FILES=		bin/curve_keygen

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !${PORT_OPTIONS:MSODIUM} && !${PORT_OPTIONS:MTWEETNACL}
CONFIGURE_ARGS+=	--disable-curve
.endif

.include <bsd.port.mk>
