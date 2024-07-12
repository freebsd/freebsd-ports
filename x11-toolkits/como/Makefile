PORTNAME=	como
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	325e41b02b58.patch:-p1 # https://github.com/winft/como/pull/22
PATCHFILES+=	d250e3a81b91.patch:-p1 # https://github.com/winft/como/pull/22

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Compositor Modules for Wayland and X11
WWW=		https://github.com/winft/como

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libwayland-server.so:graphics/wayland \
		libWraplandServer.so:graphics/wrapland \
		libwlroots.so:x11-toolkits/wlroots017 \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms
RUN_DEPENDS=	evdev-proto>0:devel/evdev-proto
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing gettext-tools kde:6 pkgconfig \
		python:build qt:6 shebangfix xorg
USE_GITHUB=	yes
USE_KDE=	auth colorscheme config configwidgets coreaddons \
		decoration ecm:build globalaccel i18n idletime kcmutils \
		kscreenlocker newstuff:build package service svg \
		widgetsaddons windowsystem
USE_LDCONFIG=	yes
USE_QT=		base declarative tools
USE_XORG=	x11 xcb
GH_ACCOUNT=	winft
SHEBANG_FILES=	plugins/effects/*.py
PLIST_SUB=	VERSION=${PORTVERSION}
LDFLAGS+=	-Wl,--as-needed # fontconfig/freetype, GL, ICE/SM/Xext/Xi, pixman

OPTIONS_DEFINE=	BREEZE DOCS QA11Y
OPTIONS_DEFAULT=BREEZE QA11Y

BREEZE_DESC=		Default window decoration plugin
BREEZE_USE=		KDE=breeze
BREEZE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Breeze

DOCS_USE=		KDE=doctools:build
DOCS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF6DocTools

QA11Y_DESC=		Accessibility (focus tracking) for Zoom effect
QA11Y_LIB_DEPENDS=	libqaccessibilityclient-qt6.so:accessibility/libqaccessibilityclient@qt6
QA11Y_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_QAccessibilityClient6

post-patch:
# Convert nodes from linprocfs(5) to procfs(5)
# XXX como lacks https://invent.kde.org/plasma/kwin/-/commit/1bc7afe8aaa9
	@${REINPLACE_CMD} -e '/proc/,+1s,/exe,/file,' \
		${WRKSRC}/${PORTNAME}/base/wayland/filtered_display.cpp \
		${WRKSRC}/${PORTNAME}/desktop/kde/service_utils.h
# Generic nodes are not supported by procfs(5)
	@${REINPLACE_CMD} -e '/mounts/s,/proc,${LINUXBASE}&,' \
		${WRKSRC}/${PORTNAME}/debug/perf/ftrace_impl.cpp

.include <bsd.port.mk>
