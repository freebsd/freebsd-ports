# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythweb
PORTVERSION=	0.27
CATEGORIES=	www
PKGNAMEPREFIX=	mythplugin-
DISTNAME=	mythweb-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A frontend for scheduling and managing recordings on your MythTV Box

RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql

USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
GH_PROJECT=	mythweb
GH_TAGNAME=	v${PORTVERSION}

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-b1df7d2

NO_BUILD=	yes
USE_PHP=	spl session mysql pcre posix json
SUB_FILES=	pkg-message
REINPLACE_ARGS=	-i ""

OPTIONS_DEFINE=	APACHE LIGHTTPD
OPTIONS_DEFAULT=	APACHE

LIGHTTPD_RUN_DEPENDS=	lighttpd:${PORTSDIR}/www/lighttpd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/var/www/html|${WWWDIR}|' \
		${WRKSRC}/mythweb.conf.apache
	@${REINPLACE_CMD} -e 's|/usr/bin/php-cgi|${LOCALBASE}/bin/php-cgi|' \
		${WRKSRC}/mythweb.conf.lighttpd

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/data
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} "! -name *.orig")

	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	${CHMOD} -R 775 ${STAGEDIR}${WWWDIR}/data

.include <bsd.port.mk>
