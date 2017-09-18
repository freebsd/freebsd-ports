# Created by: tcberner
# $FreeBSD$

PORTNAME=	kdesignerplugin
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 integration of Frameworks widgets in Qt Designer/Creator

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons doctools ecm i18n iconthemes itemviews \
		jobwidgets kdewebkit kio plotting service solid sonnet \
		textwidgets widgetsaddons xmlgui
USE_QT5=	buildtools_build core dbus designer gui linguisttools \
		network qmake_build webkit widgets xml

.include <bsd.port.mk>
