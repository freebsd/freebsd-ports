# Created by: babak@farrokhi.net
# $FreeBSD$

PORTNAME=	textpattern
PORTVERSION=	4.6.2
CATEGORIES=	www
MASTER_SITES=	http://textpattern.com/file_download/110/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, flexible, elegant, easy-to-use content management system

EXPIRATION_DATE=	2018-03-07
DEPRECATED=	Unmaintained, all www files wrongly belongs to www user.

LICENSE=	GPLv2

IGNORE_WITH_PHP=	70 71 72

USES=		cpe php:web
USE_PHP=	json mbstring mysql pcre xml zlib
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_SUB=	WWWOWN="${WWWOWN}" \
		WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

do-install:
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
