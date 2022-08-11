PORTNAME=	xoops
PORTVERSION=	2.5.10
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/XOOPS%20Core%20%28stable%20releases%29/XOOPS_${PORTVERSION}
DISTNAME=	XoopsCore25-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Dynamic Web CMS

LICENSE=	GPLv2

USE_PHP=	mysqli filter mbstring iconv xml zlib gd exif

USES=		cpe php
NO_BUILD=	yes
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
.for d in docs extras htdocs
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${WWWDIR}
.endfor

.include <bsd.port.mk>
