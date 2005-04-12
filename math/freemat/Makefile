# New ports collection makefile for:	FreeMat
# Date created:		Sat 26 mar 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=		freemat
PORTVERSION=		1.10
CATEGORIES=		math science
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.ifdef WITH_MPI
PKGNAMESUFFIX=		-mpi
.endif
DISTNAME=		FreeMat-${PORTVERSION}-1

MAINTAINER=		ports@FreeBSD.org
COMMENT=		An environment for rapid engineering and scientific processing

LIB_DEPENDS=		f2c.2:${PORTSDIR}/lang/f2c		\
			gsl.6:${PORTSDIR}/math/gsl		\
			jpeg.9:${PORTSDIR}/graphics/jpeg	\
			lapack.3:${PORTSDIR}/math/lapack	\
			png.5:${PORTSDIR}/graphics/png		\
			tiff.4:${PORTSDIR}/graphics/tiff
BUILD_DEPENDS=		${LOCALBASE}/lib/libarpack.a:${PORTSDIR}/math/arpack	\
			${LOCALBASE}/lib/libumfpack.a:${PORTSDIR}/math/umfpack

USE_GL=			yes
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-blas="${lib_blas}"
CONFIGURE_ENV=		CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${THRDFLG}"	\
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${THRDLIB}"

FFLAGS?=	-O2

SLAVEDIRS=	math/freemat-mpi

.if defined(WITH_BLAS)
LIB_DEPENDS+=	blas.1:${PORTSDIR}/math/blas
lib_blas=	-lblas -lgslcblas
.else
LIB_DEPENDS+=	f77blas.1:${PORTSDIR}/math/atlas
lib_blas=	-lf77blas -latlas -lgslcblas
.endif

.if !defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--enable-xft	# Set by default since FLTK depends on it.
.endif

.if defined(WITHOUT_THREADS)
LIB_DEPENDS+=		fltk.1:${PORTSDIR}/x11-toolkits/fltk
THRDFLG=
THRDLIB=
.else
LIB_DEPENDS+=		fltk.1:${PORTSDIR}/x11-toolkits/fltk-threads
CONFIGURE_ARGS+=	--enable-threads
THRDFLG=		${PTHREAD_CFLAGS}
THRDLIB=		${PTHREAD_LIBS}
.endif

WRKSRC=		${WRKDIR}/FreeMat-${PORTVERSION}
SUB_FILES=	pkg-message
DATADIR=	${PREFIX}/share/FreeMat

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Does not compile with gcc-2.95"
.endif

.if exists(${LOCALBASE}/bin/balky)
WITH_MPI=	yes
.endif
.if defined(WITH_MPI)
. if exists(${LOCALBASE}/bin/laminfo)
BROKEN=	"does not work with net/lam7, please install net/lam"
. endif
BUILD_DEPENDS+=	mpiCC:${PORTSDIR}/net/lam
RUN_DEPENDS+=	lamboot:${PORTSDIR}/net/lam
CONFIGURE_ARGS+=--with-mpi=yes
.endif

pre-everything::
	@${ECHO_MSG} '**********************************************************'
	@${ECHO_MSG} '* You can define the following variables:                *'
	@${ECHO_MSG} '* - WITH_BLAS:       to avoid atlas;                     *'
	@${ECHO_MSG} '* - WITH_MPI:        to build the MPI executable;        *'
	@${ECHO_MSG} '* - WITHOUT_XFT:     to turn off Xft support;            *'
	@${ECHO_MSG} '* - WITHOUT_THREADS: to disable multi-threading support. *'
	@${ECHO_MSG} '**********************************************************'

pre-configure:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|SUBDIRS = mdc html|SUBDIRS = mdc|' ${WRKSRC}/help/Makefile.in
.endif
	${FIND} ${WRKSRC} -name Makefile.in -exec ${REINPLACE_CMD}				\
	-e 's|-I@top_srcdir@/libs/libFLTK|-I${X11BASE}/include|;				\
	s|$$(JPEGLIB) @top_builddir@/libs/libFLTK/libFLTK.a||;					\
	s|@top_builddir@/libs/libFLTK/libFLTK.a|`fltk-config --use-images --ldflags`|;		\
	s|-I@top_srcdir@/libs/libUMFPACK/UMFPACK/Include|-I${LOCALBASE}/include/UMFPACK|;	\
	s|@top_builddir@/libs/libUMFPACK/UMFPACK/libUMFPACKdi.a|${LOCALBASE}/lib/libumfpack.a|;	\
	s|@top_builddir@/libs/libUMFPACK/UMFPACK/libUMFPACKzi.a||;				\
	s|@top_builddir@/libs/libUMFPACK/AMD/libAMD.a|${LOCALBASE}/lib/libamd.a|;		\
	s|@top_builddir@/libs/libARPACK/libARPACK.a|${LOCALBASE}/lib/libarpack.a|;		\
	s|-L/sw/lib ||'	{} \;

.include <bsd.port.post.mk>
