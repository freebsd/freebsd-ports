# New ports collection makefile for:	rezlooks
# Date created:		2006-07-02
# Whom:			brandoncash@gmail.com
#
# $FreeBSD$
#

PORTNAME=	rezlooks
PORTVERSION=	0.6
PORTREVISION=	4
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	39179-rezlooks-${PORTVERSION}

MAINTAINER=	brandoncash@gmail.com
COMMENT=	GTK+ 2.x engine based on Clearlooks

WRKSRC=		${WRKDIR}/rezlooks-${PORTVERSION}

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

OPTIONS+=	ANIMATION "Animation support" On

.if !defined(WITHOUT_ANIMATION)
CONFIGURE_ARGS+=	--enable-animation
.endif

.include <bsd.port.mk>
