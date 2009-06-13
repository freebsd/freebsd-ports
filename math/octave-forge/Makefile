# New ports collection makefile for:	octave-forge
# Date created:		5 May 2004
# Whom:			Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	octave-forge
PORTVERSION=	20090607
CATEGORIES=	math
MASTER_SITES=	#none
DISTFILES=	#none
EXTRACT_ONLY=	#none

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge metaport for math/octave

# Status of packages:
#  * java, jhandles, database are not completed.  If someone else wants to
#    work on these, I would appreciate it.
#  * vrml builds, but is non functional, as it depends on freewrl, which is
#    not yet available on FreeBSD.

OPTIONS=	\
	ANN "Install package: ann" On \
	AUDIO "Install package: audio" On \
	BENCHMARK "Install package: benchmark" On \
	BIOINFO "Install package: bioinfo" On \
	COMBINATORICS "Install package: combinatorics" On \
	COMMUNICATIONS "Install package: communications" On \
	CONTROL "Install package: control" On \
	DATA_SMOOTHING "Install package: data-smoothing" On \
	DATABASE "Install package: database (do not select)" Off \
	ECONOMETRICS "Install package: econometrics" On \
	FINANCIAL "Install package: financial" On \
	FIXED "Install package: fixed" On \
	FTP "Install package: ftp" On \
	GA "Install package: ga" On \
	GENERAL "Install package: general" On \
	GSL "Install package: gsl" On \
	IDENT "Install package: ident" On \
	IMAGE "Install package: image" On \
	INFORMATIONTHEORY "Install package: informationtheory" On \
	IO "Install package: io" On \
	IRSA "Install package: irsa" On \
	LINEAR_ALGEBRA "Install package: linear-algebra" On \
	MISCELLANEOUS "Install package: miscellaneous" On \
	MISSING_FUNCTIONS "Install package: missing-functions" On \
	NNET "Install package: nnet" On \
	OCTCDF "Install package: octcdf" On \
	OCTGPR "Install package: octgpr" On \
	ODEBVP "Install package: odebvp" On \
	ODEPKG "Install package: odepkg" On \
	OPTIM "Install package: optim" On \
	OPTIMINTERP "Install package: optiminterp" On \
	OUTLIERS "Install package: outliers" On \
	PARALLEL "Install package: parallel" On \
	PHYSICALCONSTANTS "Install package: physicalconstants" On \
	PLOT "Install package: plot" On \
	SIGNAL "Install package: signal" On \
	SIMP "Install package: simp" On \
	SOCKETS "Install package: sockets" On \
	SPECFUN "Install package: specfun" On \
	SPECIAL_MATRIX "Install package: special-matrix" On \
	SPLINES "Install package: splines" On \
	STATISTICS "Install package: statistics" On \
	STRINGS "Install package: strings" On \
	STRUCT "Install package: struct" On \
	SYMBOLIC "Install package: symbolic" On \
	TIME "Install package: time" On \
	VIDEO "Install package: video" On \
	VRML "Install package: vrml" On \
	ZENITY "Install package: zenity" On \
	\
	AD "Install package: ad" On \
	BIM "Install package: bim" On \
	CIVIL_ENGINEERING "Install package: civil-engineering" On \
	ENGINE "Install package: engine" On \
	FPL "Install package: fpl" On \
	GENERATE_HTML "Install package: generate_html" On \
	GRACEPLOT "Install package: graceplot" On \
	INTEGRATION "Install package: integration" On \
	JAVA "Install package: java (do not select)" Off \
	JHANDLES "Install package: jhandles (do not select)" Off \
	MAPPING "Install package: mapping" On \
	MSH "Install package: msh" On \
	MULTICORE "Install package: multicore" On \
	NAN "Install package: nan" On \
	NLWING2 "Install package: nlwing2" On \
	NURBS "Install package: nurbs" On \
	OCS "Install package: ocs" On \
	OCT2MAT "Install package: oct2mat" On \
	PDB "Install package: pdb" On \
	SECS1D "Install package: secs1d" On \
	SECS2D "Install package: secs2d" On \
	SYMBAND "Install package: symband" On \
	TCL_OCTAVE "Install package: tcl-octave" On \
	TRIANGULAR "Install package: triangular" On \
	TSA "Install package: tsa" On \
	WINDOWS "Install package: windows" On \
	XRAYLIB "Install package: xraylib" On \
	\
	SPANISH "Install package: spanish" On \
	PT_BR "Install package: pt_br" On \
	\
	ARPACK "Install package: arpack" Off \
	SPLINE_GCVSPL "Install package: spline-gcvspl" Off

