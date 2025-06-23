PORTNAME=	pymdown-extensions
DISTVERSION=	10.16
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=3.6:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		EXTRA
OPTIONS_DEFAULT=	EXTRA

EXTRA_DESC=	Enable support for extended lexer options
EXTRA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=2.19.1:textproc/py-pygments@${PY_FLAVOR}

.include <bsd.port.mk>
