PORTNAME=	sphinxcontrib-apidoc
DISTVERSION=	0.6.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/[-_.]/_/}-${DISTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	A Sphinx extension for running sphinx-apidoc on each build
WWW=		https://github.com/sphinx-contrib/apidoc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=4.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=5.0.0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=4.0:devel/py-pbr@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

.include <bsd.port.mk>
