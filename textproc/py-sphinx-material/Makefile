PORTNAME=	sphinx_material
DISTVERSION=	0.0.36
PORTREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Responsive Material Design theme for Sphinx documentation
WWW=		https://bashtage.github.io/sphinx-material/

LICENSE=	MIT

# See https://github.com/bashtage/sphinx-material/issues/141
DEPRECATED=	No longer maintained and does not work with Python 3.12

BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
PY_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR}	\
		slugify:textproc/py-python-slugify@${PY_FLAVOR}	\
		css-html-js-minify:www/py-css-html-js-minify@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	bashtage

USES=		python:-3.11
USE_PYTHON=	distutils

.include <bsd.port.mk>
