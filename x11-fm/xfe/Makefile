PORTNAME=	xfe
DISTVERSION=	1.46.1
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fast MS-Explorer like file manager for X
WWW=		http://roland65.free.fr/xfe/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libFOX-1.6.so:x11-toolkits/fox16 \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libxcb-util.so:x11/xcb-util

USES=		desktop-file-utils gmake gnome localbase pathfix pkgconfig \
		tar:xz xorg
USE_GNOME=	intltool
USE_XORG=	x11 xcb xft xrandr xrender

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

LDFLAGS+=	-pthread

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

post-patch:
.for i in XFileExplorer.cpp help.h xfedefs.h
	@${REINPLACE_CMD} -e \
		's|/usr/local/share/xfe|${DATADIR}|g' ${WRKSRC}/src/${i}
.endfor

.include <bsd.port.mk>
