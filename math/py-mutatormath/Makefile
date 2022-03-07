# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	mutatormath
PORTVERSION=	3.0.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MutatorMath-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python for piecewise linear interpolation in multiple dimensions with multiple, arbitrarily placed, masters

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defcon>=0.3.5:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontMath>=0.4.8:x11-fonts/py-fontMath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=3.32.0:print/py-fonttools@${PY_FLAVOR}

USES=		python:3.7+ zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
