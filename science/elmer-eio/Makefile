# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	eio
PORTVERSION=	5.4.0
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=   http://garr.dl.sourceforge.net/sourceforge/elmerfem/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	ELMER FEM Package Data base Interface

USES=		fortran

GNU_CONFIGURE=	yes
ALL_TARGET=

PLIST_FILES=	include/eio_api.h lib/libeioc.a lib/libeiof.a

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FCFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
