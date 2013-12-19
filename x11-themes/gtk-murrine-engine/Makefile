# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	murrine
PORTVERSION=	0.98.2
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	GNOME
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrine GTK+ 2.x cairo based engine

USE_XZ=	yes
USE_XORG=	pixman
USE_GNOME=	gtk20 intltool intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig

OPTIONS_DEFINE=	ANIMATION
ANIMATION_DESC=	Animation support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANIMATION} 
CONFIGURE_ARGS+=--enable-animation
.else
CONFIGURE_ARGS+=--disable-animation
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gtimer.h|glib.h|g' \
		${WRKSRC}/src/animation.c

.include <bsd.port.mk>
