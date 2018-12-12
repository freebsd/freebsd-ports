# $FreeBSD$

PORTNAME=	pymc3
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Probabilistic programming in Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.7.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=0.9:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.18.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patsy>=0.4.0:math/py-patsy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}theano>=1.0.0:math/py-theano@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.8.4:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pymc-devs
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
