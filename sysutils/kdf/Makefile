# $FreeBSD$

PORTNAME=	kdf
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Shows free space of devices for KDE

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons doctools \
		i18n iconthemes jobwidgets kcmutils kio notifications service \
		widgetsaddons xmlgui
USE_QT=		core dbus gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
