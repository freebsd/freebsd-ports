PORTNAME=	arianna
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	textproc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	e-book reader
WWW=		https://apps.kde.org/arianna/

LICENSE=	GPLv3

USES=		cmake desktop-file-utils gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	archive baloo config coreaddons dbusaddons filemetadata i18n \
		kirigami-addons kirigami2 kquickcharts qqc2-desktop-style \
		windowsystem \
		ecm:build
USE_QT=		base declarative httpserver webengine websockets
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
