# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	tt-rss
PORTVERSION=	2017.01.16
CATEGORIES=	www
MASTER_SITES=	https://tt-rss.org/gitlab/fox/tt-rss/repository/archive${EXTRACT_SUFX}?ref=${GL_TAGNAME}&num;/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator

LICENSE=	GPLv2

GL_TAGNAME=	db92edd1

NO_BUILD=	yes
NO_ARCH=	yes

USE_PHP=	ctype dom hash json mbstring pcntl posix session xmlrpc
REINPLACE_ARGS=	-i ""
USES=		php:cli,web shebangfix tar:bz2
SHEBANG_FILES=	lib/dojo-src/rebuild-dojo.sh utils/extract-i18n-js.pl
WRKSRC=		${WRKDIR}/tt-rss.git

USE_RC_SUBR=	ttrssd

OPTIONS_DEFINE=	CURL GD
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=	CURL GD MYSQL
CURL_DESC=	Use SimplePie instead of Magpie
GD_DESC=	Use OTP QR code generation

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
DB=		pgsql
MYSQL=		"\#"
PGSQL=
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysqli
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
PKGMESSAGE=	${WRKDIR}/pkg-message

PHP2FIX=	config.php-dist update.php update_daemon2.php

SCRIPTS=	update.php update_daemon2.php

pre-configure:
	${REINPLACE_CMD} -E "1,/define.*VERSION_STATIC/s/([0-9]+\.[0-9]+)/\1 (${GL_TAGNAME})/" ${WRKSRC}/include/version.php
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

	${MV} ${STAGEDIR}${WWWDIR}/config.php-dist ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
