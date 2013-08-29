# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=		vmd
DISTVERSION=		1.9.1
CATEGORIES=		science graphics python tcl tk
MASTER_SITES=		http://jedi.ks.uiuc.edu/~johns/raytracer/files/0.99b2/:tachyon \
			http://www.photonlimited.com/~johns/tachyon/files/0.99b2/:tachyon \
			http://www.ks.uiuc.edu/Research/vmd/extsrcs/:stride
DISTFILES=		${VMD_DIST} \
			${TACHYON_DIST}:tachyon \
			${STRIDE_DIST}:stride

MAINTAINER=		bjk@FreeBSD.org
COMMENT=		A molecular visualization program

BUILD_DEPENDS=		makedepend:${PORTSDIR}/devel/makedepend \
			${PYNUMERIC}
LIB_DEPENDS=		tcl85:${PORTSDIR}/lang/tcl85 \
			tk85:${PORTSDIR}/x11-toolkits/tk85 \
			fltk.1:${PORTSDIR}/x11-toolkits/fltk \
			netcdf:${PORTSDIR}/science/netcdf
RUN_DEPENDS=		${PYNUMERIC}

USE_PERL5_BUILD=	yes
USE_GMAKE=		yes
USE_GL=			glu
USE_PYTHON=		yes

ONLY_FOR_ARCHS=		i386 amd64

RESTRICTED=		License has restrictions

VMD_DIST=		${PORTNAME}-${DISTVERSION}.src.tar.gz
TACHYON_DIST=		tachyon-0.99b2.tar.gz
# I get stride.tar.gz from ftp://ftp.ebi.ac.uk/pub/software/unix/stride/src/
# but the www.ks.uiuc.edu site (that gives Stride_src.tar.Z) is closer
# to vmd upstream (and google actually knows about it).
#STRIDE_DIST=		stride.tar.gz
STRIDE_DIST=		Stride_src.tar.Z

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
VMD_ARCH=		FREEBSDAMD64
VMD_TARGET=		freebsd.amd64.opengl
.else
VMD_ARCH=		FREEBSD
VMD_TARGET=		freebsd.opengl
.endif

PLIST_SUB+=		VMD_ARCH=${VMD_ARCH}

# Check for VMD sources
.if !exists(${DISTDIR}/${VMD_DIST})
IGNORE= Because of licensing restrictions, you must fetch the source distribution manually.  Please access http://www.ks.uiuc.edu/Development/Download/download.cgi?PackageName=VMD with a web browser.  You will be required to log in and register, but you can create an account on this page.  After registration and accepting the University of Illinois agreement, download the source file, ${VMD_DIST}.  Please place this file in ${DISTDIR}, and re-run make
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	${TAR} xfz ${DISTDIR}/${VMD_DIST} -C ${WRKDIR}
	${TAR} xfz ${WRKSRC}/lib/surf/surf.tar.Z -C ${WRKSRC}/lib/surf
	${TAR} xfz ${DISTDIR}/${TACHYON_DIST} -C ${WRKSRC}/lib
	${TAR} xfz ${DISTDIR}/${STRIDE_DIST} -C ${WRKSRC}/lib/stride

post-patch:
	${REINPLACE_CMD} "s/-lpthread/${PTHREAD_LIBS}/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/-ltk8.5/-ltk85/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/-ltcl8.5/-ltcl85/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s%\$$python_dir/lib_\$$config_arch%${PREFIX}%" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/python2.5/${PYTHON_VERSION}/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/.SILENT:/#.SILENT:/" ${WRKDIR}/plugins/Makefile
	${REINPLACE_CMD} "s/.SILENT:/#.SILENT:/" ${WRKDIR}/plugins/*/Makefile
	${REINPLACE_CMD} "s%log2f(\([^ ,]*\))%logf(\1)/(float)M_LN2%g" ${WRKSRC}/src/Orbital.C
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/configure

do-build:
	${SETENV} ${MAKE_ENV} ${GMAKE} bsd -C ${WRKSRC}/lib/tachyon/unix && ${MV} ${WRKSRC}/lib/tachyon/compile/bsd/tachyon ${WRKSRC}/lib/tachyon/tachyon_${VMD_ARCH}
	${SETENV} ${MAKE_ENV} TCLLIB=-L${PREFIX}/lib/tcl8.5 TCLINC=-I${PREFIX}/include/tcl8.5 PLUGINDIR=${WRKSRC}/plugins ${GMAKE} ${VMD_ARCH} distrib -C ${WRKDIR}/plugins
	${SETENV} ${MAKE_ENV} TCL_INCLUDE_DIR=${PREFIX}/include/tcl8.5 TK_INCLUDE_DIR=${PREFIX}/include/tk8.5 ${GMAKE} ${VMD_TARGET} -C ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${GMAKE} all -C ${WRKSRC}/src
	${SETENV} ${MAKE_ENV} ${GMAKE} depend -C ${WRKSRC}/lib/surf && ${SETENV} ${MAKE_ENV} ${GMAKE} surf -C ${WRKSRC}/lib/surf && ${MV} ${WRKSRC}/lib/surf/surf ${WRKSRC}/lib/surf/surf_${VMD_ARCH}
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC}/lib/stride && ${MV} ${WRKSRC}/lib/stride/stride ${WRKSRC}/lib/stride/stride_${VMD_ARCH}

do-install:
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC}/src install
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/vmd

.include <bsd.port.post.mk>
