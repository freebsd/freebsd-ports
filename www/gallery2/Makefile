# New ports collection makefile for:   gallery2
# Date created:                29 Aug 2005
# Whom:                        Alex Varju <freebsd-ports@varju.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery2
PORTVERSION=	2.0.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gallery
DISTNAME=	gallery-2.0.1-full
DIST_SUBDIR=	gallery2

MAINTAINER=	freebsd-ports@varju.ca
COMMENT=	Gallery is a web based photo album written using PHP

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		jhead:${PORTSDIR}/graphics/jhead \
		unzip:${PORTSDIR}/archivers/unzip \
		convert:${PORTSDIR}/graphics/ImageMagick

USE_PHP=	pcre session mysql
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${DIST_SUBDIR}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum -R
PLIST_SUB+=	GALLERY2DIR=${GALLERY2DIR}

pre-fetch:
.if !defined(GALLERY2DIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define GALLERY2DIR to override default of '${GALLERY2DIR}'."
	@${ECHO_MSG} ""
.endif

GALLERY2DIR?=	www/data/gallery2
WWWOWN?=	www
WWWGRP?=	www

post-configure:
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' \
	  -e 's#%%GALLERY2DIR%%#${GALLERY2DIR}#g' pkg-message > ${PKGMESSAGE}

do-install:
	@ ${MKDIR} -m 0755 ${PREFIX}/${GALLERY2DIR}
	@ cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${PREFIX}/${GALLERY2DIR}
	@ ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${GALLERY2DIR}

post-install:
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
