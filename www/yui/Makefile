# New ports collection makefile for:	yui
# Date created:		2008-01-29
# Whom:			Greg Larkin <glarkin@sourcehosting.net>
#
# $FreeBSD$
#

PORTNAME=	yui
PORTVERSION=	2.4.1
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	The Yahoo! User Interface (YUI) Library

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

.if defined(WITH_APACHE)
USE_APACHE=	2.0+
CONFDIR=	${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=	${APACHEETCDIR}/Includes
PLIST_SUB+=	NOAPACHE="" CONFDIR=${CONFDIR_REL}

CONF=		yui.conf
SUB_FILES+=	pkg-message ${CONF}
.else
PLIST_SUB+=	NOAPACHE="@comment "
.endif

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "assets build index.html \
		tests" ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

post-install:
.if defined(WITH_APACHE)
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
	@${CAT} ${PKGMESSAGE}
.endif
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
	@${CP} ${WRKSRC}/README ${DOCSDIR}
.endif
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}

.include <bsd.port.post.mk>
