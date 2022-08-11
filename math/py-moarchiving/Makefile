PORTNAME=	moarchiving
PORTVERSION=	0.6.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Biobjective Archive class with hypervolume indicator and uncrowded hypervolume improvement computation

LICENSE=	BSD3CLAUSE

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ARBITRARY_PRECISION
ARBITRARY_PRECISION_DESC=	Arbitrary precision hypervolume computation support

ARBITRARY_PRECISION_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}fraction>=0:math/py-fraction@${PY_FLAVOR}

.include <bsd.port.mk>