.include <bsd.port.pre.mk>

.if defined(WITH_ANN)
RUN_DEPENDS+=	${TARBALLS_DIR}/ann.tar.gz:${PORTSDIR}/math/octave-forge-ann
.endif
.if defined(WITH_AUDIO)
RUN_DEPENDS+=	${TARBALLS_DIR}/audio.tar.gz:${PORTSDIR}/math/octave-forge-audio
.endif
.if defined(WITH_BENCHMARK)
RUN_DEPENDS+=	${TARBALLS_DIR}/benchmark.tar.gz:${PORTSDIR}/benchmarks/octave-forge-benchmark
.endif
.if defined(WITH_BIOINFO)
RUN_DEPENDS+=	${TARBALLS_DIR}/bioinfo.tar.gz:${PORTSDIR}/math/octave-forge-bioinfo
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
.if defined(WITH_DATABASE)
#RUN_DEPENDS+=	${TARBALLS_DIR}/database.tar.gz:${PORTSDIR}/math/octave-forge-database
.endif
.if defined(WITH_ECONOMETRICS)
RUN_DEPENDS+=	${TARBALLS_DIR}/econometrics.tar.gz:${PORTSDIR}/math/octave-forge-econometrics
.endif
.if defined(WITH_FINANCIAL)
RUN_DEPENDS+=	${TARBALLS_DIR}/financial.tar.gz:${PORTSDIR}/math/octave-forge-financial
.endif
.if defined(WITH_FIXED)
RUN_DEPENDS+=	${TARBALLS_DIR}/fixed.tar.gz:${PORTSDIR}/math/octave-forge-fixed
.endif
.if defined(WITH_FTP)
RUN_DEPENDS+=	${TARBALLS_DIR}/ftp.tar.gz:${PORTSDIR}/math/octave-forge-ftp
.endif
.if defined(WITH_GA)
RUN_DEPENDS+=	${TARBALLS_DIR}/ga.tar.gz:${PORTSDIR}/math/octave-forge-ga
.endif
.if defined(WITH_GENERAL)
RUN_DEPENDS+=	${TARBALLS_DIR}/general.tar.gz:${PORTSDIR}/math/octave-forge-general
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
.if defined(WITH_IO)
RUN_DEPENDS+=	${TARBALLS_DIR}/io.tar.gz:${PORTSDIR}/math/octave-forge-io
.endif
.if defined(WITH_IRSA)
RUN_DEPENDS+=	${TARBALLS_DIR}/irsa.tar.gz:${PORTSDIR}/math/octave-forge-irsa
.endif
.if defined(WITH_LINEAR_ALGEBRA)
RUN_DEPENDS+=	${TARBALLS_DIR}/linear-algebra.tar.gz:${PORTSDIR}/math/octave-forge-linear-algebra
.endif
.if defined(WITH_MISCELLANEOUS)
RUN_DEPENDS+=	${TARBALLS_DIR}/miscellaneous.tar.gz:${PORTSDIR}/math/octave-forge-miscellaneous
.endif
.if defined(WITH_MISSING_FUNCTIONS)
RUN_DEPENDS+=	${TARBALLS_DIR}/missing-functions.tar.gz:${PORTSDIR}/math/octave-forge-missing-functions
.endif
.if defined(WITH_NNET)
RUN_DEPENDS+=	${TARBALLS_DIR}/nnet.tar.gz:${PORTSDIR}/math/octave-forge-nnet
.endif
.if defined(WITH_OCTCDF)
RUN_DEPENDS+=	${TARBALLS_DIR}/octcdf.tar.gz:${PORTSDIR}/math/octave-forge-octcdf
.endif
.if defined(WITH_OCTGPR)
RUN_DEPENDS+=	${TARBALLS_DIR}/octgpr.tar.gz:${PORTSDIR}/math/octave-forge-octgpr
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
.if defined(WITH_PHYSICALCONSTANTS)
RUN_DEPENDS+=	${TARBALLS_DIR}/physicalconstants.tar.gz:${PORTSDIR}/math/octave-forge-physicalconstants
.endif
.if defined(WITH_PLOT)
RUN_DEPENDS+=	${TARBALLS_DIR}/plot.tar.gz:${PORTSDIR}/math/octave-forge-plot
.endif
.if defined(WITH_SIGNAL)
RUN_DEPENDS+=	${TARBALLS_DIR}/signal.tar.gz:${PORTSDIR}/math/octave-forge-signal
.endif
.if defined(WITH_SIMP)
RUN_DEPENDS+=	${TARBALLS_DIR}/simp.tar.gz:${PORTSDIR}/math/octave-forge-simp
.endif
.if defined(WITH_SYMBOLIC)
RUN_DEPENDS+=	${TARBALLS_DIR}/symbolic.tar.gz:${PORTSDIR}/math/octave-forge-symbolic
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
.if defined(WITH_TIME)
RUN_DEPENDS+=	${TARBALLS_DIR}/time.tar.gz:${PORTSDIR}/math/octave-forge-time
.endif
.if defined(WITH_VIDEO)
RUN_DEPENDS+=	${TARBALLS_DIR}/video.tar.gz:${PORTSDIR}/math/octave-forge-video
.endif
.if defined(WITH_VRML)
RUN_DEPENDS+=	${TARBALLS_DIR}/vrml.tar.gz:${PORTSDIR}/math/octave-forge-vrml
.endif
.if defined(WITH_ZENITY)
RUN_DEPENDS+=	${TARBALLS_DIR}/zenity.tar.gz:${PORTSDIR}/math/octave-forge-zenity
.endif

