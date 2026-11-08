PORTNAME=	keepsecret
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Password manager for a Secret Service compatible provider
WWW=		https://apps.kde.org/keepsecret/

LIB_DEPENDS=	libsecret-1.so:security/libsecret \
		libKirigamiActionCollection.so:x11-toolkits/kirigami-app-components

USES=		cmake gettext gl gnome kde:6 pkgconfig qt:6 tar:xz
USE_GL=		gl
USE_GNOME=	glib20
USE_KDE=	config coreaddons crash i18n dbusaddons \
		itemmodels kirigami-addons kirigami2 \
		ecm:build
USE_QT=		base declarative svg

.include <bsd.port.mk>
