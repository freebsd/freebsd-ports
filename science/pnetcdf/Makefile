# New ports collection makefile for:	pnetcdf
# Date created:		April 30 2007
# Whom:			Chao Shin <quakelee@cn.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pnetcdf
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	science parallel
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/parallel-netcdf/
DISTNAME=	parallel-netcdf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library providing high-performance I/O

OPTIONS=	OPENMPI "Use openmpi instead of mpich2" off

CONFLICTS=	hdf-4.*

USE_BZIP2=	yes
USE_FORTRAN=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4FLAGS=""

MAN1=		ncmpidiff.1 ncmpidump.1 ncmpigen.1
MAN3=		pnetcdf.3
PORTDOCS=	COPYRIGHT INSTALL README
PLIST_FILES=	bin/ncmpidiff bin/ncmpidump bin/ncmpigen bin/ncvalid \
		include/pnetcdf.h include/pnetcdf.inc include/pnetcdf.mod \
		lib/libpnetcdf.a

CFLAGS+=	-fPIC -DPIC

.include <bsd.port.pre.mk>

.if defined(WITH_OPENMPI)
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
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
