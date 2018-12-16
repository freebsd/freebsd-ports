# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mpmath
PORTVERSION=	1.1.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Library for Arbitrary-precision Floating-point Arithmetic

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gmpy.so:math/py-gmpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
