PORTNAME=	kdewebkit
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	www kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing integration of QtWebKit

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		i18n jobwidgets kio parts service sonnet textwidgets \
		wallet widgetsaddons xmlgui \
		ecm_build
USE_QT=		concurrent core dbus gui network webkit widgets xml \
		buildtools_build qmake_build 

.include <bsd.port.mk>
