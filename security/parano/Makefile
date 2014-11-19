# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parano
PORTVERSION=	0.3.5
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome program to deal with hashfiles

USE_GNOME=	pygnome2
USES=		desktop-file-utils gettext gmake python shared-mime-info
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-mime-database

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
