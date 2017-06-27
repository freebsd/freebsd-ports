# Created by: Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
# $FreeBSD$

PORTNAME=	pari
PORTVERSION=	2.9.2
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	yuri@rawbw.com
COMMENT=	Mathematics library and advanced calculator package

LICENSE=	GPLv2

LIB_DEPENDS=	libgmp.so:math/gmp

MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	gp
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man/man1 \
		--prefix=${PREFIX} \
		--with-readline
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	build
USES=		perl5 readline

OPTIONS_DEFINE=		DOCS OPTIMIZED_CFLAGS X11
OPTIONS_RADIO=		THREADS
OPTIONS_RADIO_THREADS=	PTHREADS MPI
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS X11 PTHREADS
THREADS_DESC=		Thread engine (single-threaded when none is selected)
PTHREADS_DESC=		Enable pthread thread engine
MPI_DESC=		Enable MPI thread engine
MPI_BUILD_ENV=		CC=mpicc
.ifndef WITH_DEBUG
OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fno-strict-aliasing -fomit-frame-pointer
.endif
X11_CONFIGURE_ON=	--graphic=X11
X11_CONFIGURE_OFF=	--graphic=none
X11_USE=		xorg=x11
MPI_RUN_DEPENDS=	${LOCALBASE}/bin/mpirun:net/mpich2
MPI_BUILD_DEPENDS=	${LOCALBASE}/bin/mpicc:net/mpich2
MPI_LIB_DEPENDS=	libgmp.so:math/gmp
PTHREADS_LIB_DEPENDS=	libgmp.so:math/gmp
PTHREADS_CONFIGURE_ON=	--mt=pthread --with-gmp=${LOCALBASE}
MPI_CONFIGURE_ON=	--mt=mpi --with-gmp=${LOCALBASE}
MPI_CONFIGURE_ENV=	CC=${LOCALBASE}/bin/mpicc
OPTIONS_SUB=	yes

PLIST_SUB=	GP_VERSION=${GP_VERSION} PORTVERSION=${PORTVERSION}
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

GP_VERSION=	${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS=/s/\$$cflags//' \
		${WRKSRC}/config/get_cc
	@${REINPLACE_CMD} -e 's|-lX11|-L${LOCALBASE}/lib -lX11|' \
		${WRKSRC}/config/get_X11
	@${REINPLACE_CMD} -e 's|-lreadline|-L${LOCALBASE}/lib -lreadline|' \
		${WRKSRC}/config/get_readline

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpari-gmp*.so.*

do-test-PTHREADS-on:
	@cd ${WRKSRC} && ${MAKE_CMD} test-parallel

do-test-MPI-on:
	@cd ${WRKSRC} && ${MAKE_CMD} test-parallel RUNTEST="mpirun -np 3"

.include <bsd.port.mk>
