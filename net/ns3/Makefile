# $FreeBSD$

PORTNAME=	ns3
PORTVERSION=	3.24.1
CATEGORIES=	net
MASTER_SITES=	https://www.nsnam.org/release/
DISTNAME=	ns-allinone-${PORTVERSION}

MAINTAINER=	koue@chaosophia.net
COMMENT=	Network simulator for Internet systems

LICENSE=	GPLv2

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libsqlite3.so:databases/sqlite3

USES=		pkgconfig python tar:bzip2 waf
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	ns-${DISTVERSION}
CONFIGURE_ARGS=	--int64x64=cairo
PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DEBUG EXAMPLES GSL GTK2 SUDO TEST
OPTIONS_DEFAULT=TEST
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ON=	--build-profile=debug
DEBUG_PLIST_SUB=	DEBUG_SUFX="-debug"
DEBUG_CONFIGURE_OFF=	--build-profile=release
DEBUG_PLIST_SUB_OFF=	DEBUG_SUFX=""

EXAMPLES_CONFIGURE_ON=	--enable-examples
EXAMPLES_CONFIGURE_OFF=	--disable-examples

GSL_DESC=		GNU Scientific Library support
GSL_LIB_DEPENDS=	libgsl.so:math/gsl

GTK2_LIB_DEPENDS=	libgtk-x11-2.0.so:x11-toolkits/gtk20
GTK2_CONFIGURE_OFF=	--disable-gtk

SUDO_DESC=		Use sudo to set suid bits on executables
SUDO_BUILD_DEPENDS=	sudo:security/sudo
SUDO_CONFIGURE_ON=	--enable-sudo

TEST_CONFIGURE_ON=	--enable-tests
TEST_CONFIGURE_OFF=	--disable-tests

post-install:
	@${FIND} ${STAGEDIR} \( -path '*/bin/*' -or -name '*.so' \) \
		-type f -exec ${STRIP_CMD} {} +
	@${FIND} ${STAGEDIR} \( -path '*/pkgconfig/*' -or \
			-name 'config-store-config.h' \) \
		-type f -exec ${REINPLACE_CMD} -i '' 's,${STAGEDIR},,' {} +

.include <bsd.port.mk>
