PORTNAME=	matomo
PORTVERSION=	5.7.1
CATEGORIES=	www
MASTER_SITES=	http://builds.matomo.org/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	marko.cupac@mimar.rs
COMMENT=	Open Source Web Analytics Software Program
WWW=		https://www.matomo.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe shebangfix php:flavors
USE_PHP=	ctype curl dom fileinfo filter gd iconv intl mbstring mcrypt \
		memcache mysqli opcache pdo pdo_mysql posix readline session \
		simplexml soap sockets sqlite3 tidy tokenizer xml zlib

SHEBANG_FILES=	misc/log-analytics/import_logs.py
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=		PHPMYSQLI PHPPDOMYSQL
OPTIONS_DEFAULT=	PHPPDOMYSQL
PHPMYSQLI_DESC=		Use mysqli php module
PHPPDOMYSQL_DESC=	Use pdo_mysql php module
PHPMYSQLI_USE=		PHP=mysqli
PHPPDOMYSQL_USE=	PHP=pdo_mysql

pre-install:
	@if [ ! -f ${LOCALBASE}/bin/php ]; then \
		echo " It seems you installed PHP without CLI enabled. "; \
		echo " This will cause problems when using Matomo. "; \
		echo " If you want to reconsider, press Ctrl-C now to cancel. "; \
		echo " Then reinstall PHP with CLI enabled. "; \
		sleep 3; \
	fi

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
