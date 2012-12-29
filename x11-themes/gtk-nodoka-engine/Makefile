# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	gtk-nodoka-engine
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	https://fedorahosted.org/releases/n/o/nodoka/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK nodoka engine and themes

OPTIONS_DEFINE=	ANIMATION ANIMATIONTOLEFT
ANIMATION_DESC=		Animation support
ANIMATIONTOLEFT_DESC=	Animation from right to left

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANIMATION}
CONFIGURE_ARGS+=	--enable-animation
.else
CONFIGURE_ARGS+=	--disable-animation
.endif

.if ${PORT_OPTIONS:MANIMATIONTOLEFT}
CONFIGURE_ARGS+=	--enable-animationtoleft
.else
CONFIGURE_ARGS+=	--disable-animationtoleft
.endif

.include <bsd.port.mk>
