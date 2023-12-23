PORTNAME=	lib2geom
DISTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	math gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Easy to use 2D geometry library in C++
WWW=		https://gitlab.com/inkscape/lib2geom

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING-LGPL-2.1
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING-MPL-1.1

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		ragel:devel/ragel \
		googletest>0:devel/googletest
LIB_DEPENDS=	libdouble-conversion.so:devel/double-conversion \
		libgsl.so:math/gsl \
		libboost_thread.so:devel/boost-libs
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR}
TEST_DEPENDS=	googletest>0:devel/googletest \
		ragel:devel/ragel

USES=		cmake:testing gettext-runtime gnome localbase:ldflags pkgconfig \
		python
USE_GNOME=	cairo glib20 gtk30
USE_PYTHON=	cython cython_test

USE_GITLAB=	yes
GL_ACCOUNT=	inkscape

CMAKE_ON=	2GEOM_BUILD_SHARED \
		2GEOM_TESTING

PLIST_SUB=	VERSION=${PORTVERSION}.0

OPTIONS_DEFINE=	GPL

GPL_DESC=	Build with GPL-licensed code
GPL_CMAKE_BOOL=	2GEOM_USE_GPL_CODE

.include <bsd.port.mk>
