# Created by: rom
# $FreeBSD$

PORTNAME=	geg
PORTVERSION=	1.0.2
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	SUNSITE/science/visualization/plotting \
		http://www.infolaunch.com/~daveb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visualise multiple 2D-functions of one variable

USE_GNOME=	gtk12
USES=		autoreconf
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/geg \
		man/man1/geg.1.gz

.include <bsd.port.mk>
