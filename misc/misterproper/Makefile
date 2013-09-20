# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	misterproper
PORTVERSION=	0.4
PORTREVISION=	10
CATEGORIES=	misc gnome
MASTER_SITES=	SF
#ftp://misterproper.sourceforge.net/pub/misterproper/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME application designed to manage cyclic tasks

USES=        pathfix
USE_GNOME=	gnomelibs gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
