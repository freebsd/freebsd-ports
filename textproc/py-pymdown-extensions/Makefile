PORTNAME=	pymdown-extensions
DISTVERSION=	9.9.2
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymdown_extensions-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Extension pack for Python Markdown
WWW=		https://github.com/facelessuser/pymdown-extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0.21.1:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=3.2:textproc/py-markdown@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
