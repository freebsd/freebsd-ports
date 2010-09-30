# New ports collection makefile for:   lxinput
# Date created:                2010/09/24
# Whom:                        Kris Moore <kmoore@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	lxinput
PORTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/lxde/LXInput%20%28Kbd%20and%20amp_%20mouse%20config%29/LXInput%200.3

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	A keyboard and mouse config tool from the LXDE project

USE_GNOME=	gtk20 intlhack
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
MAN1=		lxinput.1

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
