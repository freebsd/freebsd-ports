# New ports collection makefile for:	mpich (portable mpi standard imp.)
# Date created:		2 May 1998
# Whom:                 dbader@ece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	mpich2
DISTVERSION=	1.1.1p1
PORTEPOCH=	4
CATEGORIES=	net parallel
MASTER_SITES=	http://www.mcs.anl.gov/research/projects/mpich2/downloads/tarballs/${DISTVERSION}/
DIST_SUBDIR=	mpich
#PATCH_SITES=	ftp://ftp.mcs.anl.gov/pub/mpi/mpich2-patch/
#PATCHFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable implementation of MPI-1 and MPI-2

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo
#BUILD_DEPENDS=	doctext:${PORTSDIR}/textproc/sowing

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_JAVA	don't build MPE Jumpshot-4
# - WITHOUT_X11		disable MPE graphics routines
# - WITH_SMPD		use SMPD instead of MPD for OS-mixed cluster
#-----------------------------------------------------------------------

USE_PYTHON=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-romio --enable-sharedlibs=gcc	\
		--docdir=${DOCSDIR}
CONFIGURE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}" CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib -lexecinfo ${PTHREAD_LIBS}"			\
		PACKAGE=${PORTNAME}
FFLAGS?=	-O2
NOCCACHE=	yes
MAKE_ENV=	CCACHE_DISABLE=yes PACKAGE=${PORTNAME}
.if defined(WITH_DEBUG)
MAKE_ENV+=	VERBOSE=1
.endif

USE_FORTRAN=	yes
F90FLAGS+=	${FFLAGS}
CONFIGURE_ENV+=	F90="${FC}" F90FLAGS="${F90FLAGS}"

NO_MTREE=	yes
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--disable-graphics
WITHOUT_JAVA=	yes
PLIST_SUB+=	X11="@comment "
.else
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include --x-libraries==${X11BASE}/lib
USE_XORG=	x11 xt
PLIST_SUB+=	X11=${PLX11}
.endif
.if defined(WITHOUT_JAVA)
CONFIGURE_ARGS+=	--without-java
PLIST_SUB+=	JAVA="@comment "
PLX11=		"@comment "
.else
USE_JAVA=	yes
JAVA_VERSION=	1.4+
BUILD_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper
PLIST_SUB+=	JAVA=""
PLX11=		""
.endif

.if defined(WITH_SMPD)
CONFIGURE_ARGS+=	--with-pmi=smpd --with-pm=smpd
PLIST_SUB+=	PM_MPD="@comment " PM_SMPD=""
.else
CONFIGURE_ARGS+=	--with-pmi=simple --with-pm=mpd
PLIST_SUB+=	PM_MPD="" PM_SMPD="@comment "
.endif

LIBSSO=		fmpich mpich mpichcxx

THREAD2FIX=	configure test/mpi/threads/comm/Makefile.in	\
		test/mpi/threads/pt2pt/Makefile.in		\
		src/mpe2/src/logging/configure			\
		src/mpi/romio/configure src/openpa/configure	\
		src/pm/hydra/configure
LOCALBASE2FIX=	src/mpe2/src/slog2sdk/trace_rlog/configure	\
		src/mpe2/src/slog2sdk/trace_sample/configure	\
		src/mpe2/src/graphics/configure
DOC2PATCH=	Makefile.in src/mpe2/sbin/mpeinstall.in		\
		src/openpa/Makefile.in src/mpi/romio/util/romioinstall.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000 && defined(PACKAGE_BUILDING)
WITHOUT_JAVA=	yo	# No package for Java ATM
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
WITHOUT_JAVA=	yo	# No package for Java ATM
.endif

.if ${ARCH} == "amd64"
# gmake should not be required, this is a work-around
USE_GMAKE=	yes
.endif

.if ${OSVERSION} < 700000
BROKEN=	Requested timer clock_gettime (POSIX) is not available for ${OSREL}
.endif

.if !defined(NOPORTDOCS)
.include "${FILESDIR}/manpages"
.endif

PREFIX:=	${PREFIX}/${PORTNAME}

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You could define the following options:"
.if !defined(WITHOUT_JAVA)
	@${ECHO_MSG} "- WITHOUT_JAVA	do not build MPE Jumpshot-4"
.endif
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} "- WITHOUT_X11	disable MPE graphics routines"
.endif
.if !defined(WITH_SMPD)
	@${ECHO_MSG} "- WITH_SMPD	use SMPD instead of MPD, to work with SMPD under MS Windows"
.endif
	@${ECHO_MSG}

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${THREAD2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${LOCALBASE2FIX:S|^|${WRKSRC}/|}
	${FIND} ${WRKSRC} -name configure | ${XARGS}	\
		${REINPLACE_CMD} -e 's|doc/$${PACKAGE}|doc/${PORTNAME}|'
.for fin in ${DOC2PATCH}
. if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|%%PORTDOCS%%|#|' ${WRKSRC}/${fin}
. else
	${REINPLACE_CMD} -e 's|%%PORTDOCS%%||' ${WRKSRC}/${fin}
. endif
.endfor
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|lib doc share|lib share|'	\
		${WRKSRC}/src/mpe2/src/slog2sdk/sbin/install-package.in
.endif

post-configure:
	${REINPLACE_CMD} -e 's|$${exec_prefix}|${PREFIX}|g;	\
		s|$${prefix}|${PREFIX}|g'			\
		${WRKSRC}/src/packaging/pkgconfig/mpich2-ch3.pc

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/bin
.for lib in ${LIBSSO}
	${MV} ${PREFIX}/lib/lib${lib}.so.1.1 ${PREFIX}/lib/lib${lib}.so.1
	${LN} -sf ${PREFIX}/lib/lib${lib}.so.1 ${PREFIX}/lib/lib${lib}.so
	${LN} -sf ${PREFIX}/lib/lib${lib}.so.1 ${PREFIX}/lib/lib${lib}.so.1.1
.endfor
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/bin
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.if defined(MAINTAINER_MODE)
regression-test:	install
.if !exists(${HOME}/.mpd.conf)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${HOME}/.mpd.conf
	${CHMOD} go-r ${HOME}/.mpd.conf
	@${ECHO_MSG} "${HOME}/.mpd.conf has been generated - please change the secret word!"
.endif
	@${ECHO_MSG} "Don't hesitate to increase MPIEXEC_RECV_TIMEOUT if needed!"
	${PREFIX}/bin/mpd &
	(cd ${WRKSRC} && \
	PATH=${PATH}:${PREFIX}/bin VERBOSE=1 ${MAKE} testing)
	${PREFIX}/bin/mpdallexit
.endif

.include <bsd.port.post.mk>
