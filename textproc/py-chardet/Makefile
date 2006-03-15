# New ports collection Makefile for:	py-chardet
# Date created:				2005-01-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	chardet
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	http://chardet.feedparser.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Character encoding auto-detection in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.if !defined(NOPORTDOCS)
PORTDOCS=	docs COPYING
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${CP} -R ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
