# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phpmp
PORTVERSION=	0.12.0
CATEGORIES=	www
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A web interface for music player daemon

LICENSE=	GPLv2

NO_BUILD=	YES
USE_PHP=	pcre sockets

PHPMP?=		${WWWDIR_REL}
PLIST_SUB+=	PHPMP=${PHPMP}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/${PHPMP}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PHPMP}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPMP}
	@${CHMOD} -R 755 ${PREFIX}/${PHPMP}

post-install:
	@${CAT} ${PKGMESSAGE}
	@if [ ! -f ${PREFIX}/${PHPMP}/config.php ]; then \
		${CP} -p ${PREFIX}/${PHPMP}/config.php.sample \
			${PREFIX}/${PHPMP}/config.php ; \
	fi

.include <bsd.port.mk>
