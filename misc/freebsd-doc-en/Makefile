# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

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
PORTVERSION=	43088
PORTREVISION=	1
PORTEPOCH=	1
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

OPTIONS_DEFINE=	HTML HTML_SPLIT PDF PS TXT
OPTIONS_DEFAULT=	HTML_SPLIT PDF
HTML_DESC=		Single HTML file per document
HTML_SPLIT_DESC=	The default HTML format used on www.FreeBSD.org
PDF_DESC=		PDF format
PS_DESC=		PostScript format
TXT_DESC=		Plain text

NO_STAGE=	yes

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
.if ${PORT_OPTIONS:M${F}}
DOCFORMAT+=	${F:L:S,_,-,}
.endif
.endfor

# set a default value when DOCFORMAT is empty
.if empty(DOCFORMAT)
DOCFORMAT=		html-split
WITH_HTML_SPLIT=	yes
.endif

BUILD_DEPENDS=	docproj>=1.17:${PORTSDIR}/textproc/docproj

MAKE_JOBS_UNSAFE=	yes

.for F in ${DOCFORMAT:L}
PLIST_FORMATS+=	${F:L}
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

.include <bsd.port.post.mk>
