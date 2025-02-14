PORTNAME=	libspelling
DISTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Spellcheck library for GTK 4
WWW=		https://gitlab.gnome.org/GNOME/libspelling

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	gtk40 gtksourceview5 introspection:build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS ENCHANT
OPTIONS_DEFAULT=ENCHANT

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	docs

ENCHANT_LIB_DEPENDS=	libicuuc.so:devel/icu \
			libenchant-2.so:textproc/enchant2
ENCHANT_MESON_ENABLED=	enchant

.include <bsd.port.mk>
