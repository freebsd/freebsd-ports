# New ports collection makefile for:   gallery
# Date created:                09 Sep 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery
PORTVERSION=	1.5.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LANGPACKS}
DIST_SUBDIR=	gallery

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A slick web based photo album written using PHP

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		jhead:${PORTSDIR}/graphics/jhead \
		unzip:${PORTSDIR}/archivers/unzip

USE_PHP=	pcre session
WANT_PHP_WEB=	yes

.if !defined(WITHOUT_NLS)
USE_PHP+=	gettext
USE_GETTEXT=	yes	# Pet portlint

LANGPACKS=	af_ZA-1.5.2${EXTRACT_SUFX} \
		ar_EG-1.5.1-cvs${EXTRACT_SUFX} \
		bg_BG-1.5.4${EXTRACT_SUFX} \
		ca_ES-1.5${EXTRACT_SUFX} \
		cs_CZ.cp1250-1.5.1${EXTRACT_SUFX} \
		cs_CZ.iso-8859-2-1.5.6${EXTRACT_SUFX} \
		da_DK-1.5.9${EXTRACT_SUFX} \
		de_DE-1.5.9${EXTRACT_SUFX} \
		en_GB-1.5-RC2${EXTRACT_SUFX} \
		es_ES-1.5.2${EXTRACT_SUFX} \
		fi_FI-1.5.2${EXTRACT_SUFX} \
		fr_FR-1.5.9${EXTRACT_SUFX} \
		gl_ES-1.5.1${EXTRACT_SUFX} \
		hu_HU-1.5.1${EXTRACT_SUFX} \
		is_IS-1.5.2${EXTRACT_SUFX} \
		it_IT-1.5.2${EXTRACT_SUFX} \
		ja_JP-1.5.2${EXTRACT_SUFX} \
		ja_JP.utf8-1.5.1${EXTRACT_SUFX} \
		ko_KR-1.5.2${EXTRACT_SUFX} \
		lt_LT-1.5.1${EXTRACT_SUFX} \
		nl_NL-1.5.2${EXTRACT_SUFX} \
		no_NO-1.5.2${EXTRACT_SUFX} \
		pl_PL-1.5.2${EXTRACT_SUFX} \
		pt_BR-1.5.4${EXTRACT_SUFX} \
		pt_PT-1.5.1${EXTRACT_SUFX} \
		ru_RU.cp1251-1.5.2${EXTRACT_SUFX} \
		ru_RU.koi8r-1.5.1${EXTRACT_SUFX} \
		sk_SK-1.5.1${EXTRACT_SUFX} \
		sl_SI-1.5.1${EXTRACT_SUFX} \
		sv_SE-1.5.6${EXTRACT_SUFX} \
		tr_TR-1.5.1-u1${EXTRACT_SUFX} \
		vi_VN-1.5.1${EXTRACT_SUFX} \
		zh_HK-1.5.2${EXTRACT_SUFX} \
		zh_HK.utf8-1.5.2${EXTRACT_SUFX} \
		zh_TW-1.5.2${EXTRACT_SUFX} \
		zh_TW.utf8-1.5.2${EXTRACT_SUFX}
PLIST_SUB=		NLS=""
.else
PLIST_SUB=		NLS="@comment "
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
PORTDOCS=	AUTHORS ChangeLog README
EXCEPTFILES=	${PORTDOCS} LICENSE.txt
CPIOARGS=	--quiet -pdum -R

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

pre-everything::
.if defined(GALLERYDIR)
WWWDIR=	${GALLERYDIR}
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define GALLERYDIR to override default of ${WWWDIR}."
	@${ECHO_MSG} ""
.endif

do-extract:
	@ ${INSTALL} -d ${WRKDIR}
	@ cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}
	@ for i in ${LANGPACKS}; do \
		if ! (cd ${WRKSRC}/locale && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/$$i ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi \
	done

do-install:
	@ ${INSTALL} -d -m 0755 ${WWWDIR}
	@ cd ${WRKSRC} && ${FIND} * -name \*.bat -o -name \*.orig -o -name \*Changelog ${EXCEPTFILES:S/^/-o -name /} \
	  -o -print | ${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
.if !defined(NOPORTDOCS)
	@ ${INSTALL} -d ${DOCSDIR}
	@ cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
