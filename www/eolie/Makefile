# Created by: Rozhuk Ivan 2019 <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	eolie
PORTVERSION=	0.9.100
CATEGORIES=	www gnome
MASTER_SITES=	https://adishatz.org/eolie/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple web browser for GNOME

LICENSE=	GPLv3+

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${LOCALBASE}/share/gir-1.0/GtkSpell-3.0.gir:textproc/gtkspell3 \
		${LOCALBASE}/share/gir-1.0/WebKit2-4.0.gir:www/webkit2-gtk3 \
		${LOCALBASE}/share/glib-2.0/schemas/org.gnome.settings-daemon.plugins.color.gschema.xml:sysutils/gnome-settings-daemon

USES=		desktop-file-utils gettext gnome meson pkgconfig python \
		shebangfix tar:xz
USE_GNOME=	gtk30 introspection:build pygobject3
GLIB_SCHEMAS=	org.gnome.Eolie.gschema.xml
INSTALLS_ICONS=	yes
SHEBANG_FILES=	eolie.in search-provider/eolie-sp.in
BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
