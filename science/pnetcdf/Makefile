# New ports collection makefile for:	pnetcdf
# Date created:		April 30 2007
# Whom:			Chao Shin <quakelee@cn.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pnetcdf
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	science parallel
MASTER_SITES=	http://www-unix.mcs.anl.gov/parallel-netcdf/
DISTNAME=	parallel-netcdf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library providing high-performance I/O

CONFLICTS=	hdf-4.*

USE_BZIP2=	YES

OPTIONS=	OPENMPI "Use openmpi instead of mpich2" off

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_FORTRAN=	yes

MAN1=		ncmpigen.1 ncmpidump.1
MAN3=		pnetcdf.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not configure
.endif

.if defined(WITH_OPENMPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:${PORTSDIR}/net/openmpi
CONFIGURE_ARGS=	--enable-shared --disable-f77 --with-mpi=${PREFIX}/mpi/openmpi
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -fPIC -DPIC -Df2cFortran"
.else
BUILD_DEPENDS+=	${LOCALBASE}/mpich2/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/mpich2/lib/libmpich.so:${PORTSDIR}/net/mpich2
CONFIGURE_ARGS=	--enable-shared --disable-f77 --with-mpi=${PREFIX}/mpich2
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -fPIC -DPIC -Df2cFortran"
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/ncmpidump ${PREFIX}/bin/ncmpigen ${PREFIX}/bin/ncvalid
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in COPYRIGHT INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
