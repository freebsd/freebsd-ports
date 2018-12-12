# $FreeBSD$

PORTNAME=	artikulate
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	3
CATEGORIES=	misc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pronunciation trainer for KDE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libQt5GStreamer-1.0.so:multimedia/gstreamer1-qt@qt5

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	archive attica auth codecs config configwidgets coreaddons \
		crash doctools ecm i18n kdeclarative newstuff service \
		widgetsaddons xmlgui
USE_QT=		core dbus declarative gui multimedia network sql testlib widgets \
		xml xmlpatterns \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
