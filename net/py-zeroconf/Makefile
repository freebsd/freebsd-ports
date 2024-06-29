PORTNAME=	zeroconf
PORTVERSION=	0.132.2
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Pure python implementation of multicast DNS service discovery
WWW=		https://github.com/python-zeroconf/python-zeroconf

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ifaddr>=0.1.7:net/py-ifaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>=4.0.1:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep8-naming>=0.12.0:devel/py-pep8-naming@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry>=1.8.0:devel/py-poetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=8.0.0:devel/py-pytest@${PY_FLAVOR}

USES=		python cargo
USE_PYTHON=	autoplist concurrent distutils pep517 pytest
USE_GITHUB=	yes
GH_ACCOUNT=	python-zeroconf
GH_PROJECT=	python-zeroconf

NO_ARCH=	yes
TEST_TARGET=	test

.include <bsd.port.mk>
