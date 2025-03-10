PORTNAME=	tokodon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE mastodon client
WWW=		https://apps.kde.org/tokodon/

LICENSE=	GPLv3

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6 \
		libmpv.so:multimedia/mpv \
		libMpvQt.so:multimedia/mpvqt

USES=		cmake desktop-file-utils gettext kde:6 pkgconfig qt:6 tar:xz \
		xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons i18n itemmodels jobwidgets kio kirigami-addons \
		kirigami2 notifications purpose qqc2-desktop-style service \
		solid sonnet widgetsaddons windowsystem \
		ecm:build \
		itemmodels:run
USE_QT=		base websockets webview
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
