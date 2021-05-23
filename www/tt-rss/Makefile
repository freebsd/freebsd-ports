# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	tt-rss
PORTVERSION=	g20210423
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	https://git.tt-rss.org/fox/tt-rss/archive/
DISTNAME=	${_GIT_TAGNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/git:devel/git

USES=		gettext-tools php:cli,web shebangfix
USE_PHP=	ctype dom exif fileinfo filter hash iconv intl json mbstring \
		openssl pcntl pdo posix session tokenizer xml xmlrpc zip
USE_RC_SUBR=	ttrssd

SHEBANG_FILES=	update.php update_daemon2.php

_GIT_TAGNAME=	e8f78181f

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

SUB_FILES=	config.php httpd-tt-rss.conf pkg-message
SUB_LIST=	DB=${DB} \
		MYSQL=${MYSQL} \
		PGSQL=${PGSQL} \
		WWWOWN=${WWWOWN}
PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
		"! -name LICENSE ! -name .empty")
	${RM} -r ${STAGEDIR}${WWWDIR}/debian
	${INSTALL_DATA} ${WRKDIR}/httpd-tt-rss.conf ${STAGEDIR}${DATADIR}
	${ECHO} "${OPSYS}:${PORTVERSION}:${_GIT_TAGNAME}" > \
		"${STAGEDIR}${WWWDIR}/version_static.txt"
	${RM} ${STAGEDIR}${WWWDIR}/config.php-dist
	${INSTALL_DATA} ${WRKDIR}/config.php \
		${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
