# New ports collection makefile for:   zenphoto
# Date created:                27 December 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
#
# $FreeBSD$
#

PORTNAME=	zenphoto
PORTVERSION=	1.4.0.3
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

do-install:
	${MKDIR} ${WWWDIR}
	@${RM} ${WRKSRC}/doc_files/License.txt \
		${WRKSRC}/doc_files/README.html \
		${WRKSRC}/zp-core/Zenphoto.package
	@${TOUCH} ${WRKSRC}/uploaded/.keepme
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} 644 ${WWWDIR}/zp-core/images/*

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
