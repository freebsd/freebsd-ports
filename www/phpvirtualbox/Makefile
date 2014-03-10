# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	phpvirtualbox
DISTVERSION=	4.3-1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME} \
		LOCAL/decke

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox

LICENSE=	GPLv3

USES=		dos2unix zip
USE_PHP=	json session soap simplexml xml
NO_BUILD=	yes
DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} "! -name *.orig")

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${FIND} ${STAGEDIR}${WWWDIR} -type f -exec ${CHMOD} 0444 {} \;
	@${FIND} ${STAGEDIR}${WWWDIR} -type d -exec ${CHMOD} 0755 {} \;

.include <bsd.port.mk>
