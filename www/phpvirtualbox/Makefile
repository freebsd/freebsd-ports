# New ports collection makefile for:	phpvirtualbox
# Date created:		2010-07-26
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	phpvirtualbox
PORTVERSION=	0.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_ZIP=	yes
USE_PHP=	json session soap
NO_BUILD=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} ${WRKSRC}/config.php ${WWWDIR}/config.php.sample
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${WWWDIR} "! -name config.php ! -name *.orig")

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${FIND} ${WWWDIR} -type f -exec ${CHMOD} 0444 {} \;
	@${FIND} ${WWWDIR} -type d -exec ${CHMOD} 0755 {} \;

post-install:
	@if [ ! -f ${WWWDIR}/config.php ]; then \
		${CP} ${WWWDIR}/config.php.sample ${WWWDIR}/config.php ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
