# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	tt-rss
PORTVERSION=	g20200305
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	https://git.tt-rss.org/fox/tt-rss/archive/
DISTNAME=	${GIT_TAGNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator

LICENSE=	GPLv2

USES=		php:cli,web shebangfix gettext-tools
USE_PHP=	ctype dom fileinfo intl hash json mbstring pcntl posix session xmlrpc

REINPLACE_ARGS=	-i ""
SHEBANG_FILES=	lib/dojo-src/rebuild-dojo.sh utils/extract-i18n-js.pl
WRKSRC=		${WRKDIR}/tt-rss

GIT_TAGNAME=	da926067a

NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	ttrssd

OPTIONS_DEFINE=	CURL GD
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=	CURL GD MYSQL
CURL_DESC=	Use SimplePie instead of Magpie
GD_DESC=	Use OTP QR code generation

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql pgsql
DB=		pgsql
MYSQL=		"\#"
PGSQL=
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	pdo_mysql mysqli
DB=		mysql
MYSQL=
PGSQL=		"\#"
.endif

.if ${PORT_OPTIONS:MCURL}
USE_PHP+=	curl
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

SUB_FILES=	httpd-tt-rss.conf pkg-message
SUB_LIST=	DB=${DB} WWWOWN=${WWWOWN} MYSQL=${MYSQL} PGSQL=${PGSQL}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

PHP2FIX=	config.php-dist update.php update_daemon2.php

SCRIPTS=	update.php update_daemon2.php

pre-configure:
.for script in ${PHP2FIX}
	${REINPLACE_CMD} -e 's|/usr/bin/php|${LOCALBASE}/bin/php|'	\
		-e 's|/usr/bin/env php| ${LOCALBASE}/bin/php|'		\
		${WRKSRC}/${script}
.endfor

do-configure:
.if ${PORT_OPTIONS:MPGSQL}
	${REINPLACE_CMD} -e '/DB_TYPE/s|pgsql|mysql|;s|mysql$$|pgsql|'	\
		${WRKSRC}/config.php-dist
.endif

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} "! -name LICENSE")
	${RM} -r ${STAGEDIR}${WWWDIR}/debian
	${MKDIR} ${STAGEDIR}${WWWDIR}/icons/	# Not used for fresh installation
	${TOUCH} ${STAGEDIR}${WWWDIR}/icons/.empty
	${INSTALL_DATA} ${WRKDIR}/httpd-tt-rss.conf ${STAGEDIR}${DATADIR}
	${ECHO} "${OPSYS}:${PORTVERSION}:${GIT_TAGNAME}" > "${STAGEDIR}${WWWDIR}/version_static.txt"

	${MV} ${STAGEDIR}${WWWDIR}/config.php-dist ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
