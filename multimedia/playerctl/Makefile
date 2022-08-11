PORTNAME=	playerctl
DISTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	https://github.com/altdesktop/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	aly@aaronly.me
COMMENT=	MPRIS command-line controller and library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome meson pkgconfig tar:xz
USE_CSTD=	c99
USE_GNOME=	glib20
USE_LDCONFIG=	yes

MESON_ARGS+=	-Dbash-completions=true -Dzsh-completions=true

PLIST_SUB=	VERSION=${DISTVERSION}

OPTIONS_DEFINE=			DOCS INTROSPECTION
OPTIONS_SUB=			yes

DOCS_DESC=			Build GTK documentation
DOCS_BUILD_DEPENDS=		gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=		gtk-doc
DOCSDIR=			${PREFIX}/share/gtk-doc/html/${PORTNAME}

INTROSPECTION_DESC=		Build GObject Introspection
INTROSPECTION_USE=		gnome=introspection:build
INTROSPECTION_MESON_TRUE=	introspection

.include <bsd.port.mk>
