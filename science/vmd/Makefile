# New ports collection makefile for:	vmd
# Date created:		12 August 2004
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=		vmd
PORTVERSION=		1.8.3
PORTREVISION=		0
CATEGORIES=		science graphics python tcl84 tk84
MASTER_SITES=		http://jedi.ks.uiuc.edu/~johns/raytracer/files/0.97/:tachyon \
			ftp://ftp.ebi.ac.uk/pub/software/unix/stride/src/:stride
DISTFILES=		${VMD_DIST} \
			${TACHYON_DIST}:tachyon \
			${STRIDE_DIST}:stride

MAINTAINER=		sangwoos@gmail.com
COMMENT=		A molecular visualization program

BUILD_DEPENDS=		makedepend:${X_IMAKE_PORT} \
			${PYNUMERIC}
LIB_DEPENDS=		tcl84:${PORTSDIR}/lang/tcl84 \
			tk84:${PORTSDIR}/x11-toolkits/tk84 \
			fltk:${PORTSDIR}/x11-toolkits/fltk
RUN_DEPENDS=		${PYNUMERIC}

USE_PERL5_BUILD=	yes
USE_GMAKE=		yes
USE_GL=			yes
USE_PYTHON=		yes

NO_PACKAGE=		"License has restrictions"
NO_CDROM=		"License has restrictions"
RESTRICTED=		"License has restrictions"

VMD_DIST=		${PORTNAME}-${PORTVERSION}.src.tar.gz
TACHYON_DIST=		tachyon-0.97.tar.gz
STRIDE_DIST=		stride.tar.gz

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
.if !exists(${DISTDIR}/${VMD_DIST}) # && !defined(PACKAGE_BUILDING)
ECHO_MSG=	${PRINTF}
IGNORE=	:\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Please access\n\
http://www.ks.uiuc.edu/Development/Download/download.cgi?PackageName=VMD\n\
with a web browser.  You will be required to log in and register,\n\
but you can create an account on this page.  After registration and\n\
accepting the University of Illinois agreement, download the source file,\n\
${VMD_DIST}.  Please place this file in ${DISTDIR}.\n
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	${TAR} xfz ${DISTDIR}/${VMD_DIST} -C ${WRKDIR}
	${TAR} xfz ${WRKSRC}/lib/surf/surf.tar.Z -C ${WRKSRC}/lib/surf
	${TAR} xfz ${DISTDIR}/${TACHYON_DIST} -C ${WRKSRC}/lib
	${TAR} xfz ${DISTDIR}/${STRIDE_DIST} -C ${WRKSRC}/lib/stride

post-patch:
	${REINPLACE_CMD} "s/-lpthread/${PTHREAD_LIBS}/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/-ltk8.4/-ltk84/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/-ltcl8.4/-ltcl84/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s%\$$python_dir/lib_\$$config_arch%${PREFIX}%" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/python2.2/${PYTHON_VERSION}/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/.SILENT:/#.SILENT:/" ${WRKDIR}/plugins/Makefile
	${REINPLACE_CMD} "s/.SILENT:/#.SILENT:/" ${WRKDIR}/plugins/*/Makefile

do-build:
	${SETENV} ${MAKE_ENV} ${GMAKE} bsd -C ${WRKSRC}/lib/tachyon/unix && ${MV} ${WRKSRC}/lib/tachyon/compile/bsd/tachyon ${WRKSRC}/lib/tachyon/tachyon_${VMD_ARCH}
	${SETENV} ${MAKE_ENV} PLUGINDIR=${WRKSRC}/plugins ${GMAKE} ${VMD_ARCH} distrib -C ${WRKDIR}/plugins
	${SETENV} ${MAKE_ENV} TCL_INCLUDE_DIR=${PREFIX}/include/tcl8.4 TK_INCLUDE_DIR=${PREFIX}/include/tk8.4 ${GMAKE} ${VMD_TARGET} -C ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${GMAKE} all -C ${WRKSRC}/src
	${SETENV} ${MAKE_ENV} ${GMAKE} depend -C ${WRKSRC}/lib/surf && ${SETENV} ${MAKE_ENV} ${GMAKE} surf -C ${WRKSRC}/lib/surf && ${MV} ${WRKSRC}/lib/surf/surf ${WRKSRC}/lib/surf/surf_${VMD_ARCH}
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC}/lib/stride && ${MV} ${WRKSRC}/lib/stride/stride ${WRKSRC}/lib/stride/stride_${VMD_ARCH}

do-install:
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC}/src install
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/vmd

.include <bsd.port.post.mk>
