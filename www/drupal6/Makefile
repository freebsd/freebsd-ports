# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	drupal6
PORTVERSION=	6.38
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTNAME=	drupal-${PORTVERSION}
DIST_SUBDIR=	drupal

MAINTAINER=	simon.wright@gmx.net
COMMENT=	Database driven web content management system (CMS)

BROKEN_powerpc64=	Does not build

DEPRECATED=	EOL upstream as of 2016-02-24
EXPIRATION_DATE=	2016-04-24

USES=		drupal:6 shebangfix
SHEBANG_FILES=	scripts/drupal.sh

USE_PHP=	gd pcre session xml mbstring
WANT_PHP_WEB=	yes

OPTIONS_DEFINE=	MYSQLI MYSQL PGSQL DOCS
OPTIONS_DEFAULT=MYSQLI

MYSQLI_DESC=	MySQL Improved Extension database

NO_BUILD=	yes
DOCS=		CHANGELOG.txt INSTALL.txt LICENSE.txt MAINTAINERS.txt \
		UPGRADE.txt INSTALL.mysql.txt INSTALL.pgsql.txt \
		COPYRIGHT.txt
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif
.if ${PORT_OPTIONS:MMYSQLI}
USE_PHP+=	mysqli
.endif
.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/DB.php:databases/pear-DB
USE_PHP+=	pgsql
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/.htaccess ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/cron.php ${STAGEDIR}${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/includes ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/index.php ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/install.php ${STAGEDIR}${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/misc ${STAGEDIR}${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/modules ${STAGEDIR}${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/profiles ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/robots.txt ${STAGEDIR}${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/scripts ${STAGEDIR}${DRUPAL_DIR}
	${MKDIR} ${STAGEDIR}${DRUPAL_DIR}/sites/all
	${CP} ${WRKSRC}/sites/all/README.txt ${STAGEDIR}${DRUPAL_DIR}/sites/all/
	${MKDIR} ${STAGEDIR}${DRUPAL_DIR}/sites/default
	${CP} ${WRKSRC}/sites/default/default.settings.php ${STAGEDIR}${DRUPAL_DIR}/sites/default/default.settings.php.sample
	${CP} -R ${WRKSRC}/themes ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/update.php ${STAGEDIR}${DRUPAL_DIR}
	${CP} ${WRKSRC}/xmlrpc.php ${STAGEDIR}${DRUPAL_DIR}
	${MKDIR} ${STAGEDIR}${DRUPAL_DIR}/sites/all/modules ${STAGEDIR}${DRUPAL_DIR}/sites/all/themes
	${TOUCH} ${STAGEDIR}${DRUPAL_DIR}/sites/all/modules/.keepme ${STAGEDIR}${DRUPAL_DIR}/sites/all/themes/.keepme
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
