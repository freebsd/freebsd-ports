# New ports collection makefile for:	dojo
# Date created:		2008-01-29
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		dojo
PORTVERSION=		1.3.1
CATEGORIES=		www
MASTER_SITES=		http://download.dojotoolkit.org/release-${PORTVERSION}/ \
			LOCAL/glarkin
DISTNAME=		dojo-release-${PORTVERSION}

MAINTAINER=		glarkin@FreeBSD.org
COMMENT=		An open-source DHTML toolkit written in JavaScript

NO_BUILD=		yes

OPTIONS=		APACHE  "Configure for Apache-2.x" off

.include <bsd.port.pre.mk>

.if defined(WITH_APACHE)
USE_APACHE=		2.0+
CONFDIR=		${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=		${APACHEETCDIR}/Includes
PLIST_SUB+=		NOAPACHE="" CONFDIR=${CONFDIR_REL}

CONF=			dojo.conf
SUB_FILES+=		pkg-message ${CONF}
.else
PLIST_SUB+=		NOAPACHE="@comment "
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

.if defined(WITH_APACHE)
post-install:
	@if [ -d "${CONFDIR}" ]; then \
	  ${CP} ${WRKDIR}/${CONF} ${CONFDIR}/dojo.conf; \
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

.include <bsd.port.post.mk>
