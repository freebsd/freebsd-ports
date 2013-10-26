# Created by: Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	octave-forge
PORTVERSION=	20130917
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	#none
DISTFILES=	#none
EXTRACT_ONLY=	#none

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge metaport for math/octave

OPTIONS_DEFINE=	ACTUARIAL AD AUDIO BENCHMARK BIM BIOINFO CGI \
		CIVIL_ENGINEERING COMMUNICATIONS CONTROL DATA_SMOOTHING \
		DATABASE DATAFRAME DICOM ECONOMETRICS ENGINE FENV FITS \
		FINANCIAL FL_CORE FPL FUZZY_LOGIC_TOOLKIT GA GEOMETRY GENERAL \
		GENERATE_HTML GNUPLOT GSL IDENT IMAGE INFORMATIONTHEORY \
		INTEGRATION IO IRSA LINEAR_ALGEBRA LSSA LTFAT MAPPING \
		MECHANICS MISCELLANEOUS MISSING_FUNCTIONS MSH MULTICORE NAN \
		NCARRAY NETCDF NLWING2 NNET NURBS OCS OCT2MAT OCTCDF OCTCLIP \
		OCTGPR OCTPROJ ODEBVP ODEPKG OPTIM OPTIMINTERP OUTLIERS \
		PARALLEL PDB PLOT PT_BR QUATERNION QUEUEING SECS1D SECS2D \
		SECS3D SIGNAL SIMP SOCKETS SPECFUN SPECIAL_MATRIX \
		SPLINE_GCVSPL SPLINES STATISTICS STRINGS STRUCT SYMBAND \
		SYMBOLIC TCL_OCTAVE TSA VIDEO XRAYLIB ZENITY

ACTUARIAL_DESC=		Install package: actuarial
AD_DESC=		Install package: ad
AUDIO_DESC=		Install package: audio
BENCHMARK_DESC=		Install package: benchmark
BIM_DESC=		Install package: bim
BIOINFO_DESC=		Install package: bioinfo
CGI_DESC=		Install package: cgi
CIVIL_ENGINEERING_DESC=	Install package: civil-engineering
COMMUNICATIONS_DESC=	Install package: communications
CONTROL_DESC=		Install package: control
DATA_SMOOTHING_DESC=	Install package: data-smoothing
DATABASE_DESC=		Install package: database
DATAFRAME_DESC=		Install package: dataframe
DICOM_DESC=		Install package: dicom
ECONOMETRICS_DESC=	Install package: econometrics
ENGINE_DESC=		Install package: engine
FENV_DESC=		Install package: fenv
FITS_DESC=		Install package: fits
FINANCIAL_DESC=		Install package: financial
FL_CORE_DESC=		Install package: fl-core
FPL_DESC=		Install package: fpl
FUZZY_LOGIC_TOOLKIT_DESC=	Install package: fuzzy-logic-toolkit
GA_DESC=		Install package: ga
GEOMETRY_DESC=		Install package: geometry
GENERAL_DESC=		Install package: general
GENERATE_HTML_DESC=	Install package: generate_html
GNUPLOT_DESC=		Install package: gnuplot
GSL_DESC=		Install package: gsl
IDENT_DESC=		Install package: ident
IMAGE_DESC=		Install package: image
INFORMATIONTHEORY_DESC=	Install package: informationtheory
INTEGRATION_DESC=	Install package: integration
IO_DESC=		Install package: io
IRSA_DESC=		Install package: irsa
LINEAR_ALGEBRA_DESC=	Install package: linear-algebra
LSSA_DESC=		Install package: lssa
LTFAT_DESC=		Install package: ltfat
MAPPING_DESC=		Install package: mapping
MECHANICS_DESC=		Install package: mechanics
MISCELLANEOUS_DESC=	Install package: miscellaneous
MISSING_FUNCTIONS_DESC=	Install package: missing-functions
MSH_DESC=		Install package: msh
MULTICORE_DESC=		Install package: multicore
NAN_DESC=		Install package: nan
NCARRAY_DESC=		Install package: ncarray
NETCDF_DESC=		Install package: netcdf
NLWING2_DESC=		Install package: nlwing2
NNET_DESC=		Install package: nnet
NURBS_DESC=		Install package: nurbs
OCS_DESC=		Install package: ocs
OCT2MAT_DESC=		Install package: oct2mat
OCTCDF_DESC=		Install package: octcdf
OCTCLIP_DESC=		Install package: octclip
OCTGPR_DESC=		Install package: octgpr
OCTPROJ_DESC=		Install package: octproj
ODEBVP_DESC=		Install package: odebvp
ODEPKG_DESC=		Install package: odepkg
OPTIM_DESC=		Install package: optim
OPTIMINTERP_DESC=	Install package: optiminterp
OUTLIERS_DESC=		Install package: outliers
PARALLEL_DESC=		Install package: parallel
PDB_DESC=		Install package: pdb
PLOT_DESC=		Install package: plot
PT_BR_DESC=		Install package: pt_br
QUATERNION_DESC=	Install package: quaternion
QUEUEING_DESC=		Install package: queueing
SECS1D_DESC=		Install package: secs1d
SECS2D_DESC=		Install package: secs2d
SECS3D_DESC=		Install package: secs3d
SIGNAL_DESC=		Install package: signal
SIMP_DESC=		Install package: simp
SOCKETS_DESC=		Install package: sockets
SPECFUN_DESC=		Install package: specfun
SPECIAL_MATRIX_DESC=	Install package: special-matrix
SPLINE_GCVSPL_DESC=	Install package: spline-gcvspl
SPLINES_DESC=		Install package: splines
STATISTICS_DESC=	Install package: statistics
STRINGS_DESC=		Install package: strings
STRUCT_DESC=		Install package: struct
SYMBAND_DESC=		Install package: symband
SYMBOLIC_DESC=		Install package: symbolic
TCL_OCTAVE_DESC=	Install package: tcl-octave
TSA_DESC=		Install package: tsa
VIDEO_DESC=		Install package: video
XRAYLIB_DESC=		Install package: xraylib
ZENITY_DESC=		Install package: zenity

OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MACTUARIAL}
RUN_DEPENDS+=	${TARBALLS_DIR}/actuarial.tar.gz:${PORTSDIR}/math/octave-forge-actuarial
.endif
.if ${PORT_OPTIONS:MAD}
RUN_DEPENDS+=	${TARBALLS_DIR}/ad.tar.gz:${PORTSDIR}/math/octave-forge-ad
.endif
.if ${PORT_OPTIONS:MAUDIO}
RUN_DEPENDS+=	${TARBALLS_DIR}/audio.tar.gz:${PORTSDIR}/math/octave-forge-audio
.endif
.if ${PORT_OPTIONS:MBENCHMARK}
RUN_DEPENDS+=	${TARBALLS_DIR}/benchmark.tar.gz:${PORTSDIR}/benchmarks/octave-forge-benchmark
.endif
.if ${PORT_OPTIONS:MBIM}
RUN_DEPENDS+=	${TARBALLS_DIR}/bim.tar.gz:${PORTSDIR}/math/octave-forge-bim
.endif
.if ${PORT_OPTIONS:MBIOINFO}
RUN_DEPENDS+=	${TARBALLS_DIR}/bioinfo.tar.gz:${PORTSDIR}/math/octave-forge-bioinfo
.endif
.if ${PORT_OPTIONS:MCGI}
RUN_DEPENDS+=	${TARBALLS_DIR}/cgi.tar.gz:${PORTSDIR}/math/octave-forge-cgi
.endif
.if ${PORT_OPTIONS:MCIVIL_ENGINEERING}
RUN_DEPENDS+=	${TARBALLS_DIR}/civil-engineering.tar.gz:${PORTSDIR}/math/octave-forge-civil-engineering
.endif
.if ${PORT_OPTIONS:MCOMMUNICATIONS}
RUN_DEPENDS+=	${TARBALLS_DIR}/communications.tar.gz:${PORTSDIR}/math/octave-forge-communications
.endif
.if ${PORT_OPTIONS:MCONTROL}
RUN_DEPENDS+=	${TARBALLS_DIR}/control.tar.gz:${PORTSDIR}/math/octave-forge-control
.endif
.if ${PORT_OPTIONS:MDATA_SMOOTHING}
RUN_DEPENDS+=	${TARBALLS_DIR}/data-smoothing.tar.gz:${PORTSDIR}/math/octave-forge-data-smoothing
.endif
.if ${PORT_OPTIONS:MDATABASE}
RUN_DEPENDS+=	${TARBALLS_DIR}/database.tar.gz:${PORTSDIR}/math/octave-forge-database
.endif
.if ${PORT_OPTIONS:MDATAFRAME}
RUN_DEPENDS+=	${TARBALLS_DIR}/dataframe.tar.gz:${PORTSDIR}/math/octave-forge-dataframe
.endif
.if ${PORT_OPTIONS:MDICOM}
RUN_DEPENDS+=	${TARBALLS_DIR}/dicom.tar.gz:${PORTSDIR}/math/octave-forge-dicom
.endif
.if ${PORT_OPTIONS:MECONOMETRICS}
RUN_DEPENDS+=	${TARBALLS_DIR}/econometrics.tar.gz:${PORTSDIR}/math/octave-forge-econometrics
.endif
.if ${PORT_OPTIONS:MENGINE}
RUN_DEPENDS+=	${TARBALLS_DIR}/engine.tar.gz:${PORTSDIR}/math/octave-forge-engine
.endif
.if ${PORT_OPTIONS:MFENV}
RUN_DEPENDS+=	${TARBALLS_DIR}/fenv.tar.gz:${PORTSDIR}/math/octave-forge-fenv
.endif
.if ${PORT_OPTIONS:MFITS}
RUN_DEPENDS+=	${TARBALLS_DIR}/fits.tar.gz:${PORTSDIR}/math/octave-forge-fits
.endif
.if ${PORT_OPTIONS:MFINANCIAL}
RUN_DEPENDS+=	${TARBALLS_DIR}/financial.tar.gz:${PORTSDIR}/math/octave-forge-financial
.endif
.if ${PORT_OPTIONS:MFL_CORE}
RUN_DEPENDS+=	${TARBALLS_DIR}/fl-core.tar.gz:${PORTSDIR}/math/octave-forge-fl-core
.endif
.if ${PORT_OPTIONS:MFPL}
RUN_DEPENDS+=	${TARBALLS_DIR}/fpl.tar.gz:${PORTSDIR}/math/octave-forge-fpl
.endif
.if ${PORT_OPTIONS:MFUZZY_LOGIC_TOOLKIT}
RUN_DEPENDS+=	${TARBALLS_DIR}/fuzzy-logic-toolkit.tar.gz:${PORTSDIR}/math/octave-forge-fuzzy-logic-toolkit
.endif
.if ${PORT_OPTIONS:MGA}
RUN_DEPENDS+=	${TARBALLS_DIR}/ga.tar.gz:${PORTSDIR}/math/octave-forge-ga
.endif
.if ${PORT_OPTIONS:MGEOMETRY}
RUN_DEPENDS+=	${TARBALLS_DIR}/geometry.tar.gz:${PORTSDIR}/math/octave-forge-geometry
.endif
.if ${PORT_OPTIONS:MGENERAL}
RUN_DEPENDS+=	${TARBALLS_DIR}/general.tar.gz:${PORTSDIR}/math/octave-forge-general
.endif
.if ${PORT_OPTIONS:MGENERATE_HTML}
RUN_DEPENDS+=	${TARBALLS_DIR}/generate_html.tar.gz:${PORTSDIR}/math/octave-forge-generate_html
.endif
.if ${PORT_OPTIONS:MGNUPLOT}
RUN_DEPENDS+=	${TARBALLS_DIR}/gnuplot.tar.gz:${PORTSDIR}/math/octave-forge-gnuplot
.endif
.if ${PORT_OPTIONS:MGSL}
RUN_DEPENDS+=	${TARBALLS_DIR}/gsl.tar.gz:${PORTSDIR}/math/octave-forge-gsl
.endif
.if ${PORT_OPTIONS:MIDENT}
RUN_DEPENDS+=	${TARBALLS_DIR}/ident.tar.gz:${PORTSDIR}/math/octave-forge-ident
.endif
.if ${PORT_OPTIONS:MIMAGE}
RUN_DEPENDS+=	${TARBALLS_DIR}/image.tar.gz:${PORTSDIR}/math/octave-forge-image
.endif
.if ${PORT_OPTIONS:MINFORMATIONTHEORY}
RUN_DEPENDS+=	${TARBALLS_DIR}/informationtheory.tar.gz:${PORTSDIR}/math/octave-forge-informationtheory
.endif
.if ${PORT_OPTIONS:MINTEGRATION}
RUN_DEPENDS+=	${TARBALLS_DIR}/integration.tar.gz:${PORTSDIR}/math/octave-forge-integration
.endif
.if ${PORT_OPTIONS:MIO}
RUN_DEPENDS+=	${TARBALLS_DIR}/io.tar.gz:${PORTSDIR}/math/octave-forge-io
.endif
.if ${PORT_OPTIONS:MIRSA}
RUN_DEPENDS+=	${TARBALLS_DIR}/irsa.tar.gz:${PORTSDIR}/math/octave-forge-irsa
.endif
.if ${PORT_OPTIONS:MLINEAR_ALGEBRA}
RUN_DEPENDS+=	${TARBALLS_DIR}/linear-algebra.tar.gz:${PORTSDIR}/math/octave-forge-linear-algebra
.endif
.if ${PORT_OPTIONS:MLSSA}
RUN_DEPENDS+=	${TARBALLS_DIR}/lssa.tar.gz:${PORTSDIR}/math/octave-forge-lssa
.endif
.if ${PORT_OPTIONS:MLTFAT}
RUN_DEPENDS+=	${TARBALLS_DIR}/ltfat.tar.gz:${PORTSDIR}/math/octave-forge-ltfat
.endif
.if ${PORT_OPTIONS:MMAPPING}
RUN_DEPENDS+=	${TARBALLS_DIR}/mapping.tar.gz:${PORTSDIR}/math/octave-forge-mapping
.endif
.if ${PORT_OPTIONS:MMECHANICS}
RUN_DEPENDS+=	${TARBALLS_DIR}/mechanics.tar.gz:${PORTSDIR}/math/octave-forge-mechanics
.endif
.if ${PORT_OPTIONS:MMISCELLANEOUS}
RUN_DEPENDS+=	${TARBALLS_DIR}/miscellaneous.tar.gz:${PORTSDIR}/math/octave-forge-miscellaneous
.endif
.if ${PORT_OPTIONS:MMISSING_FUNCTIONS}
RUN_DEPENDS+=	${TARBALLS_DIR}/missing-functions.tar.gz:${PORTSDIR}/math/octave-forge-missing-functions
.endif
.if ${PORT_OPTIONS:MMSH}
RUN_DEPENDS+=	${TARBALLS_DIR}/msh.tar.gz:${PORTSDIR}/math/octave-forge-msh
.endif
.if ${PORT_OPTIONS:MMULTICORE}
RUN_DEPENDS+=	${TARBALLS_DIR}/multicore.tar.gz:${PORTSDIR}/math/octave-forge-multicore
.endif
.if ${PORT_OPTIONS:MNAN}
RUN_DEPENDS+=	${TARBALLS_DIR}/nan.tar.gz:${PORTSDIR}/math/octave-forge-nan
.endif
.if ${PORT_OPTIONS:MNCARRAY}
RUN_DEPENDS+=	${TARBALLS_DIR}/ncarray.tar.gz:${PORTSDIR}/math/octave-forge-ncarray
.endif
.if ${PORT_OPTIONS:MNETCDF}
RUN_DEPENDS+=	${TARBALLS_DIR}/netcdf.tar.gz:${PORTSDIR}/math/octave-forge-netcdf
.endif
.if ${PORT_OPTIONS:MNLWING2}
RUN_DEPENDS+=	${TARBALLS_DIR}/nlwing2.tar.gz:${PORTSDIR}/math/octave-forge-nlwing2
.endif
.if ${PORT_OPTIONS:MNNET}
RUN_DEPENDS+=	${TARBALLS_DIR}/nnet.tar.gz:${PORTSDIR}/math/octave-forge-nnet
.endif
.if ${PORT_OPTIONS:MNURBS}
RUN_DEPENDS+=	${TARBALLS_DIR}/nurbs.tar.gz:${PORTSDIR}/math/octave-forge-nurbs
.endif
.if ${PORT_OPTIONS:MOCS}
RUN_DEPENDS+=	${TARBALLS_DIR}/ocs.tar.gz:${PORTSDIR}/math/octave-forge-ocs
.endif
.if ${PORT_OPTIONS:MOCT2MAT}
RUN_DEPENDS+=	${TARBALLS_DIR}/oct2mat.tar.gz:${PORTSDIR}/math/octave-forge-oct2mat
.endif
.if ${PORT_OPTIONS:MOCTCDF}
RUN_DEPENDS+=	${TARBALLS_DIR}/octcdf.tar.gz:${PORTSDIR}/math/octave-forge-octcdf
.endif
.if ${PORT_OPTIONS:MOCTCLIP}
RUN_DEPENDS+=	${TARBALLS_DIR}/octclip.tar.gz:${PORTSDIR}/math/octave-forge-octclip
.endif
.if ${PORT_OPTIONS:MOCTGPR}
RUN_DEPENDS+=	${TARBALLS_DIR}/octgpr.tar.gz:${PORTSDIR}/math/octave-forge-octgpr
.endif
.if ${PORT_OPTIONS:MOCTPROJ}
RUN_DEPENDS+=	${TARBALLS_DIR}/octproj.tar.gz:${PORTSDIR}/math/octave-forge-octproj
.endif
.if ${PORT_OPTIONS:MODEBVP}
RUN_DEPENDS+=	${TARBALLS_DIR}/odebvp.tar.gz:${PORTSDIR}/math/octave-forge-odebvp
.endif
.if ${PORT_OPTIONS:MODEPKG}
RUN_DEPENDS+=	${TARBALLS_DIR}/odepkg.tar.gz:${PORTSDIR}/math/octave-forge-odepkg
.endif
.if ${PORT_OPTIONS:MOPTIM}
RUN_DEPENDS+=	${TARBALLS_DIR}/optim.tar.gz:${PORTSDIR}/math/octave-forge-optim
.endif
.if ${PORT_OPTIONS:MOPTIMINTERP}
RUN_DEPENDS+=	${TARBALLS_DIR}/optiminterp.tar.gz:${PORTSDIR}/math/octave-forge-optiminterp
.endif
.if ${PORT_OPTIONS:MOUTLIERS}
RUN_DEPENDS+=	${TARBALLS_DIR}/outliers.tar.gz:${PORTSDIR}/math/octave-forge-outliers
.endif
.if ${PORT_OPTIONS:MPARALLEL}
RUN_DEPENDS+=	${TARBALLS_DIR}/parallel.tar.gz:${PORTSDIR}/math/octave-forge-parallel
.endif
.if ${PORT_OPTIONS:MPDB}
RUN_DEPENDS+=	${TARBALLS_DIR}/pdb.tar.gz:${PORTSDIR}/math/octave-forge-pdb
.endif
.if ${PORT_OPTIONS:MPLOT}
RUN_DEPENDS+=	${TARBALLS_DIR}/plot.tar.gz:${PORTSDIR}/math/octave-forge-plot
.endif
.if ${PORT_OPTIONS:MPT_BR}
RUN_DEPENDS+=	${TARBALLS_DIR}/pt_br.tar.gz:${PORTSDIR}/math/octave-forge-pt_br
.endif
.if ${PORT_OPTIONS:MQUATERNION}
RUN_DEPENDS+=	${TARBALLS_DIR}/quaternion.tar.gz:${PORTSDIR}/math/octave-forge-quaternion
.endif
.if ${PORT_OPTIONS:MQUEUEING}
RUN_DEPENDS+=	${TARBALLS_DIR}/queueing.tar.gz:${PORTSDIR}/math/octave-forge-queueing
.endif
.if ${PORT_OPTIONS:MSECS1D}
RUN_DEPENDS+=	${TARBALLS_DIR}/secs1d.tar.gz:${PORTSDIR}/math/octave-forge-secs1d
.endif
.if ${PORT_OPTIONS:MSECS2D}
RUN_DEPENDS+=	${TARBALLS_DIR}/secs2d.tar.gz:${PORTSDIR}/math/octave-forge-secs2d
.endif
.if ${PORT_OPTIONS:MSECS3D}
RUN_DEPENDS+=	${TARBALLS_DIR}/secs3d.tar.gz:${PORTSDIR}/math/octave-forge-secs3d
.endif
.if ${PORT_OPTIONS:MSIGNAL}
RUN_DEPENDS+=	${TARBALLS_DIR}/signal.tar.gz:${PORTSDIR}/math/octave-forge-signal
.endif
.if ${PORT_OPTIONS:MSIMP}
RUN_DEPENDS+=	${TARBALLS_DIR}/simp.tar.gz:${PORTSDIR}/math/octave-forge-simp
.endif
.if ${PORT_OPTIONS:MSOCKETS}
RUN_DEPENDS+=	${TARBALLS_DIR}/sockets.tar.gz:${PORTSDIR}/math/octave-forge-sockets
.endif
.if ${PORT_OPTIONS:MSPECFUN}
RUN_DEPENDS+=	${TARBALLS_DIR}/specfun.tar.gz:${PORTSDIR}/math/octave-forge-specfun
.endif
.if ${PORT_OPTIONS:MSPECIAL_MATRIX}
RUN_DEPENDS+=	${TARBALLS_DIR}/special-matrix.tar.gz:${PORTSDIR}/math/octave-forge-special-matrix
.endif
.if ${PORT_OPTIONS:MSPLINE_GCVSPL}
RUN_DEPENDS+=	${TARBALLS_DIR}/spline-gcvspl.tar.gz:${PORTSDIR}/math/octave-forge-spline-gcvspl
.endif
.if ${PORT_OPTIONS:MSPLINES}
RUN_DEPENDS+=	${TARBALLS_DIR}/splines.tar.gz:${PORTSDIR}/math/octave-forge-splines
.endif
.if ${PORT_OPTIONS:MSTATISTICS}
RUN_DEPENDS+=	${TARBALLS_DIR}/statistics.tar.gz:${PORTSDIR}/math/octave-forge-statistics
.endif
.if ${PORT_OPTIONS:MSTRINGS}
RUN_DEPENDS+=	${TARBALLS_DIR}/strings.tar.gz:${PORTSDIR}/math/octave-forge-strings
.endif
.if ${PORT_OPTIONS:MSTRUCT}
RUN_DEPENDS+=	${TARBALLS_DIR}/struct.tar.gz:${PORTSDIR}/math/octave-forge-struct
.endif
.if ${PORT_OPTIONS:MSYMBAND}
RUN_DEPENDS+=	${TARBALLS_DIR}/symband.tar.gz:${PORTSDIR}/math/octave-forge-symband
.endif
.if ${PORT_OPTIONS:MSYMBOLIC}
RUN_DEPENDS+=	${TARBALLS_DIR}/symbolic.tar.gz:${PORTSDIR}/math/octave-forge-symbolic
.endif
.if ${PORT_OPTIONS:MTCL_OCTAVE}
RUN_DEPENDS+=	${TARBALLS_DIR}/tcl-octave.tar.gz:${PORTSDIR}/math/octave-forge-tcl-octave
.endif
.if ${PORT_OPTIONS:MTSA}
RUN_DEPENDS+=	${TARBALLS_DIR}/tsa.tar.gz:${PORTSDIR}/math/octave-forge-tsa
.endif
.if ${PORT_OPTIONS:MVIDEO}
RUN_DEPENDS+=	${TARBALLS_DIR}/video.tar.gz:${PORTSDIR}/math/octave-forge-video
.endif
.if ${PORT_OPTIONS:MXRAYLIB}
RUN_DEPENDS+=	${TARBALLS_DIR}/xraylib.tar.gz:${PORTSDIR}/math/octave-forge-xraylib
.endif
.if ${PORT_OPTIONS:MZENITY}
RUN_DEPENDS+=	${TARBALLS_DIR}/zenity.tar.gz:${PORTSDIR}/math/octave-forge-zenity
.endif

TARBALLS_DIR=	${LOCALBASE}/share/octave/tarballs

do-build:
	@${DO_NADA}

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
