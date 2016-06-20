# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	stegdetect
PORTVERSION=	0.6
PORTREVISION=	13
CATEGORIES=	security
MASTER_SITES=	http://www.sourcefiles.org/Graphics/Tools/Miscellaneous/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automated tool for detecting steganographic content in JPEGs

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11

OPTIONS_SUB=	yes

X11_LIB_DEPENDS=	libevent.so:devel/libevent2
X11_USE=	GNOME=gtk12 XORG=x11,xext,xi
X11_CONFIGURE_ENV+=	PATH_GTKCONFIG="${GTK_CONFIG}"

# Note: stegdetect includes a modified version of jpeg-6b linked statically
GNU_CONFIGURE=	yes
USES=		gmake
CONFIGURE_ARGS+=--program-prefix=''

post-patch:
	@${REINPLACE_CMD} 's;/usr/include/event;${LOCALBASE}/include;g' \
		${WRKSRC}/configure
post-patch-X11-on:
	@${REINPLACE_CMD} 's/gtk-config//g' ${WRKSRC}/configure

.include <bsd.port.mk>
