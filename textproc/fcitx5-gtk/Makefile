PORTNAME=	fcitx5-gtk
DISTVERSION=	5.0.10
CATEGORIES=	textproc

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Fcitx support for GTK+ 2/3

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++17-lang gettext-tools cmake gnome kde:5 pkgconfig xorg

PLIST_SUB=	VER=${PORTVERSION}

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx
USE_GNOME=	introspection glib20 gtk20 gtk30
USE_KDE=	ecm
USE_XORG=	x11

CMAKE_OFF=	ENABLE_GTK4_IM_MODULE

.include <bsd.port.mk>
