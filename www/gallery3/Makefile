# New ports collection makefile for:   gallery
# Date created:                09 Sep 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery
PORTVERSION=	1.4.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LANGPACKS}
DIST_SUBDIR=	gallery

MAINTAINER=	varju@webct.com
COMMENT=	Gallery is a slick web based photo album written using PHP

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		jhead:${PORTSDIR}/graphics/jhead \
		unzip:${PORTSDIR}/archivers/unzip

LANGPACKS=	af_ZA-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		bg_BG-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		cs_CZ.cp1250-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		da_DK-pack-${PORTVERSION}${EXTRACT_SUFX} \
		de_DE-pack-${PORTVERSION}-u2${EXTRACT_SUFX} \
		de_DE.du-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		en_GB-pack-${PORTVERSION}${EXTRACT_SUFX} \
		es_ES-pack-${PORTVERSION}-u2${EXTRACT_SUFX} \
		fi_FI-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		fr_FR-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		he_IL-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		hu_HU-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		is_IS-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		it_IT-pack-${PORTVERSION}${EXTRACT_SUFX} \
		ja_JP-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		ko_KR-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		lt_LT-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		nl_NL-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		no_NO-pack-${PORTVERSION}${EXTRACT_SUFX} \
		pl_PL-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		pt_BR-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		pt_PT-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		ru_RU.koi8r-pack-${PORTVERSION}${EXTRACT_SUFX} \
		sl_SI-pack-${PORTVERSION}${EXTRACT_SUFX} \
		sv_SE-pack-${PORTVERSION}-u2${EXTRACT_SUFX} \
		tr_TR-pack-${PORTVERSION}${EXTRACT_SUFX} \
		uk_UA-pack-${PORTVERSION}${EXTRACT_SUFX} \
		vi_VN-pack-${PORTVERSION}-u2${EXTRACT_SUFX} \
		zh_CN-pack-${PORTVERSION}${EXTRACT_SUFX} \
		zh_TW-pack-${PORTVERSION}-u1${EXTRACT_SUFX} \
		zh_TW.utf8-pack-${PORTVERSION}${EXTRACT_SUFX}

WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
DOCFILES=	AUTHORS ChangeLog README RELEASE_NOTES
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

do-extract:
	@ ${MKDIR} ${WRKDIR}
	@ cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}
	@ for file in ${LANGPACKS}; do \
		if ! (cd ${WRKDIR}/gallery/locale && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi \
	done

do-install:
	@ ${MKDIR} -m 0755 ${PREFIX}/${GALLERYDIR}
	@ cd ${WRKSRC} && ${FIND} * -name \*.bat -o -name \*.orig -o -name \*Changelog ${EXCEPTFILES:S/^/-o -name /} \
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
