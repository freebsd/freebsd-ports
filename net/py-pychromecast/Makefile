PORTNAME=	PyChromecast
DISTVERSION=	13.0.8
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lexi.freebsd@le-fay.org
COMMENT=	Python module to talk to Google Chromecast
WWW=		https://pypi.org/project/PyChromecast/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}zeroconf>0:net/py-zeroconf@${PY_FLAVOR}		\
		${PYTHON_PKGNAMEPREFIX}casttube>0:net/py-casttube@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
