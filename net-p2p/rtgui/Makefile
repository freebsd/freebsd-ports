# $FreeBSD$

PORTNAME=	rtgui
PORTVERSION=	0.2.81
CATEGORIES=	net-p2p www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A web based front end for rTorrent

OPTIONS_DEFINE=	APACHE LIGHTTPD

OPTIONS_RADIO=	HTTP
OPTIONS_RADIO_HTTP=	APACHE LIGHTTPD
OPTIONS_DEFAULTS=	APACHE

BUILD_DEPENDS+=	xmlrpc-c-config:${PORTSDIR}/net/xmlrpc-c

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_scgi.so:${PORTSDIR}/www/mod_scgi
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

USE_PHP=	xmlrpc session mbstring
WANT_PHP_WEB=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST=	WWWDIR=${WWWDIR} \
		PORTNAME=${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's/import_request_variables("gp","r_")/extract(\$_REQUEST, EXTR_PREFIX_ALL|EXTR_REFS, "r")/' ${WRKSRC}/*.php
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${MKDIR} ${WWWDIR}
	${RM} ${WRKSRC}/functions.php~
	${RM} ${WRKSRC}/index.php~
	${CP} -r ${WRKSRC}/* ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
