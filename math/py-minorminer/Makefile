PORTNAME=	minorminer
DISTVERSION=	0.2.23
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Heuristic tool for minor embedding of graphs
WWW=		https://docs.ocean.dwavesys.com/projects/minorminer/en/latest/ \
		https://github.com/dwavesystems/minorminer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fasteners>=0.19:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}homebase>=1.0.1:devel/py-homebase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=3.2.1:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-graphs>=1:science/py-dwave-graphs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rectangle-packer>=2.0.1:math/py-rectangle-packer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.13.1:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		boost-libs>0:devel/boost-libs
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subtests>0:devel/py-pytest-subtests@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	distutils cython autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems
GH_TUPLE=	boothby:glasgow-subgraph-solver:e544b549c0e6:glasgow_subgraph_solver/external/glasgow-subgraph-solver \
			nemequ:portable-snippets:84abba9:portable_snippets/external/portable-snippets

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload

pre-test:
	@${CP} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/minorminer/_extern/rpack/_core${PYTHON_TAG}.so \
		${WRKSRC}/minorminer/_extern/rpack/_core${PYTHON_TAG}.so
	@${CP} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/minorminer/_minorminer${PYTHON_TAG}.so \
		${WRKSRC}/minorminer/_minorminer${PYTHON_TAG}.so
	@${CP} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/minorminer/busclique${PYTHON_TAG}.so \
		${WRKSRC}/minorminer/busclique${PYTHON_TAG}.so
	@${CP} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/minorminer/subgraph${PYTHON_TAG}.so \
		${WRKSRC}/minorminer/subgraph${PYTHON_TAG}.so

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/minorminer/_extern/rpack/_core${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/minorminer/_minorminer${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/minorminer/busclique${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/minorminer/subgraph${PYTHON_TAG}.so

# tests as of 0.2.23: 322 passed, 1 skipped, 390 warnings, 415 subtests passed in 92.19s (0:01:32)

.include <bsd.port.mk>
