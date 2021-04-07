PORTNAME=	matomo
DISTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://builds.matomo.org/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	piwik-${DISTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Open Source Web Analytics Software Program

LICENSE=	GPLv3

USES=		cpe shebangfix php:flavors

NO_BUILD=	yes
SUB_FILES=	pkg-message

USE_PHP=	ctype curl dom fileinfo filter gd hash iconv intl json \
		mbstring mcrypt memcache mysqli openssl pcre pdo posix readline session \
		simplexml soap sockets sqlite3 tidy tokenizer xml opcache zlib
NO_ARCH=yes

WRKSRC=		${WRKDIR}/piwik

OPTIONS_DEFINE=	PHPPDOMYSQL PHPMYSQLI
OPTIONS_DEFAULT=	PHPPDOMYSQL
PHPPDOMYSQL_DESC=	Use pdo_mysql php module
PHPPDOMYSQL_USE=	PHP=pdo_mysql
PHPMYSQLI_DESC=	Use mysqli php module
PHPMYSQLI_USE=	PHP=mysqli

PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

SHEBANG_FILES=	misc/log-analytics/import_logs.py

pre-install:
	@if [ ! -f ${LOCALBASE}/bin/php ]; then \
		echo " It seems you installed php without CLI enabled. "; \
		echo " This will cause problems when using piwik. "; \
		echo " If you want to reconsider, press Ctrl-C now to cancel. "; \
		echo " Then reinstall php with CLI enabled. "; \
		sleep 3; \
	fi

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/cache/tracker
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
