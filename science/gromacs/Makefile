# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	gromacs
PORTVERSION=	4.5.5
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compute molecular dynamics

USE_GNOME=	libxml2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} --program-suffix="" --enable-shared

PLIST_SUB=	BUILD=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS_DEFINE= FFTW GSL FLOAT X11 MPI
OPTIONS_DEFAULT= FFTW FFTW3 GSL X11
OPTIONS_SINGLE=	FFTW MPI
OPTIONS_SINGLE_FFTW=	FFTW2 FFTW3
OPTIONS_SINGLE_MPI=	MPICH OMPI

FFTW_DESC=	Use FFT routines
FFTW2_DESC=	Use FFT routines from math/fftw
FFTW3_DESC=	Use FFT routines from math/fftw3
GSL_DESC=	Enable extra analysis using math/gsl
FLOAT_DESC=	Use single instead of double precision
MPI_DESC=	Enable MPI support
MPICH_DESC=	Enable MPI support using net/mpich2
OMPI_DESC=	Enable MPI support using net/openmpi

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
CONFIGURE_ARGS+=	--disable-ia32-sse
.endif

.if ${PORT_OPTIONS:MFFTW3}
CONFIGURE_ARGS+=	--with-fft=fftw3
. if ${PORT_OPTIONS:MFLOAT}
LIB_DEPENDS+=	fftw3f:${PORTSDIR}/math/fftw3-float
. else
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
. endif
.else
. if ${PORT_OPTIONS:MFFTW2}
CONFIGURE_ARGS+=	--with-fft=fftw2
.  if ${PORT_OPTIONS:MFLOAT}
LIB_DEPENDS+=	sfftw.2:${PORTSDIR}/math/fftw-float
.  else
LIB_DEPENDS+=	fftw.2:${PORTSDIR}/math/fftw
.  endif
. else
CONFIGURE_ARGS+=	--with-fft=fftpack
. endif
.endif

.if ${PORT_OPTIONS:MGSL}
CONFIGURE_ARGS+=	--with-gsl
LIB_DEPENDS+=	gsl.16:${PORTSDIR}/math/gsl
.else
CONFIGURE_ARGS+=	--without-gsl
.endif

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
CONFIGURE_ARGS+=	--with-x
USE_XORG=	x11
.else
PLIST_SUB+=	X11="@comment "
CONFIGURE_ARGS+=	--without-x
.endif

.if ${PORT_OPTIONS:MFLOAT}
PLIST_SUB+=	SUFFIX_D="" SUFFIX_DOUBLE=""
.else
CONFIGURE_ARGS+=	--disable-float
PLIST_SUB+=	SUFFIX_D=_d SUFFIX_DOUBLE=_double
.endif

.if ${PORT_OPTIONS:MMPICH} || ${PORT_OPTIONS:MOMPI}
CONFIGURE_ARGS+=	--enable-mpi
.if ${PORT_OPTIONS:MMPICH}
CONFIGURE_ENV+=	MPICC=${PREFIX}/bin/mpicc
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
.elif ${PORT_OPTIONS:MOMPI}
CONFIGURE_ENV+=	MPICC=${PREFIX}/mpi/openmpi/bin/mpicc
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
.endif
PLIST_SUB+=	SUFFIX_MPI="_mpi" MPI=""
.else
PLIST_SUB+=	SUFFIX_MPI="" MPI="@comment "
.endif

MAN1=	do_dssp.1 \
	editconf.1 \
	eneconv.1 \
	g_anadock.1 \
	g_anaeig.1 \
	g_analyze.1 \
	g_angle.1 \
	g_bar.1 \
	g_bond.1 \
	g_bundle.1 \
	g_chi.1 \
	g_cluster.1 \
	g_clustsize.1 \
	g_confrms.1 \
	g_covar.1 \
	g_current.1 \
	g_density.1 \
	g_densmap.1 \
	g_densorder.1 \
	g_dielectric.1 \
	g_dih.1 \
	g_dipoles.1 \
	g_disre.1 \
	g_dist.1 \
	g_dyndom.1 \
	g_enemat.1 \
	g_energy.1 \
	g_filter.1 \
	g_gyrate.1 \
	g_h2order.1 \
	g_hbond.1 \
	g_helix.1 \
	g_helixorient.1 \
	g_hydorder.1 \
	g_lie.1 \
	g_mdmat.1 \
	g_membed.1 \
	g_mindist.1 \
	g_morph.1 \
	g_msd.1 \
	g_nmeig.1 \
	g_nmens.1 \
	g_nmtraj.1 \
	g_options.1 \
	g_order.1 \
	g_pme_error.1 \
	g_polystat.1 \
	g_potential.1 \
	g_principal.1 \
	g_protonate.1 \
	g_rama.1 \
	g_rdf.1 \
	g_rms.1 \
	g_rmsdist.1 \
	g_rmsf.1 \
	g_rotacf.1 \
	g_rotmat.1 \
	g_saltbr.1 \
	g_sas.1 \
	g_select.1 \
	g_sgangle.1 \
	g_sham.1 \
	g_sigeps.1 \
	g_sorient.1 \
	g_spatial.1 \
	g_spol.1 \
	g_tcaf.1 \
	g_traj.1 \
	g_tune_pme.1 \
	g_vanhove.1 \
	g_velacc.1 \
	g_wham.1 \
	g_wheel.1 \
	g_x2top.1 \
	g_xrama.1 \
	genbox.1 \
	genconf.1 \
	genion.1 \
	genrestr.1 \
	gmxcheck.1 \
	gmxdump.1 \
	grompp.1 \
	make_edi.1 \
	make_ndx.1 \
	mdrun.1 \
	mk_angndx.1 \
	ngmx.1 \
	pdb2gmx.1 \
	tpbconv.1 \
	trjcat.1 \
	trjconv.1 \
	trjorder.1 \
	xpm2ps.1

MAN7=	gromacs.7

.include <bsd.port.post.mk>
