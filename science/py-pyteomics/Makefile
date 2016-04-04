# $FreeBSD$

PORTNAME=	pyteomics
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Python modules for proteomics data analysis

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib \
		${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
