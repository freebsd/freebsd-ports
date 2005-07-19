# New ports collection makefile for:	eventum
# Date created:		2005-07-18
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	eventum
PORTVERSION=	1.5.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	eventum

MAINTAINER=	babak@farrokhi.net
COMMENT=	Eventum issue tracking system

NO_BUILD=	YES
USE_PHP=	pcre session mysql gd
WANT_PHP_WEB=	YES
PLIST_SUB+=	EVENTUM=${EVENTUM}
PLIST=		${WRKDIR}/pkg-plist

EVENTUM?=	www/data-dist/eventum
PLIST_SUB+=	EVENTUM=${EVENTUM}

pre-install:
	@cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${EVENTUM}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${EVENTUM}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${EVENTUM} >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${EVENTUM}
	${CP} -R ${WRKSRC}/ ${PREFIX}/${EVENTUM}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${EVENTUM}
	${CHMOD} -R 755 ${PREFIX}/${EVENTUM}

.include <bsd.port.mk>
