PORTNAME=	GeoIP2
PORTVERSION=	5.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net python geography
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	MaxMind GeoIP2 Python API
WWW=		https://github.com/maxmind/GeoIP2-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.6.2:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}maxminddb>=2.5.1:net/py-maxminddb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.24.0:www/py-requests@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	GeoIP2-python

USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
