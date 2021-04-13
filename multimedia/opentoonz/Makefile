PORTNAME=	opentoonz
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	multimedia

MAINTAINER=	kde@FreeBSD.org
COMMENT=	2D animation software

LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libgslcblas.so:math/gsl \
		libjson-c.so:devel/json-c \
		liblz4.so:archivers/liblz4 \
		liblzo2.so:archivers/lzo2 \
		libmypaint.so:graphics/libmypaint \
		libopencv_core.so:graphics/opencv \
		libpng16.so:graphics/png \
		libsuperlu.so:math/superlu \
		libturbojpeg.so:graphics/libjpeg-turbo

USES=		cmake:noninja compiler:c++11-lang gettext-runtime gl \
		gnome jpeg pkgconfig qt:5
USE_GITHUB=	yes
USE_GL=		gl glew glu glut
USE_GNOME=	glib20
USE_QT=		core gui multimedia network opengl printsupport \
		script serialport svg widgets xml \
		buildtools_build linguisttools_build qmake_build

CMAKE_SOURCE_PATH=	${WRKSRC}/toonz/sources

.include <bsd.port.mk>
