# New ports collection makefile for:	tt-rss
# Date created:		18 August 2010
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	tt-rss
PORTVERSION=	1.5.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://tt-rss.org/download/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Tiny Tiny RSS: web-based news feed (RSS/Atom) aggregator

LICENSE=	GPLv2

NO_BUILD=	yes

USE_PHP=	ctype json mbstring pcntl posix session xmlrpc
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

SUB_FILES=	httpd-tt-rss.conf pkg-message
SUB_LIST=	DB=${DB}
PLIST_SUB=	WWWOWN=${WWWOWN}:${WWWGRP}
PKGMESSAGE=	${WRKDIR}/pkg-message

PHP2FIX=	config.php-dist update.php update_daemon2.php

SCRIPTS=	update.php update_daemon2.php

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
	${REINPLACE_CMD} -e 's|/usr/bin/curl|${LOCALBASE}/bin/curl|' \
		${WRKSRC}/lib/magpierss/extlib/Snoopy.class.inc
	${REINPLACE_CMD} -e 's|TYPE=InnoDB|ENGINE=InnoDB|'	\
			${WRKSRC}/schema/versions/mysql/*.sql

do-configure:
.if !defined(WITH_PGSQL)
	${REINPLACE_CMD} -e '/DB_TYPE/s|pgsql|mysql|;s|mysql$$|pgsql|'	\
		${WRKSRC}/config.php-dist
	${REINPLACE_CMD} -e "s|, 'DB_PORT'||" ${WRKSRC}/sanity_config.php
.endif
	${REINPLACE_CMD} -e '/SINGLE_USER_MODE/s|true|false|'		\
		-e '/ENABLE_UPDATE_DAEMON/s|false|true|'		\
		${WRKSRC}/config.php-dist

do-install:
	${MKDIR} ${WWWDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "*" ${WWWDIR} "! -name LICENSE")
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} ug+x ${SCRIPTS:S|^|${WWWDIR}/|}
	${CHMOD} ug+x ${WWWDIR}/utils/*.sh ${WWWDIR}/utils/*.pl
	${CHMOD} -R 777 ${WWWDIR}/lib/htmlpurifier/library/HTMLPurifier/DefinitionCache/Serializer
	${CHMOD} ${SHAREMODE} ${WWWDIR}/lib/htmlpurifier/library/HTMLPurifier/DefinitionCache/Serializer/README
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
