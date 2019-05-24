# $FreeBSD$

PORTNAME=	phprecipebook
PORTVERSION=	3.01
PORTREVISION=	4
CATEGORIES=	www deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION:C/\..*//}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Small php webapp to manage your recipes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.TXT

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
USES=		php:web tar:tgz
USE_PHP=	xml
SUB_FILES=	pkg-message
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	PGSQL
OPTIONS_DEFAULT=	PGSQL

PGSQL_USE=	PHP=pgsql
PGSQL_USES=	pgsql

do-install:
	${MV} ${WRKSRC}/custom_inc.php ${WRKSRC}/custom_inc.php.sample
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
