# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	scikit-fuzzy
DISTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fuzzy logic toolkit for SciPy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}networkx>=1.9.0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.9.0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
