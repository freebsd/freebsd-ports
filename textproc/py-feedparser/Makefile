# ex:ts=8
# Ports collection makefile for:	feedparser
# Date created: 		Mar 11, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	feedparser
PORTVERSION=	3.3
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://bsdchat.com/dist/dryice/
MASTER_SITE_SUBDIR=	feedparser
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	An RSS feed parser written in Python

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PYTHON=	2.1+
USE_ZIP=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in *.html
	@${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/images
.for i in *
	@${INSTALL_DATA} ${WRKSRC}/docs/images/${i} ${DOCSDIR}/images
.endfor
.endif

.include <bsd.port.mk>
