PORTNAME=	lib2geom
DISTVERSION=	1.2.2
CATEGORIES=	math gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Easy to use 2D geometry library in C++
WWW=		https://gitlab.com/inkscape/lib2geom

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libdouble-conversion.so:devel/double-conversion \
		libgsl.so:math/gsl \
		libboost_thread.so:devel/boost-libs

USES=		cmake gettext-runtime gnome localbase:ldflags pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo glib20

GL_ACCOUNT=	inkscape
GL_COMMIT=	a84a73ebdae50cc729f57d1ffb788aeaef0f746c

CMAKE_ON=	2GEOM_BUILD_SHARED

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
