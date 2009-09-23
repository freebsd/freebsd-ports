# New ports collection makefile for:	drupal5
# Date Created: 			12 Feb 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	drupal5
PORTVERSION=	5.20
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTNAME=	drupal-${PORTVERSION}
DIST_SUBDIR=	drupal

MAINTAINER=	nick@foobar.org
COMMENT=	A database driven web content management system (CMS)

DRUPAL5_PORT=	yes

USE_PHP=	gd pcre session xml mbstring
WANT_PHP_WEB=	yes

OPTIONS+=	MYSQL "MySQL database support" on \
		PGSQL "PostgreSQL database support" off

NO_BUILD=	yes
DOCS=		CHANGELOG.txt INSTALL.txt LICENSE.txt MAINTAINERS.txt \
		UPGRADE.txt INSTALL.mysql.txt INSTALL.pgsql.txt
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif
.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
USE_PHP+=	pgsql
.endif

do-install:
	${MKDIR} ${DRUPAL_DIR}
	${CP} ${WRKSRC}/.htaccess ${DRUPAL_DIR}
	${CP} ${WRKSRC}/cron.php ${DRUPAL_DIR}
	${MKDIR} ${DRUPAL_DIR}/files
	${CP} -R ${WRKSRC}/includes ${DRUPAL_DIR}
	${CP} ${WRKSRC}/index.php ${DRUPAL_DIR}
	${CP} ${WRKSRC}/install.php ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/misc ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/modules ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/profiles ${DRUPAL_DIR}
	${CP} ${WRKSRC}/robots.txt ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/scripts ${DRUPAL_DIR}
	${MKDIR} ${DRUPAL_DIR}/sites/all
	${CP} ${WRKSRC}/sites/all/README.txt ${DRUPAL_DIR}/sites/all/
	${MKDIR} ${DRUPAL_DIR}/sites/default
	${CP} ${WRKSRC}/sites/default/settings.php ${DRUPAL_DIR}/sites/default/settings.php-dist
	@if [ ! -f ${DRUPAL_DIR}/sites/default/settings.php ]; then \
		${CP} -p ${DRUPAL_DIR}/sites/default/settings.php-dist ${DRUPAL_DIR}/sites/default/settings.php ; \
	fi
	${CP} -R ${WRKSRC}/themes ${DRUPAL_DIR}
	${CP} ${WRKSRC}/update.php ${DRUPAL_DIR}
	${CP} ${WRKSRC}/xmlrpc.php ${DRUPAL_DIR}
	${MKDIR} ${DRUPAL_DIR}/sites/all/modules ${DRUPAL_DIR}/sites/all/themes
	${TOUCH} ${DRUPAL_DIR}/sites/all/modules/.keepme ${DRUPAL_DIR}/sites/all/themes/.keepme
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DRUPAL_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/bsd.drupal.mk"
.include <bsd.port.post.mk>
