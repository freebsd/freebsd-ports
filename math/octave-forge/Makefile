# New ports collection makefile for:	octave-forge
# Date created:		5 May 2004
# Whom:			Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	octave-forge
PORTVERSION=	20120814
CATEGORIES=	math
MASTER_SITES=	#none
DISTFILES=	#none
EXTRACT_ONLY=	#none

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge metaport for math/octave

OPTIONS=	\
	ACTUARIAL "Install package: actuarial" On \
	AD "Install package: ad" On \
	AUDIO "Install package: audio" On \
	BENCHMARK "Install package: benchmark" On \
	BIM "Install package: bim" On \
	BIOINFO "Install package: bioinfo" On \
	CIVIL_ENGINEERING "Install package: civil-engineering" On \
	COMBINATORICS "Install package: combinatorics" On \
	COMMUNICATIONS "Install package: communications" On \
	CONTROL "Install package: control" On \
	DATA_SMOOTHING "Install package: data-smoothing" On \
	DATAFRAME "Install package: dataframe" On \
	DICOM "Install package: dicom" On \
	ECONOMETRICS "Install package: econometrics" On \
	ENGINE "Install package: engine" On \
	ES "Install package: es" Off \
	FENV "Install package: fenv" On \
	FITS "Install package: fits" On \
	FINANCIAL "Install package: financial" On \
	FL_CORE "Install package: fl-core" On \
	FPL "Install package: fpl" On \
	FUZZY_LOGIC_TOOLKIT "Install package: fuzzy-logic-toolkit" On \
	GA "Install package: ga" On \
	GEOMETRY "Install package: geometry" On \
	GENERAL "Install package: general" On \
	GENERATE_HTML "Install package: generate_html" On \
	GNUPLOT "Install package: gnuplot" On \
	GSL "Install package: gsl" On \
	IDENT "Install package: ident" On \
	IMAGE "Install package: image" On \
	INFORMATIONTHEORY "Install package: informationtheory" On \
	INTEGRATION "Install package: integration" On \
	IO "Install package: io" On \
	IRSA "Install package: irsa" On \
	JAVA "Install package: java" On \
	LINEAR_ALGEBRA "Install package: linear-algebra" On \
	LSSA "Install package: lssa" On \
	MAPPING "Install package: mapping" On \
	MECHANICS "Install package: mechanics" On \
	MISCELLANEOUS "Install package: miscellaneous" On \
	MISSING_FUNCTIONS "Install package: missing-functions" On \
	MSH "Install package: msh" On \
	MULTICORE "Install package: multicore" On \
	NAN "Install package: nan" On \
	NCARRAY "Install package: ncarray" On \
	NLWING2 "Install package: nlwing2" On \
	NNET "Install package: nnet" On \
	NURBS "Install package: nurbs" On \
	OCS "Install package: ocs" On \
	OCT2MAT "Install package: oct2mat" On \
	OCTCDF "Install package: octcdf" On \
	OCTCLIP "Install package: octclip" On \
	OCTGPR "Install package: octgpr" On \
	OCTPROJ "Install package: octproj" On \
	ODEBVP "Install package: odebvp" On \
	ODEPKG "Install package: odepkg" On \
	OPTIM "Install package: optim" On \
	OPTIMINTERP "Install package: optiminterp" On \
	OUTLIERS "Install package: outliers" On \
	PARALLEL "Install package: parallel" On \
	PDB "Install package: pdb" On \
	PHYSICALCONSTANTS "Install package: physicalconstants" On \
	PLOT "Install package: plot" On \
	PT_BR "Install package: pt_br" On \
	QUATERNION "Install package: quaternion" On \
	QUEUEING "Install package: queueing" On \
	SECS1D "Install package: secs1d" On \
	SECS2D "Install package: secs2d" On \
	SECS3D "Install package: secs3d" On \
	SIGNAL "Install package: signal" On \
	SIMP "Install package: simp" On \
	SOCKETS "Install package: sockets" On \
	SPECFUN "Install package: specfun" On \
	SPECIAL_MATRIX "Install package: special-matrix" On \
	SPLINE_GCVSPL "Install package: spline-gcvspl" On \
	SPLINES "Install package: splines" On \
	STATISTICS "Install package: statistics" On \
	STRINGS "Install package: strings" On \
	STRUCT "Install package: struct" On \
	SYMBAND "Install package: symband" On \
	SYMBOLIC "Install package: symbolic" On \
	TCL_OCTAVE "Install package: tcl-octave" On \
	TSA "Install package: tsa" On \
	VIDEO "Install package: video" On \
	XRAYLIB "Install package: xraylib" On \
	ZENITY "Install package: zenity" On

