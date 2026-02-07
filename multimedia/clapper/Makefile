PORTNAME=	clapper
DISTVERSION=	0.10.0
CATEGORIES=	multimedia graphics wayland

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Simple and modern GNOME media player
WWW=		https://rafostar.github.io/clapper

LICENSE=	GPLv3+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING-GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING-LGPL

BUILD_DEPENDS=	dot:graphics/graphviz
LIB_DEPENDS=	libcgraph.so:graphics/graphviz \
		libgraphene-1.0.so:graphics/graphene \
		libgvc.so:graphics/graphviz \
		libpeas-2.so:devel/libpeas

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
OPTIONS_GROUP_FEATURES=	DISCOVERER MPRIS SERVER
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_MESON_TRUE=	doc
SERVER_LIB_DEPENDS=	libmicrodns.so:dns/libmicrodns \
			libsoup-3.0.so:devel/libsoup3
.for OPT in ${OPTIONS_GROUP_FEATURES}
${OPT}_DESC=		Enable ${OPT:tl} feature
${OPT}_MESON_ENABLED=	${OPT:tl}
.endfor

.include <bsd.port.mk>
