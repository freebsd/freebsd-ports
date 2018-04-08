# $FreeBSD$

PORTNAME=	artikulate
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pronunciation trainer for KDE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libQt5GStreamer-1.0.so:multimedia/gstreamer1-qt5

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	archive attica auth codecs config configwidgets coreaddons \
		crash doctools ecm i18n kdeclarative newstuff service \
		widgetsaddons xmlgui
USE_QT5=	core dbus gui multimedia network qml quick sql testlib widgets \
		xml xmlpatterns \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
