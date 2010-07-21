# New ports collection makefile for:	codeigniter
# Date created:        04 January 2008
# Whom:                Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	codeigniter
PORTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://codeigniter.com/download_files/ \
		LOCAL/glarkin
DISTNAME=	CodeIgniter_${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A framework for developing PHP web applications

USE_ZIP=	yes

NO_BUILD=	yes
USE_PHP=	session pcre
WANT_PHP_WEB=	yes

CI_SYS_DIR=	system
CI_CONF_DIR=	${CI_SYS_DIR}/application/config

# These are all user-configurable files that we'll install
# a .sample copy for each.
CI_CONF_FILES=	index.php ${CI_CONF_DIR}/autoload.php \
		${CI_CONF_DIR}/config.php ${CI_CONF_DIR}/constants.php \
		${CI_CONF_DIR}/database.php \
		${CI_CONF_DIR}/hooks.php ${CI_CONF_DIR}/mimes.php \
		${CI_CONF_DIR}/routes.php ${CI_CONF_DIR}/smileys.php \
		${CI_CONF_DIR}/user_agents.php

# This is the rest of the CodeIgniter installation that doesn't change
STD_BITS=	${CI_CONF_DIR}/index.html \
		${CI_SYS_DIR}/application/controllers \
		${CI_SYS_DIR}/application/errors \
		${CI_SYS_DIR}/application/helpers \
		${CI_SYS_DIR}/application/hooks \
		${CI_SYS_DIR}/application/index.html \
		${CI_SYS_DIR}/application/language \
		${CI_SYS_DIR}/application/libraries \
		${CI_SYS_DIR}/application/models \
		${CI_SYS_DIR}/application/views \
		${CI_SYS_DIR}/cache \
		${CI_SYS_DIR}/codeigniter \
		${CI_SYS_DIR}/database \
		${CI_SYS_DIR}/fonts \
		${CI_SYS_DIR}/helpers \
		${CI_SYS_DIR}/language \
		${CI_SYS_DIR}/libraries \
		${CI_SYS_DIR}/logs \
		${CI_SYS_DIR}/plugins \
		${CI_SYS_DIR}/scaffolding

OPTIONS=	APACHE "Configure for Apache-2.x" off \
		PROD "Install for production server (see: make confighelp)" Off \
		MSSQL "Install MSSQL support for PHP" Off \
		MYSQL "Install MySQL support for PHP" Off \
		MYSQLI "Install MySQLi support for PHP" Off \
		ODBC "Install ODBC support for PHP" Off \
		PGSQL "Install PostgreSQL support for PHP" Off \
		SQLITE "Install SQLite support for PHP" Off

.include <bsd.port.pre.mk>

.if defined(WITH_APACHE)
USE_APACHE=	2.0+

PLIST_SUB+=	NOAPACHE="" CONFDIR=${CONFDIR_REL}
CONFDIR=	${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=	${APACHEETCDIR}/Includes

PKGMESSAGE=	pkg-message-apache
SUB_FILES=	pkg-message-apache
.else
PLIST_SUB+=	NOAPACHE="@comment "
PKGMESSAGE=	pkg-message-noapache
SUB_FILES=	pkg-message-noapache
.endif
PLIST_SUB+=	ECHO_MSG=${ECHO_MSG} CI_CONF_DIR=${CI_CONF_DIR}

WITH_PHP_CGI?=	/cgi-bin/php

.if ${PHP_SAPI:Mcgi} == "cgi" && ${PHP_SAPI:Mmod} == ""
CGI_EXT=	-cgi
.else
CGI_EXT=
.endif

DEFAULT_PHP_VER=5

SUB_LIST+=	PHPCGI=${WITH_PHP_CGI}

.if defined(WITH_PROD)
PROD=		production
.else
PROD=		development
.endif

.if defined(WITH_MSSQL)
USE_PHP+=	mssql
.endif

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_MYSQLI)
USE_PHP+=	mysqli
.endif

.if defined(WITH_ODBC)
USE_PHP+=	odbc
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_SQLITE)
USE_PHP+=	sqlite
.endif

.if defined(NOPORTDOCS)
SUB_LIST+=	HASHMARK=\#
.else
SUB_LIST+=	HASHMARK=
.endif

CONF=		codeigniter-${PROD}${CGI_EXT}.conf
SUB_FILES+=	${CONF}

confighelp:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "On a production server, the Apache DocumentRoot is"
	@${ECHO_MSG} "updated to point to the CodeIgniter webroot directory."
	@${ECHO_MSG} "In this configuration, the CodeIgniter application is"
	@${ECHO_MSG} "accessed at http://www.myservername.com/."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "A non-production server, CodeIgniter is installed at"
	@${ECHO_MSG} "the /codeigniter URL, and the CodeIgniter application is"
	@${ECHO_MSG} "accessed at http://www.myservername.com/codeigniter/."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "For more information, please see:"
	@${ECHO_MSG} "http://codeigniter.com/user_guide/installation/index.html"
	@${ECHO_MSG} ""

post-patch:
	@cd ${WRKSRC} && ${RM} system/libraries/Upload.php.orig

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${STD_BITS}" ${WWWDIR}
	@for i in ${CI_CONF_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${WWWDIR}/$$i.sample; \
	done
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
	@for i in ${CI_CONF_FILES}; do \
		if [ ! -f ${WWWDIR}/$$i ]; then \
			${CP} -p ${WWWDIR}/$$i.sample ${WWWDIR}/$$i; \
		else \
			${ECHO_MSG} "===> Customized ${WWWDIR}/$$i has not been overwritten"; \
			if [ ! -z "$UPGRADE_TOOL" ]; then \
				${ECHO_MSG} "===> WARNING: You may have to manually merge changes to ${WWWDIR}/$$i.sample into ${WWWDIR}/$$i"; \
			fi; \
		fi; \
	done
.if defined(WITH_APACHE)
	@if [ -d "${CONFDIR}" ]; then \
	  ${CP} ${WRKDIR}/${CONF} ${CONFDIR}/codeigniter.conf; \
	else \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "Please check your Apache 2.x installation -" ; \
	  ${ECHO_MSG} "${CONFDIR} doesn't exist," ; \
	  ${ECHO_MSG} "so I cannot install codeigniter.conf there!" ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi
.endif
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/user_guide/ && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.if ${CGI_EXT} == "-cgi"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Your CodeIgniter installation was configured to use the PHP CGI binary."
	@${ECHO_MSG}	"The PHP CGI binary is expected to be referenced by the URL:"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"	${WITH_PHP_CGI}"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"If this is incorrect, reinstall the port with the WITH_PHP_CGI knob"
	@${ECHO_MSG}	"set to the correct URL."
.endif
	@${ECHO_MSG}	"*********************************************************************"

.include <bsd.port.post.mk>
