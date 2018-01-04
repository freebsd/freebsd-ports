# $FreeBSD$

PORTNAME=	gnustep-examples
PORTVERSION=	1.4.0
PORTREVISION=	6
CATEGORIES=	misc gnustep
MASTER_SITES=	GNUSTEP/usr-apps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep example applications

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build

l_GNUSTEP_MAKE_DIRS=	. gui/Finger gui/GFractal gui/HostAddress gui/MyGL

post-patch:
	@${REINPLACE_CMD} -e 's|^//|#|' \
		${WRKSRC}/gui/GFractal/GNUmakefile

do-build:
.for i in ${l_GNUSTEP_MAKE_DIRS}
	@(cd ${BUILD_WRKSRC}/${i}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
	   ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
.endfor

# ---------------------------------------------------------------------------
# source GNUstep.sh
#
do-install:
.for i in ${l_GNUSTEP_MAKE_DIRS}
	@(cd ${INSTALL_WRKSRC}/${i}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Calculator.app/Calculator \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/CurrencyConverter.app/CurrencyConverter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Finger.app/Finger \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GFractal.app/GFractal \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GSTest.app/GSTest \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/HostAddress.app/HostAddress \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Ink.app/Ink \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/MyGL.app/MyGL \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/NSBrowserTest.app/NSBrowserTest \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/NSImageTest.app/NSImageTest \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/NSPanelTest.app/NSPanelTest \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/NSScreenTest.app/NSScreenTest \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/md5Digest.app/md5Digest \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/Composite-test.bundle/Composite-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/CoordinateCheck-test.bundle/CoordinateCheck-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/GSHbox-test.bundle/GSHbox-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/Image-test.bundle/Image-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/ImageSelection-test.bundle/ImageSelection-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/KeyboardInput-test.bundle/KeyboardInput-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSAnimation-test.bundle/NSAnimation-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSBox-test.bundle/NSBox-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSButton-test.bundle/NSButton-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSColorList-test.bundle/NSColorList-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSColorWell-test.bundle/NSColorWell-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSForm-test.bundle/NSForm-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSOpenPanel-test.bundle/NSOpenPanel-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSOutlineView-test.bundle/NSOutlineView-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSProgressIndicator-test.bundle/NSProgressIndicator-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSSavePanel-test.bundle/NSSavePanel-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSScrollView-test.bundle/NSScrollView-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSSecureTextField-test.bundle/NSSecureTextField-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSSlider-test.bundle/NSSlider-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSSplitView-test.bundle/NSSplitView-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSTableView-test.bundle/NSTableView-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSTextView-test.bundle/NSTextView-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSViewAnimation-test.bundle/NSViewAnimation-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSWindow-test.bundle/NSWindow-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/NSWindowStyleMask-test.bundle/NSWindowStyleMask-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/PixelExactDrawing-test.bundle/PixelExactDrawing-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/StringDrawing-test.bundle/StringDrawing-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/TextSystem-test.bundle/TextSystem-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GSTest/Transparency-test.bundle/Transparency-test \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Services/example.service/example

.include <bsd.port.mk>
