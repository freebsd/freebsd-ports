PORTNAME=	pcmanfm-qt
PORTVERSION=	1.3.0
CATEGORIES=	x11-fm
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt file manager
WWW=		https://github.com/lxde/pcmanfm-qt

LICENSE=	GPLv2

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
		libfm-qt.so:x11/libfm-qt \
		libexif.so:graphics/libexif

USES=		cmake compiler:c++14-lang desktop-file-utils gnome\
		gettext-runtime localbase:ldflags lxqt perl5 pkgconfig kde:5 qt:5 \
		tar:xz xorg
USE_PERL5=	build
USE_QT=		buildtools:build qmake:build core dbus gui linguisttools \
		widgets x11extras
USE_KDE=	oxygen-icons5
USE_LXQT=	buildtools libfmqt
USE_GNOME=	glib20
USE_XORG=	xcb

.include <bsd.port.mk>
