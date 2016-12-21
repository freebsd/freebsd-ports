# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	drupal7
PORTVERSION=	7.53
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTNAME=	drupal-${PORTVERSION}
DIST_SUBDIR=	drupal

MAINTAINER=	joneum@bsdproject.de
COMMENT=	Database driven web content management system (CMS)

LICENSE=	GPLv2+

USES=		drupal:7 php:web shebangfix
USE_PHP=	dom filter gd hash json mbstring pcre pdo session simplexml xml
SHEBANG_FILES=	scripts/password-hash.sh

NO_ARCH=	yes
NO_BUILD=	yes
DOCS=		CHANGELOG.txt INSTALL.mysql.txt INSTALL.sqlite.txt \
		LICENSE.txt README.txt COPYRIGHT.txt INSTALL.pgsql.txt \
		INSTALL.txt MAINTAINERS.txt UPGRADE.txt

OPTIONS_DEFINE=		MYSQL SQLITE3 PGSQL DOCS
OPTIONS_DEFAULT=	MYSQL

SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PGSQL_USES=	pgsql
PGSQL_USE=	PHP=pdo_pgsql
SQLITE3_USE=	PHP=pdo_sqlite
MYSQL_USES=	mysql
MYSQL_USE=	PHP=pdo_mysql

do-install:
	@${MKDIR} ${STAGEDIR}${DRUPAL_DIR}/sites/default/files
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ".htaccess cron.php authorize.php \
		includes index.php install.php misc modules profiles \
		robots.txt scripts themes update.php web.config xmlrpc.php" \
		${STAGEDIR}${DRUPAL_DIR})
	(cd ${WRKSRC}/sites && ${COPYTREE_SHARE} "example.sites.php all" \
		${STAGEDIR}${DRUPAL_DIR}/sites)
	${INSTALL_DATA} ${WRKSRC}/sites/default/default.settings.php \
		${STAGEDIR}${DRUPAL_DIR}/sites/default/default.settings.php.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
