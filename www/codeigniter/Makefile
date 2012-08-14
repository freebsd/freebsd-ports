# New ports collection makefile for:	codeigniter
# Date created:        04 January 2008
# Whom:                Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	codeigniter
PORTVERSION=	2.1.2
CATEGORIES=	www
MASTER_SITES=	http://downloads.codeigniter.com/reactor/ \
		http://www.codeigniter.org.tw/download_files/
DISTNAME=	CodeIgniter_${PORTVERSION}

MAINTAINER=	appleboy.tw@gmail.com
COMMENT=	A framework for developing PHP web applications

USE_ZIP=	yes

CONFLICTS=	codeigniter-1.[0-9]*

NO_BUILD=	yes
USE_PHP=	session pcre
WANT_PHP_WEB=	yes

CI_SYS_DIR=	system
CI_CONF_DIR=	application/config
WRKSRC=		${WRKDIR}/${DISTNAME}
WWWDIR=		${PREFIX}/www/codeigniter
PORTDOCS=	*

LATEST_LINK=	codeigniter-devel

# These are all user-configurable files that we'll install
CI_CONF_FILES=	index.php ${CI_CONF_DIR}/autoload.php \
		${CI_CONF_DIR}/config.php ${CI_CONF_DIR}/constants.php \
		${CI_CONF_DIR}/database.php \
		${CI_CONF_DIR}/doctypes.php \
		${CI_CONF_DIR}/foreign_chars.php \
		${CI_CONF_DIR}/hooks.php \
		${CI_CONF_DIR}/mimes.php \
		${CI_CONF_DIR}/migration.php \
		${CI_CONF_DIR}/profiler.php \
		${CI_CONF_DIR}/routes.php ${CI_CONF_DIR}/smileys.php \
		${CI_CONF_DIR}/user_agents.php

# This is the rest of the CodeIgniter installation that doesn't change
STD_BITS=	${CI_CONF_DIR}/index.html \
		application/cache \
		application/controllers \
		application/core \
		application/errors \
		application/helpers \
		application/hooks \
		application/index.html \
		application/language \
		application/libraries \
		application/logs \
		application/models \
		application/third_party \
		application/views \
		${CI_SYS_DIR}/core \
		${CI_SYS_DIR}/database \
		${CI_SYS_DIR}/fonts \
		${CI_SYS_DIR}/helpers \
		${CI_SYS_DIR}/language \
		${CI_SYS_DIR}/libraries

OPTIONS_DEFINE=	APACHE PROD MSSQL MYSQL MYSQLI ODBC PGSQL SQLITE

APACHE_DESC=	Configure for Apache-2.x
PROD_DESC=	Install for production server (see: make confighelp)
MSSQL_DESC=	Install MSSQL support for PHP
MYSQL_DESC=	Install MySQL support for PHP
MYSQLI_DESC=	Install MySQLi support for PHP
ODBC=	Install ODBC support for PHP
PGSQL_DESC=	Install PostgreSQL support for PHP
SQLITE_DESC=	Install SQLite support for PHP

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE=	20+

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

.if ${PORT_OPTIONS:MPROD}
PROD=		production
.else
PROD=		development
.endif

.if ${PORT_OPTIONS:MMSSQL}
USE_PHP+=	mssql
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MMYSQLI}
USE_PHP+=	mysqli
.endif

.if ${PORT_OPTIONS:MODBC}
USE_PHP+=	odbc
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	sqlite
.endif

.if ${PORT_OPTIONS:MDOCS}
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
.if ${PORT_OPTIONS:MAPACHE}
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
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/user_guide && ${COPYTREE_SHARE} . ${DOCSDIR}
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
