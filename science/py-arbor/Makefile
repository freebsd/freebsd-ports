PORTNAME=	arbor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-compartment neural network simulation library
WWW=		https://arbor-sim.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11 \
		nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libarbor.so:science/arbor

USES=		cmake compiler:c++17-lang localbase:ldflags python
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	arbor-sim

WRKSRC_SUBDIR=	python

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD} \
		-DARB_PYTHON_LIB_PATH=${PYTHONPREFIX_SITELIBDIR}

CXXFLAGS+=	-fPIC

post-patch:
	@${ECHO} ${DISTVERSION} > ${WRKSRC}/VERSION

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/arbor/_arbor${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
