PORTNAME=	networkauth
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	net
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt6 Network authentication module
WWW=		https://qt-project.org

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libdouble-conversion.so:devel/double-conversion \
		libicudata.so:devel/icu \
		libpcre.so:devel/pcre \
		libpcre2-16.so:devel/pcre2 \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gettext-runtime gnome \
		qt-dist:6
USE_GNOME=	glib20
USE_QT=		base
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
