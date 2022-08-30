PORTNAME=	libshumate
DISTVERSION=	1.0.0.beta
CATEGORIES=	x11-toolkits geography

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	d4e23adc49e1.patch:-p1 # https://gitlab.gnome.org/GNOME/libshumate/-/merge_requests/136

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK4 widget to display maps
WWW=		https://wiki.gnome.org/Projects/libshumate

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		libgraphene-1.0.so:graphics/graphene

USES=		gettext gnome meson pkgconfig sqlite vala:build
USE_GITLAB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk40 introspection:build
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	290359fd6af168b3554c24298ba344eb88a2ed47

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
