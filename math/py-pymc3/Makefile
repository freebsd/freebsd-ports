PORTNAME=	pymc3
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.5
PORTREVISION=	3
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Probabilistic programming in Python
WWW=		https://docs.pymc.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}arviz>=0.11.0:math/py-arviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>=4.2.1:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecat>0:devel/py-deprecat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>0:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastprogress>=0.2.0:devel/py-fastprogress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.24.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patsy>=0.5.1:math/py-patsy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7.3:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=2.13.0:devel/py-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}theano>0:math/py-theano@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pymc-devs
USE_PYTHON=	distutils concurrent autoplist

WRKSRC=		${WRKDIR}/pymc-${DISTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
