PORTNAME=	tokenizers
DISTVERSION=	0.22.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Fast state-of-the-art tokenizers optimized for research and production
WWW=		https://github.com/huggingface/tokenizers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/tokenizers/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}
LIB_DEPENDS=	libonig.so:devel/oniguruma
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.16.4<2.0:misc/py-huggingface-hub@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}datasets>0:misc/py-datasets@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist pep517 pytest
PYTEST_BROKEN_TESTS=	test_gzip

CARGO_CARGOTOML=${WRKSRC}/bindings/python/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/bindings/python/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TEST_ARGS=	--no-default-features

MAKE_ENV=	${CARGO_ENV}
TEST_ARGS=	tests
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

BINARY_ALIAS=	python3=${PYTHON_CMD}

TEST_WRKSRC=	${WRKSRC}/bindings/python

post-test:
	cd ${TEST_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${TEST_ENV} ${CARGO} test \
		--manifest-path ${CARGO_CARGOTOML} --verbose --verbose ${CARGO_TEST_ARGS}

.include <bsd.port.mk>
