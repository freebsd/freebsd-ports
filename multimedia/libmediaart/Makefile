# Created by: Gustau Perez <gustau.perez@gmail.com>

PORTNAME=	libmediaart
DISTVERSION=	1.9.6
CATEGORIES=	multimedia devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for handling media art

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	vala>=0:lang/vala

USES=		gnome meson pathfix pkgconfig tar:xz
USE_GNOME=	gdkpixbuf2 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dimage_library=gdk-pixbuf -Dgtk_doc=false

.include <bsd.port.mk>
