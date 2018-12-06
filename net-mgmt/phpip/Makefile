# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	phpip
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	1
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/4.3.2%20-%20No%20Upgrade%20Support
DISTNAME=	${PORTNAME}-4.3.2-build-${SNAPSHOT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete IPv4 IPAM (IP address management) suite

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

SNAPSHOT=	200611081420
NO_BUILD=	yes
USE_PHP=	mysql
USES=		dos2unix php:web

IGNORE_WITH_PHP=	71 72 73

PHPIP?=		www/phpip
PLIST_SUB+=	PHPIP=${PHPIP} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHPIP}
	@${CP} -R ${WRKSRC}/ ${STAGEDIR}${PREFIX}/${PHPIP}
	@${CHMOD} -R 755 ${STAGEDIR}${PREFIX}/${PHPIP}

.include <bsd.port.mk>
