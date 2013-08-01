# $FreeBSD$

PORTNAME=	galculator
PORTVERSION=	2.1.2
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GTK-based scientific calculator

USES=		gmake
USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-gtk3

MAN1=		galculator.1

.include <bsd.port.mk>
