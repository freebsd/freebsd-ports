# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	codeigniter
PORTVERSION=	3.1.11
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for developing PHP web applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		php:web
USE_PHP=	mcrypt pcre session

USE_GITHUB=	yes
GH_ACCOUNT=	bcit-ci
GH_PROJECT=	CodeIgniter

CONFLICTS=	codeigniter-1.[0-9]* codeigniter22-2.[0-9]*

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

# These are all user-configurable files that we'll install
CI_CONF_FILES=	application/config/autoload.php \
		application/config/config.php \
		application/config/constants.php \
		application/config/database.php \
		application/config/doctypes.php \
		application/config/foreign_chars.php \
		application/config/hooks.php \
		application/config/memcached.php \
		application/config/migration.php \
		application/config/mimes.php \
		application/config/profiler.php \
		application/config/routes.php \
		application/config/smileys.php \
		application/config/user_agents.php \
		index.php

OPTIONS_DEFINE=	APACHE DOCS MSSQL MYSQLI ODBC PGSQL SQLITE
OPTIONS_SUB=	yes

SUB_FILES=	pkg-message

APACHE_DESC=	Configure for Apache-2.x
MSSQL_DESC=	Install MSSQL support for PHP
MYSQLI_DESC=	Install MySQLi support for PHP
ODBC_DESC=	Install ODBC support for PHP
PGSQL_DESC=	Install PostgreSQL support for PHP
SQLITE_DESC=	Install SQLite support for PHP

APACHE_SUB_FILES=	codeigniter.conf
APACHE_USES=	apache:run
DOCS_VARS=	SUB_LIST+=HASHMARK=
DOCS_VARS_OFF=	SUB_LIST+=HASHMARK=\#
MSSQL_USE=	PHP=mssql
MYSQLI_USE=	PHP=mysqli
ODBC_USE=	PHP=odbc
PGSQL_USE=	PHP=pgsql
SQLITE_USE=	PHP=sqlite3

post-patch:
	@${RM} ${WRKSRC}/user_guide/.buildinfo
	@${MV} ${WRKSRC}/readme.rst ${WRKSRC}/user_guide/readme.rst

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "application index.php system" ${STAGEDIR}${WWWDIR}
.for ci_conf_file in ${CI_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/${ci_conf_file} ${STAGEDIR}${WWWDIR}/${ci_conf_file}.sample
.endfor

do-install-APACHE-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes
	${INSTALL_DATA} ${WRKDIR}/codeigniter.conf ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes/codeigniter.conf

do-install-DOCS-on:
	cd ${WRKSRC}/user_guide && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
