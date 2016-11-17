# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythweb
PORTVERSION=	0.27.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	mythplugin-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend for scheduling and managing recordings on your MythTV Box

RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql

USE_GITHUB=	yes
GH_ACCOUNT=	MythTV

NO_BUILD=	yes
USES=		php shebangfix
USE_PHP=	spl session mysql pcre posix json

SHEBANG_FILES=	mythweb.pl modules/_shared/lang/build_translation.pl \
		modules/coverart/handler.pl modules/stream/*.pl

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
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} "! -name *.orig")

.include <bsd.port.mk>
