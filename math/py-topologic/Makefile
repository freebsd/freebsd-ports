PORTNAME=	topologic
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.3
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-space-modeling-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for topological representations of architectural spaces
WWW=		https://topologic.app/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11
LIB_DEPENDS=	libTopologicCore.so:math/topologic

USES=		cmake compiler:c++17-lang localbase:ldflags python

USE_GITHUB=	yes
GH_ACCOUNT=	wassimj
GH_PROJECT=	Topologic

WRKSRC_SUBDIR=	TopologicPythonBindings

CXXFLAGS+=	-I${LOCALBASE}/include/OpenCASCADE \
		-I${LOCALBASE}/include/TopologicCore
LDFLAGS+=	-L${LOCALBASE}/lib/TopologicCore

PLIST_FILES=	${PYTHON_SITELIBDIR}/topologic_core${PYTHON_TAG}.so

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-install: # workaround for https://github.com/wassimj/Topologic/issues/34
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/topologic_core${PYTHON_TAG}.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
.for tst in topologictest01 topologictest02
	${ECHO} "====> Running test ${tst}"
	${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${WRKSRC}/test/${tst}.py
.endfor

.include <bsd.port.mk>
