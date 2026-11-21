PORTNAME=	kscreenlocker
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	security kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library and components for secure lock screen architecture

BUILD_DEPENDS=	ck-list-sessions:sysutils/consolekit2
RUN_DEPENDS=	ck-list-sessions:sysutils/consolekit2 \
		dbus-send:devel/dbus \
		unix-selfauth-helper>=1.0:security/unix-selfauth-helper

USES=		cmake gettext-tools gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	crash globalaccel i18n idletime kcmutils kio \
		notifications solid svg windowsystem xmlgui \
		ecm:build
# KDE Plasma
USE_KDE+=	layer-shell-qt libkscreen libplasma
USE_QT=		base declarative \
		tools:build
USE_XORG=	x11

SUB_FILES=	kde.pam

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pam.d
	${INSTALL_DATA} ${WRKDIR}/kde.pam ${STAGEDIR}${PREFIX}/etc/pam.d/kde

.include <bsd.port.mk>
