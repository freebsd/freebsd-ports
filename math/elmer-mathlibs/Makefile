# New ports collection makefile for:	Elmer-mathlibs
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	mathlibs
PORTVERSION=	1.0.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	giffunip@asme.org
COMMENT=	Math libraries build with F90 for used in ELMER FEM

BUILD_DEPENDS=	${FC}:${PORTSDIR}/lang/gfortran

CONFLICTS=	atlas-[0-9]* blas-[0-9]* arpack-[0-9]* lapack-[0-9]* scalapack-[0-9]*

USE_GCC=	4.1+
WITH_FORTRAN=	yes
FC=	${LOCALBASE}/bin/gfortran41
F77=	${FC}

CONFIGURE_ENV+=	F77=${FC}

GNU_CONFIGURE=	yes
ALL_TARGET=

PLIST_FILES=	lib/libarpack.a lib/libblas.a lib/liblapack.a

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
FFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
