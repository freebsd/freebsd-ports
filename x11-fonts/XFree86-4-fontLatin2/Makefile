# New ports collection makefile for:	XFree86-4-fontLatin2
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	fontLatin2
PORTVERSION=	4.0.3
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.0.2
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X402src-2.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings

XFREE86_VERSION=	4
USE_IMAKE=		YES
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - xc/fonts
WRKSRC=			${WRKDIR}/xc/fonts/bdf/latin2

# XFree86 User Config:
# ---
# Name          	Default		Meaning
# ----------------------------------------------------------------------------
# Build75DpiFonts	YES		build/install 75dpi fonts
# Build100DpiFonts	YES		build/install 100dpi fonts
Build75DpiFonts?=	DEFAULT
Build100DpiFonts?=	DEFAULT

.if ${Build75DpiFonts} == DEFAULT || ${Build75DpiFonts} == YES
PLIST_SUB+=	75DPI:=""
75DPI:=		-DBuild75DpiFonts=YES
.elif ${Build75DpiFonts} == NO
PLIST_SUB+=	75DPI:="@comment "
75DPI:=		-DBuild75DpiFonts=NO
.endif
.if ${Build100DpiFonts} == DEFAULT || ${Build100DpiFonts} == YES
PLIST_SUB+=	100DPI:=""
100DPI:=	-DBuild100DpiFonts=YES
.elif ${Build100DpiFonts} == NO
PLIST_SUB+=	100DPI:="@comment "
100DPI:=	-DBuild100DpiFonts=NO
.endif

do-configure:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${75DPI} ${100DPI} \
		${PROJECTROOT} \
		-I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

pre-build:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	 ${MAKE} all)

.include <bsd.port.mk>
