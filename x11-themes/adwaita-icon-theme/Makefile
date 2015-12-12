# Created by: Gustau Pérez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	adwaita-icon-theme
PORTVERSION=	3.16.2.2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

INSTALLS_ICONS=	yes
USES=		gettext-tools gmake pathfix pkgconfig tar:xz
USE_GNOME=	intltool gtk-update-icon-cache
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GTK_ENCODE_SYMBOLIC_SVG="false"

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/locale
	@${RM} -rf ${STAGEDIR}${PREFIX}/locale

.include <bsd.port.mk>
