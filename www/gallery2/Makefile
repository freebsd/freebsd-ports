# New ports collection makefile for:   gallery
# Date created:                09 Sep 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery
PORTVERSION=	1.4.1.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1$/-pl1/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LANGPACKS}
DIST_SUBDIR=	gallery

MAINTAINER=	varju@webct.com
COMMENT=	Gallery is a slick web based photo album written using PHP

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		jhead:${PORTSDIR}/graphics/jhead \
		unzip:${PORTSDIR}/archivers/unzip

LANGVERSION=	1.4.1
LANGPACKS=	af_ZA-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		bg_BG-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		cs_CZ.cp1250-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		da_DK-pack-${LANGVERSION}${EXTRACT_SUFX} \
		de_DE-pack-${LANGVERSION}-u2${EXTRACT_SUFX} \
		de_DE.du-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		en_GB-pack-${LANGVERSION}${EXTRACT_SUFX} \
		es_ES-pack-${LANGVERSION}-u2${EXTRACT_SUFX} \
		fi_FI-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		fr_FR-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		he_IL-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		hu_HU-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		is_IS-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		it_IT-pack-${LANGVERSION}${EXTRACT_SUFX} \
		ja_JP-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		ko_KR-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		lt_LT-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		nl_NL-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		no_NO-pack-${LANGVERSION}${EXTRACT_SUFX} \
		pl_PL-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		pt_BR-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		pt_PT-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		ru_RU.koi8r-pack-${LANGVERSION}${EXTRACT_SUFX} \
		sl_SI-pack-${LANGVERSION}${EXTRACT_SUFX} \
		sv_SE-pack-${LANGVERSION}-u2${EXTRACT_SUFX} \
		tr_TR-pack-${LANGVERSION}${EXTRACT_SUFX} \
		uk_UA-pack-${LANGVERSION}${EXTRACT_SUFX} \
		vi_VN-pack-${LANGVERSION}-u2${EXTRACT_SUFX} \
		zh_CN-pack-${LANGVERSION}${EXTRACT_SUFX} \
		zh_TW-pack-${LANGVERSION}-u1${EXTRACT_SUFX} \
		zh_TW.utf8-pack-${LANGVERSION}${EXTRACT_SUFX}

USE_PHP=	yes
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
DOCFILES=	AUTHORS ChangeLog README RELEASE_NOTES
EXCEPTFILES=	${DOCFILES} LICENSE.txt
CPIOARGS=	--quiet -pdum -R
PLIST_SUB=	GALLERYDIR=${GALLERYDIR}

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
	@ for i in ${LANGPACKS}; do \
		if ! (cd ${WRKDIR}/gallery/locale && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$i ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi \
	done

do-install:
	@ ${MKDIR} -m 0755 ${PREFIX}/${GALLERYDIR}
	@ cd ${WRKSRC} && ${FIND} * -name \*.bat -o -name \*.orig -o -name \*Changelog ${EXCEPTFILES:S/^/-o -name /} \
	  -o -print | ${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${PREFIX}/${GALLERYDIR}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
