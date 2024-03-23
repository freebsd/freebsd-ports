PORTNAME=	pnetcdf
PORTVERSION=	1.12.3
PORTREVISION=	2
CATEGORIES=	science parallel
MASTER_SITES=	https://parallel-netcdf.github.io/Release/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library providing high-performance I/O
WWW=		https://parallel-netcdf.github.io/ \
		https://github.com/Parallel-NetCDF/PnetCDF

USES=		fortran gmake libtool pathfix perl5
USE_PERL5=	build

CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--with-mpi=${MPI_HOME} ac_cv_fc_compiler_nag=no
# Workaround for GCC 10+ for Type mismatch between actual argument at (1) and actual argument at (2) (INTEGER(8)/CHARACTER(*)).
FCFLAGS+=	-fallow-argument-mismatch
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	hdf-4.*

OPTIONS_SINGLE=	MPI
OPTIONS_SINGLE_MPI=	OPENMPI MPICH
OPTIONS_DEFAULT=OPENMPI
# Use Use MPICH option for 32-bit architecture.
# PnetCDF requires MPI_Offset >= 8 but Open MPI sets MPI_Offset to 4 on 32-bit architecture regardless of LFS.
# See https://github.com/open-mpi/ompi/issues/3195 for details.
OPTIONS_DEFAULT_armv6=	MPICH
OPTIONS_DEFAULT_armv7=	MPICH
OPTIONS_DEFAULT_i386=	MPICH
OPTIONS_DEFAULT_powerpc=MPICH
OPTIONS_EXCLUDE_armv6=	OPENMPI
OPTIONS_EXCLUDE_armv7=	OPENMPI
OPTIONS_EXCLUDE_i386=	OPENMPI
OPTIONS_EXCLUDE_powerpc=OPENMPI

MPICH_USES=	mpi:mpich
OPENMPI_USES=	mpi:openmpi

.include <bsd.port.mk>
