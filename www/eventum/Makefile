# New ports collection makefile for:	eventum
# Date created:		2005-07-18
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	eventum
PORTVERSION=	1.7.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	eventum

MAINTAINER=	babak@farrokhi.net
COMMENT=	Eventum issue tracking system

NO_BUILD=	YES
USE_PHP=	pcre session mysql gd
WANT_PHP_WEB=	YES

EVENTUM?=	www/data-dist/eventum
PLIST_SUB+=	EVENTUM=${EVENTUM}
SUB_LIST+=	EVENTUM=${EVENTUM}
SUB_FILES=	pkg-message

.if ${EVENTUM:M/*}
EVENTUM_DIST=${EVENTUM}
.else
EVENTUM_DIST=${PREFIX}/${EVENTUM}
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This port has the following tunables"
	@${ECHO_MSG} "EVENTUM   path where Eventum will be installed"
	@${ECHO_MSG} "          either absolute or relative to the PREFIX"
	@${ECHO_MSG} "WWWOWN    eventum files owner"
	@${ECHO_MSG} "WWWGRP    eventum files group"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Current state is"
	@${ECHO_MSG} "EVENTUM   " ${EVENTUM}
	@${ECHO_MSG} "WWWOWN    " ${WWWOWN}
	@${ECHO_MSG} "WWWGRP    " ${WWWGRP}
	@${ECHO_MSG} ""

pre-install:
	@${MV} ${WRKSRC}/setup.conf.php ${WRKSRC}/setup.conf.php-dist
	@${MV} ${WRKSRC}/config.inc.php ${WRKSRC}/config.inc.php-dist

do-install:
	@${MKDIR} ${EVENTUM_DIST}
	@${CP} -R ${WRKSRC}/ ${EVENTUM_DIST}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${EVENTUM_DIST}
	@${CHMOD} -R 755 ${EVENTUM_DIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
