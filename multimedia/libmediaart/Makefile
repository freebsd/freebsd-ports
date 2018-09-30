# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	libmediaart
PORTVERSION=	1.9.4
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

MESON_ARGS=	-Dimage_library=gdk-pixbuf

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	gtk-doc>=0:textproc/gtk-doc
DOCS_MESON_ON=	-Dwith-docs=yes
DOCS_MESON_OFF=	-Dwith-docs=no
#option('image_library', type: 'combo', choices: ['auto', 'gdk-pixbuf', 'qt4', 'qt5'],
#       description: 'Which image processing backend to use')
#option('with-docs', type : 'combo', choices : ['auto', 'yes', 'no'], value : 'auto')


.include <bsd.port.mk>
