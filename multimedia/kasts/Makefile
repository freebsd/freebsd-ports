PORTNAME=	kasts
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE podcast app
WWW=		https://apps.kde.org/kasts/

LICENSE=	GPLv2+

BUILD_DEPENDS=	kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons
LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5 \
		libtag.so:audio/taglib \
		libvlc.so:multimedia/vlc
RUN_DEPENDS=	kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons

USES=		cmake desktop-file-utils gettext-runtime gnome gstreamer kde:5 \
		pkgconfig qt:5 tar:xz xorg
USE_GNOME=	glib20
USE_GSTREAMER1=	yes
USE_KDE=	config coreaddons i18n kirigami2 syndication threadweaver \
		ecm:build
USE_QT=		core dbus declarative gui multimedia network quickcontrols2 \
		sql svg widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

.include <bsd.port.mk>
