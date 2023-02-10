PORTNAME=	mkdocs-material-extensions
DISTVERSION=	1.1.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocs_material_extensions-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Markdown extension resources for MkDocs for Material
WWW=		https://github.com/facelessuser/mkdocs-material-extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Avoid that pyproject.toml is read during setup otherwise build fails
post-extract:
	@${MV} ${WRKSRC}/pyproject.toml ${WRKSRC}/pyproject.toml.dist

post-patch:
	@${REINPLACE_CMD} -e 's/%%DISTVERSION%%/${DISTVERSION}/' ${WRKSRC}/setup.py

.include <bsd.port.mk>
