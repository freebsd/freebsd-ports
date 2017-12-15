# Created by: ijliao
# $FreeBSD$

PORTNAME=	feedparser
PORTVERSION=	5.2.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Universal feed parser written in Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python tar:bzip2
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	NEWS README.rst

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	@(cd ${WRKSRC}/${PORTNAME}; ${PYTHON_CMD} ${PORTNAME}test.py)

.include <bsd.port.mk>
