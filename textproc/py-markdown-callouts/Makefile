PORTNAME=	markdown-callouts
DISTVERSION=	0.4.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	markdown_callouts-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Markdown extension: Classier syntax for admonitions
WWW=		https://github.com/oprypin/markdown-callouts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=3.3.3:textproc/py-markdown@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
