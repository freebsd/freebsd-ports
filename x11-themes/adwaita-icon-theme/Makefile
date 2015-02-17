# Created by: Gustau Pérez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/adwaita-icon-theme/Makefile 19966 2014-10-16 06:32:52Z gusi $

PORTNAME=	adwaita-icon-theme
PORTVERSION=	3.14.0
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

INSTALLS_ICONS=	yes
USES=		gettext-tools gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intltool gtk-update-icon-cache
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GTK_ENCODE_SYMBOLIC_SVG="false"

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/locale

.include <bsd.port.mk>
