PORTNAME=	neochat
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Glossy Matrix IM client based on KDE technologies
WWW=		https://invent.kde.org/network/neochat

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

# Quotient is a static lib, doesn't need to be in RUN_DEPENDS
BUILD_DEPENDS=	libquotient>=0.9.3:net-im/libquotient \
		kquickimageeditor-qt6>=0.2.0:graphics/kquickimageeditor
LIB_DEPENDS=	libKUnifiedPush.so:devel/kunifiedpush \
		libQCoro6Core.so:devel/qcoro \
		libcmark.so:textproc/cmark \
		libqt6keychain.so:security/qtkeychain@qt6 \
		libdbus-1.so:devel/dbus \
		libolm.so:security/olm
RUN_DEPENDS=	kquickimageeditor-qt6>=0.2.0:graphics/kquickimageeditor

USES=		cmake compiler:c++20-lang desktop-file-utils gettext kde:6 \
		pkgconfig qt:6 tar:xz xorg
USE_QT=		base multimedia speech webview \
		location:run positioning:run
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons i18n itemmodels jobwidgets kio kirigami-addons \
		kirigami2 kquickcharts notifications purpose qqc2-desktop-style \
		service solid sonnet statusnotifieritem syntaxhighlighting \
		widgetsaddons windowsystem \
		prison:run \
		ecm:build
USE_XORG=	x11

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
USES+=		llvm:min=16
.endif

.include <bsd.port.mk>
