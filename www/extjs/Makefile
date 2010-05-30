# New ports collection makefile for:	extjs
# Date created:		2010-01-28
# Whom:			Joe Horn <joehorn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	extjs
PORTVERSION=	3.2.1
CATEGORIES=	www
MASTER_SITES=	http://www.extjs.com/deploy/
DISTNAME=	ext-${PORTVERSION}

MAINTAINER=	joehorn@gmail.com
COMMENT=	A JavaScript platform for rapid development of cross-browser web apps

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_ZIP=	yes
NO_BUILD=	yes

OPTIONS=	DOC	"Install with documents" on \
		EXAMPLE "Install with examples" on

WWW_SUB=	"INCLUDE_ORDER.txt adapter ext-all-debug-w-comments.js \
		 ext-all-debug.js ext-all.js ext.jsb2 gpl-3.0.txt index.html \
		 license.txt pkgs resources src test welcome"

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
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
