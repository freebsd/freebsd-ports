PORTNAME=	gwlearn
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geographically weighted modeling based on scikit-learn
WWW=		https://pysal.org/gwlearn/stable/ \
		https://github.com/pysal/gwlearn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geopandas>=1.0.0:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=1.4.0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=4.12:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.1.0,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.4.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.12.0,1:science/py-scipy@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
