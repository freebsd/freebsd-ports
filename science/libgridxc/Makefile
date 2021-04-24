PORTNAME=	libgridxc
DISTVERSION=	0.9.6
CATEGORIES=	science
MASTER_SITES=	https://gitlab.com/siesta-project/libraries/${PORTNAME}/-/archive/${PORTNAME}-${DISTVERSION}/
DISTNAME=	${PORTNAME}-${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to compute the exchange and correlation energy and potentials

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf fortran gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		MPI LIBXC
OPTIONS_DEFAULT=	# MPI LIBXC

MPI_USES=		localbase:ldflags
MPI_CONFIGURE_WITH=	mpi=${LOCALBASE}
MPI_VARS=		FCFLAGS+="-I${LOCALBASE}/include" LDFLAGS+="-L${LOCALBASE}/lib -lmpifort"
MPI_LDFLAGS=		-lmpich
MPI_LIB_DEPENDS=	libmpich.so:net/mpich
MPI_BROKEN=		https://gitlab.com/siesta-project/libraries/libgridxc/-/issues/15

LIBXC_DESC=		Use libxc for exchange-correlation functionals for DFT
LIBXC_CONFIGURE_WITH=	libxc=${LOCALBASE}
LIBXC_VARS=		FCFLAGS+="-I${LOCALBASE}/include" LDFLAGS+="-L${LOCALBASE}/lib -lxcf90"
LIBXC_LIB_DEPENDS=	libxc.so:science/libxc
LIBXC_BROKEN=		https://gitlab.com/siesta-project/libraries/libgridxc/-/issues/16

.include <bsd.port.mk>
