# Created by: Chao Shin <quakelee@cn.FreeBSD.org>
# $FreeBSD$

PORTNAME=	pnetcdf
PORTVERSION=	1.8.1
PORTREVISION=	10
CATEGORIES=	science parallel
MASTER_SITES=	http://cucis.ece.northwestern.edu/projects/PnetCDF/Release/ \
		LOCAL/sunpoet
DISTNAME=	parallel-netcdf-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library providing high-performance I/O

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	MPI
OPTIONS_SINGLE_MPI=	OPENMPI OPENMPI3 MPICH
OPTIONS_DEFAULT=OPENMPI
OPENMPI_DESC=	Parallel processing support via Open MPI (current)
OPENMPI3_DESC=	Parallel processing support via Open MPI 3.x

CONFLICTS_INSTALL=	hdf-4.*

CFLAGS+=	-fPIC
CONFIGURE_ARGS=	ac_cv_fc_compiler_nag=no
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_PERL5=	build
USES=		fortran gmake pathfix perl5 tar:bzip2

PORTDOCS=	COPYRIGHT INSTALL README

MPICH_CONFIGURE_ON=	--with-mpi=${LOCALBASE}
MPICH_LIB_DEPENDS=	libmpich.so:net/mpich
OPENMPI_CONFIGURE_ON=	--with-mpi=${LOCALBASE}/mpi/openmpi
OPENMPI_LIB_DEPENDS=	libmpi.so:net/openmpi
OPENMPI3_CONFIGURE_ON=	--with-mpi=${LOCALBASE}/mpi/openmpi3
OPENMPI3_LIB_DEPENDS=	libmpi.so:net/openmpi3

post-patch:
	@${REINPLACE_CMD} -e '/$$(INSTALL.*$$(PREFIX)/ s|$$(PREFIX)|$$(DESTDIR)&|' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/n* ${STAGEDIR}${PREFIX}/bin/pnetcdf_version

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
