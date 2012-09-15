# $FreeBSD$

PORTNAME=	galculator
PORTVERSION=	1.3.4
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GTK2-based scientific calculator

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	libglade2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

MAN1=		galculator.1

.include <bsd.port.mk>
