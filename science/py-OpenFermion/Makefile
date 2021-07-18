PORTNAME=	OpenFermion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronic structure package for quantum computers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cvxopt>0:math/py-cvxopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.8:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	quantumlib
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
