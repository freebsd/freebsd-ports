# Created by: Chao Shin <quakelee@cn.FreeBSD.org>
# $FreeBSD$

PORTNAME=	pnetcdf
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	science parallel
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/parallel-netcdf/ \
		LOCAL/sunpoet
DISTNAME=	parallel-netcdf-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library providing high-performance I/O

OPTIONS_DEFINE=	DOCS OPENMPI
OPENMPI_DESC=	Use openmpi instead of mpich2

CONFLICTS=	hdf-4.*

CFLAGS+=	-fPIC -DPIC
CONFIGURE_ENV=	M4FLAGS=""
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_FORTRAN=	yes
USES=		gmake

MAN1=		ncmpidiff.1 ncmpidump.1 ncmpigen.1
MAN3=		pnetcdf.3
PORTDOCS=	COPYRIGHT INSTALL README
PLIST_FILES=	bin/ncmpidiff bin/ncmpidump bin/ncmpigen bin/ncvalid \
		include/pnetcdf.h include/pnetcdf.inc include/pnetcdf.mod \
		lib/libpnetcdf.a

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMPI}
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:${PORTSDIR}/net/openmpi
CONFIGURE_ARGS+=--with-mpi=${LOCALBASE}/mpi/openmpi
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/lib/libmpich.so:${PORTSDIR}/net/mpich2
CONFIGURE_ARGS+=--with-mpi=${LOCALBASE}
.endif

post-install:
.for file in ncmpidiff ncmpidump ncmpigen ncvalid
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
