PORTNAME=	pyopenssl
PORTVERSION=	26.3.0
PORTEPOCH=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the OpenSSL library
WWW=		https://pyopenssl.org/en/latest/ \
		https://github.com/pyca/pyopenssl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pretend>=0:devel/py-pretend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>=0:devel/py-pytest-rerunfailures@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent cryptography pep517 pytest

NO_ARCH=	yes
# test_connect_refused: Avoid stalling in build environments that don't have an internet connection
# test_connect_ex: https://github.com/pyca/pyopenssl/issues/1192
PYTEST_IGNORED_TESTS=	test_connect_ex \
			test_connect_refused
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

CPE_VENDOR=	jean-paul_calderone

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.9:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
