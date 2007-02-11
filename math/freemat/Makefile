# New ports collection makefile for:	FreeMat
# Date created:		Sat 26 mar 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=		FreeMat
PORTVERSION=		3.0
CATEGORIES=		math science
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
.ifdef WITH_MPI
PKGNAMESUFFIX=		-mpi
.endif

MAINTAINER=		ports@FreeBSD.org
COMMENT=		An environment for rapid engineering and scientific processing

LIB_DEPENDS=		lapack.4:${PORTSDIR}/math/lapack
BUILD_DEPENDS=		pkg-config:${PORTSDIR}/devel/pkg-config

.ifdef WITH_MPI
IGNORE=			no MPI support at the moment
.endif

WANT_FORTRAN=		yes #dummy but future use
BUILD_DEPENDS+=		gfortran42:${PORTSDIR}/lang/gcc42
FC=			gfortran42
F77=			gfortran42
FFLAGS+=		-O2

USE_GL=			yes
USE_QT_VER=		4
USE_GMAKE=		yes
QT_COMPONENTS=		gui network opengl moc rcc uic
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-blas="${BLAS}"
CPPFLAGS=		${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include ${AMDINC}
CONFIGURE_ENV=		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"		\
			FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"

SLAVEDIRS=	math/freemat-mpi

DATADIR+=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}

.if !defined(WITHOUT_FFTW)
LIB_DEPENDS+=	fftw3.4:${PORTSDIR}/math/fftw3		\
		fftw3f.4:${PORTSDIR}/math/fftw3-float
.endif

.if !defined(WITHOUT_ARPACK)
LIB_DEPENDS+=	arpack.1:${PORTSDIR}/math/arpack
.endif

.if !defined(WITHOUT_AVCALL)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libavcall.a:${PORTSDIR}/devel/ffcall
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas	\
		lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if !defined(WITHOUT_UMFPACK)
. if exists(${LOCALBASE}/include/AMD/amd.h)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libamd.a:${PORTSDIR}/math/umfpack
AMDINC=		-I${LOCALBASE}/include/AMD
. else
LIB_DEPENDS+=	amd.1:${PORTSDIR}/math/suitesparse
AMDINC=		-I${LOCALBASE}/include/suitesparse
. endif
.endif

pre-everything::
.if !defined(WITH_ATLAS)
	@${ECHO_MSG} '**********************************************************'
	@${ECHO_MSG} '* You can define the following variables:                *'
	@${ECHO_MSG} '* - WITH_ATLAS:       to link with atlas                 *'
	@${ECHO_MSG} '* - WITHOUT_FFTW      remove FFTW support                *'
	@${ECHO_MSG} '* - WITHOUT_ARPACK    remove Arpack support              *'
	@${ECHO_MSG} '* - WITHOUT_AVCALL    remove FFCALL support              *'
	@${ECHO_MSG} '* - WITHOUT_UMFPACK   remove UMFPACK support             *'
	@${ECHO_MSG} '**********************************************************'
.endif

pre-configure:
	${REINPLACE_CMD} -e 's| == x| = x|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
