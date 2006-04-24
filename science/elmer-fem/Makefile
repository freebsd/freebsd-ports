# New ports collection makefile for:	elmer-fem
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	fem
PORTVERSION=	5.0.2
CATEGORIES=	science tk84
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	giffunip@asme.org
COMMENT=	FEM solver for use in the ELMER FEM package

BUILD_DEPENDS=	${FC}:${PORTSDIR}/lang/gfortran	\
		${LOCALBASE}/lib/libmatc.a:${PORTSDIR}/science/elmer-matc	\
		${LOCALBASE}/lib/libblas.a:${PORTSDIR}/math/elmer-mathlibs	\
		${LOCALBASE}/lib/liblapack.a:${PORTSDIR}/math/elmer-mathlibs	\
		${LOCALBASE}/lib/libumfpack.a:${PORTSDIR}/math/elmer-umfpack	\
		${LOCALBASE}/lib/libeiof.a:${PORTSDIR}/science/elmer-eio	\
		${LOCALBASE}/lib/libhuti.a:${PORTSDIR}/science/elmer-hutiter
RUN_DEPENDS=	${MACHINE_ARCH}-portbld-freebsd${OSREL}-ElmerGrid:${PORTSDIR}/science/elmergrid \
		${MACHINE_ARCH}-portbld-freebsd${OSREL}-Mesh2D:${PORTSDIR}/science/elmer-meshgen2d

USE_GCC=	4.1+
WITH_FORTRAN=	yes
FC=	${LOCALBASE}/bin/gfortran41
F77=	${FC}

USE_AUTOTOOLS=	autoconf:259
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	FC=${FC} F77=${FC} FCFLAGS=${FCFLAGS}
USE_GMAKE=	yes
ALL_TARGET=
INSTALLS_SHLIB=	yes

DATADIR=	${PREFIX}/share/elmersolver
PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FCFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
