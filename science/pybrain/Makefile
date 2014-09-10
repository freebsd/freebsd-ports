# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pybrain
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	science python
DISTNAME=	PyBrain-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	PyBrain is the swiss army knife for neural networking

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.7.1:${PORTSDIR}/science/py-scipy

GH_ACCOUNT=	${PORTNAME}
GH_COMMIT=	a56fafc

USE_GITHUB=	yes

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
