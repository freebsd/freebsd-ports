# ex:ts=8
# Ports collection makefile for:	recmpeg
# Date created:			Mar 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	recmpeg
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/fame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple video encoder

LIB_DEPENDS=	fame-0.9.1:${PORTSDIR}/multimedia/libfame

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		recmpeg.1
PLIST_FILES=	bin/recmpeg

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Fails to link on ia64"
.endif

.include <bsd.port.post.mk>
