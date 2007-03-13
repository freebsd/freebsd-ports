# New ports collection makefile for:	gamess
# Date created:		2007-3-13
# Whom:			NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gamess
PORTVERSION=    ${SNAPDATE}.4
CATEGORIES=	science
MASTER_SITES=   #http://www.msg.ameslab.gov/GAMESS/GAMESS.html
DISTNAME=	gamess-current
DIST_SUBDIR=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A freely obtainable ab-initio molecular orbital calculation program

USE_GMAKE=	yes
WRKSRC=         ${WRKDIR}/gamess
SNAPDATE=	20060907

WANT_FORTRAN=   yes
BUILD_DEPENDS+= gfortran42:${PORTSDIR}/lang/gcc42
FC=             gfortran42
F77=            gfortran42

RESTRICTED=	NOT DISTRIBUTED FREELY. BUT YOU CAN OBTAIN SOURCE CODE FREELY.
NO_CDROM=	${RESTRICTED}

.if !exists(${DISTDIR}/${DISTFILES})
IGNORE=You must manually get the source distribution from master site. http://www.msg.ameslab.gov/GAMESS/dist.menu.html. Please selsect "Source code distribution", and check on "running on Intel compatible PC running Linux". You must have license, and freely obtainable.
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS=		-lblas
.endif

.if defined(WITH_OPTIMIZED_FLAGS)
.if ${ARCH} == "amd64"
CFLAGS+=      -pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
FFLAGS+=      -pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
.elif ${ARCH} == "i386"
CFLAGS+=      -pipe -O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double -mcpu=i686 -march=i686 -mfancy-math-387
FFLAGS+=      -pipe -O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double -mcpu=i686 -march=i686 -mfancy-math-387
.endif
.endif

#WITH_IFC=       yes #currently building with ifc is broken
.if defined(WITH_IFC)
FC=    ${LOCALBASE}/intel_fc_80/bin/ifort
F77=   ${LOCALBASE}/intel_fc_80/bin/ifort
CC=    ${LOCALBASE}/intel_cc_80/bin/icc
FFLAGS= -axP -xW -ipo -O3 -Vaxlib
CFLAGS= -axP -xW -ipo -O3 -Vaxlib
LIBSVM=	-lsvml
LIBG2C=	-lg2c
.else
LIBG2C=
LIBSVM=
.endif

.if defined(WITH_IFC)
FORTRAN=	ifort
.else
FORTRAN=	gfortran
.endif

pre-build:
.if ${ARCH} == "amd64"
	@${REINPLACE_CMD} -e 's+%%ARCH%%+freebsd-amd64+g' ${WRKSRC}/comp
	@${REINPLACE_CMD} -e 's+%%ARCH%%+freebsd-amd64+g' ${WRKSRC}/compall
	@${REINPLACE_CMD} -e 's+%%ARCH%%+freebsd-amd64+g' ${WRKSRC}/ddi/compddi
	@${REINPLACE_CMD} -e 's+%%ARCH%%+freebsd-amd64+g' ${WRKSRC}/lked
.elif ${ARCH} == "i386"
	@${REINPLACE_CMD} -e 's+%%ARCH%%+freebsd-i386+g' ${WRKSRC}/comp
	@${REINPLACE_CMD} -e 's+%%ARCH%%+freebsd-i386+g' ${WRKSRC}/compall
	@${REINPLACE_CMD} -e 's+%%ARCH%%+freebsd-i386+g' ${WRKSRC}/ddi/compddi
	@${REINPLACE_CMD} -e 's+%%ARCH%%+freebsd-i386+g' ${WRKSRC}/lked
.endif
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; \
			      s+%%PREFIX%%+${PREFIX}+g ; \
			      s+%%LIBSVM%%+${LIBSVM}+g ; \
			      s+%%LIBG2C%%+${LIBG2C}+g ; \
			      s+%%BLAS%%+${BLAS}+g ; \
			      s+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g' \
			 ${WRKSRC}/lked
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; \
			      s+%%PREFIX%%+${PREFIX}+g ; \
			      s+%%FFLAGS%%+${FFLAGS}+g ; \
			      s+%%FORTRAN%%+${FORTRAN}+g' \
			 ${WRKSRC}/comp
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g' \
			 ${WRKSRC}/compall
	@${REINPLACE_CMD} -e 's+%%PREFIX%%+${PREFIX}+g' \
			 ${WRKSRC}/rungms
	@${REINPLACE_CMD} -e 's+%%PTHREAD_CFLAGS%%+${PTHREAD_CFLAGS}+g ; \
			      s+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g ; \
			      s+%%UNDERSCORES%%+${UNDERSCORES}+g ; \
			      s+%%FORTRAN%%+${FORTRAN}+g ; \
			      s+%%CC%%+${CC}+g' \
			 ${WRKSRC}/ddi/compddi

	${CP} ${FILESDIR}/Makefile.top ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/Makefile.tools ${WRKSRC}/tools/Makefile
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; \
			      s+%%FFLAGS%%+${FFLAGS}+g' \
		${WRKSRC}/tools/Makefile
do-build:
	(cd ${WRKSRC}; ${GMAKE})

do-install:
	${MKDIR} ${PREFIX}/bin/gms
	${MKDIR} ${PREFIX}/share/gamess
	${MKDIR} ${PREFIX}/share/doc/gamess
	${MKDIR} ${PREFIX}/share/examples/gamess
	${INSTALL_SCRIPT}  ${WRKDIR}/gamess/rungms		${PREFIX}/bin/gamess
	${CHMOD} 555 ${PREFIX}/bin/gamess
	${INSTALL_PROGRAM} ${WRKDIR}/gamess/gamess.00.x          ${PREFIX}/bin/gms
	${INSTALL_PROGRAM} ${WRKDIR}/gamess/ddi/ddikick.x            ${PREFIX}/bin/gms
	${INSTALL_DATA}    ${WRKDIR}/gamess/*.DOC                ${PREFIX}/share/doc/gamess/
	${INSTALL_DATA}    ${WRKDIR}/gamess/tests/*.inp          ${PREFIX}/share/examples/gamess/
	${INSTALL_DATA}    ${WRKDIR}/gamess/ericfmt.dat          ${PREFIX}/share/gamess/

.include <bsd.port.post.mk>
