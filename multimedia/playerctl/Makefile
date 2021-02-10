# Created by: Aaron LI <aly@aaronly.me>
# $FreeBSD$

PORTNAME=	playerctl
DISTVERSION=	2.3.1
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

OPTIONS_DEFINE=			DOC INTROSPECTION
OPTIONS_SUB=			yes

DOC_DESC=			Build GTK documentation
DOC_BUILD_DEPENDS=		gtkdoc-scan:textproc/gtk-doc
DOC_MESON_TRUE=			gtk-doc

INTROSPECTION_DESC=		Build GObject Introspection
INTROSPECTION_USE=		gnome=introspection:build
INTROSPECTION_MESON_TRUE=	introspection

.include <bsd.port.mk>
