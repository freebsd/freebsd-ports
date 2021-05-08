PORTNAME=	qwtplot3d
PORTVERSION=	0.3.0.g20210210
CATEGORIES=	math
PKGNAMESUFFIX=	-qt5

MAINTAINER=	makc@FreeBSD.org
COMMENT=	3D plotting widgets for Qt

LIB_DEPENDS=	libgl2ps.so:print/gl2ps

USES=		cmake compiler:c++17-lang gl qt:5
USE_QT=		core gui opengl widgets buildtools_build qmake_build
USE_GL=		gl glu
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SciDAVis
GH_TAGNAME=	438c855d

CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt6=True \
		-DBUILD_SHARED_LIBS=True

.include <bsd.port.mk>
