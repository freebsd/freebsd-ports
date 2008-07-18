# New ports collection makefile for:	prado
# Date created:        04 January 2008
# Whom:                Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	prado
PORTVERSION=	3.1.2.r2448
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A framework for developing PHP web applications

USE_ZIP=	yes

USE_APACHE=	2.0+

NO_BUILD=	yes
USE_PHP=	session
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message

OPTIONS=	PROD "Install for production server (see: make confighelp)" Off \
		REQPHP "Install required PHP dependencies" On \
		OPTPHP "Install optional PHP dependencies" Off

PLIST_SUB+=	CONFDIR=${CONFDIR_REL}

CONFDIR=	${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=	${APACHEETCDIR}/Includes

.include <bsd.port.pre.mk>

WITH_PHP_CGI?=	/cgi-bin/php

.if ${PHP_SAPI:Mcgi} == "cgi" && ${PHP_SAPI:Mmod} == ""
CGI_EXT=	-cgi
.else
CGI_EXT=
.endif

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

SUB_LIST+=	PHPCGI=${WITH_PHP_CGI}

.if defined(WITH_PROD)
PROD=		production
.else
PROD=		development
.endif

.if defined(NOPORTDOCS)
SUB_LIST+=	HASHMARK=\#
.else
SUB_LIST+=	HASHMARK=
.endif

CONF=		prado-${PROD}${CGI_EXT}.conf
SUB_FILES+=	${CONF}

.if defined(WITH_REQPHP)
USE_PHP+=	dom spl ctype pcre
.endif

.if defined(WITH_OPTPHP)
USE_PHP+=	pdo iconv zlib sqlite memcache mcrypt xsl soap
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/apc.so:${PORTSDIR}/www/pecl-APC
.endif

confighelp:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "On a production server, the Apache DocumentRoot is"
	@${ECHO_MSG} "updated to point to the Prado webroot directory."
	@${ECHO_MSG} "In this configuration, the Prado application is"
	@${ECHO_MSG} "accessed at http://www.myservername.com/."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "A non-production server, Prado is installed at"
	@${ECHO_MSG} "the /prado URL, and the Prado application is"
	@${ECHO_MSG} "accessed at http://www.myservername.com/prado/."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "For more information, please see:"
	@${ECHO_MSG} "http://www.pradosoft.com/wiki/index.php/Installation"
	@${ECHO_MSG} ""

post-configure:
	@cd ${WRKSRC} && ${MV} "HISTORY" "UPGRADE" docs/

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "index.html demos editors \
		framework requirements tests" ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

post-install:
	@if [ -d "${CONFDIR}" ]; then \
	  ${CP} ${WRKDIR}/${CONF} ${CONFDIR}/prado.conf; \
	else \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "Please check your Apache 2.x installation -" ; \
	  ${ECHO_MSG} "${CONFDIR} doesn't exist," ; \
	  ${ECHO_MSG} "so I cannot install prado.conf there!" ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}
.if ${CGI_EXT} == "-cgi"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Your Prado installation was configured to use the PHP CGI binary."
	@${ECHO_MSG}	"The PHP CGI binary is expected to be referenced by the URL:"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"	${WITH_PHP_CGI}"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"If this is incorrect, reinstall the port with the WITH_PHP_CGI knob"
	@${ECHO_MSG}	"set to the correct URL."
.endif
	@${ECHO_MSG}	"*********************************************************************"

.include <bsd.port.post.mk>
