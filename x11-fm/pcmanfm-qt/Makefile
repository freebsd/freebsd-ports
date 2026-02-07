PORTNAME=	pcmanfm-qt
PORTVERSION=	2.3.0
CATEGORIES=	x11-fm
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	LXQt file manager
WWW=		https://github.com/lxde/pcmanfm-qt

LICENSE=	GPLv2

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
		libfm-qt6.so:x11/libfm-qt6 \
		libexif.so:graphics/libexif
RUN_DEPENDS=    lxqt-menu-data>=2.0.0:x11/lxqt-menu-data

USES=		cmake compiler:c++20-lang gnome kde:6 gettext-runtime \
		localbase:ldflags lxqt:2 perl5 pkgconfig qt:6 \
		tar:xz xorg
USE_PERL5=	build
USE_GNOME=	glib20 gvfs
USE_QT=		base:run tools:build svg
USE_KDE=	layer-shell-qt
USE_LXQT=	buildtools2 libfmqt6
USE_XORG=	xcb

.include <bsd.port.mk>
