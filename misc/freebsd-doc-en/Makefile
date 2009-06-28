# New ports collection makefile for:	freebsd-doc-en
# Date created:		13 August 2008
# Whom:			Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#
# Several knobs can be used to select the documentation formats.
#
# WITH_HTML_SPLIT allows the build of the "html-split" format:
# This is the default format, it is the same format used on
# www.FreeBSD.org.  It is a collection of small, linked HTML files
# (index.html, plus images and secondary files).
#
# WITH_HTML allows the build of the "html" format:
# a single HTML file per document (article.html or book.html, as
# appropriate, plus images).
#
# WITH_PDF allows the build of the "pdf" format:
# Adobe Portable Document Format, for use with Adobe
# Acrobat Reader or Ghostscript (article.pdf or book.pdf, as
# appropriate).
#
# WITH_PS allows the build of the "ps" format:
# Postscript (article.ps or book.ps, as appropriate).
#
# WITH_TXT allows the build of the "txt" format:
# Plain text (article.txt or book.txt, as appropriate).
#

PORTNAME=	freebsd-doc
PORTVERSION=	20090628
CATEGORIES=	misc docs
MASTER_SITES=	LOCAL/blackend
PKGNAMEPREFIX?=	en-

MAINTAINER=	doceng@FreeBSD.org
COMMENT?=	Documentation from the FreeBSD Documentation Project

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

DOCLANG?=		en_US.ISO8859-1
DOCLANG_PREFIX?=	${DOCLANG:C/_.*$//}
DOCBASE?=		share/doc/freebsd

PLIST=		${WRKDIR}/pkg-plist

OPTIONS=	HTML		"Single HTML file per document" Off \
		HTML_SPLIT	"The default HTML format used on www.FreeBSD.org" On \
		PDF		"PDF format" On \
		PS		"PostScript format" Off \
		TXT		"Plain text" Off

.include <bsd.port.pre.mk>

AVAILABLEFORMATS=	HTML HTML_SPLIT PDF PS TXT

# if PACKAGE_BUILDING=yes, enable all of $AVAILABLEFORMATS.
.if defined(PACKAGE_BUILDING)
.for F in ${AVAILABLEFORMATS}
WITH_${F}=		yes
.endfor
.endif

# translate "WITH_FOO=yes" into "DOCFORMAT+=FOO".
.for F in ${AVAILABLEFORMATS}
.if defined(WITH_${F}) && !empty(WITH_${F})
DOCFORMAT+=	${F:L:S,_,-,}
.endif
.endfor

# set a default value when DOCFORMAT is empty
.if empty(DOCFORMAT)
DOCFORMAT=		html-split
WITH_HTML_SPLIT=	yes
.endif

.if defined(WITH_PDF) || defined(WITH_PS)
BUILD_DEPENDS=	docproj-jadetex>=1.17:${PORTSDIR}/textproc/docproj-jadetex
.else
BUILD_DEPENDS=	docproj-nojadetex>=1.17:${PORTSDIR}/textproc/docproj-nojadetex
.endif

MAKE_JOBS_SAFE=	yes

.for F in ${DOCFORMAT:L}
PLIST_FORMATS+=	${F:L}
.endfor

# when html or html-split is defined as the format, add HTML_COMMON.
.if defined(WITH_HTML) || defined(WITH_HTML_SPLIT)
PLIST_FORMATS+=	html-common
.endif

# example files, scripts, etc. coming with the doc and common
# directories for all formats.
PLIST_FORMATS+=	extras common

pre-build:
	${CAT} ${PLIST_FORMATS:S,^,${.CURDIR}/pkg-plist.,} > ${PLIST}

.include <bsd.port.post.mk>
