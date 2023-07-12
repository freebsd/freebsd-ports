PORTNAME=	mkdocs-material
DISTVERSION=	9.1.18
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocs_material-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Material Design theme for MkDocs
WWW=		https://github.com/squidfunk/mkdocs-material

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-requirements-txt>0:devel/py-hatch-requirements-txt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-nodejs-version>0:devel/py-hatch-nodejs-version@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.2:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.4.2:textproc/py-mkdocs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-material-extensions>=1.1:textproc/py-mkdocs-material-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.14:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymdown-extensions>=9.9.1:textproc/py-pymdown-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2022.4.24:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
