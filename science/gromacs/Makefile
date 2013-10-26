# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	gromacs
PORTVERSION=	4.6.3
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compute molecular dynamics

LICENSE=	LGPL21

OPTIONS_DEFINE=	ATLAS FLOAT GSL SIMD X11
OPTIONS_DEFAULT=	FLOAT GSL X11
OPTIONS_RADIO=	MPI
OPTIONS_RADIO_MPI=	MPICH OMPI

ATLAS_DESC=	Use ATLAS for BLAS and LAPACK
FLOAT_DESC=	Use single instead of double precision
GSL_DESC=	Extra analysis using math/gsl
MPICH_DESC=	MPI support using net/mpich2
OMPI_DESC=	MPI support using net/openmpi

USES=		cmake pkgconfig shebangfix perl5
SHEBANG_FILES=	admin/*.pl scripts/*.pl scripts/*.sh src/gmxlib/selection/*.sh
bash_CMD=	${SH}
USE_FORTRAN=	yes
CMAKE_ARGS=	-DBLAS_LIBRARIES:FILEPATH="${BLAS_LIBS}" \
		-DLAPACK_LIBRARIES:FILEPATH="${LAPACK_LIBS}"
USE_LDCONFIG=	yes

MAN1=		do_dssp.1 editconf.1 eneconv.1 g_anadock.1 \
		g_anaeig.1 g_analyze.1 g_angle.1 g_bar.1 \
		g_bond.1 g_bundle.1 g_chi.1 g_cluster.1 \
		g_clustsize.1 g_confrms.1 g_covar.1 g_current.1 \
		g_density.1 g_densmap.1 g_densorder.1 g_dielectric.1 \
		g_dipoles.1 g_disre.1 g_dist.1 g_dos.1 \
		g_dyecoupl.1 g_dyndom.1 g_enemat.1 g_energy.1 \
		g_filter.1 g_gyrate.1 g_h2order.1 g_hbond.1 \
		g_helix.1 g_helixorient.1 g_hydorder.1 g_kinetics.1 \
		g_lie.1 g_mdmat.1 g_membed.1 g_mindist.1 \
		g_morph.1 g_msd.1 g_nmeig.1 g_nmens.1 \
		g_nmtraj.1 g_order.1 g_pme_error.1 g_polystat.1 \
		g_potential.1 g_principal.1 g_protonate.1 g_rama.1 \
		g_rdf.1 g_rms.1 g_rmsdist.1 g_rmsf.1 \
		g_rotacf.1 g_rotmat.1 g_saltbr.1 g_sans.1 \
		g_sas.1 g_select.1 g_sgangle.1 g_sham.1 \
		g_sigeps.1 g_sorient.1 g_spatial.1 g_spol.1 \
		g_tcaf.1 g_traj.1 g_tune_pme.1 g_vanhove.1 \
		g_velacc.1 g_wham.1 g_wheel.1 g_x2top.1 \
		genbox.1 genconf.1 genion.1 genrestr.1 \
		gmxcheck.1 gmxdump.1 grompp.1 make_edi.1 \
		make_ndx.1 mdrun.1 mk_angndx.1 pdb2gmx.1 \
		tpbconv.1 trjcat.1 trjconv.1 trjorder.1 \
		xpm2ps.1
MAN7=		gromacs.7

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	alapack:${PORTSDIR}/math/atlas
BLAS_LIBS=	${LOCALBASE}/lib/libcblas.so;${LOCALBASE}/lib/libf77blas.so
LAPACK_LIBS=	${LOCALBASE}/lib/libalapack.so
.else
LIB_DEPENDS+=	blas:${PORTSDIR}/math/blas \
		lapack:${PORTSDIR}/math/lapack
BLAS_LIBS=	${LOCALBASE}/lib/libblas.so
LAPACK_LIBS=	${LOCALBASE}/lib/liblapack.so
.endif

.if ${PORT_OPTIONS:MFLOAT}
BUILD_DEPENDS+=	fftw3>0:${PORTSDIR}/math/fftw3
LIB_DEPENDS+=	fftw3f:${PORTSDIR}/math/fftw3-float
CMAKE_ARGS+=	-DGMX_DOUBLE:BOOL=OFF
PLIST_SUB+=	SUFFIX_D=""
.else
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
CMAKE_ARGS+=	-DGMX_DOUBLE:BOOL=ON
PLIST_SUB+=	SUFFIX_D="_d"
.endif

.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=	gsl:${PORTSDIR}/math/gsl
CMAKE_ARGS+=	-DGMX_GSL:BOOL=ON
.else
CMAKE_ARGS+=	-DGMX_GSL:BOOL=OFF
.endif

.if empty(PORT_OPTIONS:MSIMD)
CMAKE_ARGS+=	-DGMX_CPU_ACCELERATION:STRING="None"
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	xext x11
CMAKE_ARGS+=	-DGMX_X11:BOOL=ON
PLIST_SUB+=	X11=""
MAN1+=		g_xrama.1 ngmx.1
.else
CMAKE_ARGS+=	-DGMX_X11:BOOL=OFF
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MMPICH} || ${PORT_OPTIONS:MOMPI}
CMAKE_ARGS+=	-DGMX_MPI:BOOL=ON \
		-DMPI_C_COMPILER:FILEPATH="${MPICC}"
PLIST_SUB+=	SUFFIX_MPI="_mpi"
.else
CMAKE_ARGS+=	-DGMX_MPI:BOOL=OFF
PLIST_SUB+=	SUFFIX_MPI=""
.endif

.if ${PORT_OPTIONS:MMPICH}
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
MPICC=		${LOCALBASE}/bin/mpicc
.endif

.if ${PORT_OPTIONS:MOMPI}
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
MPICC=		${LOCALBASE}/mpi/openmpi/bin/mpicc
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "CMakeLists.txt" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|share/man|man| ; \
		 s|-lpthread|-pthread| ; \
		 /pkgconfig/s|LIB_INSTALL_DIR}|CMAKE_INSTALL_PREFIX}/libdata|'
	@${FIND} ${WRKSRC} -name "GMXRC.*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|LDLIB/pkgconfig|LDLIB/../libdata/pkgconfig| ; \
		 s|LDLIB}/pkgconfig|LDLIB}/../libdata/pkgconfig|'

.include <bsd.port.mk>
