# $FreeBSD$

PORTNAME=	kamoso
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Application to take pictures and videos out of your webcam

LICENSE=	GPLv2

USES=		cmake:outsource gettext kde:5 pkgconfig qt:5 tar:xz
USE_GNOME=	glib20
USE_GSTREAMER1=	yes
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons ecm i18n itemviews jobwidgets kio purpose \
		service solid widgetsaddons xmlgui
USE_QT=		core dbus gui network qml quick widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
