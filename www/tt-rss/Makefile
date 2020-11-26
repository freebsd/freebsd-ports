# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	tt-rss
PORTVERSION=	g20201105
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	https://git.tt-rss.org/fox/tt-rss/archive/
DISTNAME=	${GIT_TAGNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator

LICENSE=	GPLv2

USES=		php:cli,web shebangfix gettext-tools
USE_PHP=	ctype dom fileinfo filter iconv intl hash json mbstring pcntl posix session xmlrpc

REINPLACE_ARGS=	-i ""
SHEBANG_FILES=	lib/dojo-src/rebuild-dojo.sh utils/extract-i18n-js.pl update_daemon2.php
WRKSRC=		${WRKDIR}/tt-rss

GIT_TAGNAME=	242aa6e41

NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	ttrssd

OPTIONS_DEFINE=	CURL GD
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=	CURL GD MYSQL

CURL_DESC=	Use SimplePie instead of Magpie
CURL_USE=	PHP=curl

GD_DESC=	Use OTP QR code generation
GD_USE=		PHP=gd

PGSQL_VARS=	DB=pgsql
PGSQL_USE=	PHP=pdo_pgsql,pgsql
PGSQL_VARS_OFF=	PGSQL="\#"

MYSQL_VARS=	DB=mysql
MYSQL_USE=	PHP=pdo_mysql,mysqli
MYSQL_VARS_OFF=	MYSQL="\#"

.include <bsd.port.options.mk>

SUB_FILES=	httpd-tt-rss.conf pkg-message
SUB_LIST=	DB=${DB} WWWOWN=${WWWOWN} MYSQL=${MYSQL} PGSQL=${PGSQL}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

PHP2FIX=	config.php-dist update.php

SCRIPTS=	update.php update_daemon2.php

pre-configure:
.for script in ${PHP2FIX}
	${REINPLACE_CMD} -e 's|/usr/bin/php|${LOCALBASE}/bin/php|'	\
		-e 's|/usr/bin/env php| ${LOCALBASE}/bin/php|'		\
		${WRKSRC}/${script}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
		"! -name LICENSE ! -name .empty")
	${RM} -r ${STAGEDIR}${WWWDIR}/debian
	${INSTALL_DATA} ${WRKDIR}/httpd-tt-rss.conf ${STAGEDIR}${DATADIR}
	${ECHO} "${OPSYS}:${PORTVERSION}:${GIT_TAGNAME}" > "${STAGEDIR}${WWWDIR}/version_static.txt"
	${MV} ${STAGEDIR}${WWWDIR}/config.php-dist ${STAGEDIR}${WWWDIR}/config.php.sample
	${RLN} ${STAGEDIR}${WWWDIR}/config.php.sample ${STAGEDIR}${WWWDIR}/config.php-dist

.include <bsd.port.mk>
