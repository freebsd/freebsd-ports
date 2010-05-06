# New ports collection makefile for:	yahoo-ui
# Date created:		2008-01-29
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yahoo
PORTVERSION=	2.8.1
CATEGORIES=	www
MASTER_SITES=	http://yuilibrary.com/downloads/yui2/
PKGNAMESUFFIX=	-ui
DISTNAME=	yui_${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	The Yahoo! User Interface (YUI) Library

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/yui
NO_BUILD=	yes

OPTIONS=	APACHE	"Configure for Apache-2.x" off \
		MINIMAL "Do not install documentation and examples" off

.include <bsd.port.pre.mk>

.if defined(WITH_MINIMAL)
NOPORTDOCS=	yes
NOPORTEXAMPLES=	yes
.endif

.if defined(WITH_APACHE)
USE_APACHE=	2.0+
CONFDIR=	${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=	${APACHEETCDIR}/Includes
PLIST_SUB+=	NOAPACHE="" CONFDIR=${CONFDIR_REL}

CONF=		yui.conf
SUB_FILES+=	pkg-message ${CONF}

.if defined(NOPORTDOCS)
SUB_LIST+=	HASHMARK1=\#
.else
SUB_LIST+=	HASHMARK1=
.endif

.if defined(NOPORTEXAMPLES)
SUB_LIST+=	HASHMARK2=\#
.else
SUB_LIST+=	HASHMARK2=
.endif
.else
PLIST_SUB+=	NOAPACHE="@comment "
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "assets build index.html \
		tests" ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

post-install:
.if defined(WITH_APACHE)
.if !defined(MAINTAINER_MODE)
	@if [ -d "${CONFDIR}" ]; then \
	  ${CP} ${WRKDIR}/${CONF} ${CONFDIR}; \
	else \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "Please check your Apache 2.x installation -" ; \
	  ${ECHO_MSG} "${CONFDIR} doesn't exist," ; \
	  ${ECHO_MSG} "so I cannot install ${CONF} there!" ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi
.endif
	@${CAT} ${PKGMESSAGE}
.endif
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
