PORTNAME=	arianna
DISTVERSION=	1.0.1
CATEGORIES=	textproc kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	e-book reader
WWW=		https://apps.kde.org/arianna/

LICENSE=	GPLv3

BUILD_DEPENDS=	kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons
RUN_DEPENDS=	kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons

USES=		cmake desktop-file-utils gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	archive baloo config coreaddons  dbusaddons filemetadata \
		i18n kirigami2  qqc2-desktop-style  windowsystem \
		ecm:build
USE_QT=		core dbus declarative gui location network quickcontrols2 \
		sql svg webchannel webengine websockets widgets xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
