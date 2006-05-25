# New ports collection makefile for:	Drupal
# Date Created: 			10 Nov 2003
# Whom:					Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	drupal
PORTVERSION=	4.6.6
PORTREVISION=	2006031700
CATEGORIES=	www
MASTER_SITES=   ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     brooks
DIST_SUBDIR=    drupal

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	CMS that supports pgsql and mysql

FORBIDDEN=	SQL injection and remote execution vulnerabilities

DRUPAL_PORT=	yes

USE_PHP=	gd pcre session xml
WANT_PHP_WEB=	yes

OPTIONS+=	MYSQL "MySQL database support" on \
		PGSQL "PostgreSQL database support" off

WWWOWN?=	www
WWWGRP?=	www

NO_BUILD=	yes
DOCS=		CHANGELOG.txt INSTALL.txt LICENSE.txt MAINTAINERS.txt
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
# XXX: should be "USE_PHP+=mysql", but the depends are added too early
# by bsd.php.mk
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/mysql.so:${PORTSDIR}/${mysql_DEPENDS}
.endif
.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
.endif

do-install:
	${MKDIR} ${DRUPAL_DIR}
	${CP} ${WRKSRC}/.htaccess ${DRUPAL_DIR}
	${CP} ${WRKSRC}/cron.php ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/database ${DRUPAL_DIR}
	${CP} ${WRKSRC}/favicon.ico ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/includes ${DRUPAL_DIR}
	${CP} ${WRKSRC}/index.php ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/misc ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/modules ${DRUPAL_DIR}
	${CP} -R ${WRKSRC}/scripts ${DRUPAL_DIR}
	${MKDIR} ${DRUPAL_DIR}/sites/default
	${CP} ${WRKSRC}/sites/default/settings.php ${DRUPAL_DIR}/sites/default/settings.php-dist
	@if [ ! -f ${DRUPAL_DIR}/sites/default/settings.php ]; then \
		${CP} -p ${DRUPAL_DIR}/sites/default/settings.php-dist ${DRUPAL_DIR}/sites/default/settings.php ; \
	fi
	${CP} -R ${WRKSRC}/themes ${DRUPAL_DIR}
	${CP} ${WRKSRC}/update.php ${DRUPAL_DIR}
	${CP} ${WRKSRC}/xmlrpc.php ${DRUPAL_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DRUPAL_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/bsd.drupal.mk"
.include <bsd.port.post.mk>
