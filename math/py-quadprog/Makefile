# $FreeBSD$

PORTNAME=	quadprog
DISTVERSION=	0.1.6
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Quadratic programming package

LICENSE=	GPLv2+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.2,1:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist cython

.include <bsd.port.mk>
