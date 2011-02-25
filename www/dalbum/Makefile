# New ports collection makefile for:	dalbum
# Date created:				21 October 2005
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

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

PLIST_SUB+=	DALBUM_DIR=${DALBUM_DIR}
SUB_LIST+=	DALBUM_DIR=${DALBUM_DIR}
SUB_FILES=	pkg-message

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} -p ${WRKSRC}
	@if ! (cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTFILES} ${EXTRACT_AFTER_ARGS});\
	then \
		exit 1; \
	fi

post-patch:
	@${REINPLACE_CMD} "s#%%LOCALBASE%%#${LOCALBASE}#" ${WRKSRC}/config/config.php
	@${RM} ${WRKSRC}/config/config.php.*

do-install:
	@${MKDIR} -m 0775 ${PREFIX}/${DALBUM_DIR}
	@cd ${WRKSRC} && ${FIND} . -print | ${CPIO} --quiet -pdum -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DALBUM_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
