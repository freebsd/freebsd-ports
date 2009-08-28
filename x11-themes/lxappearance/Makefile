# New ports collection makefile for:   lxappearance
# Date created:                2008/06/20
# Whom:                        chinsan
#
# $FreeBSD$
#

PORTNAME=	lxappearance
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/lxde/LXAppearance/LXAppearance%20${PORTVERSION}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A desktop-independent theme switcher for GTK+

USE_GNOME=	gtk20 intlhack
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		lxappearance.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
