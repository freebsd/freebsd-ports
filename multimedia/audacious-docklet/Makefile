# New ports collection makefile for:	audacious-docklet
# Date created:		25 Febuary 2007
# Whom:			feature <feature.id@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	audacious-docklet
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://nedudu.hu/downloads/

MAINTAINER=	feature.id@gmail.com
COMMENT=	Systray plugin for audacious

LIB_DEPENDS=	audacious.5:${PORTSDIR}/multimedia/audacious
BUILD_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious

USE_BZIP2=	yes

USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
NO_INSTALL_MANPAGES=	yes
USE_XLIB=	yes
USE_BZIP2=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CFLAGS="-I${LOCALBASE}/include"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
