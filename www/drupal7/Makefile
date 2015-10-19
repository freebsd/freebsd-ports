# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	drupal7
PORTVERSION=	7.40
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTNAME=	drupal-${PORTVERSION}
DIST_SUBDIR=	drupal

MAINTAINER=	simon.wright@gmx.net
COMMENT=	Database driven web content management system (CMS)

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		drupal:7 shebangfix
SHEBANG_FILES=	scripts/password-hash.sh

USE_PHP=	dom filter gd hash json mbstring pcre pdo session simplexml xml
WANT_PHP_WEB=	yes

OPTIONS_DEFINE=		MYSQL SQLITE3 PGSQL DOCS
OPTIONS_DEFAULT=	MYSQL

NO_BUILD=	yes
DOCS=		CHANGELOG.txt INSTALL.mysql.txt INSTALL.sqlite.txt \
		LICENSE.txt README.txt COPYRIGHT.txt INSTALL.pgsql.txt \
		INSTALL.txt MAINTAINERS.txt UPGRADE.txt

SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PGSQL_USES=	pgsql
PGSQL_USE=	PHP=pdo_pgsql

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE3}
USE_PHP+=	pdo_sqlite
.endif
.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
USE_PHP+=	pdo_mysql
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/.htaccess ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/cron.php ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/authorize.php ${STAGEDIR}${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/includes ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/index.php ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/install.php ${STAGEDIR}${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/misc ${STAGEDIR}${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/modules ${STAGEDIR}${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/profiles ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/robots.txt ${STAGEDIR}${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/scripts ${STAGEDIR}${DRUPAL_DIR}
	${MKDIR} ${STAGEDIR}${DRUPAL_DIR}/sites/all
	${MKDIR} ${STAGEDIR}${DRUPAL_DIR}/sites/all/libraries
	${CP} ${WRKSRC}/sites/example.sites.php ${STAGEDIR}${DRUPAL_DIR}/sites/
	${CP} -R ${WRKSRC}/sites/all ${STAGEDIR}${DRUPAL_DIR}/sites/
	${MKDIR} ${STAGEDIR}${DRUPAL_DIR}/sites/default
	${MKDIR} ${STAGEDIR}${DRUPAL_DIR}/sites/default/files
	${CP} ${WRKSRC}/sites/default/default.settings.php ${STAGEDIR}${DRUPAL_DIR}/sites/default/default.settings.php.sample
	${CP} -R ${WRKSRC}/themes ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/update.php ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/web.config ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/xmlrpc.php ${STAGEDIR}${DRUPAL_DIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
