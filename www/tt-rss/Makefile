# New ports collection makefile for:	tt-rss
# Date created:		18 August 2010
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	tt-rss
PORTVERSION=	1.4.2
CATEGORIES=	www
MASTER_SITES=	http://tt-rss.org/download/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator

NO_BUILD=	yes

USE_GETTEXT=	yes
USE_PHP=	mbstring pcntl session xmlrpc
WANT_PHP_WEB=	yes
WANT_PHP_CLI=	yes
REINPLACE_ARGS=	-i ""

USE_RC_SUBR=	ttrssd

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
DB=		pgsql
.else
USE_PHP+=	mysql
DB=		mysql
.endif

.if !defined(WITHOUT_CURL)
USE_PHP+=	curl
.endif

LICENSE=	GPLv2

SUB_FILES=	httpd-tt-rss.conf pkg-message
SUB_LIST=	DB=${DB}
PLIST_SUB=	WWWOWN=${WWWOWN}:${WWWGRP}
PKGMESSAGE=	${WRKDIR}/pkg-message

PHP2FIX=	config.php-dist update_daemon.php update_daemon2.php		\
		update_daemon_loop.php update_feedbrowser.php update_feeds.php

SCRIPTS=	update-translations.sh update_daemon.php update_daemon2.php	\
		update_daemon_loop.php update_feedbrowser.php update_feeds.php

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "	By default, Tiny Tiny RSS will use MySQL as a back-end;"
	@${ECHO_MSG} "	define WITH_PGSQL if you prefer PostgreSQL."
	@${ECHO_MSG}
	@${ECHO_MSG} "	CURL is required for SimplePie, but if you prefer Magpie,"
	@${ECHO_MSG} "	you can define WITHOUT_CURL."
	@${ECHO_MSG}

pre-configure:
.for script in ${PHP2FIX}
	${REINPLACE_CMD} -e 's|/usr/bin/php|${LOCALBASE}/bin/php|'	\
		${WRKSRC}/${script}
.endfor

do-configure:
.if !defined(WITH_PGSQL)
	${REINPLACE_CMD} -e '/DB_TYPE/s|pgsql|mysql|;s|mysql$$|pgsql|'	\
		${WRKSRC}/config.php-dist
.endif
	${REINPLACE_CMD} -e '/SINGLE_USER_MODE/s|true|false|'		\
		-e '/ENABLE_UPDATE_DAEMON/s|false|true|'		\
		${WRKSRC}/config.php-dist

do-install:
	${MKDIR} ${WWWDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR})
	${RM} ${WWWDIR}/LICENSE
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} ug+x ${SCRIPTS:S|^|${WWWDIR}/|}
	${INSTALL_DATA} ${WRKDIR}/httpd-tt-rss.conf ${DATADIR}
	if [ ! -f ${WWWDIR}/config.php ]; then \
		${CP} -p ${WWWDIR}/config.php-dist ${WWWDIR}/config.php; \
		${CHMOD} go-r ${WWWDIR}/config.php; \
	fi

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
