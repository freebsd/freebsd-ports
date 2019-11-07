# Created by: ptiJo
# $FreeBSD$

PORTNAME=	xfe
PORTVERSION=	1.43.2
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fast MS-Explorer like file manager for X

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libxcb-util.so:x11/xcb-util

USES=		desktop-file-utils gmake localbase pathfix pkgconfig gnome xorg
USE_XORG=	x11 xcb xft xrandr xrender
USE_GNOME=	intltool

GNU_CONFIGURE=	yes

LDFLAGS+=	-pthread

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_USES_OFF=	gettext-tools

post-patch:
.for i in XFileExplorer.cpp help.h xfedefs.h
	@${REINPLACE_CMD} -e \
		's|/usr/local/share/xfe|${DATADIR}|g' ${WRKSRC}/src/${i}
.endfor

.include <bsd.port.mk>
