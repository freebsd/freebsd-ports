PORTNAME=	sigopt
DISTVERSION=	8.8.2 # should be 8.8.2-20240313, but this fails due to *-${DISTVERSION}*.whl, while *-8.8.2.whl is built
CATEGORIES=	misc python # machine-learning
#MASTER_SITES=	PYPI # tarball is broken, see https://github.com/sigopt/sigopt-python/issues/439
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
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist # pytest - missing dependencies, like hyperopt

USE_GITHUB=	yes
GH_PROJECT=	sigopt-python
GH_TAGNAME=	a52302f

NO_ARCH=	yes

.include <bsd.port.mk>
