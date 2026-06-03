PORTNAME=	simplebayes
DISTVERSION=	3.2.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Memory-based, optional-persistence naive bayesian text classifier
WWW=		https://github.com/hickeroar/simplebayes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastapi>=0.116.1:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snowballstemmer>=3.0.1:textproc/py-snowballstemmer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.35.0:www/py-uvicorn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# FreeBSD's packaged snowballstemmer lacks Yiddish stemming support; disable
# upstream's coverage gate as well because port tests only need functional checks.
TEST_ARGS=	--no-cov \
		tests/test_api_endpoints.py \
		tests/test_cli.py \
		tests/test_cli_integration.py \
		tests/test_concurrency.py \
		tests/test_contracts.py \
		tests/test_persistence.py \
		tests/test_runtime_readiness.py \
		tests/test_tokenization.py \
		-k 'not test_create_tokenizer_language_yiddish_has_stopwords'
#TEST_WRKSRC=	${WRKSRC}/tests

post-extract: # https://github.com/hickeroar/simplebayes/issues/3
	@truncate -s 0 ${WRKSRC}/README.rst

# tests as of 3.2.0:
# Results (3.30s):
#        273 passed
#          2 warnings

.include <bsd.port.mk>
