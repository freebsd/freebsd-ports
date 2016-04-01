# $FreeBSD$

PORTNAME=	rtgui
PORTVERSION=	0.2.81
CATEGORIES=	net-p2p www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Web based front end for rTorrent

BUILD_DEPENDS+=	xmlrpc-c-config:net/xmlrpc-c

USES=		tar:tgz

OPTIONS_DEFINE=	APACHE LIGHTTPD

OPTIONS_RADIO=	HTTP
OPTIONS_RADIO_HTTP=	APACHE LIGHTTPD
OPTIONS_DEFAULTS=	APACHE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_scgi.so:www/mod_scgi
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:www/lighttpd
.endif

USE_PHP=	xmlrpc session mbstring
WANT_PHP_WEB=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's/import_request_variables("gp","r_")/extract(\$_REQUEST, EXTR_PREFIX_ALL|EXTR_REFS, "r")/' ${WRKSRC}/*.php
	@${FIND} ${WRKSRC} -name "*.bak"  -delete
	@${FIND} ${WRKSRC} -name "*.php~"  -delete

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -r ${WRKSRC}/* ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
