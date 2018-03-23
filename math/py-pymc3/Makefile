# $FreeBSD$

PORTNAME=	pymc3
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Probabilistic programming in Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=2.7.0:science/py-h5py@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=0.9:devel/py-joblib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.18.0:math/py-pandas@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patsy>=0.4.0:math/py-patsy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}theano>=1.0.0:math/py-theano@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.8.4:misc/py-tqdm@${FLAVOR}
py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enum34>=1.1.6:devel/py-enum34@${FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pymc-devs
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
