PORTNAME=	sphinx-autodoc-typehints
DISTVERSION=	1.23.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_autodoc_typehints-${DISTVERSION}

MAINTAINER=	andreas@bilke.org
COMMENT=	Type hints (PEP 484) support for the Sphinx autodoc extension
WWW=		https://github.com/tox-dev/sphinx-autodoc-typehints

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE


BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.13:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=5.3:textproc/py-sphinx@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=5.3:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517
NO_ARCH=	yes

.include <bsd.port.mk>
