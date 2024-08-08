PORTNAME=	pychromecast
PORTVERSION=	14.0.1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyChromecast-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module to talk to Google Chromecast
WWW=		https://github.com/home-assistant-libs/pychromecast

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.37.1:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}casttube>=0.2.0:net/py-casttube@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.25.1,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zeroconf>=0.25.1:net/py-zeroconf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
