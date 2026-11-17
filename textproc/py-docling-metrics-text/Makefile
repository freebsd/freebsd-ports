PORTNAME=	docling-metrics-text
DISTVERSION=	0.19.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Text metrics
WWW=		https://github.com/docling-project/docling-metrics

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=2.12:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0:devel/py-scikit-build-core@${PY_FLAVOR} \
		loguru>=2.1.0:devel/loguru
LIB_DEPENDS=	libabsl_strings.so:devel/abseil \
		libre2.so:devel/re2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling-metrics-core>=0.0.1:textproc/py-docling-metrics-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}evaluate>=0.4.3:misc/py-evaluate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.9.1:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR}

USES=		cmake:indirect python localbase pkgconfig
USE_PYTHON=	autoplist concurrent pep517 pytest

CMAKE_ARGS=	-DUSE_SYSTEM_DEPS=ON

# tests download the evaluate metric modules from the network
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		REQUESTS_CA_BUNDLE=/etc/ssl/cert.pem SSL_CERT_FILE=/etc/ssl/cert.pem
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload

post-extract:
	@${MKDIR} ${WRKSRC}/cpp/include
	@${CP} ${FILESDIR}/cpp_include/*.h ${WRKSRC}/cpp/include/

# tests as of 0.19.0: 3 passed in 13.57s

.include <bsd.port.mk>
