PORTNAME=	tokodon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE mastodon client
WWW=		https://apps.kde.org/tokodon/

LICENSE=	GPLv3

BUILD_DEPENDS=	kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons
LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5 \
		libmpv.so:multimedia/mpv
RUN_DEPENDS=	kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons

USES=		cmake desktop-file-utils gettext kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons i18n jobwidgets kio kirigami2 notifications \
		purpose qqc2-desktop-style service solid widgetsaddons \
		windowsystem \
		ecm:build \
		itemmodels:run
USE_QT=		concurrent core dbus declarative gui multimedia network \
		quickcontrols2 websockets widgets xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
