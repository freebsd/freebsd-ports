PORTNAME=	kasts
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE podcast app
WWW=		https://apps.kde.org/kasts/

LICENSE=	GPLv2+

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6 \
		libtag.so:audio/taglib \
		libvlc.so:multimedia/vlc

USES=		cmake desktop-file-utils gettext gettext-runtime gnome \
		gstreamer kde:6 pkgconfig qt:6 tar:xz xorg
USE_GNOME=	glib20
USE_GSTREAMER1=	yes
USE_KDE=	colorscheme config coreaddons crash i18n kirigami-addons \
		kirigami2 syndication threadweaver \
		ecm:build
USE_QT=		base multimedia
USE_XORG=	x11

.include <bsd.port.mk>
