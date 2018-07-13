# $FreeBSD$

PORTNAME=	dragon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications
PKGNAMESUFFIX=	-player

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multimedia player with a focus on simplicity

LICENSE=	GPLv2

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons doctools ecm  kio service sonnet textwidgets i18n \
		iconthemes jobwidgets notifications parts solid widgetsaddons \
		windowsystem xmlgui
USE_QT=		core dbus gui network phonon4 widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
