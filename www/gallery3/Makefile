# New ports collection makefile for:   gallery
# Date created:                09 Sep 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery
PORTVERSION=	1.4.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.[0-9]\.([0-9]+)$/-pl\1/}

MAINTAINER=	jamie@hermans.ca
COMMENT=	Gallery is a slick web based photo album written using PHP

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		jhead:${PORTSDIR}/graphics/jhead \
		unzip:${PORTSDIR}/archivers/unzip

WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
DOCFILES=	AUTHORS ChangeLog README UPGRADING
EXCEPTFILES=	${DOCFILES} LICENSE.txt
CPIO=		cpio --quiet -pdum -R
PLIST_SUB=	GALLERYDIR=${GALLERYDIR}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/php4/bsd.php.mk"

pre-fetch:
.if !defined(GALLERYDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define GALLERYDIR to override default of 'www/data/gallery'."
	@${ECHO_MSG} ""
.endif

GALLERYDIR?=	www/data/gallery
WWWOWN?=	www
WWWGRP?=	www

post-configure:
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' \
	  -e 's#%%GALLERYDIR%%#${GALLERYDIR}#g' pkg-message > ${PKGMESSAGE}

do-install:
	@ ${MKDIR} -m 0755 ${PREFIX}/${GALLERYDIR}
	@ cd ${WRKSRC} && ${FIND} * -name \*.bat ${EXCEPTFILES:S/^/-o -name /} \
	  -o -print | ${CPIO} ${WWWOWN}:${WWWGRP} ${PREFIX}/${GALLERYDIR}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
