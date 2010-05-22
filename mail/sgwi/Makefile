# New ports collection makefile for:  sgwi
# Date created:                       11 March 2008
# Whom:                               Lukasz Wasikowski <lukasz@wasikowski.net>
#
# $FreeBSD$
#

PORTNAME=	sgwi
PORTVERSION=	0.8
CATEGORIES=	mail www
MASTER_SITES=	http://www.vanheusden.com/sgwi/
DISTNAME=	sqlgreywebinterface-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	PHP web interface to SQLGrey

NO_BUILD=	yes
SUB_FILES+=	pkg-message

OPTIONS=	MYSQL "MySQL back-end (use mysql PHP extension)" on
OPTIONS+=	PGSQL "PostgreSQL back-end (use pgsql PHP extension)" off

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL)
IGNORE=	needs at least one database back-end
.endif

post-patch:
		${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
		@[ ! -f ${WRKSRC}/.htpasswd ] || ${MV} ${WRKSRC}/.htpasswd ${WRKSRC}/.htpasswd.dist
		@[ ! -f ${WRKSRC}/.htaccess ] || ${MV} ${WRKSRC}/.htaccess ${WRKSRC}/.htaccess.dist
		@[ ! -f ${WRKSRC}/config.inc.php ] || ${MV} ${WRKSRC}/config.inc.php ${WRKSRC}/config.inc.php.dist
		@${MKDIR} ${PREFIX}/www/sgwi
		@${INSTALL_DATA} ${WRKSRC}/*.php ${PREFIX}/www/sgwi
		@${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/www/sgwi
		@${INSTALL_DATA} ${WRKSRC}/*.dist ${PREFIX}/www/sgwi
		@${INSTALL_DATA} ${WRKSRC}/.ht* ${PREFIX}/www/sgwi
		@[ -f ${PREFIX}/www/sgwi/config.inc.php ] || \
			${CP} ${PREFIX}/www/sgwi/config.inc.php.dist \
				${PREFIX}/www/sgwi/config.inc.php
		@[ -f ${PREFIX}/www/sgwi/.htpasswd ] || \
			${CP} ${PREFIX}/www/sgwi/.htpasswd.dist \
				${PREFIX}/www/sgwi/.htpasswd
		@[ -f ${PREFIX}/www/sgwi/.htaccess ] || \
			${CP} ${PREFIX}/www/sgwi/.htaccess.dist \
				${PREFIX}/www/sgwi/.htaccess

post-install:
		@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/sgwi
		@${CHOWN} root ${PREFIX}/www/sgwi/.ht* ${PREFIX}/www/sgwi/config.inc.php*
		@${CHMOD} 640 ${PREFIX}/www/sgwi/*.php ${PREFIX}/www/sgwi/*.txt ${PREFIX}/www/sgwi/.ht* ${PREFIX}/www/sgwi/*.dist
		${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
