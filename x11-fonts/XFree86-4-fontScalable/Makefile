# New ports collection makefile for:	XFree86-fontScalable
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	fontScalable
PORTVERSION=	4.4.0
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-4.4.0-src-4.tgz \
		XFree86-4.4.0-src-5.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 scalable fonts

BUILD_DEPENDS=	ucs2any:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings

CONFLICTS=	xorg-fonts-type1-* xorg-fonts-truetype-*

USE_IMAKE=		YES
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc/fonts

# XFree86 User Config:
# ---
# Name          	Default		Meaning
# ----------------------------------------------------------------------------
# BuildSpeedoFonts	YES		build/install Speedo fonts
# BuildType1Fonts	YES		build/install Type1 fonts
# BuildCIDFonts		YES		build/install CID fonts
# BuildTTFonts		YES		build/install TrueType fonts
BuildSpeedoFonts?=	DEFAULT
BuildType1Fonts?=	DEFAULT
BuildCIDFonts?=		DEFAULT
BuildTTFonts?=		DEFAULT

.if ${BuildSpeedoFonts} == DEFAULT || ${BuildSpeedoFonts} == YES
PLIST_SUB+=	SPEEDO:=""
SPEEDO:=	-DBuildSpeedoFonts=YES
.elif ${BuildSpeedoFonts} == NO
PLIST_SUB+=	SPEEDO:="@comment "
SPEEDO:=	-DBuildSpeedoFonts=NO
.endif
.if ${BuildType1Fonts} == DEFAULT || ${BuildType1Fonts} == YES
PLIST_SUB+=	TYPE1:=""
TYPE1:=	-DBuildType1Fonts=YES
.elif ${BuildType1Fonts} == NO
PLIST_SUB+=	TYPE1:="@comment "
TYPE1:=	-DBuildType1Fonts=NO
.endif
.if ${BuildCIDFonts} == DEFAULT || ${BuildCIDFonts} == YES
PLIST_SUB+=	CID:=""
CID:=	-DBuildCIDFonts=YES
.elif ${BuildCIDFonts} == NO
PLIST_SUB+=	CID:="@comment "
CID:=	-DBuildCIDFonts=NO
.endif
.if ${BuildTTFonts} == DEFAULT || ${BuildTTFonts} == YES
PLIST_SUB+=	TT:=""
TT:=	-DBuildTTFonts=YES
.elif ${BuildTTFonts} == NO
PLIST_SUB+=	TT:="@comment "
TT:=	-DBuildTTFonts=NO
.endif

do-configure:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		${SPEEDO} ${TYPE1} ${CID} ${TT} \
		-DMakeLocalFontDir=YES \
		-DFreeBSDBuildXscl=YES \
		-DTOPDIR=.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

pre-build:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	 ${MAKE} all)

.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
