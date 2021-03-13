# Created by: Juraj Lutter <otis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osticket
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.2
CATEGORIES=	www
MASTER_SITES=	https://github.com/osTicket/osTicket/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	osTicket-v${DISTVERSION}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Widely-used open source support ticket system

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}

USES=		php:web zip
USE_PHP=	gd gettext imap json mbstring mysqli xml
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
