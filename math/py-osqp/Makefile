# $FreeBSD$

PORTNAME=	osqp
DISTVERSION=	0.6.2.post0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Operator Splitting QP Solver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}qdldl>0:math/py-qdldl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.13.2:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		cmake:devel/cmake
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
