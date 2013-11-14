# Created by: Steffen Vogelreuter
# $FreeBSD$

PORTNAME=	gtk-imonc
PORTVERSION=	0.6.4.1
PORTREVISION=	13
CATEGORIES=	sysutils
MASTER_SITES=	http://stefan-strigler.de/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2-based imond-client to control an on(e) disc fli4l router

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USES=		pkgconfig gettext iconv
USE_GNOME=	gdkpixbuf2 gtk20
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|/gnome/apps/Internet|/applications|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/usr/share/pixmaps/||' ${WRKSRC}/gtk-imonc.desktop
	@${REINPLACE_CMD} -e \
		's|<endian.h>|<sys/endian.h>|' ${WRKSRC}/src/md5.h

.include <bsd.port.mk>
