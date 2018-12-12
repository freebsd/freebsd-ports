# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	vmd
DISTVERSION=	1.9.3
PORTREVISION=	6
CATEGORIES=	science graphics python tcl tk
MASTER_SITES=	http://jedi.ks.uiuc.edu/~johns/raytracer/files/0.99b6/:tachyon \
		http://www.photonlimited.com/~johns/tachyon/files/0.99b6/:tachyon \
		http://webclu.bio.wzw.tum.de/stride/:stride \
		ftp://ftp.ebi.ac.uk/pub/software/unix/stride/src/:stride
DISTFILES=	${VMD_DIST} \
		${TACHYON_DIST}:tachyon \
		${STRIDE_DIST}:stride

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Molecular visualization program

LICENSE=	VMD BSD3CLAUSE STRIDE
LICENSE_COMB=	multi

BUILD_DEPENDS=	makedepend:devel/makedepend \
		${PYNUMPY}
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfltk.so:x11-toolkits/fltk \
		libnetcdf.so:science/netcdf
RUN_DEPENDS=	${PYNUMPY}

LICENSE_FILE_VMD=	${WRKSRC}/LICENSE
LICENSE_PERMS_VMD=	no-auto-accept
LICENSE_NAME_VMD=	Visual Molecular Dynamics Software License Agreement
LICENSE_DISTFILES_VMD=	${VMD_DIST}

LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/lib/tachyon/Copyright
LICENSE_DISTFILES_BSD3CLAUSE=	${TACHYON_DIST}

LICENSE_TEXT_STRIDE=	${FILESDIR}/stride.txt
LICENSE_PERMS_STRIDE=	dist-mirror pkg-mirror auto-accept
LICENSE_NAME_STRIDE=	Stride Copyright Notice
LICENSE_DISTFILES_STRIDE=${STRIDE_DIST}

USES=		gmake perl5 python shebangfix sqlite tcl tk