.if defined(WITH_AD)
RUN_DEPENDS+=	${TARBALLS_DIR}/ad.tar.gz:${PORTSDIR}/math/octave-forge-ad
.endif
.if defined(WITH_BIM)
RUN_DEPENDS+=	${TARBALLS_DIR}/bim.tar.gz:${PORTSDIR}/math/octave-forge-bim
.endif
.if defined(WITH_CIVIL_ENGINEERING)
RUN_DEPENDS+=	${TARBALLS_DIR}/civil-engineering.tar.gz:${PORTSDIR}/math/octave-forge-civil-engineering
.endif
.if defined(WITH_ENGINE)
RUN_DEPENDS+=	${TARBALLS_DIR}/engine.tar.gz:${PORTSDIR}/math/octave-forge-engine
.endif
.if defined(WITH_FPL)
RUN_DEPENDS+=	${TARBALLS_DIR}/fpl.tar.gz:${PORTSDIR}/math/octave-forge-fpl
.endif
.if defined(WITH_GENERATE_HTML)
RUN_DEPENDS+=	${TARBALLS_DIR}/generate_html.tar.gz:${PORTSDIR}/math/octave-forge-generate_html
.endif
.if defined(WITH_GRACEPLOT)
RUN_DEPENDS+=	${TARBALLS_DIR}/graceplot.tar.gz:${PORTSDIR}/math/octave-forge-graceplot
.endif
.if defined(WITH_INTEGRATION)
RUN_DEPENDS+=	${TARBALLS_DIR}/integration.tar.gz:${PORTSDIR}/math/octave-forge-integration
.endif
.if defined(WITH_JAVA)
#RUN_DEPENDS+=	${TARBALLS_DIR}/java.tar.gz:${PORTSDIR}/math/octave-forge-java
.endif
.if defined(WITH_JHANDLES)
#RUN_DEPENDS+=	${TARBALLS_DIR}/jhandles.tar.gz:${PORTSDIR}/math/octave-forge-jhandles
.endif
.if defined(WITH_MAPPING)
RUN_DEPENDS+=	${TARBALLS_DIR}/mapping.tar.gz:${PORTSDIR}/math/octave-forge-mapping
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
.if defined(WITH_NLWING2)
RUN_DEPENDS+=	${TARBALLS_DIR}/nlwing2.tar.gz:${PORTSDIR}/math/octave-forge-nlwing2
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
.if defined(WITH_PDB)
RUN_DEPENDS+=	${TARBALLS_DIR}/pdb.tar.gz:${PORTSDIR}/math/octave-forge-pdb
.endif
.if defined(WITH_SECS1D)
RUN_DEPENDS+=	${TARBALLS_DIR}/secs1d.tar.gz:${PORTSDIR}/math/octave-forge-secs1d
.endif
.if defined(WITH_SECS2D)
RUN_DEPENDS+=	${TARBALLS_DIR}/secs2d.tar.gz:${PORTSDIR}/math/octave-forge-secs2d
.endif
.if defined(WITH_SYMBAND)
RUN_DEPENDS+=	${TARBALLS_DIR}/symband.tar.gz:${PORTSDIR}/math/octave-forge-symband
.endif
.if defined(WITH_TCL_OCTAVE)
RUN_DEPENDS+=	${TARBALLS_DIR}/tcl-octave.tar.gz:${PORTSDIR}/math/octave-forge-tcl-octave
.endif
.if defined(WITH_TRIANGULAR)
RUN_DEPENDS+=	${TARBALLS_DIR}/triangular.tar.gz:${PORTSDIR}/math/octave-forge-triangular
.endif
.if defined(WITH_TSA)
RUN_DEPENDS+=	${TARBALLS_DIR}/tsa.tar.gz:${PORTSDIR}/math/octave-forge-tsa
.endif
.if defined(WITH_WINDOWS)
RUN_DEPENDS+=	${TARBALLS_DIR}/windows.tar.gz:${PORTSDIR}/math/octave-forge-windows
.endif
.if defined(WITH_XRAYLIB)
RUN_DEPENDS+=	${TARBALLS_DIR}/xraylib.tar.gz:${PORTSDIR}/math/octave-forge-xraylib
.endif

.if defined(WITH_SPANISH)
RUN_DEPENDS+=	${TARBALLS_DIR}/spanish.tar.gz:${PORTSDIR}/math/octave-forge-spanish
.endif
.if defined(WITH_PT_BR)
RUN_DEPENDS+=	${TARBALLS_DIR}/pt_br.tar.gz:${PORTSDIR}/math/octave-forge-pt_br
.endif

.if defined(WITH_ARPACK)
RUN_DEPENDS+=	${TARBALLS_DIR}/arpack.tar.gz:${PORTSDIR}/math/octave-forge-arpack
.endif
.if defined(WITH_SPLINE_GCVSPL)
RUN_DEPENDS+=	${TARBALLS_DIR}/spline-gcvspl.tar.gz:${PORTSDIR}/math/octave-forge-spline-gcvspl
.endif

TARBALLS_DIR=	${LOCALBASE}/share/octave/tarballs

do-build:
	@${DO_NADA}

do-install:
	@${DO_NADA}

check-all-octave-forge-depends:
	@for p in ${.CURDIR}/../octave-forge-*; do (cd $$p;(make check-octave-forge-depends 2>/dev/null)||true); done | (grep dependency || true)

.include <bsd.port.post.mk>
