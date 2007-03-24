# New ports collection makefile for:	hastymail
# Date created:		2006-11-04
# Whom:			Bartlomiej Rutkowski <r@robakdesign.com>
#
# $FreeBSD$
#

PORTNAME=		hastymail
PORTVERSION=		1.5
PORTREVISION=		1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	hastymail

MAINTAINER=	r@robakdesign.com
COMMENT=	Small, fast and secure yet powerful IMAP webmail

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
SUB_FILES=	pkg-message

INSTALL_DIR?=	www/${PORTNAME}
PLIST=		${WRKDIR}/pkg-plist

WANT_PHP_WEB=	yes
USE_PHP=	session imap

.include <bsd.port.pre.mk>

pre-install:
		@${FIND} -s -d ${WRKSRC}/ -type f | ${SED} "s?${WRKSRC}?${INSTALL_DIR}?g" >${PLIST}
		@${FIND} -s -d ${WRKSRC}/ -type d  | ${SED} "s?${WRKSRC}?@dirrm ${INSTALL_DIR}?g" >> ${PLIST}

do-install:
		@${MKDIR} ${PREFIX}/${INSTALL_DIR}
		@cd ${WRKSRC} && ${FIND} . | ${PAX} -rw ${PREFIX}/${INSTALL_DIR}
		@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${INSTALL_DIR}

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
