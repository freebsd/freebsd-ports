PORTNAME=	zeroconf
PORTVERSION=	0.132.2
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Pure python implementation of multicast DNS service discovery
WWW=		https://github.com/python-zeroconf/python-zeroconf

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING


BUILD_DEPENDS=	lang/cython3>=3.0.8:lang/cython3 \
		${PYTHON_PKGNAMEPREFIX}poetry-core>=1.5.2:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.40.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}async_timeout>=3.0.1:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ifaddr>=0.1.7:net/py-ifaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep8-naming>=0.12.0:devel/py-pep8-naming@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=8.0.0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.20.3:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest
USE_GITHUB=	yes
GH_ACCOUNT=	python-zeroconf
GH_PROJECT=	python-zeroconf

TEST_TARGET=	test

.include <bsd.port.mk>
