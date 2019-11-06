# Created by: Saulius Menkevicius <bob@nulis.lt>
# $FreeBSD$

PORTNAME=	vqcc-gtk
PORTVERSION=	0.5
PORTREVISION=	9
CATEGORIES?=	net-im
MASTER_SITES=	SF

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	LAN chat client compatible with quickChat and Vypress Chat (TM)

LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

USES=		pathfix gmake gnome gettext pkgconfig xorg
USE_GNOME=	gnomeprefix gtk20
USE_XORG=	x11 xext xscrnsaver
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
