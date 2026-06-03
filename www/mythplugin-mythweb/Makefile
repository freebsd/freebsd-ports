PORTNAME=	mythweb
DISTVERSIONPREFIX=	v
DISTVERSION=	34.0
DISTVERSIONSUFFIX=	-g92f0f9bc
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	mythplugin-

MAINTAINER=	ahicks@p-o.co.uk
COMMENT=	Frontend for scheduling and managing recordings on your MythTV Box
WWW=		https://www.mythtv.org/wiki/MythWeb

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	mythweb is no longer maintained in MythTV
USES=		php shebangfix perl5
USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
USE_PERL5=	run
USE_PHP=	posix mysqli session sockets
SHEBANG_FILES=	mythweb.pl modules/_shared/lang/build_translation.pl \
		modules/coverart/handler.pl modules/stream/*.pl

REINPLACE_ARGS=	-i ""
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	APACHE LIGHTTPD NGINX
OPTIONS_DEFAULT=	APACHE

NGINX_DESC=		Nginx server support
APACHE_USES=		apache
LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd
NGINX_RUN_DEPENDS=	nginx:www/nginx

post-patch:
	@${REINPLACE_CMD} -e 's|/var/www/html|${WWWDIR}|' \
		${WRKSRC}/mythweb.conf.apache
	@${REINPLACE_CMD} -e 's|/usr/bin/php-cgi|${LOCALBASE}/bin/php-cgi|' \
		${WRKSRC}/mythweb.conf.lighttpd

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
		"! -name *.orig -and ! -name LICENSE")

.include <bsd.port.mk>
