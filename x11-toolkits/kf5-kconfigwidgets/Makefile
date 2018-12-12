# $FreeBSD$

PORTNAME=	kconfigwidgets
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 widgets for configuration dialogs

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 shebangfix tar:xz
USE_KDE=	archive auth codecs config coreaddons doctools ecm guiaddons \
		i18n widgetsaddons
USE_QT=		buildtools_build core dbus gui qmake_build widgets xml

SHEBANG_FILES=	src/preparetips5

.include <bsd.port.mk>
