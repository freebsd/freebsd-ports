PORTNAME=	octomap
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient probabilistic 3D mapping framework based on octrees
WWW=		https://octomap.github.io/ \
		https://github.com/OctoMap/octomap

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/octomap/LICENSE.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/octovis/LICENSE.txt

LIB_DEPENDS=	libQGLViewer.so:graphics/libQGLViewer

USES=		cmake:testing compiler:c++11-lang localbase:ldflags gl qt:6
USE_QT=		base tools:build
USE_GL=		gl glu
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	OctoMap

CMAKE_ARGS=	-DQGLVIEWER_BASE_DIR:PATH=${LOCALBASE}/include/QGLViewer #-DQGLViewer_LIBRARY_DIR_OTHER:PATH=${LOCALBASE}/lib

# tests as of 1.10.1: 100% tests passed, 0 tests failed out of 16

.include <bsd.port.mk>
