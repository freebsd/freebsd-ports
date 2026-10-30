PORTNAME=	mkdocs-material
DISTVERSION=	9.8.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocs_material-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Material Design theme for MkDocs
WWW=		https://github.com/squidfunk/mkdocs-material

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Material for MkDocs is scheduled to reach end of life on May 5, 2027. Please use textproc/py-zensical instead
EXPIRATION_DATE=2027-05-05

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-requirements-txt>0:devel/py-hatch-requirements-txt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-nodejs-version>=0.3.0:devel/py-hatch-nodejs-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trove-classifiers>=2023.10.18:devel/py-trove-classifiers@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.10:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}backrefs>=5.7:textproc/py-backrefs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.8.1:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.6<2:textproc/py-mkdocs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-material-extensions>=1.3:textproc/py-mkdocs-material-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paginate>=0.5:textproc/py-paginate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.20.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymdown-extensions>=11.0.1:textproc/py-pymdown-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.33.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

# Option GIT requires py-mkdocs-git-committers-plugin-2 which is not currently
# in the ports tree.
OPTIONS_DEFINE=		IMAGING RECOMMENDED
OPTIONS_DEFAULT=	RECOMMENDED

IMAGING_DESC=		Support for image processing
RECOMMENDED_DESC=	Install a recommended set of MkDocs plugins

IMAGING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairosvg>=2.9.1:graphics/py-cairosvg@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=13.0.0:graphics/py-pillow@${PY_FLAVOR}

RECOMMENDED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocs-minify-plugin>=0.7:textproc/py-mkdocs-minify-plugin@${PY_FLAVOR}

.include <bsd.port.mk>
