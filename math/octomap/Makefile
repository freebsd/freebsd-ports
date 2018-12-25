# $FreeBSD$

PORTNAME=	octomap
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient probabilistic 3D mapping framework based on octrees

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/octomap/LICENSE.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/octovis/LICENSE.txt

BUILD_DEPENDS=		libQGLViewer>0:graphics/libQGLViewer # otherwise it doesn't build, see https://github.com/OctoMap/octomap/issues/225

USES=		cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	OctoMap
USE_LDCONFIG=	yes

# Viewer is broken: https://github.com/OctoMap/octomap/issues/224, and libQGLViewer detection is broken: https://github.com/OctoMap/octomap/issues/225
#CMAKE_ON=	OCTOVIS_QT5
CMAKE_ARGS=	-DQGLVIEWER_BASE_DIR:PATH=${LOCALBASE}/include/QGLViewer #-DQGLViewer_LIBRARY_DIR_OTHER:PATH=${LOCALBASE}/lib

.include <bsd.port.mk>
