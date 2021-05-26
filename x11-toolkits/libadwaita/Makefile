PORTNAME=	libadwaita
PORTVERSION=	0.0.20210526
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/archive/${_COMMIT}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Building blocks for modern GNOME applications

LICENSE=	LGPL21

BUILD_DEPENDS=	sassc:textproc/sassc \
		valac:lang/vala

USES=		gnome meson ninja pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk40

PORTSCOUT=	limit:1,even

WRKSRC=		${WRKDIR}/${PORTNAME}-${_COMMIT}/

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen>=0:textproc/gi-docgen
DOCS_MESON_TRUE=	gtk_doc

_COMMIT=		7f61711633dfd067f4928df80afe6b14f16f886e/

.include <bsd.port.mk>
