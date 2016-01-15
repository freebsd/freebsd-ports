# Created by: Steffen Vogelreuter
# $FreeBSD$

PORTNAME=	gtk-imonc
PORTVERSION=	0.6.4.1
PORTREVISION=	15
CATEGORIES=	sysutils
MASTER_SITES=	http://stefan-strigler.de/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2-based imond-client to control an on(e) disc fli4l router

LICENSE=	GPLv2+

GNU_CONFIGURE=	yes
USES=		pkgconfig gettext iconv
USE_GNOME=	gtk20
USE_XORG=	x11
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

post-patch:
	@${REINPLACE_CMD} -e \
		's|/gnome/apps/Internet|/applications|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/usr/share/pixmaps/||' ${WRKSRC}/gtk-imonc.desktop
	@${REINPLACE_CMD} -e \
		's|<endian.h>|<sys/endian.h>|' ${WRKSRC}/src/md5.h

.include <bsd.port.mk>
