# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	tt-rss
PORTVERSION=	1.14
CATEGORIES=	www

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	gothfox
GH_PROJECT=	Tiny-Tiny-RSS
GH_COMMIT=	edccb21

NO_BUILD=	yes
NO_ARCH=	yes

USE_PHP=	ctype dom hash json mbstring pcntl posix session xmlrpc
WANT_PHP_WEB=	yes
WANT_PHP_CLI=	yes
REINPLACE_ARGS=	-i ""
USES=		shebangfix
SHEBANG_FILES=	lib/dojo-src/rebuild-dojo.sh utils/extract-i18n-js.pl

USE_RC_SUBR=	ttrssd

OPTIONS_DEFINE=	CURL GD DBLOCAL
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=	CURL GD MYSQL DBLOCAL
CURL_DESC=	Use SimplePie instead of Magpie
GD_DESC=	Use OTP QR code generation
DBLOCAL_DESC=	Database is local?

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
DB=		pgsql
MYSQL=		"\#"
PGSQL=
.else
USE_PHP+=	mysql
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

.if ${PORT_OPTIONS:MDBLOCAL}
DBLOCAL=
.else
DBLOCAL=	"\#"
.endif

SUB_FILES=	httpd-tt-rss.conf pkg-message
SUB_LIST=	DB=${DB} WWWOWN=${WWWOWN} MYSQL=${MYSQL} PGSQL=${PGSQL} DBLOCAL=${DBLOCAL}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PKGMESSAGE=	${WRKDIR}/pkg-message

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
	${RM} -rf ${STAGEDIR}${WWWDIR}/debian
	${MKDIR} ${STAGEDIR}${WWWDIR}/icons/	# Not used for fresh installation
	${TOUCH} ${STAGEDIR}${WWWDIR}/icons/.empty
	${INSTALL_DATA} ${WRKDIR}/httpd-tt-rss.conf ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
