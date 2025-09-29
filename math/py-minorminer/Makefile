PORTNAME=	minorminer
DISTVERSION=	0.2.19
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Heuristic tool for minor embedding of graphs
WWW=		https://docs.ocean.dwavesys.com/projects/minorminer/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fasteners>=0.19:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}homebase>=1.0.1:devel/py-homebase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=3.2.1:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-networkx>=0.8.15:science/py-dwave-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}rectangle-packer>=2.0.1:math/py-rectangle-packer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.13.1:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems
GH_TUPLE=	boothby:glasgow-subgraph-solver:568c45f:glasgow_subgraph_solver/external/glasgow-subgraph-solver \
		nemequ:portable-snippets:84abba9:portable_snippets/external/portable-snippets

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/minorminer/_extern/rpack/_core${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/minorminer/_minorminer${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/minorminer/busclique${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/minorminer/subgraph${PYTHON_TAG}.so

.include <bsd.port.mk>
