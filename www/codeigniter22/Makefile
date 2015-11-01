# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	codeigniter
PORTVERSION=	2.2.6
CATEGORIES=	www
PKGNAMESUFFIX=	22

MAINTAINER=	junovitch@FreeBSD.org
COMMENT=	Framework for developing PHP web applications

DEPRECATED=	Codeigniter 2.2.x reached its End of Life on 31 October 2015. Please update to the current version.
EXPIRATION_DATE=	2016-01-31

USES=		tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	bcit-ci

CONFLICTS=	codeigniter-[0-9]*

NO_ARCH=	yes
NO_BUILD=	yes
USE_PHP=	mcrypt pcre session
WANT_PHP_WEB=	yes
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

CI_SYS_DIR=	system
CI_CONF_DIR=	application/config
WRKSRC=		${WRKDIR}/CodeIgniter-${PORTVERSION}
PORTDOCS=	*

# These are all user-configurable files that we'll install
CI_CONF_FILES=	index.php \
		${CI_CONF_DIR}/autoload.php \
		${CI_CONF_DIR}/config.php \
		${CI_CONF_DIR}/constants.php \
		${CI_CONF_DIR}/database.php \
		${CI_CONF_DIR}/doctypes.php \
		${CI_CONF_DIR}/foreign_chars.php \
		${CI_CONF_DIR}/hooks.php \
		${CI_CONF_DIR}/mimes.php \
		${CI_CONF_DIR}/migration.php \
		${CI_CONF_DIR}/profiler.php \
		${CI_CONF_DIR}/routes.php \
		${CI_CONF_DIR}/smileys.php \
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

OPTIONS_DEFINE=	APACHE DOCS MSSQL MYSQL MYSQLI ODBC PGSQL SQLITE
OPTIONS_SUB=	yes

SUB_FILES=	pkg-message
PLIST_SUB+=	ECHO_MSG=${ECHO_MSG} CI_CONF_DIR=${CI_CONF_DIR}

APACHE_DESC=	Configure for Apache-2.x
MSSQL_DESC=	Install MSSQL support for PHP
MYSQL_DESC=	Install MySQL support for PHP
MYSQLI_DESC=	Install MySQLi support for PHP
ODBC_DESC=	Install ODBC support for PHP
PGSQL_DESC=	Install PostgreSQL support for PHP
SQLITE_DESC=	Install SQLite support for PHP

APACHE_VARS=	USE_APACHE_RUN=22+
DOCS_VARS=	SUB_LIST+=HASHMARK=
DOCS_VARS_OFF=	SUB_LIST+=HASHMARK=\#
MSSQL_VARS=	USE_PHP+=mssql
MYSQL_VARS=	USE_PHP+=mysql
MYSQLI_VARS=	USE_PHP+=mysqli
ODBC_VARS=	USE_PHP+=odbc
PGSQL_VARS=	USE_PHP+=pgsql
SQLITE_VARS=	USE_PHP+=sqlite3

# These variables are specifically defined for Apache
CONF=		codeigniter.conf
CONFDIR=	${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=	${APACHEETCDIR}/Includes
PLIST_SUB+=	CONFDIR=${CONFDIR_REL}
SUB_FILES+=	${CONF}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${STD_BITS}" ${STAGEDIR}${WWWDIR}
	for i in ${CI_CONF_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${STAGEDIR}${WWWDIR}/$$i.sample; \
	done

post-install-APACHE-on:
	${MKDIR} ${STAGEDIR}${CONFDIR}
	${CP} ${WRKDIR}/${CONF} ${STAGEDIR}${CONFDIR}/codeigniter.conf;
post-install-DOCS-on:
	cd ${WRKSRC}/user_guide && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
