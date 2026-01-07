PORTNAME=	libzmq4
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://github.com/zeromq/libzmq/releases/download/${DISTVERSIONFULL}/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ZeroMQ core library (Version 4)
WWW=		https://www.zeromq.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--disable-silent-rules \
			--disable-Werror \
			--mandir=${PREFIX}/share/man

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFLICTS=	libzmq[^4] zmq

OPTIONS_DEFINE=			CURVE DRAFT_API LIBUNWIND MANPAGES STATIC
OPTIONS_DEFAULT=		CURVE DRAFT_API MANPAGES NORM PGM STATIC
OPTIONS_GROUP=			MULTICAST
OPTIONS_GROUP_MULTICAST=	NORM PGM
OPTIONS_SUB=			yes

CURVE_DESC=	CURVE security backend
DRAFT_API_DESC=	Enable draft (experimental) APIs
LIBUNWIND_DESC=	Use libunwind to print stack trace in case of error
MULTICAST_DESC=	Reliable Multicast Transports
NORM_DESC=	Enable NORM via NRL
PGM_DESC=	Enable PGM transport via OpenPGM

CURVE_LIB_DEPENDS=		libsodium.so:security/libsodium
CURVE_CONFIGURE_OFF=		--disable-curve
CURVE_CONFIGURE_WITH=		libsodium
CURVE_PLIST_FILES=		bin/curve_keygen
DRAFT_API_CONFIGURE_ENABLE=	drafts
LIBUNWIND_LIB_DEPENDS=		libunwind.so:devel/libunwind
LIBUNWIND_CONFIGURE_ENABLE=	libunwind
NORM_LIB_DEPENDS=		libnorm.so:net/norm
NORM_CONFIGURE_WITH=		norm=${PREFIX}
PGM_LIB_DEPENDS=		libpgm.so:net/openpgm
PGM_CONFIGURE_WITH=		pgm

STATIC_CONFIGURE_OFF=		--disable-static

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.mk>
