# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	codeigniter
PORTVERSION=	2.2.5
CATEGORIES=	www

MAINTAINER=	appleboy.tw@gmail.com
COMMENT=	Framework for developing PHP web applications

USES=		tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	bcit-ci

CONFLICTS=	codeigniter-1.[0-9]*

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

OPTIONS_DEFINE=	APACHE DOCS MSSQL MYSQL MYSQLI ODBC PGSQL SQLITE

APACHE_DESC=	Configure for Apache-2.x
MSSQL_DESC=	Install MSSQL support for PHP
MYSQL_DESC=	Install MySQL support for PHP
MYSQLI_DESC=	Install MySQLi support for PHP
ODBC_DESC=	Install ODBC support for PHP
PGSQL_DESC=	Install PostgreSQL support for PHP
SQLITE_DESC=	Install SQLite support for PHP

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-message
.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
PLIST_SUB+=	NOAPACHE="" CONFDIR=${CONFDIR_REL}
CONFDIR=	${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=	${APACHEETCDIR}/Includes
.else
PLIST_SUB+=	NOAPACHE="@comment "
.endif
PLIST_SUB+=	ECHO_MSG=${ECHO_MSG} CI_CONF_DIR=${CI_CONF_DIR}

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
USE_PHP+=	sqlite3
.endif

.if ${PORT_OPTIONS:MDOCS}
SUB_LIST+=	HASHMARK=\#
.else
SUB_LIST+=	HASHMARK=
.endif

CONF=		codeigniter.conf
SUB_FILES+=	${CONF}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${STD_BITS}" ${STAGEDIR}${WWWDIR}
	@for i in ${CI_CONF_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${STAGEDIR}${WWWDIR}/$$i.sample; \
	done

post-install:
.if ${PORT_OPTIONS:MAPACHE}
	  ${CP} ${WRKDIR}/${CONF} ${STAGEDIR}${CONFDIR}/codeigniter.conf;
.endif
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/user_guide && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
