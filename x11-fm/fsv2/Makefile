PORTNAME=	fsv2
PORTVERSION=	1.1.0
PORTREVISION=	5
CATEGORIES=	x11-fm
MASTER_SITES=	http://cyber.dabamos.de/pub/distfiles/

MAINTAINER=	kidon@posteo.de
COMMENT=	3D filesystem visualizer
WWW=		http://fedorchenko.net/fsv2.php

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		does not configure: No fonts installed on the system
EXPIRATION_DATE=2025-10-13

LIB_DEPENDS=	libgtkgl-2.0.so:x11-toolkits/gtkglarea2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libftgl.so:graphics/ftgl

USES=		compiler:c++11-lang tar:bzip2 libtool gettext-runtime gl gnome \
		pkgconfig
USE_GL=		gl glu
USE_GNOME=	gtkmm24 atkmm glibmm pangomm cairomm libsigc++20 gtk20 atk \
		cairo gdkpixbuf
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|auto_ptr|unique_ptr|' \
		${WRKSRC}/uilib/ColorCellRenderer.cpp
.endif

.include <bsd.port.post.mk>
