PORTNAME=	arybo
DISTVERSION=	1.1.0
CATEGORIES=	math
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Manipulation of mixed boolean-arithmetic symbolic expressions

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llvmlite>0:devel/py-llvmlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.4:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytanque>=1.0:math/py-pytanque@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		compiler:c++14-lang python:3.5+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
