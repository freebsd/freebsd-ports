# ex:ts=8
# Ports collection makefile for:	feedparser
# Date created: 		Mar 11, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	feedparser
PORTVERSION=	4.1
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	An RSS feed parser written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/chardet/__init__.py:${PORTSDIR}/textproc/py-chardet

WRKSRC=		${WRKDIR}
USE_PYTHON=	yes
USE_ZIP=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in *.html
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.for j in images css examples
	@${MKDIR} ${DOCSDIR}/${j}
.for i in *
	${INSTALL_DATA} ${WRKSRC}/docs/${j}/${i} ${DOCSDIR}/${j}
.endfor
.endfor
.endif

.include <bsd.port.post.mk>
