PORTNAME=	PyNaCl
DISTVERSION=	1.6.2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding to the Networking and Cryptography library
WWW=		https://github.com/pyca/pynacl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.29.0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=2.0.0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=2.0.0:devel/py-cffi@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=7.4.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.10.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.5.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=3.27.0:devel/py-hypothesis@${PY_FLAVOR}

USES=		python localbase
USE_PYTHON=	pep517 autoplist

OPTIONS_DEFINE=	BUNDLED_NACL
BUNDLED_NACL_DESC=	Use bundled NaCl version
BUNDLED_NACL_LIB_DEPENDS_OFF=	libsodium.so:security/libsodium
BUNDLED_NACL_MAKE_ENV_OFF=	SODIUM_INSTALL=system

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nacl/_sodium*.so

do-test: # tests fail: https://github.com/pyca/pynacl/issues/747
	@cd ${WRKSRC} && ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${PYTHON_CMD} -m pytest -rs tests

# tests as of 1.6.2:
# Results (15.25s):
#          6 failed # failures are due to missing fixtures
#      14003 passed
#         10 skipped
#          1 warning

.include <bsd.port.mk>
