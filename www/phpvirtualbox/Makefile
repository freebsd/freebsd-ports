# Created by:	Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	phpvirtualbox
DISTVERSION=	4.2-4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		LOCAL/decke

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_ZIP=	yes
USE_PHP=	json session soap simplexml
NO_BUILD=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)

do-install:
	@${MKDIR} ${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${WWWDIR} "! -name *.orig")

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${FIND} ${WWWDIR} -type f -exec ${CHMOD} 0444 {} \;
	@${FIND} ${WWWDIR} -type d -exec ${CHMOD} 0755 {} \;

post-install:
	@if [ ! -f ${WWWDIR}/config.php ]; then \
		${CP} ${WWWDIR}/config.php-example ${WWWDIR}/config.php ; \
	fi

.include <bsd.port.mk>
