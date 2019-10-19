# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	gtk-nodoka-engine
PORTVERSION=	0.7.5
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	https://BSDforge.com/projects/source/x11-themes/gtk-nodoka-engine/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK nodoka engine and themes

OPTIONS_DEFINE=	ANIMATION ANIMATIONTOLEFT
ANIMATION_DESC=		Animation support
ANIMATIONTOLEFT_DESC=	Animation from right to left
ANIMATION_CONFIGURE_ENABLE=		animation
ANIMATIONTOLEFT_CONFIGURE_ENABLE=	animationtoleft

GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
