# $FreeBSD$

PORTNAME=	krdc
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDP and VNC client for KDE

LIB_DEPENDS=	libvncserver.so:net/libvncserver

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons dnssd doctools ecm i18n iconthemes kcmutils \
		notifications notifyconfig service wallet widgetsaddons \
		xmlgui
USE_QT=		core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	FREERDP DOCS
OPTIONS_SUB=	yes
FREERDP_CMAKE_BOOL=	WITH_FREERDP
FREERDP_DESC=	Remote Desktop support via FreeRDP
FREERDP_BUILD_DEPENDS=	xfreerdp:net/freerdp
FREERDP_RUN_DEPENDS=	xfreerdp:net/freerdp

.include <bsd.port.mk>
