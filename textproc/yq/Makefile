PORTNAME=	yq
DISTVERSION=	3.4.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line YAML and XML processor, jq wrapper for YAML/XML documents
WWW=		https://kislyuk.github.io/yq/ \
		https://github.com/kislyuk/yq

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	jq:textproc/jq \
		${PYTHON_PKGNAMEPREFIX}argcomplete>=1.8.1:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>=5.3.1:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.11.6:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.11.0:devel/py-xmltodict@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		ruff:devel/ruff \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 noflavors autoplist

SHEBANG_FILES=	test/test.py

TEST_ENV=	${MAKE_ENV} PATH=${STAGEDIR}${PREFIX}/bin:${PATH} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	go-yq

NO_ARCH=	yes

do-test: # tests fail: https://github.com/mikefarah/yq/issues/2016
	@cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ./test.py

.include <bsd.port.mk>
