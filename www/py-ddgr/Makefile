# $FreeBSD$

PORTNAME=	ddgr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
CATEGORIES=	www
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Command line tool for performing DuckDuckGo web searches

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests@${FLAVOR}

USES=		python:3.3+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	jarun
USE_PYTHON=	concurrent flavors
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	${PORTNAME}
python_OLD_CMD=	"/usr/bin/env python3" # see bug#223980

MAKE_ARGS=	DOCDIR=${STAGEDIR}${DOCSDIR} FREEBSD_PYTHON_VER=${PYTHON_VER}

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/ddgr \
		man/man1/ddgr.1.gz
PORTDOCS=	README.md

.include <bsd.port.mk>
