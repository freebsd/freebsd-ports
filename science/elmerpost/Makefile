# New ports collection makefile for:	elmerpost
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	elmerpost
PORTVERSION=	5.3.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/src/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Visualization of Numerical Results in the ELMER FEM package

BUILD_DEPENDS=	${LOCALBASE}/lib/libmatc.a:${PORTSDIR}/science/elmer-matc	\
		wish8.4:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

# Elmer avoids the new C++ headers because they cause problems
# on older systems (Irix)
CXXFLAGS+=	-Wno-deprecated

USE_GL=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=

WANT_FORTRAN=	yes
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
CONFIGURE_ENV+=	FC=gfortran42 F77=gfortran42 FCFLAGS=${FCFLAGS}

PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