SHEBANG_FILES=	${WRKDIR}/plugins/topotools/*.tcl

USE_PERL5=	build
USE_GL=		gl glu
USE_XORG=	x11

ONLY_FOR_ARCHS=	i386 amd64

CONFIGURE_ENV=	PYTHON_INCLUDE_DIR=${PYTHON_INCLUDEDIR} \
		PYTHON_LIBRARY_DIR=${PYTHON_LIBDIR} \
		NUMPY_INCLUDE_DIR=${PYTHON_SITELIBDIR}/numpy/core/include \
		NUMPY_LIBRARY_DIR=${PYTHON_SITELIBDIR} \
		TCL_INCLUDE_DIR=${TCL_INCLUDEDIR} \
		TCL_LIBRARY_DIR=${LOCALBASE}/lib \
		TK_INCLUDE_DIR=${TK_INCLUDEDIR} \
		TK_LIBRARY_DIR=${LOCALBASE}/lib
CONFIGURE_ARGS=	${VMD_ARCH} OPENGL FLTK TK IMD TCL PTHREADS LIBTACHYON NETCDF NUMPY PYTHON
INSTALL_WRKSRC=	${WRKSRC}/src
MAKE_ENV=	EXPATINC=-I${LOCALBASE}/include \
		EXPATLIB=-L${LOCALBASE}/lib \
		EXPATLDFLAGS=-lexpat \
		EXPATDYNAMIC=1 \
		NETCDFINC=-I${LOCALBASE}/include \
		NETCDFLIB=-L${LOCALBASE}/lib \
		NETCDFLDFLAGS=-lnetcdf \
		SQLITEINC=-I${LOCALBASE}/include \
		SQLITELIB=-L${LOCALBASE}/lib \
		SQLITELDFLAGS=-lsqlite3 \
		SQLITEDYNAMIC=1 \
		TCLLIB=-L${LOCALBASE}/lib \
		TCLINC=-I${TCL_INCLUDEDIR} \
		TCLLDFLAGS=-ltcl${TCL_VER:S/.//} \
		TKLDFLAGS="-ltk${TK_VER:S/.//} -lX11"

VMD_DIST=	${PORTNAME}-${DISTVERSION}.src.tar.gz
TACHYON_DIST=	tachyon-0.99b6.tar.gz
STRIDE_DIST=	stride.tar.gz
STRIDE_DOC=	stride.doc

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
VMD_ARCH=		FREEBSDAMD64
.else
VMD_ARCH=		FREEBSD
.endif

PLIST_SUB+=		VMD_ARCH=${VMD_ARCH}

# Check for VMD sources
.if !exists(${DISTDIR}/${VMD_DIST})
IGNORE=	license restrictions require manual fetching of the distribution\
	source.  Please visit http://www.ks.uiuc.edu/Development/Download/download.cgi?PackageName=VMD\
	with a browser.  You will be required to register, log in, and accept\
	the University of Illinois agreement before you can download the\
	${VMD_DIST} source file.  Place this file in ${DISTDIR} and try again.
.endif

do-extract:
	${MKDIR} ${WRKDIR} ${WRKSRC}/lib/stride
	${TAR} -xzf ${DISTDIR}/${VMD_DIST} -C ${WRKDIR}
	${TAR} -xzf ${WRKSRC}/lib/surf/surf.tar.Z -C ${WRKSRC}/lib/surf
	${TAR} -xzf ${DISTDIR}/${TACHYON_DIST} -C ${WRKSRC}/lib
	${TAR} -xzf ${DISTDIR}/${STRIDE_DIST} -C ${WRKSRC}/lib/stride

post-patch:
	${REINPLACE_CMD} \
		-e "s|-lpython2.5|-l${PYTHON_VERSION}${PYTHON_ABIVER}|" \
		-e "s|/usr/local|${LOCALBASE}|g"  \
		-e "s|-fno-for-scope||g" \
		-e "s/\"gcc\"/\"${CC}\"/;s/\"g++\"/\"${CXX}\"/" \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e "s/.SILENT:/#.SILENT:/" ${WRKDIR}/plugins/Makefile
	${REINPLACE_CMD} "s/.SILENT:/#.SILENT:/" ${WRKDIR}/plugins/*/Makefile
	${REINPLACE_CMD} "s%log2f(\([^ ,]*\))%logf(\1)/(float)M_LN2%g" \
		${WRKSRC}/src/Orbital.C
	${REINPLACE_CMD} -E "s/(SHLD[[:space:]]*=[[:space:]]*)gcc/\1${CC}/" \
		${WRKDIR}/plugins/Make-arch
	${REINPLACE_CMD} -E "s/(CC[[:space:]]*=[[:space:]]*)(gcc|cc)/\1${CC}/" \
		${WRKSRC}/lib/stride/Makefile \
		${WRKSRC}/lib/surf/Makefile \
		${WRKSRC}/lib/tachyon/unix/Make-arch \
		${WRKDIR}/plugins/cionize/Makefile.specialbuilds \
		${WRKDIR}/plugins/cionize/Makefile.mine \
		${WRKDIR}/plugins/cionize/Makefile.testing \
		${WRKDIR}/plugins/Make-arch \
		${WRKDIR}/plugins/molfile_plugin/f77/Makefile
	${REINPLACE_CMD} -E "s/(CXX[[:space:]]*=[[:space:]]*)g\+\+/\1${CXX}/" \
		${WRKDIR}/plugins/fmtool/Makefile.specialbuilds \
		${WRKDIR}/plugins/hesstrans/src/foo/Makefile \
		${WRKDIR}/plugins/hesstrans/src/foo/nm_gnu.mak \
		${WRKDIR}/plugins/Make-arch
	${REINPLACE_CMD} -e "s/return *;/return 0;/g" \
		${WRKSRC}/lib/surf/*.c

do-build:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} bsd -C ${WRKSRC}/lib/tachyon/unix
		${MV} ${WRKSRC}/lib/tachyon/compile/bsd/tachyon ${WRKSRC}/lib/tachyon/tachyon_${VMD_ARCH}
	${SETENV} ${MAKE_ENV} PLUGINDIR=${WRKSRC}/plugins ${MAKE_CMD} ${VMD_ARCH} distrib -C ${WRKDIR}/plugins
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} all -C ${WRKSRC}/src
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} depend -C ${WRKSRC}/lib/surf
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} surf -C ${WRKSRC}/lib/surf
		${MV} ${WRKSRC}/lib/surf/surf ${WRKSRC}/lib/surf/surf_${VMD_ARCH}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} -C ${WRKSRC}/lib/stride 
		${MV} ${WRKSRC}/lib/stride/stride ${WRKSRC}/lib/stride/stride_${VMD_ARCH}

post-install:
	${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||g' ${STAGEDIR}${PREFIX}/bin/vmd
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/vmd/*${VMD_ARCH} \
	    ${STAGEDIR}${LOCALBASE}/lib/vmd/plugins/${VMD_ARCH}/molfile/*.so
.for f in tcl/autopsf1.6/psfcheck.so tcl/hesstrans1.0/hesstrans.so \
	  tcl/mutator1.5/libalchemify.so tcl/pmepot1.0/libpmepot.so \
	  tcl/psfgen1.6/libpsfgen.so tcl/rnaview1.1/rnaview \
	  tcl/signalproc1.1/specden.so tcl/signalproc1.1/fftcmds.so \
	  tcl/signalproc1.1/sgsmooth.so tcl/volutil1.3/volutil \
	  tcl/clustalw1.1/clustalw tcl/libbiokit1.1/tcl_libbiokit.so \
	  tcl/libbiokit1.1/q tcl/libbiokit1.1/seqqr \
	  tcl/libbiokit1.1/structqr tcl/libbiokit1.1/qpair \
	  tcl/libbiokit1.1/rmsd tcl/libbiokit1.1/percid \
	  tcl/phylotree1.2/upgmaclu tcl/stamp1.2/stamp \
	  tcl/bossconvert1.0/Topology \
	  bin/catdcd5.1/catdcd bin/cionize1.0/cionize
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/vmd/plugins/${VMD_ARCH}/${f}
.endfor

.include <bsd.port.post.mk>
