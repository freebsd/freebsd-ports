PORTNAME=	openmesh
DISTVERSION=	11.0.0
CATEGORIES=	math
MASTER_SITES=	http://www.openmesh.org/media/Releases/${DISTVERSION:R}/
DISTNAME=	OpenMesh-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic data structure for manipulating polygonal meshes
WWW=		https://www.openmesh.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lang dos2unix eigen:3 gl qt:5 xorg
USE_QT=		core gui opengl widgets \
		buildtools:build qmake:build uitools:build
USE_GL=		gl glu
USE_XORG=	xi xmu
USE_LDCONFIG=	yes

DOS2UNIX_FILES=	src/OpenMesh/Tools/CMakeLists.txt

CMAKE_TESTING_ON=	OPENMESH_BUILD_UNIT_TESTS

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/OpenMesh/Tools/VDPM/xpm

# 2 tests fail, reported to Jan Moebius via e-mail on 2024-06-26

.include <bsd.port.mk>
