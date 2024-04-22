PORTNAME=	epy-reader
DISTVERSION=	2023.6.11
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TUI Ebook Reader
WWW=		https://github.com/wustho/epy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517

SHEBANG_FILES=	${WRKSRC}/src/epy_reader/tools/KindleUnpack/*.py

.include <bsd.port.mk>
