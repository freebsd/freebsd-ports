# New ports collection makefile for:	elmerfront
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	front
PORTVERSION=	5.4.0
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	SF/elmerfem
PKGNAMEPREFIX=	elmer

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Graphical User Interface for the ELMER FEM package

BUILD_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84	\
		${LOCALBASE}/lib/libmatc.a:${PORTSDIR}/science/elmer-matc	\
		${LOCALBASE}/lib/libeioc.a:${PORTSDIR}/science/elmer-eio
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84	\
		ElmerSolver:${PORTSDIR}/science/elmer-fem	\
		ElmerMesh2D:${PORTSDIR}/science/elmer-meshgen2d

BROKEN=		does not compile

# Elmer avoids the new C++ headers because they cause problems
# on older systems (Irix)
CXXFLAGS+=	-Wno-deprecated

USE_FORTRAN=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=

DATADIR=	${PREFIX}/share/elmerfront

.include <bsd.port.mk>
