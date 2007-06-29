# New ports collection makefile for:	Elmer-MatC
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	matc
PORTVERSION=	5.3.0
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/src/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	MatC language library used by ELMER FEM package

GNU_CONFIGURE=	yes
ALL_TARGET=

WANT_FORTRAN=yes	#dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=	gfortran42
F77=	gfortran42

PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
