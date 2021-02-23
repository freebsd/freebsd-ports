# $FreeBSD$

PORTNAME=	cvxpy
DISTVERSION=	1.1.10
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Domain-specific language for modeling convex optimization problems

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ecos>=2:math/py-ecos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osqp>=0.4.1:math/py-osqp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scs>=1.1.6:math/py-scs@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-install:
		${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_cvxcore*.so

.include <bsd.port.mk>
