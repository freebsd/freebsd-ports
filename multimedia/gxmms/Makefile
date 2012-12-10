# Created by: Radek Kozlowski <radek@raadradd.com>
# $FreeBSD$

PORTNAME=	gxmms
PORTVERSION=	0.2.1
PORTREVISION=	14
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GNOME panel applet for controlling XMMS

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomepanel gnomeprefix intlhack libgnomeui
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="`pkg-config --libs libgnomeui-2.0`"
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
