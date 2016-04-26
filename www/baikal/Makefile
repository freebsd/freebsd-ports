# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	baikal
PORTVERSION=	0.4.4
CATEGORIES=	www
MASTER_SITES=	https://github.com/fruux/Baikal/releases/download/${PORTVERSION}/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Lightweight CalDAV/CardDAV server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	zip
USE_PHP=	ctype filter xml xmlreader xmlwriter pdo_sqlite session mbstring dom

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
