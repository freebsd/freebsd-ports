# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	drupal7
PORTVERSION=	7.19
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTNAME=	drupal-${PORTVERSION}
DIST_SUBDIR=	drupal

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Database driven web content management system (CMS)

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_DRUPAL=	yes
DRUPAL_PORT=	yes
DRUPAL_VERSION=	7

USE_PHP=	dom filter gd hash json mbstring pcre pdo session simplexml xml
WANT_PHP_WEB=	yes

OPTIONS+=	MYSQL "MySQL database support" on \
		SQLITE3 "SQLite 3.x database support" off \
		PGSQL "PostgreSQL database support" off

NO_BUILD=	yes
DOCS=		CHANGELOG.txt INSTALL.mysql.txt INSTALL.sqlite.txt \
		LICENSE.txt README.txt COPYRIGHT.txt INSTALL.pgsql.txt \
		INSTALL.txt MAINTAINERS.txt UPGRADE.txt

SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_SQLITE3)
USE_PHP+=	pdo_sqlite
.endif
.if defined(WITH_MYSQL)
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	41
USE_PHP+=	pdo_mysql
.endif
.if defined(WITH_PGSQL)
USE_PGSQL=	yes
USE_PHP+=	pdo_pgsql
.endif

do-install:
	${MKDIR} ${DRUPAL_DIR}
	${CP} ${WRKSRC}/.htaccess ${DRUPAL_DIR}
	${CP} ${WRKSRC}/cron.php ${DRUPAL_DIR}
	${CP} ${WRKSRC}/authorize.php ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/includes ${DRUPAL_DIR}
	${CP} ${WRKSRC}/index.php ${DRUPAL_DIR}
	${CP} ${WRKSRC}/install.php ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/misc ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/modules ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/profiles ${DRUPAL_DIR}
	${CP} ${WRKSRC}/robots.txt ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/scripts ${DRUPAL_DIR}
	${MKDIR} ${DRUPAL_DIR}/sites/all
	${MKDIR} ${DRUPAL_DIR}/sites/all/libraries
	${CP} ${WRKSRC}/sites/example.sites.php ${DRUPAL_DIR}/sites/
	${CP} -R ${WRKSRC}/sites/all ${DRUPAL_DIR}/sites/
	${MKDIR} ${DRUPAL_DIR}/sites/default
	${MKDIR} ${DRUPAL_DIR}/sites/default/files
	${CP} ${WRKSRC}/sites/default/default.settings.php ${DRUPAL_DIR}/sites/default/default.settings.php-dist
	@if [ ! -f ${DRUPAL_DIR}/sites/default/default.settings.php ]; then \
		${CP} -p ${DRUPAL_DIR}/sites/default/default.settings.php-dist ${DRUPAL_DIR}/sites/default/default.settings.php ; \
	fi
	${CP} -R ${WRKSRC}/themes ${DRUPAL_DIR}
	${CP} ${WRKSRC}/update.php ${DRUPAL_DIR}
	${CP} ${WRKSRC}/web.config ${DRUPAL_DIR}
	${CP} ${WRKSRC}/xmlrpc.php ${DRUPAL_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DRUPAL_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
