# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythweb
PORTVERSION=	0.28.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	mythplugin-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend for scheduling and managing recordings on your MythTV Box

LICENSE=	GPLv2

IGNORE_WITH_PHP=	70 71 72

RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql

USE_GITHUB=	yes
GH_ACCOUNT=	MythTV

USES=		php shebangfix
USE_PHP=	spl session mysql pcre posix json
SHEBANG_FILES=	mythweb.pl modules/_shared/lang/build_translation.pl \
		modules/coverart/handler.pl modules/stream/*.pl
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message
REINPLACE_ARGS=	-i ""
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	APACHE LIGHTTPD
OPTIONS_DEFAULT=	APACHE

LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd
APACHE_USE=	APACHE_RUN=22+

post-patch:
	@${REINPLACE_CMD} -e 's|/var/www/html|${WWWDIR}|' \
		${WRKSRC}/mythweb.conf.apache
	@${REINPLACE_CMD} -e 's|/usr/bin/php-cgi|${LOCALBASE}/bin/php-cgi|' \
		${WRKSRC}/mythweb.conf.lighttpd

do-install:
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} "! -name *.orig")

.include <bsd.port.mk>
