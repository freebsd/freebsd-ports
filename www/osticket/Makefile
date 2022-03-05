PORTNAME=	osticket
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.1
CATEGORIES=	www
MASTER_SITES=	https://github.com/osTicket/osTicket/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	osTicket-v${DISTVERSION}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Widely-used open source support ticket system

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}

USES=		cpe php:web zip
CPE_VENDOR=	enhancesoft
USE_PHP=	curl dom fileinfo filter gd gettext iconv imap intl json \
		mbstring mysqli opcache phar session xml zip
IGNORE_WITH_PHP=	74 81
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	WWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

WRKSRC=		${WRKDIR}/upload

PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/
	${MV} ${STAGEDIR}${WWWDIR}/include/ost-sampleconfig.php \
	  ${STAGEDIR}${WWWDIR}/include/ost-config.php.sample

.include <bsd.port.mk>
