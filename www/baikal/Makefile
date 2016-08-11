# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	baikal
PORTVERSION=	0.4.5
CATEGORIES=	www
MASTER_SITES=	https://github.com/fruux/Baikal/releases/download/${PORTVERSION}/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Lightweight CalDAV/CardDAV server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	zip
USE_PHP=	ctype dom filter mbstring openssl pdo_sqlite session xml xmlreader xmlwriter

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
