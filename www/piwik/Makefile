# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	piwik
PORTVERSION=	3.2.1
CATEGORIES=	www
MASTER_SITES=	http://builds.piwik.org/

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Open Source Web Analytics Software Program

LICENSE=	GPLv3

NO_BUILD=	yes
SUB_FILES=	pkg-message
USE_PHP=	ctype dom gd filter hash iconv json session xml zlib \
		mbstring simplexml
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	PHPPDOMYSQL PHPMYSQLI
OPTIONS_DEFAULT=	PHPPDOMYSQL
PHPPDOMYSQL_DESC=	Use pdo_mysql php module
PHPPDOMYSQL_USE=	PHP=pdo_mysql
PHPMYSQLI_DESC=	Use mysqli php module
PHPMYSQLI_USE=	PHP=mysqli

PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

USES=		cpe shebangfix php
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
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
