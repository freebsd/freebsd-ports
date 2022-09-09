PORTNAME=	Pyomo
DISTVERSION=	6.4.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Optimization Modeling Objects
WWW=		https://github.com/Pyomo/pyomo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils cython concurrent autoplist

.include <bsd.port.mk>
