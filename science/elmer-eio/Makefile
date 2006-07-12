# New ports collection makefile for:	elmer-eio
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	eio
PORTVERSION=	5.2.0
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ELMER FEM Package Data base Interface

BUILD_DEPENDS=	${FC}:${PORTSDIR}/lang/gfortran

USE_GCC=	4.1+
WITH_FORTRAN=	yes
FC=	${LOCALBASE}/bin/gfortran41
F77=	${FC}
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
