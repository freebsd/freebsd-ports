# $FreeBSD$

PORTNAME=		dojo
PORTVERSION=		1.8.3
CATEGORIES=		www
MASTER_SITES=		http://download.dojotoolkit.org/release-${PORTVERSION}/
DISTNAME=		dojo-release-${PORTVERSION}

MAINTAINER=		glarkin@FreeBSD.org
COMMENT=		Open-source DHTML toolkit written in JavaScript

NO_BUILD=		yes

OPTIONS_DEFINE=		APACHE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=		22+
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

.include <bsd.port.mk>
