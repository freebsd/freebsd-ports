# Created by: Lukasz Wasikowski <lukasz@wasikowski.net>
# $FreeBSD$

PORTNAME=	sgwi
PORTVERSION=	1.1.6
CATEGORIES=	mail www
MASTER_SITES=	http://www.vanheusden.com/sgwi/
DISTNAME=	sqlgreywebinterface-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	PHP web interface to SQLGrey

LICENSE=	GPLv2

NO_BUILD=	yes
SUB_FILES+=	pkg-message pkg-install
SUB_LIST=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	MYSQL PGSQL

MYSQL_DESC=	MySQL back-end (use mysql PHP extension)
PGSQL_DESC=	PostgreSQL back-end (use pgsql PHP extension)

OPTIONS_DEFAULT=MYSQL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

WANT_PHP_WEB=	yes

post-patch:
		${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
		@[ ! -f ${WRKSRC}/.htpasswd ] || ${MV} ${WRKSRC}/.htpasswd ${WRKSRC}/.htpasswd.sample
		@[ ! -f ${WRKSRC}/.htaccess ] || ${MV} ${WRKSRC}/.htaccess ${WRKSRC}/.htaccess.sample
		@[ ! -f ${WRKSRC}/includes/config.inc.php ] || ${MV} ${WRKSRC}/includes/config.inc.php ${WRKSRC}/includes/config.inc.php.sample
		@${MKDIR} ${WWWDIR}
		@${MKDIR} ${WWWDIR}/includes
		${INSTALL_DATA} ${WRKSRC}/*.php ${WWWDIR}
		${INSTALL_DATA} ${WRKSRC}/*.txt ${WWWDIR}
		${INSTALL_DATA} ${WRKSRC}/*.css ${WWWDIR}
		${INSTALL_DATA} ${WRKSRC}/.ht* ${WWWDIR}
		${INSTALL_DATA} ${WRKSRC}/includes/*.sample ${WWWDIR}/includes/
		${INSTALL_DATA} ${WRKSRC}/includes/*.php ${WWWDIR}/includes/
		@if [ -f ${WWWDIR}/config.inc.php ]; then \
			${MV} ${WWWDIR}/config.inc.php ${WWWDIR}/includes/config.inc.php; \
		fi
		@[ -f ${WWWDIR}/includes/config.inc.php ] || \
			${CP} ${WWWDIR}/includes/config.inc.php.sample ${WWWDIR}/includes/config.inc.php
		@[ -f ${WWWDIR}/.htpasswd ] || \
			${CP} ${WWWDIR}/.htpasswd.sample ${WWWDIR}/.htpasswd
		@[ -f ${WWWDIR}/.htaccess ] || \
			${CP} ${WWWDIR}/.htaccess.sample ${WWWDIR}/.htaccess

post-install:
		@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/
		@${CHOWN} root ${WWWDIR}/.ht* ${WWWDIR}/includes/config.inc.php*
		@${CHMOD} -R 0640 ${WWWDIR}/*.php ${WWWDIR}/*.txt ${WWWDIR}/*.css ${WWWDIR}/.ht* ${WWWDIR}/includes/*.php ${WWWDIR}/includes/*.sample
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
