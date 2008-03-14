# New ports collection makefile for:	elmerpost
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	elmerpost
PORTVERSION=	5.4.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	SF/elmerfem

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

USE_FORTRAN=	yes
CONFIGURE_ENV+=	FC=${FC} F77=${FC} FCFLAGS=${FCFLAGS}

PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
