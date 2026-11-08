PORTNAME=	jarvis-tools
DISTVERSION=	2026.6.12
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Joint Automated Repository for Various Integrated Simulations
WWW=		https://jarvis.nist.gov/ \
		https://github.com/atomgptlab/jarvis-tools

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}joblib>=0.14.1:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.0.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.20.1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.23.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.5.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toolz>=0.9.0:devel/py-toolz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.41.1:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.11.0:devel/py-xmltodict@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
