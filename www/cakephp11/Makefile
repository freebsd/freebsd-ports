# New ports collection makefile for:	cakephp
# Date created:        19 January 2007
# Whom:                Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cakephp
PORTVERSION=	1.1.19.6305
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://cakeforge.org/frs/download.php/591/
DISTNAME=	cake_${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A framework for developing PHP web applications

USE_BZIP2=	yes
DISTFILE_SUFFIX=/donation=complete
FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${TARGET_DISTFILE}
TARGET_DISTFILE=${DISTNAME}${EXTRACT_SUFX}

USE_APACHE=	2.0+
SLAVE_PORT_MODULES=	rewrite

CONFLICTS=	cakephp-1.[23].*
NO_BUILD=	yes
USE_PHP=	pcre session
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/cake_${DISTVERSION}

OPTIONS=	PROD "Install for production server (see: make confighelp)" Off \
		MYSQL "Check for/install MySQL support in PHP" Off \
		PGSQL "Check for/install PostgreSQL support in PHP" Off \
		SQLITE "Check for/install SQLite support in PHP" Off

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
EXTRA_PATCHES=	${FILESDIR}/development-app-config-core.php.patch
.endif

CONF=		cakephp-${PROD}${CGI_EXT}.conf
SUB_FILES+=	${CONF}

DB_DEFINED=	no

.if defined(WITH_MYSQL)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_mysql.so:${PORTSDIR}/databases/php5-pdo_mysql
DB_DEFINED=	yes
.endif

.if defined(WITH_PGSQL)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
DB_DEFINED=	yes
.endif

.if defined(WITH_SQLITE)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_sqlite.so:${PORTSDIR}/databases/php5-pdo_sqlite
DB_DEFINED=	yes
.endif

.if ${DB_DEFINED} == "yes"
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/php5-pdo \
		${DB_DEPENDS}
.endif

do-fetch:
.if !exists(${DISTDIR}/${TARGET_DISTFILE})
	${FETCH_CMD} ${FETCH_BEFORE_ARGS} -1 ${MASTER_SITES:S|$|${TARGET_DISTFILE}${DISTFILE_SUFFIX}|g}
.endif

confighelp:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "On a production server, the Apache DocumentRoot is"
	@${ECHO_MSG} "updated to point to the CakePHP webroot directory."
	@${ECHO_MSG} "In this configuration, the CakePHP application is"
	@${ECHO_MSG} "accessed at http://www.myservername.com/."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "A non-production server, CakePHP is installed at"
	@${ECHO_MSG} "the /cakephp URL, and the CakePHP application is"
	@${ECHO_MSG} "accessed at http://www.myservername.com/cakephp/."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "For more information, please see:"
	@${ECHO_MSG} "http://manual.cakephp.org/chapter/installing"
	@${ECHO_MSG} ""

do-install:
	@${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/.htaccess \
			${WRKSRC}/app \
			${WRKSRC}/cake \
			${WRKSRC}/index.php \
			${WRKSRC}/vendors ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

post-install:
	@if [ -d "${CONFDIR}" ]; then \
	  ${CP} ${WRKDIR}/${CONF} ${CONFDIR}/cakephp.conf; \
	else \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "Please check your Apache 2.x installation -" ; \
	  ${ECHO_MSG} "${CONFDIR} doesn't exist," ; \
	  ${ECHO_MSG} "so I cannot install cakephp.conf there!" ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}
.if ${CGI_EXT} == "-cgi"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Your CakePHP installation was configured to use the PHP CGI binary."
	@${ECHO_MSG}	"The PHP CGI binary is expected to be referenced by the URL:"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"	${WITH_PHP_CGI}"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"If this is incorrect, reinstall the port with the WITH_PHP_CGI knob"
	@${ECHO_MSG}	"set to the correct URL."
.endif
	@${ECHO_MSG}	"*********************************************************************"

.include <bsd.port.post.mk>
