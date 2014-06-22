# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mpmath
PORTVERSION=	0.19
CATEGORIES=	devel math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Library for Arbitrary-precision Floating-point Arithmetic

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gmpy.so:${PORTSDIR}/math/py-gmpy

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
