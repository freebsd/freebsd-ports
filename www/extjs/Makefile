# New ports collection makefile for:	extjs
# Date created:		2010-01-28
# Whom:			Joe Horn <joehorn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	extjs
PORTVERSION=	4.1.1
CATEGORIES=	www
MASTER_SITES=	http://cdn.sencha.io/ \
		http://extjs.cachefly.net/ \
		http://mirror.joehorn.idv.tw/extjs/
DISTNAME=	ext-${PORTVERSION}-gpl

MAINTAINER=	joehorn@gmail.com
COMMENT=	A JavaScript platform for rapid development of cross-browser web apps

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

WRKSRC=		${WRKDIR}/extjs-${PORTVERSION}

USE_ZIP=	yes
NO_BUILD=	yes

OPTIONS=	DOC	"Install with documents" on \
		EXAMPLE "Install with examples" on

WWW_SUB=	"bootstrap.js build builds ext-all-debug-w-comments.js \
		 ext-all-debug.js ext-all-dev.js ext-all.js \
		 ext-debug-w-comments.js ext-debug.js ext-dev.js \
		 ext-neptune-debug-w-comments.js ext-neptune-debug.js \
		 ext-neptune.js	ext.js index.html license.txt locale \
		 pkgs release-notes.html resources src welcome"

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
	@cd ${WRKSRC} && ${RM} -rf resources/sass/.sass-cache/*
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
