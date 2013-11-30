# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freebsd-doc
PORTVERSION=	43251
PORTEPOCH=	1
CATEGORIES=	misc docs
MASTER_SITES=	LOCAL/blackend
PKGNAMEPREFIX?=	en-

MAINTAINER=	doceng@FreeBSD.org
COMMENT?=	Documentation from the FreeBSD Documentation Project

BUILD_DEPENDS=	docproj>=2.0_1:${PORTSDIR}/textproc/docproj \
		fop:${PORTSDIR}/textproc/fop \
		${LOCALBASE}/lib/X11/fonts/GentiumPlus/GentiumPlus-R.ttf:${PORTSDIR}/x11-fonts/gentium-plus \
		${LOCALBASE}/lib/X11/fonts/Droid/DroidSans.ttf:${PORTSDIR}/x11-fonts/droid-fonts-ttf \
		${LOCALBASE}/lib/X11/fonts/Lohit/Lohit-Bengali.ttf:${PORTSDIR}/x11-fonts/lohit \
		${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSansMono.ttf:${PORTSDIR}/x11-fonts/dejavu \
		${LOCALBASE}/share/fonts/TrueType/gkai00mp.ttf:${PORTSDIR}/chinese/arphicttf \
		${LOCALBASE}/share/fonts/OTF/ipam.otf:${PORTSDIR}/japanese/font-ipa

WRKSRC=		${WRKDIR}/doc
PLIST_SUB=	DOCSDIR=${DOCBASE} \
		DOCLANG=${DOCLANG} \
		DOCLANG_PREFIX=${DOCLANG_PREFIX}
MAKE_ARGS=	FORMATS="${DOCFORMAT}" \
		DOC_LANG="${DOCLANG}" \
		INSTALL_COMPRESSED= \
		DOCDIR=${PREFIX}/${DOCBASE} \
		DOCOWN=${SHAREOWN} \
		DOCGRP=${SHAREGRP}
MAKE_JOBS_UNSAFE=	yes
PLIST=		${WRKDIR}/pkg-plist
NO_STAGE=	yes

DOCLANG?=		en_US.ISO8859-1
DOCLANG_PREFIX?=	${DOCLANG:C/_.*$//}
DOCBASE?=		share/doc/freebsd

AVAILABLEFORMATS=	HTML HTML_SPLIT PDF PS TXT

OPTIONS_DEFINE=		${AVAILABLEFORMATS}
OPTIONS_DEFAULT=	HTML_SPLIT PDF
HTML_DESC=		Single HTML file per document
HTML_SPLIT_DESC=	The default HTML format used on www.FreeBSD.org
PDF_DESC=		PDF format
PS_DESC=		PostScript format
TXT_DESC=		Plain text

# if PACKAGE_BUILDING=yes, enable all of $AVAILABLEFORMATS.
.if defined(PACKAGE_BUILDING)
OPTIONS_SET+=	${AVAILABLEFORMATS}
.endif

.include <bsd.port.options.mk>

.for O in ${AVAILABLEFORMATS}
.if ${PORT_OPTIONS:M${O}}
DOCFORMAT+=	${O:L:S,_,-,}
PLIST_FORMATS+=	${O:L:S,_,-,}
.endif
.endfor

# when html or html-split is defined as the format, add HTML_COMMON.
.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MHTML_SPLIT}
PLIST_FORMATS+=	html-common
.endif

# example files, scripts, etc. coming with the doc and common
# directories for all formats.
PLIST_FORMATS+=	extras common

pre-build:
	${CAT} ${PLIST_FORMATS:S,^,${.CURDIR}/pkg-plist.,} > ${PLIST}

.include <bsd.port.mk>
