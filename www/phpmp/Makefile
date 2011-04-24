# New ports collection makefile for:	phpmp
# Date created:		2007-02-27
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phpmp
PORTVERSION=	0.11.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/musicpd/phpMp/${PORTVERSION}
DISTNAME=	phpMp-${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A web interface for music player daemon

NO_BUILD=	YES
USE_PHP=	pcre sockets

PHPMP?=		www/phpmp
PLIST_SUB+=	PHPMP=${PHPMP}

post-patch:
# Replace deprecated HTTP_(GET|POST)_VARS with _(GET|POST)
	@${REINPLACE_CMD} -e 's#HTTP\(_[^_]*\)_VARS#\1#' \
		${WRKSRC}/playlist.php ${WRKSRC}/main_body.php
# Stop clobbering config.php & disable volume control by default;
# incremental volume changes no longer supported by musicpd
	@${MV} ${WRKSRC}/config.php ${WRKSRC}/config.php.sample
	@${REINPLACE_CMD} -e 's/^\(.display_volume[^"]*"\)yes/\1no/' \
		${WRKSRC}/config.php.sample
	@${RM} ${WRKSRC}/*.bak

do-install:
	@${MKDIR} ${PREFIX}/${PHPMP}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PHPMP}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPMP}
	@${CHMOD} -R 755 ${PREFIX}/${PHPMP}

post-install:
	@if [ ! -f ${PREFIX}/${PHPMP}/config.php ]; then \
		${CP} -p ${PREFIX}/${PHPMP}/config.php.sample \
			${PREFIX}/${PHPMP}/config.php ; \
	fi

.include <bsd.port.mk>
