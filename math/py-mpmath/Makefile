# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mpmath
PORTVERSION=	0.17
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Library for Arbitrary-precision Floating-point Arithmetic

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gmpy.so:${PORTSDIR}/math/py-gmpy

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
