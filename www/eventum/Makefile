# New ports collection makefile for:	eventum
# Date created:		2005-07-18
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	eventum
PORTVERSION=	2.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	eventum

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Eventum issue tracking system

NO_BUILD=	YES
USE_PHP=	pcre session mysql gd gettext
WANT_PHP_WEB=	YES

pre-install:
	@${MV} ${WRKSRC}/setup/config.php ${WRKSRC}/setup/config.php-dist

post-patch:
	@${REINPLACE_CMD} -e 's|%%WWWOWN%%|${WWWOWN}|g' ${WRKSRC}/misc/monitor.php
	@${REINPLACE_CMD} -e 's|%%WWWGRP%%|${WWWGRP}|g' ${WRKSRC}/misc/monitor.php
	@${RM} ${WRKSRC}/misc/monitor.php.*

do-install:
	-${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@if [ ! -f ${WWWDIR}/setup/config.php ]; then \
	    ${CP} -p ${WWWDIR}/setup/config.php-dist ${WWWDIR}/setup/config.php ; \
	fi

.include <bsd.port.mk>
