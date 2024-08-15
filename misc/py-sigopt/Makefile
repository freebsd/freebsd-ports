PORTNAME=	sigopt
DISTVERSION=	8.8.3
PORTREVISION=	1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SigOpt Python API client
WWW=		https://sigopt.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backoff>=1.10.0:devel/py-backoff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=2.0.0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}png>0:graphics/py-png@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.5:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist # pytest - missing dependencies, like hyperopt

NO_ARCH=	yes

.include <bsd.port.mk>
