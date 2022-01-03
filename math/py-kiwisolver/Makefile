PORTNAME=	kiwisolver
PORTVERSION=	1.3.2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Fast implementation of the Cassowary constraint solver

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}cppy>=1.1.0:devel/py-cppy@${PY_FLAVOR}

USES=		compiler:c++11-lang python:3.6+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
