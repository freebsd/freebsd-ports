PORTNAME=	krdc
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDP and VNC client for KDE

LIB_DEPENDS=	libvncserver.so:net/libvncserver

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons dnssd doctools i18n iconthemes kcmutils \
		notifications notifyconfig service wallet widgetsaddons \
		windowsystem xmlgui \
		ecm_build
USE_QT=		core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

CMAKE_ON=	WITH_VNC

OPTIONS_DEFINE=	FREERDP DOCS
OPTIONS_DEFAULT=	FREERDP
OPTIONS_SUB=	yes
FREERDP_CMAKE_BOOL=	WITH_FREERDP
FREERDP_DESC=	Remote Desktop support via FreeRDP
FREERDP_BUILD_DEPENDS=	xfreerdp:net/freerdp
FREERDP_RUN_DEPENDS=	xfreerdp:net/freerdp

.include <bsd.port.mk>
