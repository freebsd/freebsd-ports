# New ports collection makefile for:	codeigniter
# Date created:        04 January 2008
# Whom:                Greg Larkin <glarkin@sourcehosting.net>
#
# $FreeBSD$
#

PORTNAME=	codeigniter
PORTVERSION=	1.5.4
CATEGORIES=	www
MASTER_SITES=	http://codeigniter.com/download_files/
DISTNAME=	CodeIgniter_${PORTVERSION}

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	A framework for developing PHP web applications

USE_ZIP=	yes

USE_APACHE=	2.0+

NO_BUILD=	yes
USE_PHP=	session pcre
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message

OPTIONS=	PROD "Install for production server (see: make confighelp)" Off \
		MSSQL "Install MSSQL support for PHP" Off \
		MYSQL "Install MySQL support for PHP" Off \
		MYSQLI "Install MySQLi support for PHP" Off \
		OCI8 "Install OCI8 support for PHP" Off \
		ODBC "Install ODBC support for PHP" Off \
		PGSQL "Install PostgreSQL support for PHP" Off \
		SQLITE "Install SQLite support for PHP" Off

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

.if defined(WITH_OCI8)
USE_PHP+=	oci8
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

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "index.php system" ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR}' >> ${TMPPLIST}

post-install:
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
