# Created by: ijliao
# $FreeBSD$

PORTNAME=	feedparser
PORTVERSION=	5.1.3
PORTREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Universal feed parser written in Python

LICENSE=	MIT

USES=		tar:bzip2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	NEWS PKG-INFO README

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

regression-test: extract
	@(cd ${WRKSRC}/${PORTNAME}; ${PYTHON_CMD} ${PORTNAME}test.py)

.include <bsd.port.mk>
