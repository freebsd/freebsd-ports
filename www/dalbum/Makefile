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

RUN_DEPENDS=	convert:graphics/ImageMagick

USES=		cpe
CPE_VERSION=	${PORTVERSION:C/^([0-9])([0-9][0-9]).*/\1.\2/}
CPE_UPDATE=	${PORTVERSION:C/^.*\.//}
USE_PHP=	session pcre
NO_BUILD=	yes
NO_ARCH=	yes

DALBUM_DIR?=	www/photo
NO_WRKSUBDIR=	yes

PLIST_SUB+=	DALBUM_DIR=${DALBUM_DIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST+=	DALBUM_DIR=${DALBUM_DIR}
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} "s#%%LOCALBASE%%#${LOCALBASE}#" ${WRKSRC}/config/config.php
	@${RM} ${WRKSRC}/config/config.php.*

do-install:
	@${MKDIR} -m 0775 ${STAGEDIR}${PREFIX}/${DALBUM_DIR}
	@cd ${WRKSRC} && ${FIND} .htaccess .private config images include pictures *.css *.js *.php *.txt -print | \
		${CPIO} --quiet -pdum \
		${STAGEDIR}${PREFIX}/${DALBUM_DIR}

.include <bsd.port.mk>
