# Created by: Greg Larkin <glarkin@FreeBSD.org>

PORTNAME=	ZendFramework
PORTVERSION=	1.12.16
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://packages.zendframework.com/releases/${DISTNAME}/
PKGNAMESUFFIX=	1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for developing PHP web applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Fails to work with current active PHP versions
EXPIRATION_DATE=	2022-01-24

USES=		gettext php:web
USE_PHP=	spl
IGNORE_WITH_PHP=	74 80 81

CONFLICTS=	ZendFramework-2.*

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	DOCS EXAMPLES MYSQL MYSQLI DBLIB PGSQL ODBC SQLITE REQPHP OPTPHP
OPTIONS_DEFAULT=REQPHP

DBLIB_DESC=	Enable DBLIB PDO support
MYSQLI_DESC=	Enable MySQLi support
MYSQL_DESC=	Enable MySQL PDO support
ODBC_DESC=	Enable ODBC PDO support
OPTPHP_DESC=	Install optional PHP dependencies
PGSQL_DESC=	Enable PostgreSQL PDO support
REQPHP_DESC=	Install required PHP dependencies
SQLITE_DESC=	Enable SQLite v3 PDO support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-manual-en${EXTRACT_SUFX}
.endif

INSTALL_DIRS=	library extras/library externals/dojo/dijit \
		externals/dojo/dojo externals/dojo/dojox \
		externals/dojo/util

# Add all of the required and/or optional PHP extension dependencies,
# if chosen by the user.
#
# See http://framework.zend.com/manual/1.12/en/requirements.introduction.html
# for a table of what PHP extensions are required for what ZF classes.

.if ${PORT_OPTIONS:MREQPHP}
USE_PHP+=	ctype curl dom gd hash iconv mbstring ldap mcrypt memcache \
		memcached opcache pcre pdo session simplexml soap sqlite3 \
		wddx xml zlib
.endif
.if ${PORT_OPTIONS:MOPTPHP}
USE_PHP+=	bcmath bitset json posix
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MMYSQLI}
USE_PHP+=	mysqli
.endif

.if ${PORT_OPTIONS:MDBLIB}
USE_PHP+=	pdo_dblib
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql
.endif

.if ${PORT_OPTIONS:MODBC}
USE_PHP+=	pdo_odbc
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	pdo_sqlite
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${INSTALL_DIRS}" ${STAGEDIR}${DATADIR}
	@${FIND} ${STAGEDIR}${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${FIND} ${STAGEDIR}${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} zf.sh ${STAGEDIR}${PREFIX}/bin/zf
	@cd ${WRKSRC}/bin && ${INSTALL_DATA} zf.php ${STAGEDIR}${PREFIX}/bin/zf.php
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "demos tests" ${STAGEDIR}${EXAMPLESDIR}
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/manual
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "INSTALL.md README.md" ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/documentation/manual/core/en && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/manual
.endif

.include <bsd.port.post.mk>
