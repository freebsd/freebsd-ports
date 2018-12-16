# $FreeBSD$

PORTNAME=	booleanOperations
PORTVERSION=	0.8.0
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Boolean operations on paths

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.11:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyclipper>=1.0.5:math/py-pyclipper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=3.1.2:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufoLib>=2.0.0:x11-fonts/py-ufoLib@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
