PORTNAME=	plasma-browser-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	www kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Components necessary to integrate browsers into the Plasma Desktop

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_KDE=	activities config coreaddons crash dbusaddons filemetadata \
		i18n itemmodels jobwidgets kio notifications plasma-workspace \
		purpose runner service statusnotifieritem \
		ecm:build
USE_GL=		gl opengl
USE_QT=		base declarative

.include <bsd.port.mk>
