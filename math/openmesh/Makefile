PORTNAME=	openmesh
DISTVERSION=	9.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.openmesh.org/media/Releases/${DISTVERSION}/
DISTNAME=	OpenMesh-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic data structure for manipulating polygonal meshes
WWW=		https://www.openmesh.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lang dos2unix gl qt:5 xorg
USE_QT=		core concurrent gui help network opengl printsupport script scripttools sql svg x11extras xml xmlpatterns webkit widgets \
		buildtools:build qmake:build uitools:build
USE_GL=		gl glu glut
USE_XORG=	xi xmu
USE_LDCONFIG=	yes

DOS2UNIX_FILES=	src/OpenMesh/Tools/CMakeLists.txt

WRKSRC=		${WRKDIR}/OpenMesh-${DISTVERSION}.0

CMAKE_TESTING_ON=	OPENMESH_BUILD_UNIT_TESTS

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/OpenMesh/Tools/VDPM/xpm

.include <bsd.port.mk>
