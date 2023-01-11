PORTNAME=	booleanOperations
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Boolean operations on paths
WWW=		https://github.com/typemytype/booleanOperations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.11:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyclipper>=1.0.5:math/py-pyclipper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=3.32.0:print/py-fonttools@${PY_FLAVOR}

USES=		python:3.6+ zip
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
