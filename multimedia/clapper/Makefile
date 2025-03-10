PORTNAME=	clapper
DISTVERSION=	0.8.0
CATEGORIES=	multimedia wayland

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Simple and modern GNOME media player
WWW=		https://rafostar.github.io/clapper

LICENSE=	GPLv3+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING-GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING-LGPL

BUILD_DEPENDS=	dot:graphics/graphviz
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig python:build shared-mime-info vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	Rafostar
USE_GNOME=	glib20 gtk40 libadwaita
GLIB_SCHEMAS=	com.github.rafostar.Clapper.gschema.xml
USE_GSTREAMER=	gl good libav soup taglib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DISCOVERER MPRIS
OPTIONS_GROUP=		FEATURES
OPTIONS_GROUP_FEATURES=	DISCOVERER ENHANCERS MPRIS SERVER
OPTIONS_SUB=		yes

DISCOVERER_DESC=	Enable Discoverer feature
ENHANCERS_DESC=		Enable ability to load libpeas based plugins
MPRIS_DESC=		Enable MPRIS feature
SERVER_DESC=		Enable Server feature

DISCOVERER_MESON_ON=	-Ddiscoverer=enabled
DISCOVERER_MESON_OFF=	-Ddiscoverer=disabled
DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_USE=		GNOME=introspection
DOCS_MESON_ON=		-Ddoc=true
ENHANCERS_BROKEN=	Needs libpeas-2 that isn't yet available
ENHANCERS_MESON_ON=	-Denhancers-loader=enabled
ENHANCERS_MESON_OFF=	-Denhancers-loader=disabled
MPRIS_MESON_ON=		-Dmpris=enabled
MPRIS_MESON_OFF=	-Dmpris=disabled
SERVER_MESON_ON=	-Dserver=enabled
SERVER_MESON_OFF=	-Dserver=disabled

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/bin/clapper-app/data/applications/com.github.rafostar.Clapper.desktop.in \
		${STAGEDIR}${DESKTOPDIR}/com.github.rafostar.Clapper.desktop

.include <bsd.port.mk>
