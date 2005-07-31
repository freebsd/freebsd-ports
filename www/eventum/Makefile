# New ports collection makefile for:	eventum
# Date created:		2005-07-18
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	eventum
PORTVERSION=	1.5.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	eventum

MAINTAINER=	babak@farrokhi.net
COMMENT=	Eventum issue tracking system

NO_BUILD=	YES
USE_PHP=	pcre session mysql gd
WANT_PHP_WEB=	YES

EVENTUM?=	www/data-dist/eventum
PLIST=		${WRKDIR}/pkg-plist
PLIST_SUB+=	EVENTUM=${EVENTUM}
SUB_LIST+=	EVENTUM=${EVENTUM}
SUB_FILES=	pkg-message

pre-install:
	@${MV} ${WRKSRC}/setup.conf.php ${WRKSRC}/setup.conf.php-dist
	@${MV} ${WRKSRC}/config.inc.php ${WRKSRC}/config.inc.php-dist
	@cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${EVENTUM}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${EVENTUM}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${EVENTUM} >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/${EVENTUM}
	@${CP} ${WRKSRC}/setup.conf.php-dist ${WRKSRC}/setup.conf.php
	@${CP} ${WRKSRC}/config.inc.php-dist ${WRKSRC}/config.inc.php
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${EVENTUM}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${EVENTUM}
	@${CHMOD} -R 755 ${PREFIX}/${EVENTUM}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
