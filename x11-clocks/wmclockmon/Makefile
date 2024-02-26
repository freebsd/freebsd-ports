PORTNAME=	wmclockmon
PORTVERSION=	0.8.1
PORTREVISION=	10
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	list@understudy.net
COMMENT=	Digital clock dockapp with a similar look to wmcpuload
WWW=		http://tnemeth.free.fr/projets/dockapps.html

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		xorg gnome pkgconfig
USE_XORG=	xpm x11 xext
USE_GNOME=	gtk20 cairo gdkpixbuf2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|pkgconf gtk+-2.0|g'\
		${WRKSRC}/wmclockmon-config/Makefile.in
	 @${REINPLACE_CMD} -e 's|gtk-config|pkgconf gtk+-2.0|g'\
		${WRKSRC}/wmclockmon-cal/Makefile.in
post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in 1 2
	@${INSTALL_DATA} ${WRKSRC}/doc/sample${i}.wmclockmonrc ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
