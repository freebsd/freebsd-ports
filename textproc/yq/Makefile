PORTNAME=	yq
DISTVERSION=	4.1.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line YAML and XML processor, jq wrapper for YAML/XML documents
WWW=		https://kislyuk.github.io/yq/ \
		https://github.com/kislyuk/yq

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=1.8.1:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.11.6:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.11.0:devel/py-xmltodict@${PY_FLAVOR} \
		jq:textproc/jq
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		ruff:devel/ruff

USES=		python shebangfix
USE_PYTHON=	pep517 noflavors autoplist

SHEBANG_FILES=	test/test.py

TEST_ENV=	${MAKE_ENV} PATH=${STAGEDIR}${PREFIX}/bin:${PATH} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	go-yq

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ./test.py

# tests as of 4.1.2: Ran 28 tests in 0.400s

.include <bsd.port.mk>
