PORTNAME=	plasma-browser-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	www kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Components necessary to integrate browsers into the Plasma Desktop

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	activities config coreaddons crash dbusaddons filemetadata \
		i18n jobwidgets kio notifications plasma-workspace purpose \
		runner statusnotifieritem \
		ecm:build
USE_QT=		base

.include <bsd.port.mk>
