PORTNAME=	tt-rss
PORTVERSION=	g20230307
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	https://git-gitea.tt-rss.org/fox/tt-rss/archive/
DISTNAME=	${_GIT_TAGNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator
WWW=		https://tt-rss.org/

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/git:devel/git

USES=		gettext-tools php:cli,web shebangfix
USE_PHP=	ctype dom exif fileinfo filter iconv intl mbstring \
		openssl pcntl pdo phar posix session simplexml tokenizer xml \
		xmlwriter zip
USE_RC_SUBR=	ttrssd

SHEBANG_FILES=	update.php update_daemon2.php

_GIT_TAGNAME=	cddbf5bf5

REINPLACE_ARGS=	-i ""

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	config.php httpd-tt-rss.conf pkg-message
SUB_LIST=	MYSQL=${MYSQL} \
		PGSQL=${PGSQL} \
		WWWOWN=${WWWOWN}

WRKSRC=		${WRKDIR}/tt-rss

PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

OPTIONS_DEFINE=		CURL GD
OPTIONS_DEFAULT=	CURL GD MYSQL
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL

CURL_DESC=	Use SimplePie instead of Magpie
GD_DESC=	Use OTP QR code generation

CURL_USE=	PHP=curl
GD_USE=		PHP=gd

MYSQL_USE=	PHP=mysqli,pdo_mysql
MYSQL_VARS_OFF=	MYSQL="\#"

PGSQL_USE=	PHP=pdo_pgsql,pgsql
PGSQL_VARS_OFF=	PGSQL="\#"

do-install:
	${MKDIR} \
		${STAGEDIR}${WWWDIR} \
		${STAGEDIR}${DATADIR} \
		${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
		"! -name LICENSE ! -name .empty ! -name Jenkinsfile")
	${RM} -r ${STAGEDIR}${WWWDIR}/debian
	${INSTALL_DATA} ${WRKDIR}/httpd-tt-rss.conf ${STAGEDIR}${DATADIR}
	${ECHO} "${OPSYS}:${PORTVERSION}:${_GIT_TAGNAME}" > \
		"${STAGEDIR}${WWWDIR}/version_static.txt"
	${RM} ${STAGEDIR}${WWWDIR}/config.php-dist
	${INSTALL_DATA} ${WRKDIR}/config.php \
		${STAGEDIR}${WWWDIR}/config.php.sample
	${INSTALL_DATA} ${FILESDIR}/newsyslog.sample \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
