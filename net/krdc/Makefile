PORTNAME=	krdc
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDP and VNC client for KDE
WWW=		https://kde.org/applications/internet/krdc/

LIB_DEPENDS=	libvncclient.so:net/libvncserver \
		libxkbcommon.so:x11/libxkbcommon \
		libwayland-client.so:graphics/wayland \
		libwayland-cursor.so:graphics/wayland \
		libssh.so:security/libssh

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl kde:6 \
		pkgconfig qt:6 shared-mime-info tar:xz xorg
USE_GL=		opengl
USE_KDE=	activities bookmarks colorscheme completion config \
		configwidgets coreaddons crash dnssd doctools i18n iconthemes \
		jobwidgets kcmutils kio notifications notifyconfig service \
		solid statusnotifieritem wallet widgetsaddons windowsystem \
		xmlgui ecm:build
USE_QT=		base declarative wayland
USE_XORG=	x11
USE_LDCONFIG=	yes

CMAKE_ON=	WITH_VNC

OPTIONS_DEFINE=	FREERDP DOCS
OPTIONS_DEFAULT=	FREERDP
OPTIONS_SUB=	yes
FREERDP_DESC=	Remote Desktop support via FreeRDP
FREERDP_LIB_DEPENDS=	libfreerdp3.so:net/freerdp3
FREERDP_CMAKE_BOOL=	WITH_RDP

.include <bsd.port.mk>
