# Makefile include for: vecfem
# Date created:		15 January 2001
# Whom:			Ralf Becker <ralf@akk.org>
#
#

.ifdef MPI
VECFEM_ARCH=	FREEBSD_MPI
LINUX=		LINUX_MPI
.else
VECFEM_ARCH=	FREEBSD
LINUX=		LINUX
.endif

VEMTOOL=	vemaxiom vembuild vemfc vemcompile vemmaple vemmaxima \
		vempost vemrun vemtar vemhint

VEMSHARE=	avsout1.h avsout2.h avsout32.h avsscalarseries.net  \
		avsscalarsteady.net avsvectorseries.net avsvectorsteady.net \
		dummy.equation dummy.resource dxout1.h dxout2.h dxout32.h \
		dxscalarseries.net dxscalarsteady.net dxvectorseries.net \
		dxvectorsteady.net ensightout1.h ensightout2.h ensightout32.h \
		fortra.lisp gnuplotout1.h gnuplotout2.h gnuplotout32.h \
		ideasin.h ideasout1.h ideasout2.h ideasout31.h ideasout32.h \
		isvasout1.h isvasout2.h isvasout32.h maple1.h maple3.h \
		maxima1.h maxima1.h.back maxima3.h nomeshout.h noopen.h \
		openout.h patran.vecfem.res_tmpl patranin.h patranout1.h \
		patranout2.h patranout31.h patranout32.h printin.h \
		printout1.h printout2.h printout32.h userb1.h userb3.h \
		userf1.h userf3.h useru01.h useru03.h usrfu1.h usrfu3.h \
		usrfut1.h usrfut3.h vecfem1.h vecfem10.h vecfem1a.h \
		vecfem1e.h vecfem1p.h vecfem2.h vecfem3.h vecfem4e.h \
		vecfem4p.h vecfem5.h vecfem6.h vecfem71.h vecfem72.h \
		vecfem8.h vecfem9.h vempfade

VEMDOCDIR=	RefManual

VEMINCLUDE=	archi.h cache.h maxnpe.h nproc.h scalar.h bytes.h const.h \
		norec.h nprocs.h solex.h

VEMLIB=		lib${PORTNAME}${PORTVERSION}.a
VEMLIBDIR=	${WRKDIR}/${VECFEM_ARCH}

MAKE_ENV=	VECFEM_ROOT=${WRKDIR} \
		VECFEM_SHELL=/bin/sh \
		LIB=${VEMLIBDIR}/${VEMLIB} \
		VECFEM_ARCH=${VECFEM_ARCH} \
		AR=ar \
		ARFLAGS=rv
pre-build:
.ifdef MPI
	@${ECHO_MSG} "Building ${PORTNAME}-${PORTVERSION} with MPI support"
.endif

# necessary links
	-@${LN} -s ${WRKDIR}/include/${LINUX} ${WRKDIR}/include/${VECFEM_ARCH}
	-@${LN} -s ${WRKDIR}/source/${LINUX}  ${WRKDIR}/source/${VECFEM_ARCH}
	@${MKDIR} ${WRKDIR}/${VECFEM_ARCH}

