# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	opencart
PORTVERSION=	2.2.0.0
PORTREVISION=	1
CATEGORIES=	www misc

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open source PHP-based online shopping cart system

LICENSE=	GPLv3

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_ACCOUNT=	opencart

USE_PHP=	filter mysqli curl mbstring gd zlib mcrypt session zip hash
WRKSRC_SUBDIR=	upload

NO_BUILD=	yes
SUB_FILES=	pkg-message

post-patch:
	${MV} ${WRKSRC}/config-dist.php ${WRKSRC}/config.php
	${MV} ${WRKSRC}/admin/config-dist.php ${WRKSRC}/admin/config.php

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
