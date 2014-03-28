# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cakephp
PORTVERSION=	1.1.19.6305
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMESUFFIX=	11
DISTNAME=	cake_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for developing PHP web applications

USES=		tar:bzip2
USE_APACHE_RUN=	22+
SLAVE_PORT_MODULES=	REWRITE

CONFLICTS=	cakephp-1[23]-* cakephp-2?-.* cakephp-2.3.*
NO_BUILD=	yes

USE_PHP=	pcre session
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/cake_${DISTVERSION}

OPTIONS_DEFINE=	PROD MYSQL PGSQL SQLITE DOCS
PROD_DESC=	Install for production server (see: make confighelp)

PLIST_SUB+=	CONFDIR=${CONFDIR_REL}

CONFDIR=	${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=	${APACHEETCDIR}/Includes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

WITH_PHP_CGI?=	/cgi-bin/php

.if ${PHP_SAPI:Mcgi} == "cgi" && ${PHP_SAPI:Mmod} == ""
CGI_EXT=	-cgi
.else
CGI_EXT=
.endif

SUB_LIST+=	PHPCGI=${WITH_PHP_CGI}

.if ${PORT_OPTIONS:MPROD}
PROD=		production
.else
PROD=		development
EXTRA_PATCHES=	${FILESDIR}/development-app-config-core.php.patch
.endif

CONF=		cakephp-${PROD}${CGI_EXT}.conf
SUB_FILES+=	${CONF}

DB_DEFINED=	no

.if ${PORT_OPTIONS:MMYSQL}
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_mysql.so:${PORTSDIR}/databases/php5-pdo_mysql
DB_DEFINED=	yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
DB_DEFINED=	yes
.endif

.if ${PORT_OPTIONS:MSQLITE}
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_sqlite.so:${PORTSDIR}/databases/php5-pdo_sqlite
DB_DEFINED=	yes
.endif

.if ${DB_DEFINED} == "yes"
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/php5-pdo \
		${DB_DEPENDS}
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
	@${CP} -R ${WRKSRC}/.htaccess \
			${WRKSRC}/app \
			${WRKSRC}/cake \
			${WRKSRC}/index.php \
			${WRKSRC}/vendors ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

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
.if ${PORT_OPTIONS:MDOCS}
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
