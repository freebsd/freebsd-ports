# New ports collection makefile for:	yuicompressor
# Date created:	   25 Apr 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	yuicompressor
PORTVERSION=	2.3.6
CATEGORIES=	www java
MASTER_SITES=	http://www.julienlecomte.net/yuicompressor/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	The Yahoo! JavaScript and CSS Compressor

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

PLIST_FILES=	bin/yuicompressor %%DATADIR%%/yuicompressor.jar
PLIST_DIRS=	%%DATADIR%%
SUB_FILES=	yuicompressor

PORTDOCS=	README

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/build/yuicompressor-${PORTVERSION}.jar ${DATADIR}/yuicompressor.jar
	${INSTALL_SCRIPT} ${WRKDIR}/yuicompressor ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
