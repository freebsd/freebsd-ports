# $FreeBSD$

PORTNAME=	print-manager
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	print kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Printer manager for KDE

LIB_DEPENDS=	libcups.so:print/cups

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons ecm i18n iconthemes itemviews jobwidgets kcmutils \
		kio notifications plasma-framework service widgetsaddons \
		windowsystem
USE_QT=		core dbus gui network qml quick widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
