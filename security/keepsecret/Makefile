PORTNAME=	keepsecret
PORTVERSION=	1.0.0
CATEGORIES=	security kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Password manager for a Secret Service compatible provider
WWW=		https://invent.kde.org/utilities/keepsecret

LIB_DEPENDS=	libsecret-1.so:security/libsecret

USES=		cmake gettext gl gnome kde:6 pkgconfig qt:6 tar:xz
USE_GL=		gl
USE_GNOME=	glib20
USE_KDE=	config coreaddons crash dbusaddons i18n itemmodels \
		kirigami-addons kirigami2 \
		ecm:build
USE_QT=		base declarative svg

.include <bsd.port.mk>
