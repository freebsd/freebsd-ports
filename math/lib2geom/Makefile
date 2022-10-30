PORTNAME=	lib2geom
DISTVERSION=	1.1
PORTREVISION=	3
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
GL_COMMIT=	651c48a76e2c0f361feba8a66d4d693a2a0605a9

CMAKE_ON=	2GEOM_BUILD_SHARED

.include <bsd.port.mk>
