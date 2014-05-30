# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dalbum
PORTVERSION=	140.152
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.dalbum.org/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Free, highly customizable PHP photo album

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_PHP=	session pcre
NO_BUILD=	yes

DALBUM_DIR?=	www/photo
NO_WRKSUBDIR=	yes

PLIST_SUB+=	DALBUM_DIR=${DALBUM_DIR}
SUB_LIST+=	DALBUM_DIR=${DALBUM_DIR}
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} "s#%%LOCALBASE%%#${LOCALBASE}#" ${WRKSRC}/config/config.php
	@${RM} ${WRKSRC}/config/config.php.*

do-install:
	@${MKDIR} -m 0775 ${STAGEDIR}${PREFIX}/${DALBUM_DIR}
	@cd ${WRKSRC} && ${FIND} . -print | \
		${CPIO} --quiet -pdum -R ${WWWOWN}:${WWWGRP} \
		${STAGEDIR}${PREFIX}/${DALBUM_DIR}

.include <bsd.port.mk>
