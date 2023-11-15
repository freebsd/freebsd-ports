PORTNAME=	rss-bridge
DISTVERSION=	2023-09-24
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	osidorkin@gmail.com
COMMENT=	RSS feed generator for websites missing it
WWW=		https://github.com/RSS-Bridge/rss-bridge

LICENSE=	UNLICENSE

USES=		php:web
USE_GITHUB=	yes
GH_ACCOUNT=	RSS-Bridge
USE_PHP=	curl mbstring simplexml zip

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	SQLITE
OPTIONS_DEFAULT=SQLITE
OPTIONS_SUB=	yes

SQLITE_DESC=	Enable sqlite-based cache support (requires sqlite)

SQLITE_USE=	PHP=sqlite3

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "." ${STAGEDIR}${WWWDIR} "-not ( \
	    -name .git-blame-ignore-revs -or -name CONTRIBUTORS.md \
	    -or -name README.md -or -name LICENSE -or -name LICENSE.txt \
	    -or -name UNLICENSE -or -name app.json -or -name composer.json \
	    -or -name composer.lock -or -name docker-bake.hcl \
	    -or -name docker-entrypoint.sh \
	    -or -path ./config -or -path ./config/nginx.conf \
	    -or -path ./config/php-fpm.conf -or -path ./config/php.ini \
	    -or -regex ./.devcontainer.* -or -regex ./contrib.* \
	    -or -regex ./doc.* -or -regex ./static/screenshot_.* \
	    -or -regex ./static/screenshot-.* ) \
	    -or -name config.default.ini.php" )

.include <bsd.port.mk>
