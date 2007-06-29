# New ports collection makefile for:	elmer-meshgen2d
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	meshgen2d
PORTVERSION=	5.0.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/src/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A Mesh Generation Utility for use with the ELMER FEM package

WANT_FORTRAN=yes #dummy but future use
BUILD_DEPENDS+= gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42

GNU_CONFIGURE=	yes
ALL_TARGET=

PLIST_FILES=	bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-ElmerMesh2D \
		bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-Mesh2D	\
		bin/ElmerMesh2D bin/Mesh2D

post-install:
		${LN} -sf ${PREFIX}/bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-ElmerMesh2D \
			${PREFIX}/bin/ElmerMesh2D
		${LN} -sf ${PREFIX}/bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-Mesh2D \
			${PREFIX}/bin/Mesh2D

.include <bsd.port.mk>
