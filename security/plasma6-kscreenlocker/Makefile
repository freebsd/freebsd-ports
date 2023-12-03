PORTNAME=	kscreenlocker
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	security kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library and components for secure lock screen architecture

BUILD_DEPENDS=	ck-list-sessions:sysutils/consolekit2
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	ck-list-sessions:sysutils/consolekit2 \
		dbus-send:devel/dbus \
		unix-selfauth-helper>=1.0:security/unix-selfauth-helper

USES=		cmake gettext gl kde:6 pkgconfig qt:6 shebangfix tar:xz xorg
USE_KDE=	colorscheme config configwidgets coreaddons crash globalaccel \
		i18n idletime kcmutils kio layer-shell-qt libkscreen libplasma \
		notifications package solid svg widgetsaddons windowsystem \
		xmlgui \
		ecm:build
USE_GL=		gl opengl
USE_QT=		base declarative
USE_XORG=	x11 xcb xext xi

SHEBANG_FILES=	updaters/ksreenlocker_5_3_separate_autologin.pl

SUB_FILES=	kde.pam

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pam.d
	${INSTALL_DATA} ${WRKDIR}/kde.pam ${STAGEDIR}${PREFIX}/etc/pam.d/kde

.include <bsd.port.mk>
