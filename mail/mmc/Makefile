# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mmc
PORTVERSION=	0.5
PORTREVISION=	10
CATEGORIES=	mail gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiny mail client for Gnome Desktop

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.1//}

USES=        pathfix
USE_GNOME=	gnomelibs gnomeprefix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTSCOUT=	skipv:0.35

CFLAGS+=	-fpermissive

NO_STAGE=	yes
.include <bsd.port.mk>
