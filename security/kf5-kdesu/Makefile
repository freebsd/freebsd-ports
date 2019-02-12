# $FreeBSD$

PORTNAME=	kdesu
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	security kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 integration with su for elevated privileges

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons dbusaddons ecm i18n pty service
USE_QT=		buildtools_build core dbus qmake_build xml
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
