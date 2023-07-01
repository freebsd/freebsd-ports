PORTNAME=	kaccounts-integration
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	System to administer web accounts for the KDE desktop
WWW=		https://projects.kde.org/projects/kdereview/kaccounts-integration

BUILD_DEPENDS=	${LOCALBASE}/include/qcoro5/qcoro/qcoro.h:devel/qcoro@qt5
LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib \
		libaccounts-qt5.so:net-im/libaccounts-qt5 \
		liboauth2plugin.so:sysutils/signon-plugin-oauth2 \
		libsignon-qt5.so:sysutils/signon-qt5 \
		libkeyring-kwallet.so:sysutils/signon-kwallet-extension
RUN_DEPENDS=	signon-ui:sysutils/signon-ui

USES=		cmake compiler:c++11-lang gettext pkgconfig kde:5 \
		qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		i18n iconthemes kcmutils kdeclarative kio service wallet widgetsaddons \
		akonadi \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools:build qmake:build

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*} && ${OSVERSION} < 1400092
CXX=		clang++${LLVM_VERSION}
USES+=		llvm:min=16
.endif

.include <bsd.port.mk>
