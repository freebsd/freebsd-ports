# New ports collection makefile for:	fontconfig
# Date created:		06 October 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fontconfig
PORTVERSION=	2.2.3
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://pdx.freedesktop.org/~fontconfig/release/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An XML-based font configuration API for X Windows

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		expat.5:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
PREFIX?=	${X11BASE}
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack gnometarget lthack pkgconfig
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc/fonts \
		--with-expat-includes=${LOCALBASE}/include \
		--with-expat-lib=${LOCALBASE}/lib \
		--with-default-fonts=${X11BASE}/lib/X11/fonts
MAKE_ENV=	LC_ALL=C
PKGINSTALL=	${WRKDIR}/pkg-install

MAN1=		fc-cache.1 fc-list.1
MAN3=		FcAtomicCreate.3  \
		FcAtomicDeleteNew.3  \
		FcAtomicDestroy.3  \
		FcAtomicLock.3  \
		FcAtomicNewFile.3  \
		FcAtomicOrigFile.3  \
		FcAtomicReplaceOrig.3  \
		FcAtomicUnlock.3  \
		FcBlanksAdd.3  \
		FcBlanksCreate.3  \
		FcBlanksDestroy.3  \
		FcBlanksIsMember.3  \
		FcCharSetAddChar.3  \
		FcCharSetCopy.3  \
		FcCharSetCount.3  \
		FcCharSetCreate.3  \
		FcCharSetDestroy.3  \
		FcCharSetEqual.3  \
		FcCharSetFirstPage.3  \
		FcCharSetHasChar.3  \
		FcCharSetIntersect.3  \
		FcCharSetIntersectCount.3  \
		FcCharSetIsSubset.3  \
		FcCharSetNextPage.3  \
		FcCharSetSubtract.3  \
		FcCharSetSubtractCount.3  \
		FcCharSetUnion.3  \
		FcConfigAppFontAddDir.3  \
		FcConfigAppFontAddFile.3  \
		FcConfigAppFontClear.3  \
		FcConfigBuildFonts.3  \
		FcConfigCreate.3  \
		FcConfigDestroy.3  \
		FcConfigFilename.3  \
		FcConfigGetBlanks.3  \
		FcConfigGetCache.3  \
		FcConfigGetConfigDirs.3  \
		FcConfigGetConfigFiles.3  \
		FcConfigGetCurrent.3  \
		FcConfigGetFontDirs.3  \
		FcConfigGetFonts.3  \
		FcConfigGetRescanInverval.3  \
		FcConfigParseAndLoad.3  \
		FcConfigSetCurrent.3  \
		FcConfigSetRescanInverval.3  \
		FcConfigSubstitute.3  \
		FcConfigSubstituteWithPat.3  \
		FcConfigUptoDate.3  \
		FcDefaultSubstitute.3  \
		FcDirCacheValid.3  \
		FcDirSave.3  \
		FcDirScan.3  \
		FcFileScan.3  \
		FcFontList.3  \
		FcFontMatch.3  \
		FcFontRenderPrepare.3  \
		FcFontSetAdd.3  \
		FcFontSetCreate.3  \
		FcFontSetDestroy.3  \
		FcFontSort.3  \
		FcFreeTypeCharIndex.3  \
		FcFreeTypeCharSet.3  \
		FcFreeTypeQuery.3  \
		FcGetVersion.3  \
		FcInit.3  \
		FcInitBringUptoDate.3  \
		FcInitLoadConfig.3  \
		FcInitLoadConfigAndFonts.3  \
		FcInitReinitialize.3  \
		FcMatrixCopy.3  \
		FcMatrixEqual.3  \
		FcMatrixInit.3  \
		FcMatrixMultiply.3  \
		FcMatrixRotate.3  \
		FcMatrixScale.3  \
		FcMatrixShear.3  \
		FcNameConstant.3  \
		FcNameGetConstant.3  \
		FcNameGetObjectType.3  \
		FcNameParse.3  \
		FcNameRegisterConstants.3  \
		FcNameRegisterObjectTypes.3  \
		FcNameUnparse.3  \
		FcNameUnregisterConstants.3  \
		FcNameUnregisterObjectTypes.3  \
		FcObjectSetAdd.3  \
		FcObjectSetBuild.3  \
		FcObjectSetCreate.3  \
		FcObjectSetDestroy.3  \
		FcPatternAdd-Type.3  \
		FcPatternAdd.3  \
		FcPatternAddWeak.3  \
		FcPatternBuild.3  \
		FcPatternCreate.3  \
		FcPatternDel.3  \
		FcPatternDestroy.3  \
		FcPatternEqual.3  \
		FcPatternEqualSubset.3  \
		FcPatternGet-Type.3  \
		FcPatternGet.3  \
		FcPatternHash.3  \
		FcPatternPrint.3  \
		FcStrBasename.3  \
		FcStrCmpIgnoreCase.3  \
		FcStrCopy.3  \
		FcStrCopyFilename.3  \
		FcStrDirname.3  \
		FcStrListCreate.3  \
		FcStrListDone.3  \
		FcStrListNext.3  \
		FcStrSetAdd.3  \
		FcStrSetAddFilename.3  \
		FcStrSetCreate.3  \
		FcStrSetDel.3  \
		FcStrSetDestroy.3  \
		FcStrSetMember.3  \
		FcUcs4ToUtf8.3  \
		FcUtf16Len.3  \
		FcUtf16ToUcs4.3  \
		FcUtf8Len.3  \
		FcUtf8ToUcs4.3  \
		FcValueDestroy.3  \
		FcValueSave.3
MAN5=		fonts-conf.5

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.else
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
.endif

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' < ${FILESDIR}/pkg-install.in \
		> ${PKGINSTALL}
.if !defined(PACKAGE_BUILDING)
	@${LDCONFIG} -m ${PREFIX}/lib
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
