# $FreeBSD$

PORTNAME=	OpenFermion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronic structure package for quantum computers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

py27_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cvxopt>0:math/py-cvxopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0.18.0:science/py-scipy@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	quantumlib
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
