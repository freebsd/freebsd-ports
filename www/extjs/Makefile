# New ports collection makefile for:	extjs
# Date created:		2010-01-28
# Whom:			Joe Horn <joehorn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	extjs
PORTVERSION=	3.3.1
CATEGORIES=	www
MASTER_SITES=	http://downloads.sencha.com/extjs/ \
		http://mirror.joehorn.idv.tw/extjs/
DISTNAME=	ext-${PORTVERSION}

MAINTAINER=	joehorn@gmail.com
COMMENT=	A JavaScript platform for rapid development of cross-browser web apps

WRKSRC=		${WRKDIR}/${DISTNAME}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

USE_ZIP=	yes
NO_BUILD=	yes

OPTIONS=	DOC	"Install with documents" on \
		EXAMPLE "Install with examples" on

WWW_SUB=	"INCLUDE_ORDER.txt adapter ext-all-debug-w-comments.js \
		 ext-all-debug.js ext-all.js ext.jsb2 gpl-3.0.txt index.html \
		 license.txt pkgs release-notes.html resources src test welcome"

.include <bsd.port.pre.mk>

SUB_FILES+=	pkg-message

.if !defined(WITH_DOC)
NOPORTDOCS=	YES
SUB_LIST+=	COMMENTDOCS="\# "
.else
SUB_LIST+=	COMMENTDOCS=
.endif

.if !defined(WITH_EXAMPLE)
NOPORTEXAMPLES=	YES
SUB_LIST+=	COMMENTEXAMPLES="\# "
.else
SUB_LIST+=	COMMENTEXAMPLES=
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${WWW_SUB} ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
