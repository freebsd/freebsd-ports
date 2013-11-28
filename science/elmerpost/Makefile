# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	elmerpost
PORTVERSION=	5.4.0
PORTREVISION=	6
CATEGORIES=	science
MASTER_SITES=	http://garr.dl.sourceforge.net/sourceforge/elmerfem/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Visualization of Numerical Results in the ELMER FEM package

BUILD_DEPENDS=	${LOCALBASE}/lib/libmatc.a:${PORTSDIR}/science/elmer-matc	\
		wish8.4:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

DEPRECATED=	Relies on long obsolete version of GCC, does not build on FreeBSD 9 and later nor amd64
EXPIRATION_DATE=2013-12-27

# Elmer avoids the new C++ headers because they cause problems
# on older systems (Irix)
CXXFLAGS+=	-Wno-deprecated

USE_GL=		yes
USE_XORG=	x11 xt xi
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_FORTRAN=	g77

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Does not compile on amd64
.elif ${OSVERSION} >= 900035
BROKEN=		Does not compile on recent FreeBSD-9
.endif

.include <bsd.port.post.mk>
