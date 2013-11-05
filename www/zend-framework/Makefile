# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ZendFramework
PORTVERSION=	2.2.5
CATEGORIES=	www
MASTER_SITES=	https://packages.zendframework.com/releases/${DISTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Framework for developing PHP web applications

LICENSE=	BSD

CONFLICTS=	ZendFramework-1.*

NO_BUILD=	yes
USE_PHP=	spl
WANT_PHP_WEB=	yes
USES=		gettext

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS MYSQL MYSQLI DBLIB PGSQL ODBC SQLITE REQPHP OPTPHP
OPTIONS_DEFAULT=REQPHP

MYSQL_DESC=	Enable MySQL PDO support
MYSQLI_DESC=	Enable MySQLi support
DBLIB_DESC=	Enable DBLIB PDO support
PGSQL_DESC=	Enable PostgreSQL PDO support
ODBC_DESC=	Enable ODBC PDO support
SQLITE_DESC=	Enable SQLite v3 PDO support
REQPHP_DESC=	Install required PHP dependencies
OPTPHP_DESC=	Install optional PHP dependencies

PORTDOCS=	CHANGELOG.md INSTALL.md README-GIT.md CONTRIBUTING.md README.md

.include <bsd.port.pre.mk>

# Add all of the required and/or optional PHP extension dependencies,
# if chosen by the user.
.if ${PORT_OPTIONS:MREQPHP}
USE_PHP+=	apc ctype curl dom gd hash iconv mbstring ldap mcrypt \
		pcre pdo session simplexml soap wddx xml zlib
.if ${PHP_VER} == 52
USE_PHP+=	sqlite
.else
USE_PHP+=	sqlite3
.endif
RUN_DEPENDS+=	pecl-memcache>=0:${PORTSDIR}/databases/pecl-memcache \
		pecl-memcached>=0:${PORTSDIR}/databases/pecl-memcached
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
	cd ${WRKSRC} && ${COPYTREE_SHARE} "library bin resources" ${STAGEDIR}${DATADIR}

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
