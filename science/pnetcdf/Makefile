# Created by: Chao Shin <quakelee@cn.FreeBSD.org>

PORTNAME=	pnetcdf
PORTVERSION=	1.12.3
CATEGORIES=	science parallel
MASTER_SITES=	https://parallel-netcdf.github.io/Release/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library providing high-performance I/O

USES=		fortran gmake libtool pathfix perl5
USE_PERL5=	build

CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--with-mpi=${MPI_HOME} ac_cv_fc_compiler_nag=no
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	hdf-4.*

OPTIONS_SINGLE=	MPI
OPTIONS_SINGLE_MPI=	OPENMPI MPICH
OPTIONS_DEFAULT=OPENMPI

MPICH_USES=	mpi:mpich
OPENMPI_USES=	mpi:openmpi

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (INTEGER(8)/CHARACTER(*)).
FCFLAGS+=	-fallow-argument-mismatch
.endif

post-patch:
	@${REINPLACE_CMD} -e '/$$(INSTALL.*$$(PREFIX)/ s|$$(PREFIX)|$$(DESTDIR)&|' ${WRKSRC}/Makefile.in

x-post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cdfdiff ${STAGEDIR}${PREFIX}/bin/n* ${STAGEDIR}${PREFIX}/bin/pnetcdf_version

.include <bsd.port.post.mk>
