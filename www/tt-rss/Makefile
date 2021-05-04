# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	tt-rss
PORTVERSION=	g20210123
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	https://git.tt-rss.org/fox/tt-rss/archive/
DISTNAME=	${_GIT_TAGNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator

LICENSE=	GPLv2

USES=		gettext-tools php:cli,web shebangfix
USE_PHP=	ctype dom fileinfo filter hash iconv intl json mbstring pcntl \
		posix session xmlrpc
USE_RC_SUBR=	ttrssd

SHEBANG_FILES=	lib/dojo-src/rebuild-dojo.sh update_daemon2.php \
		utils/extract-i18n-js.pl

_GIT_TAGNAME=	6c546f37b

REINPLACE_ARGS=	-i ""

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/tt-rss

OPTIONS_DEFINE=		CURL GD
OPTIONS_DEFAULT=	CURL GD MYSQL
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL

CURL_DESC=	Use SimplePie instead of Magpie
GD_DESC=	Use OTP QR code generation

CURL_USE=	PHP=curl
GD_USE=		PHP=gd

MYSQL_USE=	PHP=mysqli,pdo_mysql
MYSQL_VARS=	DB=mysql
MYSQL_VARS_OFF=	MYSQL="\#"

PGSQL_USE=	PHP=pdo_pgsql,pgsql
PGSQL_VARS=	DB=pgsql
PGSQL_VARS_OFF=	PGSQL="\#"

.include <bsd.port.options.mk>

SUB_FILES=	httpd-tt-rss.conf pkg-message
SUB_LIST=	DB=${DB} \
		MYSQL=${MYSQL} \
		PGSQL=${PGSQL} \
		WWWOWN=${WWWOWN}
PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

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
	${ECHO} "${OPSYS}:${PORTVERSION}:${_GIT_TAGNAME}" > \
		"${STAGEDIR}${WWWDIR}/version_static.txt"
	${MV} ${STAGEDIR}${WWWDIR}/config.php-dist \
		${STAGEDIR}${WWWDIR}/config.php.sample
	${RLN} ${STAGEDIR}${WWWDIR}/config.php.sample \
		${STAGEDIR}${WWWDIR}/config.php-dist

.include <bsd.port.mk>
