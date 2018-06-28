# $FreeBSD$

PORTNAME=	kteatime
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11-clocks kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Handy timer for steeping tea

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons crash doctools ecm \
		i18n iconthemes notifications notifyconfig sonnet textwidgets \
		widgetsaddons xmlgui
USE_QT=		core dbus gui widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
