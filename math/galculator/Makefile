# $FreeBSD$

PORTNAME=	galculator
PORTVERSION=	2.1.3
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GTK-based scientific calculator

USES=		gettext gmake pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-gtk3

.include <bsd.port.mk>
