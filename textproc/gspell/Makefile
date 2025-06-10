PORTNAME=	gspell
PORTVERSION=	1.14.0
CATEGORIES=	textproc
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Spell checking for GTK applications
WWW=		https://gitlab.gnome.org/GNOME/gspell

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libfribidi.so:converters/fribidi \
		libicudata.so:devel/icu \
		libharfbuzz.so:print/harfbuzz

USES=		gettext gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	glib20 gtk30 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dgtk_doc=false \
		-Dtests=false \
		-Dinstall_tests=false

.include <bsd.port.mk>
