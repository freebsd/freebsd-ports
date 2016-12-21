# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freebsd-doc
PORTVERSION=	49749
PORTEPOCH=	1
CATEGORIES=	misc docs
MASTER_SITES=	LOCAL/blackend
PKGNAMEPREFIX?=	en-

MAINTAINER=	doceng@FreeBSD.org
COMMENT?=	Documentation from the FreeBSD Documentation Project

BUILD_DEPENDS=	docproj>=2.0_6:textproc/docproj

USES=		uidfix
WRKSRC=		${WRKDIR}/doc
PLIST_SUB=	DOCSDIR=${DOCBASE} \
		DOCLANG=${DOCLANG} \
		DOCLANG_PREFIX=${DOCLANG_PREFIX}
MAKE_ARGS=	FORMATS="${DOCFORMAT}" \
		DOC_LANG="${DOCLANG}" \
		INSTALL_COMPRESSED= \
		DOCDIR=${STAGEDIR}${PREFIX}/${DOCBASE} \
		DOCOWN=${SHAREOWN} \
		DOCGRP=${SHAREGRP}
MAKE_JOBS_UNSAFE=	yes
NO_ARCH=	yes

# To populate correctly the stage directory
TMPDESTDIR=	${STAGEDIR}${DESTDIR}/${PREFIX}/${DOCBASE}
DESTDIRNAME=	TMPDESTDIR

PLIST=		${WRKDIR}/pkg-plist

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
OPTIONS_DEFAULT+=	${AVAILABLEFORMATS}
.endif

.include <bsd.port.options.mk>

.if defined(PACKAGE_BUILDING) && ${OSVERSION} < 1000000 && ${ARCH} == i386
IGNORE=	fails to build on the package builders in 9.x i386 jails due to java exceptions
.endif

.for O in ${AVAILABLEFORMATS}
.if ${PORT_OPTIONS:M${O}}
DOCFORMAT+=	${O:tl:S,_,-,}
PLIST_FORMATS+=	${O:tl:S,_,-,}
.endif
.endfor

.if ${PORT_OPTIONS:MPDF} || ${PORT_OPTIONS:MPS}
BUILD_DEPENDS+=	fop:textproc/fop \
		${LOCALBASE}/share/fonts/GentiumPlus/GentiumPlus-R.ttf:x11-fonts/gentium-plus \
		${LOCALBASE}/share/fonts/Droid/DroidSans.ttf:x11-fonts/droid-fonts-ttf \
		${LOCALBASE}/share/fonts/Lohit/Lohit-Bengali.ttf:x11-fonts/lohit \
		${LOCALBASE}/share/fonts/dejavu/DejaVuSansMono.ttf:x11-fonts/dejavu \
		${LOCALBASE}/share/fonts/TrueType/gkai00mp.ttf:chinese/arphicttf \
		${LOCALBASE}/share/fonts/OTF/ipam.otf:japanese/font-ipa \
		${LOCALBASE}/share/fonts/nanum-ttf/NanumBarunGothic.ttf:korean/nanumfonts-ttf
.endif

# when html or html-split is defined as the format, add HTML_COMMON.
.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MHTML_SPLIT}
PLIST_FORMATS+=	html-common
.endif

# example files, scripts, etc. coming with the doc and common
# directories for all formats.
PLIST_FORMATS+=	extras common

pre-build:
.for i in ${PLIST_FORMATS:S,^,${.CURDIR}/pkg-plist.,}
	if ${TEST} -f ${i}; then \
		${CAT} ${i} >> ${PLIST}; \
	fi
.endfor

# For HTML files, images links are hardcoded during the build
# with absolute pathnames.  Make these pathnames relative.
post-build:
.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MHTML_SPLIT}
	${FIND} ${WRKSRC} -name "*.html" -exec \
		${REINPLACE_CMD} -e 's,img src=\"${WRKSRC}.*share/images,img src=\"../..,g' {} \;
	${FIND} ${WRKSRC} -name "*.html" -exec \
		${REINPLACE_CMD} -e 's,img src=\"${WRKSRC}.*imagelib,img src=\"imagelib,g' {} \;
.endif

.include <bsd.port.mk>
