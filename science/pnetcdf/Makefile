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

USES=		fortran gmake pathfix perl5 tar:bzip2
USE_PERL5=	build

CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--with-mpi=${MPI_HOME} ac_cv_fc_compiler_nag=no
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	COPYRIGHT INSTALL README

CONFLICTS_INSTALL=	hdf-4.*

OPTIONS_DEFINE=	DOCS
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

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/n* ${STAGEDIR}${PREFIX}/bin/pnetcdf_version

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
