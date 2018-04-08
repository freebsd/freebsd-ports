# $FreeBSD$

PORTNAME=	ktouch
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Touch typing tutor for KDE

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons doctools \
		ecm i18n itemviews kcmutils kdeclarative kio newstuff package \
		parts service sonnet texteditor textwidgets widgetsaddons \
		windowsystem xmlgui
USE_QT5=	core dbus gui network qml quick script sql testlib widgets \
		x11extras xml xmlpatterns \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xcb xext xkbfile

.include <bsd.port.mk>
