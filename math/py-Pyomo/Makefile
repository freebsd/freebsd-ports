# $FreeBSD$

PORTNAME=	Pyomo
DISTVERSION=	5.4.3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Optimization Modeling Objects

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyUtilib>=5.6.2:devel/py-PyUtilib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
