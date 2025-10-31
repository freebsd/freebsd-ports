PORTNAME=	tt-rss
DISTVERSION=	g20251025
PORTEPOCH=	2
CATEGORIES=	www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator
WWW=		https://github.com/tt-rss/tt-rss/

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/git:devel/git

USES=		gettext-tools php:cli,web,flavors shebangfix

USE_GITHUB=	yes
GH_TAGNAME=	942f3e1bbac865d3c7da948db197067949cbb3e7
# phe json/openssl extension is required but it's statically linked in default php
USE_PHP=	ctype dom exif fileinfo filter iconv intl mbstring pcntl pdo \
		pdo_pgsql phar posix session simplexml sockets sodium tokenizer \
		xml xmlwriter zip
USE_RC_SUBR=	ttrssd

SHEBANG_FILES=	update.php update_daemon2.php

REINPLACE_ARGS=	-i ""

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	config.php httpd-tt-rss.conf pkg-message
SUB_LIST=	WWWOWN=${WWWOWN}

PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

OPTIONS_DEFINE=		CURL GD
OPTIONS_DEFAULT=	CURL GD

CURL_DESC=	Use SimplePie instead of Magpie
GD_DESC=	Use OTP QR code generation

CURL_USE=	PHP=curl
GD_USE=		PHP=gd

do-install:
	${MKDIR} \
		${STAGEDIR}${WWWDIR} \
		${STAGEDIR}${DATADIR} \
		${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
		"! -name LICENSE ! -name .empty ! -name Jenkinsfile")
	${RM} -r ${STAGEDIR}${WWWDIR}/debian
	${INSTALL_DATA} ${WRKDIR}/httpd-tt-rss.conf ${STAGEDIR}${DATADIR}
	${ECHO} "${OPSYS}:${PORTVERSION}:${GH_TAGNAME:C/^(.{11}).*$/\1/W}}" > \
		"${STAGEDIR}${WWWDIR}/version_static.txt"
	${RM} ${STAGEDIR}${WWWDIR}/config.php-dist
	${INSTALL_DATA} ${WRKDIR}/config.php \
		${STAGEDIR}${WWWDIR}/config.php.sample
	${INSTALL_DATA} ${FILESDIR}/newsyslog.sample \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
