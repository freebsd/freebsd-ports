PORTNAME=	cgal
PORTVERSION=	5.6.2
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://github.com/${PORTNAME:tu}/${PORTNAME}/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Computational geometry library
WWW=		https://www.cgal.org/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/lib/libntl.a:math/ntl
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libmpfr.so:math/mpfr \
		libgmp.so:math/gmp

#TODO math/mpfi, math/rs, graphics/qglviewer
#Not yet in ports
USES=		cmake eigen:3 shebangfix tar:xz

NO_ARCH=	yes

SHEBANG_FILES=	scripts/cgal_create_CMakeLists \
		scripts/cgal_create_cmake_script

OPTIONS_DEFINE=		VISUALIZATION QT5
VISUALIZATION_IMPLIES=	QT5
OPTIONS_SUB=		yes

VISUALIZATION_DESC=		Visualization Required for most demos (Qt5 Geomview)
VISUALIZATION_LIB_DEPENDS=	libgeomview.so:graphics/geomview

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT5}
USES+=		gl qt:5
CMAKE_ARGS+=	-DWITH_CGAL_Qt5=ON
USE_QT+=	core gui opengl widgets svg buildtools:build qmake:build xml
USE_GL+=	gl glu
.else
CMAKE_ARGS+=	-DWITH_CGAL_Qt5=OFF
.endif

.include <bsd.port.mk>
