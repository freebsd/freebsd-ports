# $FreeBSD$

PORTNAME=	galculator
PORTVERSION=	2.1.3
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GTK-based scientific calculator

USES=		gmake pkgconfig tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-gtk3

.include <bsd.port.mk>
