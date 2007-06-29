# New ports collection makefile for:	elmer-eio
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	eio
PORTVERSION=	5.3.0
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/src/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	ELMER FEM Package Data base Interface

BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42

FC=	gfortran42
F77=	gfortran42
CONFIGURE_ENV+=	FC=${FC} F77=${FC} FCFLAGS=${FCFLAGS}

GNU_CONFIGURE=	yes
ALL_TARGET=

PLIST_FILES=	include/eio_api.h lib/libeioc.a lib/libeiof.a

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FCFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
