PORTNAME=	kpmcore
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	KDE Partition Manager core library
WWW=		https://invent.kde.org/system/kpmcore

LIB_DEPENDS=	libpolkit-qt6-agent-1.so:sysutils/polkit-qt-1@qt6

USES=		cmake compiler:c++17-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth coreaddons i18n widgetsaddons \
		ecm:build
USE_QT=		base

.include <bsd.port.mk>
