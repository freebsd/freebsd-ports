# New ports collection makefile for:	elmerfront
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	front
PORTVERSION=	5.2.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/src/
PKGNAMEPREFIX=	elmer

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Graphical User Interface for the ELMER FEM package

BUILD_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84	\
		${LOCALBASE}/lib/libmatc.a:${PORTSDIR}/science/elmer-matc	\
		${LOCALBASE}/lib/libeioc.a:${PORTSDIR}/science/elmer-eio
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84	\
		ElmerSolver:${PORTSDIR}/science/elmer-fem	\
		${MACHINE_ARCH}-portbld-freebsd${OSREL}-ElmerMesh2D:${PORTSDIR}/science/elmer-meshgen2d

.include <bsd.port.pre.mk>

# Elmer avoids the new C++ headers because they cause problems
# on older systems (Irix)
CXXFLAGS+=	-Wno-deprecated

WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
USE_GCC=	3.4
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	FC=${FC} F77=${FC} FCFLAGS="${FCFLAGS}"
USE_GMAKE=	yes
ALL_TARGET=

DATADIR=	${PREFIX}/share/elmerfront
PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.post.mk>
