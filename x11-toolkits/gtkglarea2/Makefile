# Created by: Marc Recht <marc@informatik.uni-bremen.de>

PORTNAME=	gtkglarea
PORTVERSION=	2.0.1
PORTREVISION=	11
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DISTNAME=	gtkglarea-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL widget for the GTK+2 GUI toolkit

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c++11-lang gl gnome libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_GL=		gl glu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lib-GL
INSTALL_TARGET=	install-strip
LIBS+=		-lm

.include <bsd.port.mk>
