# New ports collection makefile for:	acroread-commfont
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acroread5
PORTVERSION=	2002.5
PKGNAMESUFFIX=	-${DISTNAME}
CATEGORIES+=	print linux
MASTER_SITES=	http://download.adobe.com/pub/adobe/acrobatreader/unix/5.x/
DISTNAME?=	commfont # dummy
DIST_SUBDIR=	Acrobat5

MAINTAINER=	koma2@jiro.c.u-tokyo.ac.jp
COMMENT?=	Asian Font Packs for Acrobat Reader 5.0 (for common files)

NO_BUILD=	yes
SLAVEDIRS=	chinese/acroread-chsfont chinese/acroread-chtfont

.include <bsd.port.pre.mk>

.if defined(WITH_EXTRAFONT)
FORBIDDEN=	Adobe license seems to disallow using fonts for 4.x on 5.x.
.endif

.if ${DISTNAME} == "commfont"
###### For this port #############################
.if exists(${DISTDIR}/${DIST_SUBDIR}/jpnfont.tar.gz)
DISTFILES=	jpnfont.tar.gz
WRKSUBDIR=	JPNKIT
.elif exists(${DISTDIR}/${DIST_SUBDIR}/chsfont.tar.gz)
DISTFILES=	chsfont.tar.gz
WRKSUBDIR=	CHSKIT
.elif exists(${DISTDIR}/${DIST_SUBDIR}/chtfont.tar.gz)
DISTFILES=	chtfont.tar.gz
WRKSUBDIR=	CHTKIT
.elif exists(${DISTDIR}/${DIST_SUBDIR}/korfont.tar.gz)
DISTFILES=	korfont.tar.gz
WRKSUBDIR=	KORKIT
.else
DISTFILES=	korfont.tar.gz
WRKSUBDIR=	KORKIT
.endif
TAR_FILE=	LANGCOM.TAR
RUN_DEPENDS=	acroread5:${PORTSDIR}/print/acroread5

.else
###### For slave ports ##############################
## Use a local directory of the slave port!!
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
FILESDIR=	${.CURDIR}/files
##
RUN_DEPENDS=	${PREFIX}/Acrobat5/Resource/Font/H.cmap:${PORTSDIR}/print/acroread5-commfont
#
.if ${DISTNAME} == "jpnfont"
RESTRICTED=	"Be required to register with Adobe before downloading the Japanese font pack."
IS_INTERACTIVE=	"You should manual-fetch Japanese pack of \"Asian Font Packs\" from http://www.adobe.com/products/acrobat/acrrasianfontpack.html"
.if !exists(${DISTDIR}/${DIST_SUBDIR}/jpnfont.tar.gz)
IGNORE=		": ${RESTRICTED} ${IS_INTERACTIVE}"
.endif
WRKSUBDIR=	JPNKIT
TAR_FILE=	LANGJPN.TAR
EXTRAFONT_DIR=	${PORTSDIR}/japanese/acroread-jpnfont
EXTRAFONT=	HeiseiKakuGo-W5-Acro
.elif ${DISTNAME} == "chsfont"
WRKSUBDIR=	CHSKIT
TAR_FILE=	LANGCHS.TAR
.elif ${DISTNAME} == "chtfont"
WRKSUBDIR=	CHTKIT
TAR_FILE=	LANGCHT.TAR
EXTRAFONT_DIR=	${PORTSDIR}/chinese/acroread-chtfont
EXTRAFONT=	MHei-Medium-Acro
.elif ${DISTNAME} == "korfont"
WRKSUBDIR=	KORKIT
TAR_FILE=	LANGKOR.TAR
EXTRAFONT_DIR=	${PORTSDIR}/korean/acroread-korfont
EXTRAFONT=	HYGoThic-Medium-Acro
.endif
.endif

.if defined(WITH_EXTRAFONT) && defined(EXTRAFONT_DIR)
BUILD_DEPENDS=	${NONEXISTENT}:${EXTRAFONT_DIR}:extract
PLIST_SUB=	EXTRAFONT=''
.else
PLIST_SUB=	EXTRAFONT='@comment '
.endif
WRKSRC=		${WRKDIR}/${WRKSUBDIR}

post-extract:
	${MKDIR} ${WRKSRC}/OTF
	cd ${WRKSRC}; ${TAR} xf ${TAR_FILE} -C OTF
.if defined(WITH_EXTRAFONT) && defined(EXTRAFONT_DIR)
	cd ${WRKSRC}; ${TAR} xf ${EXTRAFONT_DIR}/work/${WRKSUBDIR}/${TAR_FILE}
.endif

do-install:
	@${MKDIR} ${PREFIX}/Acrobat5/Resource/Font
	${INSTALL_DATA} ${WRKSRC}/OTF/* ${PREFIX}/Acrobat5/Resource/Font
.if defined(WITH_EXTRAFONT) && defined(EXTRAFONT_DIR)
	${INSTALL_DATA} ${WRKSRC}/CIDFont/${EXTRAFONT} ${PREFIX}/Acrobat5/Resource/Font
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
