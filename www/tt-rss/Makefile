PORTNAME=	tt-rss
PORTVERSION=	g20231202
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	www

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator
WWW=		https://tt-rss.org/

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/git:devel/git

USES=		gettext-tools php:cli,web shebangfix

USE_GITLAB=	yes
GL_SITE=	https://gitlab.tt-rss.org
GL_TAGNAME=	2b8e34453234b8b31ebc9e7020f8677bf3889898
# phe json/openssl extension is required but it's statically linked in default php
USE_PHP=	ctype dom exif fileinfo filter iconv intl mbstring pcntl pdo \
		phar posix session simplexml sockets tokenizer xml xmlwriter \
		zip
USE_RC_SUBR=	ttrssd

SHEBANG_FILES=	update.php update_daemon2.php

REINPLACE_ARGS=	-i ""

NO_ARCH=	yes
NO_BUILD=	yes

# Instead of depending on the extact database driver list php packages that tt-rss
# depends on during install pkg-message as a post install setup.
# mysql: php-mysqli php-pdo_mysql
# pgsql: php-pgsql php-pdo_pgsql
#
# from Mk/Uses/php.mk create sub vars for mysqli/pdo_mysql pgsql/pdo_pgsql values
SUB_FILES=	config.php httpd-tt-rss.conf pkg-message ttrss_db_check.php
SUB_LIST=	MYSQL_DEPS="${mysqli_DEPENDS:T} ${pdo_mysql_DEPENDS:T}" \
		PGSQL_DEPS="${pgsql_DEPENDS:T} ${pdo_pgsql_DEPENDS:T}" \
		WWWOWN=${WWWOWN}

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
	${ECHO} "${OPSYS}:${PORTVERSION}:${GL_TAGNAME:C/^(.{11}).*$/\1/W}}" > \
		"${STAGEDIR}${WWWDIR}/version_static.txt"
	${RM} ${STAGEDIR}${WWWDIR}/config.php-dist
	${INSTALL_DATA} ${WRKDIR}/config.php \
		${STAGEDIR}${WWWDIR}/config.php.sample
	${INSTALL_DATA} ${WRKDIR}/ttrss_db_check.php \
		${STAGEDIR}${WWWDIR}/ttrss_db_check.php
	${INSTALL_DATA} ${FILESDIR}/newsyslog.sample \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
