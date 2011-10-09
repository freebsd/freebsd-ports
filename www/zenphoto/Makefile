# New ports collection makefile for:   zenphoto
# Date created:                27 December 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
#
# $FreeBSD$
#

PORTNAME=	zenphoto
PORTVERSION=	1.4.1.4
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE \
		http://www.zenphoto.org/files/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A simpler web photo gallery

LICENSE=	GPLv2

NO_BUILD=	yes
USE_PHP=	gd gettext json mbstring mysql pcre session
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME}

post-extract:
	@${RM} ${WRKSRC}/doc_files/License.txt ${WRKSRC}/doc_files/README.html ${WRKSRC}/zp-core/Zenphoto.package
.for i in albums cache cache_html/rss plugins/flag_thumbnail plugins/flvplayer plugins/gd_fonts plugins/imagick_fonts \
	plugins/watermarks uploaded zp-core/zp-extensions/tiny_mce/plugins/ajaxfilemanager/jscripts/edit_area/plugins zp-data
	@${TOUCH} ${WRKSRC}/${i}/.keepme
.endfor

do-install:
	${MKDIR} ${WWWDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${WWWDIR}/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
