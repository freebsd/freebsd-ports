PORTNAME=	polo
DISTVERSIONPREFIX=	v
DISTVERSION=	18.8-beta
PORTREVISION=	5
CATEGORIES=	x11-fm

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Advanced graphical file manager written in Vala
WWW=		https://teejee2008.github.io/polo/

LICENSE=	GPLv2+

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libharfbuzz.so:print/harfbuzz \
		libjson-glib-1.0.so:devel/json-glib

USES=		desktop-file-utils gettext-tools gmake gnome pkgconfig \
		vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	teejee2008
USE_GNOME=	cairo gdkpixbuf gtk30 libxml2 vte3

MAKEFILE=	makefile
WRKSRC_SUBDIR=	src

post-patch:
	@${RM} ${WRKSRC}/share/polo/files/gtk-theme/*.orig
	@${RM} ${WRKSRC}/share/polo/files/install-*.sh
	@${RM} -r ${WRKSRC}/share/polo/files/udisks2
# Adhere to GLib.Object naming conventions for properties
	@${REINPLACE_CMD} -e 's,7zip_version,sevenzip_version,g' \
		${WRKSRC}/Gtk/MainMenubar.vala \
		${WRKSRC}/Utility/ArchiveTask.vala

.include <bsd.port.mk>
