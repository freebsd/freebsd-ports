# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	stegdetect
PORTVERSION=	0.6
PORTREVISION=	9
CATEGORIES=	security
MASTER_SITES=	http://www.outguess.org/ \
		http://distfiles.master.finkmirrors.net/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automated tool for detecting steganographic content in JPEGs

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent
USE_GNOME=	gtk12
CONFIGURE_ENV+=	PATH_GTKCONFIG="${GTK_CONFIG}"
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

# Note: stegdetect includes a modified version of jpeg-6b linked statically
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--program-prefix=''
MAN1=		stegdetect.1 stegbreak.1

post-patch:
	@${REINPLACE_CMD} 's;/usr/include/event;${LOCALBASE}/include;g' \
		${WRKSRC}/configure
.if ${PORT_OPTIONS:MX11}
	@${REINPLACE_CMD} 's/gtk-config//g' ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
