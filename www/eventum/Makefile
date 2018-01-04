# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	eventum
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	MYSQL/eventum

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eventum issue tracking system

IGNORE_WITH_PHP=	70 71 72

USES=		cpe php:web
CPE_VENDOR=	mysql
NO_BUILD=	yes
USE_PHP=	pcre session mysql gd gettext
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

pre-install:
	@${MV} ${WRKSRC}/setup/config.php ${WRKSRC}/setup/config.php-dist

post-patch:
	@${REINPLACE_CMD} -e 's|%%WWWOWN%%|${WWWOWN}|g' ${WRKSRC}/misc/monitor.php
	@${REINPLACE_CMD} -e 's|%%WWWGRP%%|${WWWGRP}|g' ${WRKSRC}/misc/monitor.php
	@${RM} ${WRKSRC}/misc/monitor.php.*

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@if [ ! -f ${STAGEDIR}${WWWDIR}/setup/config.php ]; then \
	    ${CP} -p ${STAGEDIR}${WWWDIR}/setup/config.php-dist ${STAGEDIR}${WWWDIR}/setup/config.php ; \
	fi

.include <bsd.port.mk>
