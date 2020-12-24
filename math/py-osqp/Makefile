# $FreeBSD$

PORTNAME=	osqp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Operator Splitting QP Solver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		cmake:devel/cmake
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.13.2:science/py-scipy@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	oxfordcontrol
GH_PROJECT=	${PORTNAME}-python
GH_TUPLE=	oxfordcontrol:${PORTNAME}:0baddd3:s/${PORTNAME}_sources \
		oxfordcontrol:qdldl:7ab0fca:q/${PORTNAME}_sources/lin_sys/direct/qdldl/qdldl_sources
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
