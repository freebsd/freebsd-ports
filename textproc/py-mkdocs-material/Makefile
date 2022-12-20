PORTNAME=	mkdocs-material
DISTVERSION=	8.5.11
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocs_material-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Material Design theme for MkDocs
WWW=		https://github.com/squidfunk/mkdocs-material

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.2:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.4.0:textproc/py-mkdocs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-material-extensions>=1.1:textproc/py-mkdocs-material-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.12:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymdown-extensions>=9.4:textproc/py-pymdown-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26:www/py-requests@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Avoid that pyproject.toml is read during setup otherwise build fails
post-extract:
	@${MV} ${WRKSRC}/pyproject.toml ${WRKSRC}/pyproject.toml.dist

post-patch:
	@${REINPLACE_CMD} -e 's/%%DISTVERSION%%/${DISTVERSION}/' ${WRKSRC}/setup.py

.include <bsd.port.mk>
