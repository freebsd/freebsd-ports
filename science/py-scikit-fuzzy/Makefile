# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	scikit-fuzzy
PORTVERSION=	0.2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Fuzzy logic toolkit for SciPy

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/scipy/version.py:science/py-scipy
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
