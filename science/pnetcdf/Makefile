# Created by: Chao Shin <quakelee@cn.FreeBSD.org>
# $FreeBSD$

PORTNAME=	pnetcdf
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	science parallel
MASTER_SITES=	http://cucis.ece.northwestern.edu/projects/PnetCDF/Release/ \
		LOCAL/sunpoet
DISTNAME=	parallel-netcdf-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library providing high-performance I/O

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	MPI
OPTIONS_SINGLE_MPI=	OPENMPI MPICH2
OPTIONS_DEFAULT=OPENMPI

CONFLICTS=	hdf-4.*

CFLAGS+=	-fPIC -DPIC
CONFIGURE_ENV=	M4FLAGS=""
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_BZIP2=	yes
USES=		fortran gmake

PORTDOCS=	COPYRIGHT INSTALL README

MPICH2_CONFIGURE_ON=	--with-mpi=${LOCALBASE}
MPICH2_LIB_DEPENDS=	libmpich.so:${PORTSDIR}/net/mpich2
OPENMPI_CONFIGURE_ON=	--with-mpi=${LOCALBASE}/mpi/openmpi
OPENMPI_LIB_DEPENDS=	libmpi.so:${PORTSDIR}/net/openmpi

post-install:
.for file in ncmpidiff ncmpidump ncmpigen ncmpivalid
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
