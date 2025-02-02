PORTNAME=	krdc
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDP and VNC client for KDE
WWW=		https://kde.org/applications/internet/krdc/

LIB_DEPENDS=	libvncserver.so:net/libvncserver \
		libssh.so:security/libssh

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		pkgconfig qt:6 shared-mime-info tar:xz xorg
USE_KDE=	activities bookmarks colorscheme completion config \
		configwidgets coreaddons crash dnssd doctools i18n iconthemes \
		kcmutils notifications notifyconfig statusnotifieritem \
		wallet widgetsaddons xmlgui \
		ecm:build
USE_QT=		base declarative wayland
USE_XORG=	x11
USE_LDCONFIG=	yes

CMAKE_ON=	WITH_VNC

OPTIONS_DEFINE=	FREERDP DOCS
OPTIONS_SUB=	yes
FREERDP_CMAKE_BOOL=	WITH_RDP
FREERDP_DESC=	Remote Desktop support via FreeRDP
FREERDP_BUILD_DEPENDS=	xfreerdp:net/freerdp
FREERDP_RUN_DEPENDS=	xfreerdp:net/freerdp
FREERDP_BROKEN=		net/freerdp2 has broken cmake files

.include <bsd.port.mk>
