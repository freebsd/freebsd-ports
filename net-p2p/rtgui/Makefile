# New ports collection makefile for:	rtgui
# Date created:				14 December 2008
# Whom:					Philippe Audeoud <jadawin@tuxaco.net>
#
# $FreeBSD$
#

PORTNAME=	rtgui
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	net-p2p www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jadawin@tuxaco.net
COMMENT=	A web based front end for rTorrent

OPTIONS=	APACHE "Use Apache for web interface" On \
		LIGHTTPD "Use LightHTTPD for web interface" Off

BUILD_DEPENDS+=	xmlrpc-c-config:${PORTSDIR}/net/xmlrpc-c

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_APACHE)
USE_APACHE=	1.3+
BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_scgi.so:${PORTSDIR}/www/mod_scgi
.elif defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

USE_PHP=	xmlrpc session
WANT_PHP_WEB=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST=	WWWDIR=${WWWDIR} \
		PORTNAME=${PORTNAME}

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -r ${WRKSRC}/* ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
