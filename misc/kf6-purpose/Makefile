PORTNAME=	purpose
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	misc kde kde-frameworks

COMMENT=	Offers available actions for a specific purpose
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libkaccounts6.so:net-im/kaccounts-integration
# RUN_DEPENDS=	accounts-qml-module>=0.7_5:sysutils/accounts-qml-module

USES=		cmake gettext gl gnome kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_GNOME=	intltool
USE_KDE=	completion config coreaddons i18n jobwidgets kio kirigami2 \
		notifications service solid widgetsaddons \
		ecm:build \
		kdeclarative:run prison:run
USE_QT=		base declarative

.include <bsd.port.mk>
