PORTNAME=	polars
DISTVERSIONPREFIX=	py-
DISTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	misc
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Blazingly fast DataFrame library
WWW=		https://github.com/pola-rs/polars

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
.for runtime in compat 32 64 # same as flavors in misc/py-polars-runtime
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}polars-runtime-${runtime}==${DISTVERSION}:misc/py-polars-runtime@${runtime}
.endfor
# optional dependencies
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}altair>=5.4.0:graphics/py-altair@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}great-tables>=0.8.0:devel/py-great-tables@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deltalake>0:databases/py-deltalake@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}moto>0:devel/py-moto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyiceberg>0:databases/py-pyiceberg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pola-rs

WRKSRC_SUBDIR=	py-polars

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p moto \
		-p xdist
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS+=	--ignore=unit/io/test_delta_deletion_vector.py # https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=299351
TEST_ARGS+=	--ignore=unit/io/test_iceberg.py # https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=299351
TEST_ARGS+=	--ignore=unit/operations/test_comparison.py # https://github.com/pola-rs/polars/issues/29906
TEST_ARGS+=	--ignore=unit/operations/test_join.py # https://github.com/pola-rs/polars/issues/29906

BINARY_ALIAS=	python3=${PYTHON_CMD}

NO_ARCH=	yes

PORTSCOUT=	limit:^py-

test-quick: stage
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example.py

# tests as of 2.0.0: 270 failed, 40160 passed, 67 skipped, 13 xfailed in 892.77s (0:14:52) # see https://github.com/pola-rs/polars/issues/29907 about failing tests

.include <bsd.port.mk>
