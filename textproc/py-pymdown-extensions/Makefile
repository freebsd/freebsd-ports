PORTNAME=	pymdown-extensions
DISTVERSION=	9.6
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymdown_extensions-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Extension pack for Python Markdown
WWW=		https://github.com/facelessuser/pymdown-extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=3.2:textproc/py-markdown@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Avoid that pyproject.toml is read during setup otherwise build fails
post-extract:
	@${MV} ${WRKSRC}/pyproject.toml ${WRKSRC}/pyproject.toml.dist

post-patch:
	@${REINPLACE_CMD} -e 's/%%DISTVERSION%%/${DISTVERSION}/' ${WRKSRC}/setup.py

.include <bsd.port.mk>