.include <bsd.port.options.mk>

.if defined(WITH_ACTUARIAL)
RUN_DEPENDS+=	${TARBALLS_DIR}/actuarial.tar.gz:${PORTSDIR}/math/octave-forge-actuarial
.endif
.if defined(WITH_AD)
RUN_DEPENDS+=	${TARBALLS_DIR}/ad.tar.gz:${PORTSDIR}/math/octave-forge-ad
.endif
.if defined(WITH_AUDIO)
RUN_DEPENDS+=	${TARBALLS_DIR}/audio.tar.gz:${PORTSDIR}/math/octave-forge-audio
.endif
.if defined(WITH_BENCHMARK)
RUN_DEPENDS+=	${TARBALLS_DIR}/benchmark.tar.gz:${PORTSDIR}/benchmarks/octave-forge-benchmark
.endif
.if defined(WITH_BIM)
RUN_DEPENDS+=	${TARBALLS_DIR}/bim.tar.gz:${PORTSDIR}/math/octave-forge-bim
.endif
.if defined(WITH_BIOINFO)
RUN_DEPENDS+=	${TARBALLS_DIR}/bioinfo.tar.gz:${PORTSDIR}/math/octave-forge-bioinfo
.endif
.if defined(WITH_CIVIL_ENGINEERING)
RUN_DEPENDS+=	${TARBALLS_DIR}/civil-engineering.tar.gz:${PORTSDIR}/math/octave-forge-civil-engineering
.endif
.if defined(WITH_COMBINATORICS)
RUN_DEPENDS+=	${TARBALLS_DIR}/combinatorics.tar.gz:${PORTSDIR}/math/octave-forge-combinatorics
.endif
.if defined(WITH_COMMUNICATIONS)
RUN_DEPENDS+=	${TARBALLS_DIR}/communications.tar.gz:${PORTSDIR}/math/octave-forge-communications
.endif
.if defined(WITH_CONTROL)
RUN_DEPENDS+=	${TARBALLS_DIR}/control.tar.gz:${PORTSDIR}/math/octave-forge-control
.endif
.if defined(WITH_DATA_SMOOTHING)
RUN_DEPENDS+=	${TARBALLS_DIR}/data-smoothing.tar.gz:${PORTSDIR}/math/octave-forge-data-smoothing
.endif
.if defined(WITH_DATAFRAME)
RUN_DEPENDS+=	${TARBALLS_DIR}/dataframe.tar.gz:${PORTSDIR}/math/octave-forge-dataframe
.endif
.if defined(WITH_DICOM)
RUN_DEPENDS+=	${TARBALLS_DIR}/dicom.tar.gz:${PORTSDIR}/math/octave-forge-dicom
.endif
.if defined(WITH_ECONOMETRICS)
RUN_DEPENDS+=	${TARBALLS_DIR}/econometrics.tar.gz:${PORTSDIR}/math/octave-forge-econometrics
.endif
.if defined(WITH_ENGINE)
RUN_DEPENDS+=	${TARBALLS_DIR}/engine.tar.gz:${PORTSDIR}/math/octave-forge-engine
.endif
.if defined(WITH_ES)
RUN_DEPENDS+=	${TARBALLS_DIR}/es.tar.gz:${PORTSDIR}/math/octave-forge-es
.endif
.if defined(WITH_FENV)
RUN_DEPENDS+=	${TARBALLS_DIR}/fenv.tar.gz:${PORTSDIR}/math/octave-forge-fenv
.endif
.if defined(WITH_FITS)
RUN_DEPENDS+=	${TARBALLS_DIR}/fits.tar.gz:${PORTSDIR}/math/octave-forge-fits
.endif
.if defined(WITH_FINANCIAL)
RUN_DEPENDS+=	${TARBALLS_DIR}/financial.tar.gz:${PORTSDIR}/math/octave-forge-financial
.endif
.if defined(WITH_FL_CORE)
RUN_DEPENDS+=	${TARBALLS_DIR}/fl-core.tar.gz:${PORTSDIR}/math/octave-forge-fl-core
.endif
.if defined(WITH_FPL)
RUN_DEPENDS+=	${TARBALLS_DIR}/fpl.tar.gz:${PORTSDIR}/math/octave-forge-fpl
.endif
.if defined(WITH_FUZZY_LOGIC_TOOLKIT)
RUN_DEPENDS+=	${TARBALLS_DIR}/fuzzy-logic-toolkit.tar.gz:${PORTSDIR}/math/octave-forge-fuzzy-logic-toolkit
.endif
.if defined(WITH_GA)
RUN_DEPENDS+=	${TARBALLS_DIR}/ga.tar.gz:${PORTSDIR}/math/octave-forge-ga
.endif
.if defined(WITH_GEOMETRY)
RUN_DEPENDS+=	${TARBALLS_DIR}/geometry.tar.gz:${PORTSDIR}/math/octave-forge-geometry
.endif
.if defined(WITH_GENERAL)
RUN_DEPENDS+=	${TARBALLS_DIR}/general.tar.gz:${PORTSDIR}/math/octave-forge-general
.endif
.if defined(WITH_GENERATE_HTML)
RUN_DEPENDS+=	${TARBALLS_DIR}/generate_html.tar.gz:${PORTSDIR}/math/octave-forge-generate_html
.endif
.if defined(WITH_GNUPLOT)
RUN_DEPENDS+=	${TARBALLS_DIR}/gnuplot.tar.gz:${PORTSDIR}/math/octave-forge-gnuplot
.endif
.if defined(WITH_GSL)
RUN_DEPENDS+=	${TARBALLS_DIR}/gsl.tar.gz:${PORTSDIR}/math/octave-forge-gsl
.endif
.if defined(WITH_IDENT)
RUN_DEPENDS+=	${TARBALLS_DIR}/ident.tar.gz:${PORTSDIR}/math/octave-forge-ident
.endif
.if defined(WITH_IMAGE)
RUN_DEPENDS+=	${TARBALLS_DIR}/image.tar.gz:${PORTSDIR}/math/octave-forge-image
.endif
.if defined(WITH_INFORMATIONTHEORY)
RUN_DEPENDS+=	${TARBALLS_DIR}/informationtheory.tar.gz:${PORTSDIR}/math/octave-forge-informationtheory
.endif
.if defined(WITH_INTEGRATION)
RUN_DEPENDS+=	${TARBALLS_DIR}/integration.tar.gz:${PORTSDIR}/math/octave-forge-integration
.endif
.if defined(WITH_IO)
RUN_DEPENDS+=	${TARBALLS_DIR}/io.tar.gz:${PORTSDIR}/math/octave-forge-io
.endif
.if defined(WITH_IRSA)
RUN_DEPENDS+=	${TARBALLS_DIR}/irsa.tar.gz:${PORTSDIR}/math/octave-forge-irsa
.endif
.if defined(WITH_JAVA)
RUN_DEPENDS+=	${TARBALLS_DIR}/java.tar.gz:${PORTSDIR}/math/octave-forge-java
.endif
.if defined(WITH_LINEAR_ALGEBRA)
RUN_DEPENDS+=	${TARBALLS_DIR}/linear-algebra.tar.gz:${PORTSDIR}/math/octave-forge-linear-algebra
.endif
.if defined(WITH_LSSA)
RUN_DEPENDS+=	${TARBALLS_DIR}/lssa.tar.gz:${PORTSDIR}/math/octave-forge-lssa
.endif
.if defined(WITH_MAPPING)
RUN_DEPENDS+=	${TARBALLS_DIR}/mapping.tar.gz:${PORTSDIR}/math/octave-forge-mapping
.endif
.if defined(WITH_MECHANICS)
RUN_DEPENDS+=	${TARBALLS_DIR}/mechanics.tar.gz:${PORTSDIR}/math/octave-forge-mechanics
.endif
.if defined(WITH_MISCELLANEOUS)
RUN_DEPENDS+=	${TARBALLS_DIR}/miscellaneous.tar.gz:${PORTSDIR}/math/octave-forge-miscellaneous
.endif
.if defined(WITH_MISSING_FUNCTIONS)
RUN_DEPENDS+=	${TARBALLS_DIR}/missing-functions.tar.gz:${PORTSDIR}/math/octave-forge-missing-functions
.endif
.if defined(WITH_MSH)
RUN_DEPENDS+=	${TARBALLS_DIR}/msh.tar.gz:${PORTSDIR}/math/octave-forge-msh
.endif
.if defined(WITH_MULTICORE)
RUN_DEPENDS+=	${TARBALLS_DIR}/multicore.tar.gz:${PORTSDIR}/math/octave-forge-multicore
.endif
.if defined(WITH_NAN)
RUN_DEPENDS+=	${TARBALLS_DIR}/nan.tar.gz:${PORTSDIR}/math/octave-forge-nan
.endif
.if defined(WITH_NCARRAY)
RUN_DEPENDS+=	${TARBALLS_DIR}/ncarray.tar.gz:${PORTSDIR}/math/octave-forge-ncarray
.endif
.if defined(WITH_NLWING2)
RUN_DEPENDS+=	${TARBALLS_DIR}/nlwing2.tar.gz:${PORTSDIR}/math/octave-forge-nlwing2
.endif
.if defined(WITH_NNET)
RUN_DEPENDS+=	${TARBALLS_DIR}/nnet.tar.gz:${PORTSDIR}/math/octave-forge-nnet
.endif
.if defined(WITH_NURBS)
RUN_DEPENDS+=	${TARBALLS_DIR}/nurbs.tar.gz:${PORTSDIR}/math/octave-forge-nurbs
.endif
.if defined(WITH_OCS)
RUN_DEPENDS+=	${TARBALLS_DIR}/ocs.tar.gz:${PORTSDIR}/math/octave-forge-ocs
.endif
.if defined(WITH_OCT2MAT)
RUN_DEPENDS+=	${TARBALLS_DIR}/oct2mat.tar.gz:${PORTSDIR}/math/octave-forge-oct2mat
.endif
.if defined(WITH_OCTCDF)
RUN_DEPENDS+=	${TARBALLS_DIR}/octcdf.tar.gz:${PORTSDIR}/math/octave-forge-octcdf
.endif
.if defined(WITH_OCTCLIP)
RUN_DEPENDS+=	${TARBALLS_DIR}/octclip.tar.gz:${PORTSDIR}/math/octave-forge-octclip
.endif
.if defined(WITH_OCTGPR)
RUN_DEPENDS+=	${TARBALLS_DIR}/octgpr.tar.gz:${PORTSDIR}/math/octave-forge-octgpr
.endif
.if defined(WITH_OCTPROJ)
RUN_DEPENDS+=	${TARBALLS_DIR}/octproj.tar.gz:${PORTSDIR}/math/octave-forge-octproj
.endif
.if defined(WITH_ODEBVP)
RUN_DEPENDS+=	${TARBALLS_DIR}/odebvp.tar.gz:${PORTSDIR}/math/octave-forge-odebvp
.endif
.if defined(WITH_ODEPKG)
RUN_DEPENDS+=	${TARBALLS_DIR}/odepkg.tar.gz:${PORTSDIR}/math/octave-forge-odepkg
.endif
.if defined(WITH_OPTIM)
RUN_DEPENDS+=	${TARBALLS_DIR}/optim.tar.gz:${PORTSDIR}/math/octave-forge-optim
.endif
.if defined(WITH_OPTIMINTERP)
RUN_DEPENDS+=	${TARBALLS_DIR}/optiminterp.tar.gz:${PORTSDIR}/math/octave-forge-optiminterp
.endif
.if defined(WITH_OUTLIERS)
RUN_DEPENDS+=	${TARBALLS_DIR}/outliers.tar.gz:${PORTSDIR}/math/octave-forge-outliers
.endif
.if defined(WITH_PARALLEL)
RUN_DEPENDS+=	${TARBALLS_DIR}/parallel.tar.gz:${PORTSDIR}/math/octave-forge-parallel
.endif
.if defined(WITH_PDB)
RUN_DEPENDS+=	${TARBALLS_DIR}/pdb.tar.gz:${PORTSDIR}/math/octave-forge-pdb
.endif
.if defined(WITH_PHYSICALCONSTANTS)
RUN_DEPENDS+=	${TARBALLS_DIR}/physicalconstants.tar.gz:${PORTSDIR}/math/octave-forge-physicalconstants
.endif
.if defined(WITH_PLOT)
RUN_DEPENDS+=	${TARBALLS_DIR}/plot.tar.gz:${PORTSDIR}/math/octave-forge-plot
.endif
.if defined(WITH_PT_BR)
RUN_DEPENDS+=	${TARBALLS_DIR}/pt_br.tar.gz:${PORTSDIR}/math/octave-forge-pt_br
.endif
.if defined(WITH_QUATERNION)
RUN_DEPENDS+=	${TARBALLS_DIR}/quaternion.tar.gz:${PORTSDIR}/math/octave-forge-quaternion
.endif
.if defined(WITH_QUEUEING)
RUN_DEPENDS+=	${TARBALLS_DIR}/queueing.tar.gz:${PORTSDIR}/math/octave-forge-queueing
.endif
.if defined(WITH_SECS1D)
RUN_DEPENDS+=	${TARBALLS_DIR}/secs1d.tar.gz:${PORTSDIR}/math/octave-forge-secs1d
.endif
.if defined(WITH_SECS2D)
RUN_DEPENDS+=	${TARBALLS_DIR}/secs2d.tar.gz:${PORTSDIR}/math/octave-forge-secs2d
.endif
.if defined(WITH_SECS3D)
RUN_DEPENDS+=	${TARBALLS_DIR}/secs3d.tar.gz:${PORTSDIR}/math/octave-forge-secs3d
.endif
.if defined(WITH_SIGNAL)
RUN_DEPENDS+=	${TARBALLS_DIR}/signal.tar.gz:${PORTSDIR}/math/octave-forge-signal
.endif
.if defined(WITH_SIMP)
RUN_DEPENDS+=	${TARBALLS_DIR}/simp.tar.gz:${PORTSDIR}/math/octave-forge-simp
.endif
.if defined(WITH_SOCKETS)
RUN_DEPENDS+=	${TARBALLS_DIR}/sockets.tar.gz:${PORTSDIR}/math/octave-forge-sockets
.endif
.if defined(WITH_SPECFUN)
RUN_DEPENDS+=	${TARBALLS_DIR}/specfun.tar.gz:${PORTSDIR}/math/octave-forge-specfun
.endif
.if defined(WITH_SPECIAL_MATRIX)
RUN_DEPENDS+=	${TARBALLS_DIR}/special-matrix.tar.gz:${PORTSDIR}/math/octave-forge-special-matrix
.endif
.if defined(WITH_SPLINE_GCVSPL)
RUN_DEPENDS+=	${TARBALLS_DIR}/spline-gcvspl.tar.gz:${PORTSDIR}/math/octave-forge-spline-gcvspl
.endif
.if defined(WITH_SPLINES)
RUN_DEPENDS+=	${TARBALLS_DIR}/splines.tar.gz:${PORTSDIR}/math/octave-forge-splines
.endif
.if defined(WITH_STATISTICS)
RUN_DEPENDS+=	${TARBALLS_DIR}/statistics.tar.gz:${PORTSDIR}/math/octave-forge-statistics
.endif
.if defined(WITH_STRINGS)
RUN_DEPENDS+=	${TARBALLS_DIR}/strings.tar.gz:${PORTSDIR}/math/octave-forge-strings
.endif
.if defined(WITH_STRUCT)
RUN_DEPENDS+=	${TARBALLS_DIR}/struct.tar.gz:${PORTSDIR}/math/octave-forge-struct
.endif
.if defined(WITH_SYMBAND)
RUN_DEPENDS+=	${TARBALLS_DIR}/symband.tar.gz:${PORTSDIR}/math/octave-forge-symband
.endif
.if defined(WITH_SYMBOLIC)
RUN_DEPENDS+=	${TARBALLS_DIR}/symbolic.tar.gz:${PORTSDIR}/math/octave-forge-symbolic
.endif
.if defined(WITH_TCL_OCTAVE)
RUN_DEPENDS+=	${TARBALLS_DIR}/tcl-octave.tar.gz:${PORTSDIR}/math/octave-forge-tcl-octave
.endif
.if defined(WITH_TSA)
RUN_DEPENDS+=	${TARBALLS_DIR}/tsa.tar.gz:${PORTSDIR}/math/octave-forge-tsa
.endif
.if defined(WITH_VIDEO)
RUN_DEPENDS+=	${TARBALLS_DIR}/video.tar.gz:${PORTSDIR}/math/octave-forge-video
.endif
.if defined(WITH_XRAYLIB)
RUN_DEPENDS+=	${TARBALLS_DIR}/xraylib.tar.gz:${PORTSDIR}/math/octave-forge-xraylib
.endif
.if defined(WITH_ZENITY)
RUN_DEPENDS+=	${TARBALLS_DIR}/zenity.tar.gz:${PORTSDIR}/math/octave-forge-zenity
.endif

TARBALLS_DIR=	${LOCALBASE}/share/octave/tarballs

do-build:
	@${DO_NADA}

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
