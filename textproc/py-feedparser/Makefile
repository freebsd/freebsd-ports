# Created by: ijliao
# $FreeBSD$

PORTNAME=	feedparser
PORTVERSION=	5.1.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	RSS feed parser written in Python

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:${PORTSDIR}/textproc/py-chardet

USE_PYTHON=	yes
USE_BZIP2=	yes
USE_PYDISTUTILS=yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	NEWS PKG-INFO README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

regression-test: extract
	@(cd ${WRKSRC}/${PORTNAME}; ${PYTHON_CMD} ${PORTNAME}test.py)

.include <bsd.port.mk>
