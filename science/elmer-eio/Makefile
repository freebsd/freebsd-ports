# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	eio
PORTVERSION=	5.4.0
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=   http://garr.dl.sourceforge.net/sourceforge/elmerfem/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	ELMER FEM Package Data base Interface

USE_FORTRAN=	yes

GNU_CONFIGURE=	yes
ALL_TARGET=

PLIST_FILES=	include/eio_api.h lib/libeioc.a lib/libeiof.a

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FCFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
