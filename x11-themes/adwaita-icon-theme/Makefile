PORTNAME=	adwaita-icon-theme
DISTVERSION=	47.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	GNOME Symbolic Icons
WWW=		https://gitlab.gnome.org/GNOME/adwaita-icon-theme

LICENSE=	LGPL3 CC-BY-SA-3.0
LICENSE_COMB=	dual

RUN_DEPENDS=	adwaita-icon-theme-legacy>0:x11-themes/adwaita-icon-theme-legacy

NO_ARCH=	yes
USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	gtk-update-icon-cache

.include <bsd.port.mk>
