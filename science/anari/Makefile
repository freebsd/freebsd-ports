PORTNAME=	ANARI
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	science devel graphics
MASTER_SITES=	https://github.com/KhronosGroup/ANARI-SDK/archive/refs/tags/:anari \
		https://github.com/RenderKit/embree/archive/refs/tags/:embree
PKGNAMESUFFIX=	-SDK
DISTFILES=	${DISTVERSIONPREFIX}${PORTVERSION}${EXTRACT_SUFX}:anari \
		${DISTVERSIONPREFIX}${EMBREE_VER}${EXTRACT_SUFX}:embree
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ANARI Cross-Platform 3D Rendering Engine API
WWW=		https://www.khronos.org/anari/

LICENSE=	APACHE20

#USE_GITHUB=	yes
#GH_ACCOUNT=	KhronosGroup
#GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

USES=		cmake python

EMBREE_VER=	4.3.3
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
DATADIR=	${PREFIX}/share/${PORTNAME:tl}
USE_LDCONFIG=	yes

TMPDIR?=	/tmp
TEST_ENV=	ANARI_LIBRARY=helide

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

pre-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/deps/source
	${MV} ${WRKDIR}/embree-${EMBREE_VER}	\
		${CONFIGURE_WRKSRC}/deps/source/anari_helide_embree

do-test:
	cd ${TMPDIR} && ${TEST_ENV} ${TEST_WRKSRC}/anariRenderTests

.include <bsd.port.mk>
