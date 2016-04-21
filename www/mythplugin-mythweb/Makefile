# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythweb
PORTVERSION=	0.27.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	mythplugin-

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Frontend for scheduling and managing recordings on your MythTV Box

BROKEN_powerpc64=	Does not build

RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql

USE_GITHUB=	yes
GH_ACCOUNT=	MythTV

NO_BUILD=	yes
USE_PHP=	spl session mysql pcre posix json
SUB_FILES=	pkg-message
REINPLACE_ARGS=	-i ""
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	APACHE LIGHTTPD
OPTIONS_DEFAULT=	APACHE

LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd

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
	${CHMOD} -R 775 ${STAGEDIR}${WWWDIR}/data

.include <bsd.port.mk>
