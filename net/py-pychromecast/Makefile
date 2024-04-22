PORTNAME=	PyChromecast
DISTVERSION=	13.1.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@freebsd.org
COMMENT=	Python module to talk to Google Chromecast
WWW=		https://pypi.org/project/PyChromecast/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=3.19.1:devel/py-protobuf@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}zeroconf>=0.25.1:net/py-zeroconf@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}casttube>=0.2.0:net/py-casttube@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
