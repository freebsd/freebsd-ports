PORTNAME=	ipyfastscape
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	misc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive widgets for topographic data analysis and modelling
WWW=		https://github.com/fastscape-lem/ipyfastscape

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipygany>=0.5.0:science/py-ipygany@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}xarray>0:devel/py-xarray@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	fastscape-lem

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION} # workaround for LookupError: setuptools-scm was unable to detect version for ...

NO_ARCH=	yes

.include <bsd.port.mk>
