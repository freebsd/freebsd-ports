PORTNAME=	pnetcdf
PORTVERSION=	1.14.1
CATEGORIES=	science parallel
MASTER_SITES=	https://parallel-netcdf.github.io/Release/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library providing high-performance I/O
WWW=		https://parallel-netcdf.github.io/ \
		https://github.com/Parallel-NetCDF/PnetCDF

LICENSE=	NetCDF
LICENSE_NAME=	NetCDF License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

USES=		fortran gmake libtool mpi:${FLAVOR} pathfix perl5
USE_PERL5=	build

CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--with-mpi=${MPI_HOME} ac_cv_fc_compiler_nag=no
# Workaround for GCC 10+ for Type mismatch between actual argument at (1) and actual argument at (2) (INTEGER(8)/CHARACTER(*)).
FCFLAGS+=	-fallow-argument-mismatch
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	hdf-4.* pnetcdf-mpich pnetcdf-openmpi

FLAVORS=	mpich openmpi
FLAVOR?=	${FLAVORS:[1]}
mpich_PKGNAMESUFFIX=	-mpich
openmpi_PKGNAMESUFFIX=	-openmpi
.if ${FLAVOR} == openmpi
# See https://github.com/open-mpi/ompi/issues/3195 for details.
BROKEN_armv6=	PnetCDF requires MPI_Offset >= 8 but Open MPI sets MPI_Offset to 4 on 32-bit architecture regardless of LFS
BROKEN_armv7=	PnetCDF requires MPI_Offset >= 8 but Open MPI sets MPI_Offset to 4 on 32-bit architecture regardless of LFS
BROKEN_i386=	PnetCDF requires MPI_Offset >= 8 but Open MPI sets MPI_Offset to 4 on 32-bit architecture regardless of LFS
BROKEN_powerpc=	PnetCDF requires MPI_Offset >= 8 but Open MPI sets MPI_Offset to 4 on 32-bit architecture regardless of LFS
.endif

.include <bsd.port.mk>
