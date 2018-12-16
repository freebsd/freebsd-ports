# $FreeBSD$

PORTNAME=	MutatorMath
PORTVERSION=	2.1.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Piecewise linear interpolation in multiple dimensions

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ufoLib>=2.0.0:x11-fonts/py-ufoLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0.3.5:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontMath>=0.4.4:x11-fonts/py-fontMath@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
