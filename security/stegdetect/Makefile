# New ports collection makefile for:	stegdetect
# Date created:				Jul 19, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	stegdetect
PORTVERSION=	0.6
PORTREVISION=	9
CATEGORIES=	security
MASTER_SITES=	http://www.outguess.org/ \
		http://distfiles.master.finkmirrors.net/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Automated tool for detecting steganographic content in JPEGs

OPTIONS=	X11 "Build xsteg" On

.include <bsd.port.options.mk>

.if !defined(WITHOUT_X11)
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent
.endif

# Note: stegdetect includes a modified version of jpeg-6b linked statically
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--program-prefix=''
MAN1=		stegdetect.1 stegbreak.1

.if defined(WITHOUT_X11)
PLIST_SUB+=	X11="@comment "
.else
USE_GNOME=	gtk12
CONFIGURE_ENV+=	PATH_GTKCONFIG="${GTK_CONFIG}"
PLIST_SUB+=	X11=""
.endif

post-patch:
	@${REINPLACE_CMD} 's;/usr/include/event;${LOCALBASE}/include;g' \
		${WRKSRC}/configure
.if defined(WITHOUT_X11)
	@${REINPLACE_CMD} 's/gtk-config//g' ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
