PORTNAME=	baikal
PORTVERSION=	0.9.5
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	https://github.com/fruux/Baikal/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Lightweight CalDAV/CardDAV server
WWW=		https://sabre.io/baikal/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:web,flavors zip
USE_PHP=	ctype dom filter imap mbstring pdo_sqlite \
		session xml xmlreader xmlwriter

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
