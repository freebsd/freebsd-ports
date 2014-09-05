# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	yourls
DISTVERSION=	1.5.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Your Own URL Shortener

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USES=		zip:infozip
NO_BUILD=	YES

USE_PHP=	bcmath curl json mysql pcre xml

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message
PLIST_SUB=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
