# New ports collection makefile for:   gallery
# Date created:                09 Sep 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery
PORTVERSION=	1.4.4.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.2$/-pl2/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LANGPACKS}
DIST_SUBDIR=	gallery

MAINTAINER=	freebsd-ports@varju.ca
COMMENT=	Gallery is a slick web based photo album written using PHP

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		jhead:${PORTSDIR}/graphics/jhead \
		unzip:${PORTSDIR}/archivers/unzip

USE_PHP=	session
WANT_PHP_WEB=	yes

.if !defined(WITHOUT_NLS)
USE_PHP+=	gettext
LANGVERSION=	1.4.4
LANGPACKS=	af_ZA-${LANGVERSION}${EXTRACT_SUFX} \
		bg_BG-${LANGVERSION}${EXTRACT_SUFX} \
		ca_ES-${LANGVERSION}${EXTRACT_SUFX} \
		cs_CZ.iso-8859-2-${LANGVERSION}${EXTRACT_SUFX} \
		da_DK-${LANGVERSION}${EXTRACT_SUFX} \
		de_DE-${LANGVERSION}${EXTRACT_SUFX} \
		en_GB-${LANGVERSION}${EXTRACT_SUFX} \
		es_ES-${LANGVERSION}${EXTRACT_SUFX} \
		fi_FI-${LANGVERSION}${EXTRACT_SUFX} \
		fr_FR-${LANGVERSION}${EXTRACT_SUFX} \
		gl_ES-${LANGVERSION}${EXTRACT_SUFX} \
		he_IL.utf8-${LANGVERSION}${EXTRACT_SUFX} \
		hu_HU-${LANGVERSION}${EXTRACT_SUFX} \
		is_IS-${LANGVERSION}${EXTRACT_SUFX} \
		it_IT-${LANGVERSION}${EXTRACT_SUFX} \
		ja_JP-${LANGVERSION}${EXTRACT_SUFX} \
		ko_KR-${LANGVERSION}${EXTRACT_SUFX} \
		lt_LT-${LANGVERSION}${EXTRACT_SUFX} \
		nl_NL-${LANGVERSION}${EXTRACT_SUFX} \
		no_NO-${LANGVERSION}${EXTRACT_SUFX} \
		pl_PL-${LANGVERSION}${EXTRACT_SUFX} \
		pt_BR-${LANGVERSION}${EXTRACT_SUFX} \
		pt_PT-${LANGVERSION}${EXTRACT_SUFX} \
		ru_RU.cp1251-${LANGVERSION}${EXTRACT_SUFX} \
		ru_RU.koi8r-${LANGVERSION}${EXTRACT_SUFX} \
		sl_SI-${LANGVERSION}${EXTRACT_SUFX} \
		sv_SE-${LANGVERSION}${EXTRACT_SUFX} \
		tr_TR-${LANGVERSION}${EXTRACT_SUFX} \
		uk_UA-${LANGVERSION}${EXTRACT_SUFX} \
		vi_VN-${LANGVERSION}${EXTRACT_SUFX} \
		zh_CN-${LANGVERSION}${EXTRACT_SUFX} \
		zh_HK-${LANGVERSION}${EXTRACT_SUFX} \
		zh_HK.utf8-${LANGVERSION}${EXTRACT_SUFX} \
		zh_TW-${LANGVERSION}${EXTRACT_SUFX} \
		zh_TW.utf8-${LANGVERSION}${EXTRACT_SUFX}
PLIST_SUB=		NLS=""
.else
PLIST_SUB=		NLS="@comment "
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
DOCFILES=	AUTHORS ChangeLog README
EXCEPTFILES=	${DOCFILES} LICENSE.txt
CPIOARGS=	--quiet -pdum -R
PLIST_SUB+=	GALLERYDIR=${GALLERYDIR}

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
