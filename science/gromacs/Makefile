# New ports collection makefile for: gromacs
# Date created:		August 28 2004
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	gromacs
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=	stephen@math.missouri.edu
COMMENT=	Compute molecular dynamics

.ifndef WITHOUT_FFTW
LIB_DEPENDS=	fftw:${PORTSDIR}/math/fftw:install
.endif
.ifdef WITH_MPI
BUILD_DEPENDS=	${LOCALBASE}/mpich/bin/mpicc:${PORTSDIR}/net/mpich
RUN_DEPENDS=	${LOCALBASE}/mpich/bin/mpicc:${PORTSDIR}/net/mpich
.endif

USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}

PLIST_SUB=	BUILD=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.ifndef WITHOUT_FFTW
.ifdef WITH_FLOAT
IGNORE=		Cannot currently build with fftw and single precision floating point
.elifdef WITH_MPI
IGNORE=		Cannot currently build with fftw and mpi support
.endif
.endif

.ifdef WITHOUT_X
PLIST_SUB+=	WITHOUT_X="@comment "
CONFIGURE_ARGS+=	--without-x
.else
PLIST_SUB+=	WITHOUT_X=
CONFIGURE_ARGS+=	--with-x
USE_XLIB=	yes
.endif

.ifndef WITH_FLOAT
CONFIGURE_ARGS+=	--disable-float --program-suffix=
PLIST_SUB+=	SUFFIX_D=_d SUFFIX_DOUBLE=_double
.else
PLIST_SUB+=	SUFFIX_D= SUFFIX_DOUBLE=
.endif

.ifdef WITHOUT_FFTW
CONFIGURE_ARGS+=	--without-fftw
.endif

.ifdef WITH_MPI
CONFIGURE_ARGS+=	--enable-mpi
CONFIGURE_ENV+=	MPICC=${PREFIX}/mpich/bin/mpicc
PLIST_SUB+=	WITH_MPI= SUFFIX_MPI=_mpi WITHOUT_MPI="@comment "
.else
PLIST_SUB+=	WITH_MPI="@comment " SUFFIX_MPI= WITHOUT_MPI=
.endif

MAN1=	anadock.1 \
	g_cluster.1 \
	g_filter.1 \
	g_potential.1 \
	g_velacc.1 \
	ngmx.1 \
	cdist.1 \
	g_clustsize.1 \
	g_gyrate.1 \
	g_rama.1 \
	g_wham.1 \
	pdb2gmx.1 \
	disco.1 \
	g_confrms.1 \
	g_h2order.1 \
	g_rdf.1 \
	genbox.1 \
	protonate.1 \
	do_dssp.1 \
	g_covar.1 \
	g_hbond.1 \
	g_rms.1 \
	genconf.1 \
	tpbconv.1 \
	editconf.1 \
	g_density.1 \
	g_helix.1 \
	g_rmsdist.1 \
	genion.1 \
	trjcat.1 \
	eneconv.1 \
	g_dielectric.1 \
	g_lie.1 \
	g_rmsf.1 \
	genpr.1 \
	trjconv.1 \
	ffscan.1 \
	g_dih.1 \
	g_mdmat.1 \
	g_rotacf.1 \
	gmxcheck.1 \
	trjorder.1 \
	g_anaeig.1 \
	g_dipoles.1 \
	g_mindist.1 \
	g_saltbr.1 \
	gmxdump.1 \
	wheel.1 \
	g_analyze.1 \
	g_disre.1 \
	g_morph.1 \
	g_sas.1 \
	grompp.1 \
	x2top.1 \
	g_angle.1 \
	g_dist.1 \
	g_msd.1 \
	g_sgangle.1 \
	highway.1 \
	xpm2ps.1 \
	g_bond.1 \
	g_dyndom.1 \
	g_nmeig.1 \
	g_sorient.1 \
	make_ndx.1 \
	xrama.1 \
	g_bundle.1 \
	g_enemat.1 \
	g_nmens.1 \
	g_tcaf.1 \
	mdrun.1 \
	g_chi.1 \
	g_energy.1 \
	g_order.1 \
	g_traj.1 \
	mk_angndx.1

.include <bsd.port.pre.mk>

pre-fetch:
	@${ECHO}
	@${ECHO} "OPTIONS:"
	@${ECHO}
	@${ECHO} "To compile without X11: define WITHOUT_X"
	@${ECHO} "To compile using single precision floating point: define WITH_FLOAT"
	@${ECHO} "To compile without fftw: define WITHOUT_FFTW"
	@${ECHO} "To compile with mpi: define WITH_MPI"
	@${ECHO}

.include <bsd.port.post.mk>
