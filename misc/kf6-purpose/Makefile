PORTNAME=	purpose
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	misc kde kde-frameworks

COMMENT=	Offers available actions for a specific purpose
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	accounts-qml-module>=0.7_5:sysutils/accounts-qml-module
LIB_DEPENDS=	libkaccounts6.so:net-im/kaccounts-integration
RUN_DEPENDS=	accounts-qml-module>=0.7_5:sysutils/accounts-qml-module

USES=		cmake gettext gl gnome kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_GNOME=	intltool
USE_KDE=	config coreaddons i18n itemmodels kio kirigami2 \
		notifications prison service \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
