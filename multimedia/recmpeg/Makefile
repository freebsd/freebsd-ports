# Created by: ijliao
# $FreeBSD$

PORTNAME=	recmpeg
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/fame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple video encoder

LIB_DEPENDS=	libfame.so:multimedia/libfame

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/recmpeg \
		man/man1/recmpeg.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BROKEN_ia64=	Fails to link on ia64

.include <bsd.port.mk>
