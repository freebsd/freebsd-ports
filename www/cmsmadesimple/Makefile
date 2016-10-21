# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	cmsmadesimple
PORTVERSION=	1.12
CATEGORIES=	www
MASTER_SITES=	http://s3.amazonaws.com/cmsms/downloads/12553/
DISTNAME=	${PORTNAME}-${PORTVERSION}-full

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Simple Open Source CMS

LICENSE=	GPLv2

USE_PHP=	mysql tokenizer gd

NO_BUILD=	yes
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}
CMS_DIRS=	admin doc install lib \
		modules plugins tmp uploads
CMS_FILES=	favicon_cms.ico fileloc.php include.php \
		index.php moduleinterface.php \
		version.php
WRITABLE_DIRS=	tmp tmp/templates_c tmp/cache \
		uploads uploads/images modules

post-extract:
	cd ${WRKSRC} && ${RM} config.php

do-install:
.for i in ${CMS_DIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${WWWDIR}
.endfor
.for i in ${CMS_FILES}
	cd ${WRKSRC} && ${CP} ${i} ${STAGEDIR}${WWWDIR}/${i}
.endfor

	if [ ! -f ${STAGEDIR}${WWWDIR}/config.php ]; then \
	${TOUCH} ${STAGEDIR}${WWWDIR}/config.php ; fi

.include <bsd.port.mk>
