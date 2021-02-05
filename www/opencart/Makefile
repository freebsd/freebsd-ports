# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	opencart
PORTVERSION=	3.0.3.7
CATEGORIES=	www misc
MASTER_SITES=	https://github.com/opencart/opencart/releases/download/${PORTVERSION}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open source PHP-based online shopping cart system

LICENSE=	GPLv3

#USE_GITHUB=	yes
#GH_ACCOUNT=	opencart

USES=		php zip
USE_PHP=	filter mysqli curl mbstring gd zlib mcrypt session zip hash openssl
WRKSRC=		${WRKDIR}/upload

NO_BUILD=	yes
SUB_FILES=	pkg-message

post-patch:
	${MV} ${WRKSRC}/config-dist.php ${WRKSRC}/config.php
	${MV} ${WRKSRC}/admin/config-dist.php ${WRKSRC}/admin/config.php

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
