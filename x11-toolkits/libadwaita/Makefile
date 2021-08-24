PORTNAME=	libadwaita
PORTVERSION=	0.0.20210526
PORTREVISION=	1
CATEGORIES=	x11-toolkits

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Building blocks for modern GNOME applications

LICENSE=	LGPL21

BUILD_DEPENDS=	sassc:textproc/sassc \
		valac:lang/vala

USES=		gnome meson ninja pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk40
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	7f61711633dfd067f4928df80afe6b14f16f886e

PORTSCOUT=	limit:1,even

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
