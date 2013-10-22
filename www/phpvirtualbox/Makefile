# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	phpvirtualbox
DISTVERSION=	4.2-8
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME} \
		LOCAL/decke

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox

LICENSE=	GPLv3

USE_ZIP=	yes
USE_PHP=	json session soap simplexml
NO_BUILD=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)
NO_WRKSUBDIR=	yes
STAGEDIR=	${WRKDIR}/.stage

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} "! -name *.orig")

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${FIND} ${STAGEDIR}${WWWDIR} -type f -exec ${CHMOD} 0444 {} \;
	@${FIND} ${STAGEDIR}${WWWDIR} -type d -exec ${CHMOD} 0755 {} \;

.include <bsd.port.mk>
