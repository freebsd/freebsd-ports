# $FreeBSD$

PORTNAME=	fsv2
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	http://cyber.dabamos.de/pub/distfiles/

MAINTAINER=	kidon@posteo.de
COMMENT=	3D filesystem visualizer

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtkgl-2.0.so:x11-toolkits/gtkglarea2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libftgl.so:graphics/ftgl

USES=		compiler:c++11-lang tar:bzip2 libtool gettext-runtime gl gnome \
		pkgconfig
USE_GNOME=	gtkmm24 atkmm glibmm pangomm cairomm libsigc++20 gtk20 atk \
		cairo gdkpixbuf2
USE_GL=		gl glu

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS NLS

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
