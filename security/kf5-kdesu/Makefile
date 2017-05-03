# Created by: tcberner
# $FreeBSD$

PORTNAME=	kdesu
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	security kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 integration with su for elevated privileges

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	config coreaddons dbusaddons ecm i18n pty service
USE_QT5=	buildtools_build core dbus qmake_build xml
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
