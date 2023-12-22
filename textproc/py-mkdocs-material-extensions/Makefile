PORTNAME=	mkdocs-material-extensions
DISTVERSION=	1.3.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocs_material_extensions-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Markdown extension resources for MkDocs for Material
WWW=		https://github.com/facelessuser/mkdocs-material-extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0.21.1:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
