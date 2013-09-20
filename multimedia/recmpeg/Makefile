# Created by: ijliao
# $FreeBSD$

PORTNAME=	recmpeg
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/fame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple video encoder

LIB_DEPENDS=	fame-0.9.1:${PORTSDIR}/multimedia/libfame

GNU_CONFIGURE=	yes

MAN1=		recmpeg.1
PLIST_FILES=	bin/recmpeg

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Fails to link on ia64
.endif

.include <bsd.port.post.mk>
