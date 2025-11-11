PORTNAME=	urllib3
PORTVERSION=	2.5.0
PORTEPOCH=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI \
		https://github.com/urllib3/urllib3/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	HTTP library with thread-safe connection pooling, file post, and more
WWW=		https://urllib3.readthedocs.io/en/stable/ \
		https://github.com/urllib3/urllib3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.4.0<0.6.0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.6.0<2:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8<10:devel/py-setuptools-scm@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=1.0.9:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=4<5:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>=25.0.0,1:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=1.5.6<2.0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.3.1:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quart>=0.20.0:www/py-quart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quart-trio>=0.12.0:www/py-quart-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>=0.27.0:net/py-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trustme>=1.2.1:security/py-trustme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.18.0:archivers/py-zstandard@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent cryptography_test pep517 pytest

NO_ARCH=	yes
PYTEST_IGNORED_TESTS=	test_ssl_read_timeout
TEST_ENV=	LC_ALL=en_US.UTF-8 \
		PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

SUB_FILES=	pkg-message

CPE_VENDOR=	python

OPTIONS_DEFINE=	BROTLI H2 SOCKS ZSTD
OPTIONS_DEFAULT=SOCKS
H2_DESC=	HTTP/2 protocol

BROTLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=1.0.9:archivers/py-brotli@${PY_FLAVOR}
H2_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}h2>=4<5:www/py-h2@${PY_FLAVOR}
SOCKS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=1.5.6<2.0:net/py-pysocks@${PY_FLAVOR}
ZSTD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zstandard>=0.18.0:archivers/py-zstandard@${PY_FLAVOR}

post-patch:
	# https://github.com/urllib3/urllib3/pull/3682
	@${REINPLACE_CMD} -e 's|setuptools-scm>=8,<9|setuptools-scm>=8,<10|' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
