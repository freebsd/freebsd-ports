# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	extjs
PORTVERSION=	4.2.2
CATEGORIES=	www
MASTER_SITES=	http://cdn.sencha.com/ext/gpl/ \
		http://extjs.cachefly.net/ext/gpl/ \
		http://mirror.joehorn.idv.tw/extjs/
DISTNAME=	ext-${PORTVERSION}-gpl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JavaScript platform for rapid development of cross-browser web apps

EXPIRATION_DATE=	2018-03-07
DEPRECATED=	Unmaintained, all www files wrongly belongs to www user.

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/ext-${PORTVERSION}.1144

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

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

SUB_FILES=	pkg-message

DOCS_SUB_LIST=		COMMENTDOCS=
DOCS_SUB_LIST_OFF=	COMMENTDOCS="\# "
EXAMPLES_SUB_LIST=	COMMENTEXAMPLES=
EXAMPLES_SUB_LIST_OFF=	COMMENTEXAMPLES="\# "

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${WWW_SUB}" ${STAGEDIR}${WWWDIR}

do-install-DOCS-on:
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
