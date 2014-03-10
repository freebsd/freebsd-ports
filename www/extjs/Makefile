# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	extjs
PORTVERSION=	4.2.2
CATEGORIES=	www
MASTER_SITES=	http://cdn.sencha.com/ext/gpl/ \
		http://extjs.cachefly.net/ext/gpl/ \
		http://mirror.joehorn.idv.tw/extjs/
DISTNAME=	ext-${PORTVERSION}-gpl

MAINTAINER=	joehorn@gmail.com
COMMENT=	JavaScript platform for rapid development of cross-browser web apps

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/ext-${PORTVERSION}.1144

USES=		zip
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

WWW_SUB=	bootstrap.js build.xml builds cmd ext-all-debug-w-comments.js \
		ext-all-debug.js ext-all-dev.js \
		ext-all-rtl-debug-w-comments.js ext-all-rtl-debug.js \
		ext-all-rtl-dev.js ext-all-rtl.js ext-all.js \
		ext-debug-w-comments.js ext-debug.js ext-dev.js \
		ext-theme-access.js ext-theme-classic-sandbox.js \
		ext-theme-classic.js ext-theme-gray.js ext-theme-neptune.js \
		ext.js file-header.js index.html license.txt locale \
		packages plugins release-notes.html resources src \
		welcome

.include <bsd.port.options.mk>

SUB_FILES+=	pkg-message

.if ${PORT_OPTIONS:MDOCS}
SUB_LIST+=	COMMENTDOCS=
.else
SUB_LIST+=	COMMENTDOCS="\# "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
SUB_LIST+=	COMMENTEXAMPLES=
.else
SUB_LIST+=	COMMENTEXAMPLES="\# "
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${WWW_SUB}" ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
