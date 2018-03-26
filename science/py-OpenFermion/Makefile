# $FreeBSD$

PORTNAME=	OpenFermion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4-29
DISTVERSIONSUFFIX=	-g781d0a7
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronic structure package for quantum computers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cvxopt>0:math/py-cvxopt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.18.0:science/py-scipy@${FLAVOR} \
		${PYNUMPY}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	quantumlib
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