do-build:
# build the architecture independent part
	@(cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
# build the architecture dependent subdirectoy
	@(cd ${BUILD_WRKSRC}/${VECFEM_ARCH}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-build:
# changing shell and VEMPATH of vemtools
	@(echo "===> Fixing ${WRKDIR}/vemtools")
.for i in ${VEMTOOL}
	@(${SED}  '1s/^#!\/bin\/ksh/#!\/bin\/sh/' ${WRKDIR}/vemtool/$i | ${SED} 's/vemtool\/\(vem*\)/bin\/\1/g' | ${AWK} '{ if ($$0=="MYCOMMAND=$$_") print "MYCOMMAND=${PREFIX}/share/${PORTNAME}${PORTVERSION}/vempfade"; else print $$0 }' > ${WRKDIR}/vemtool/$i.back)
	@(${CP} ${WRKDIR}/vemtool/$i.back ${WRKDIR}/vemtool/$i)
.endfor

# changing path in  vembuild

	@(${SED} 's/vemtool\/\(.*\.h\)/share\/${PORTNAME}${PORTVERSION}\/\1/g' ${WRKSRC}/vemtool/vembuild | ${SED} 's/vemtool\/\(dummy.*\)/share\/${PORTNAME}${PORTVERSION}\/\1/g' | ${SED} 's/vemtool /share\/${PORTNAME}${PORTVERSION}/g'  > ${WRKSRC}/vemtool/vembuild.back)
	@(${CP} ${WRKSRC}/vemtool/vembuild.back ${WRKSRC}/vemtool/vembuild)

#changing path in vemfc

	@( ${SED} 's/\(include\)\/".VECFEM_ARCH/\1\/${PORTNAME}${PORTVERSION}"/g' ${WRKSRC}/vemtool/vemfc | ${SED} 's/\(.VECFEM_ROOT\)"\/".VECFEM_ARCH/\1\/lib/g' | ${SED} 's/.VECFEM_ARCH\(\/liblsolpp.a\)/lib\1/' > ${WRKSRC}/vemtool/vemfc.back)
	@(${CP} ${WRKSRC}/vemtool/vemfc.back ${WRKSRC}/vemtool/vemfc)

# changing path in vempost

	@(${SED} 's/vemtool\/\(.*\.net\)/share\/${PORTNAME}${PORTVERSION}\/\1/g' ${WRKSRC}/vemtool/vempost | ${SED} 's/vemtool\/\(.*\_tmpl\)/share\/${PORTNAME}${PORTVERSION}\/\1/g' > ${WRKSRC}/vemtool/vempost.back )
	@(${CP}  ${WRKSRC}/vemtool/vempost.back  ${WRKSRC}/vemtool/vempost)

# changing path in maxima1.h

	@(${SED} 's/vemtool\/\(.*\.lisp\)/share\/${PORTNAME}${PORTVERSION}\/\1/g' ${WRKSRC}/vemtool/maxima1.h > ${WRKSRC}/vemtool/maxima1.h.back)
	@(${CP} ${WRKSRC}/vemtool/maxima1.h.back ${WRKSRC}/vemtool/maxima1.h)

# writing vemtool/vempfade

	@(${ECHO} "export VECFEM_SHELL=/bin/sh" > ${WRKSRC}/vemtool/vempfade)
	@(${ECHO} "export VECFEM_AWK=awk" >> ${WRKSRC}/vemtool/vempfade)
	@(${ECHO} "export VECFEM_ARCH=${VECFEM_ARCH}" >> ${WRKSRC}/vemtool/vempfade)
	@(${ECHO} "export VECFEM_ROOT=${PREFIX}" >> ${WRKSRC}/vemtool/vempfade)

do-install:

## installing share/vecfem3
	@( cd ${WRKSRC}/vemtool; ${INSTALL} -d ${PREFIX}/share/${PORTNAME}${PORTVERSION} ; ${INSTALL_DATA} ${VEMSHARE} ${PREFIX}/share/${PORTNAME}${PORTVERSION} )
	@( cd ${WRKSRC}; ${INSTALL} -d ${PREFIX}/share/doc/${PORTNAME}${PORTVERSION}/${VEMDOCIR} ; ${CP} -r ${VEMDOCDIR} ${PREFIX}/share/doc/${PORTNAME}${PORTVERSION} )

## installing include/vecfem3
	@( cd ${WRKSRC}/include/${VECFEM_ARCH}/; ${INSTALL} -d ${PREFIX}/include/${PORTNAME}${PORTVERSION} ; ${INSTALL_DATA} ${VEMINCLUDE} ${PREFIX}/include/${PORTNAME}${PORTVERSION} )

## installing lib
	@( cd ${WRKSRC}/${VECFEM_ARCH}; ${INSTALL_DATA} ${VEMLIB} ${PREFIX}/lib/ )

## installing bin
	@( cd ${WRKSRC}/vemtool; ${INSTALL_SCRIPT} ${VEMTOOL} ${PREFIX}/bin/ )

## installing manpages
	@( cd ${WRKSRC}/man7; ${INSTALL_DATA} ${MAN7} ${PREFIX}/man/man7/ )
