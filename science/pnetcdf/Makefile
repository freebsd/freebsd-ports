# Created by: Chao Shin <quakelee@cn.FreeBSD.org>
# $FreeBSD$

PORTNAME=	pnetcdf
PORTVERSION=	1.7.0
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

CONFLICTS_INSTALL=	hdf-4.*

CFLAGS+=	-fPIC -DPIC
CONFIGURE_ARGS=	ac_cv_fc_compiler_nag=no
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_PERL5=	build
USES=		fortran gmake pathfix perl5 tar:bzip2

PORTDOCS=	COPYRIGHT INSTALL README

MPICH2_CONFIGURE_ON=	--with-mpi=${LOCALBASE}
MPICH2_LIB_DEPENDS=	libmpich.so:net/mpich2
OPENMPI_CONFIGURE_ON=	--with-mpi=${LOCALBASE}/mpi/openmpi
OPENMPI_LIB_DEPENDS=	libmpi.so:net/openmpi

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e '/$$(INSTALL.*$$(...DIR)/ s|$$(...DIR)|$$(DESTDIR)&|'
	@${REINPLACE_CMD} -e '/$$(INSTALL.*$$(PREFIX)/ s|$$(PREFIX)|$$(DESTDIR)&|' ${WRKSRC}/src/lib/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
