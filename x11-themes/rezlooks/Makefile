# Created by: brandoncash@gmail.com
# $FreeBSD$

PORTNAME=	rezlooks
PORTVERSION=	0.6
PORTREVISION=	7
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	39179-rezlooks-${PORTVERSION}

MAINTAINER=	brandoncash@gmail.com
COMMENT=	GTK+ 2.x engine based on Clearlooks

WRKSRC=		${WRKDIR}/rezlooks-${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	gtk20

OPTIONS_DEFINE=	ANIMATION
OPTIONS_DEFAULT=	ANIMATION
ANIMATION_DESC=	Animation support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANIMATION}
CONFIGURE_ARGS+=	--enable-animation
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/animation.c

.include <bsd.port.mk>
