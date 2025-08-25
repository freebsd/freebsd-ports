PORTNAME=	xlife++
DISTVERSION=	3.0
CATEGORIES=	math
MASTER_SITES=	https://gitlab.inria.fr/xlifepp/downloads/-/raw/main/v${DISTVERSION}/
DISTNAME=	xlifepp-sources-v${DISTVERSION}-2025-01-30

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	XLiFE++: eXtended Library of Finite Elements in C++
WWW=		https://xlifepp.pages.math.cnrs.fr/ \
		https://uma.ensta-paristech.fr/soft/XLiFE++/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang eigen:3 fortran
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/xlifepp-v${DISTVERSION}

CMAKE_OFF=	XLIFEPP_ENABLE_ARPACK # should be ON, but it fails to build. Reported to their bugs ML.

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3/Eigen -I${LOCALBASE}/include/ARPACK++

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract: # delete bundled packages
	@${RM} -r ${WRKSRC}/ext/Eigen ${WRKSRC}/ext/ARPACK ${WRKSRC}/ext/ARPACK++

post-configure:
	@${REINPLACE_CMD} -E 's/.*(ARPACK|Eigen)/#&/' ${CONFIGURE_WRKSRC}/cmake_install.cmake

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r CMakeLists.txt VERSION.txt etc/visuTermVec.m etc/templates etc/gmsh

# build from source instructions: https://xlifepp.pages.math.cnrs.fr/installation/from_sources.html

.include <bsd.port.mk>
