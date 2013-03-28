# $FreeBSD$

PORTNAME=	pyteomics
PORTVERSION=	2.1.3
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP/source/p/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Python modules for proteomics data analysis

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:${PORTSDIR}/math/py-matplotlib \
		${PYNUMPY}

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
