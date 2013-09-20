# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parano
PORTVERSION=	0.3.5
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Gnome program to deal with hashfiles

USE_GNOME=	pygnome2
USE_PYTHON=	yes
USES=		gettext
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
