# New ports collection makefile for:	FreeMat
# Date created:		Sat 26 mar 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=		FreeMat
PORTVERSION=		3.6
PORTREVISION=	5
CATEGORIES=		math science
MASTER_SITES=		SF
.ifdef WITH_MPI
PKGNAMESUFFIX=		-mpi
.endif

MAINTAINER=		ports@FreeBSD.org
COMMENT=		An environment for rapid engineering and scientific processing

LIB_DEPENDS=		lapack.4:${PORTSDIR}/math/lapack	\
			pcre.0:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=		pkg-config:${PORTSDIR}/devel/pkg-config

BROKEN=			does not compile

.ifdef WITH_MPI
IGNORE=			no MPI support at the moment
.endif

USE_FORTRAN=		yes
FFLAGS+=		-O2

USE_GL=			yes
USE_QT_VER=		4
USE_GMAKE=		yes
QT_COMPONENTS=		gui network opengl moc_build rcc_build uic_build xml svg
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-blas="${BLAS}" --without-llvm
CPPFLAGS=		${CXXFLAGS} -I${LOCALBASE}/include  ${AMDINC}
CONFIGURE_ENV=		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

SLAVEDIRS=	math/freemat-mpi

DATADIR+=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}

.if !defined(WITHOUT_FFTW)
LIB_DEPENDS+=	fftw3.5:${PORTSDIR}/math/fftw3		\
		fftw3f.5:${PORTSDIR}/math/fftw3-float
.endif

.if !defined(WITHOUT_ARPACK)
LIB_DEPENDS+=	arpack.1:${PORTSDIR}/math/arpack
.endif

.if !defined(WITHOUT_AVCALL)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libavcall.a:${PORTSDIR}/devel/ffcall
.endif

.if !defined(WITHOUT_PORTAUDIO)
LIB_DEPENDS+=	portaudio.0:${PORTSDIR}/audio/portaudio
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
LIB_DEPENDS+=	amd.1:${PORTSDIR}/math/suitesparse
AMDINC=		-I${LOCALBASE}/include/suitesparse
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
	@${ECHO_MSG} '* - WITHOUT_PORTAUDIO remove Audio I/O support           *'
	@${ECHO_MSG} '**********************************************************'
.endif

pre-configure:
	${REINPLACE_CMD} -e 's| == x| = x|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
	# Avoid conflict with QT3
	${FIND} ${WRKSRC} -name Makefile | ${XARGS}	\
		${REINPLACE_CMD} -e '/^QT_CFLAGS/s|-I${LOCALBASE}/include ||'

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "===> Initializing..."
	${PREFIX}/bin/FreeMat -i ${DATADIR}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
