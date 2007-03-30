# New ports collection makefile for:	mpich (portable mpi standard imp.)
# Date created:		2 May 1998
# Whom:                 dbader@ece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	mpich2
PORTVERSION=	1.0.5p4
PORTEPOCH=	2
CATEGORIES=	net parallel
MASTER_SITES=	ftp://ftp.mcs.anl.gov/pub/mpi/	\
		http://www-unix.mcs.anl.gov/mpi/mpich/downloads/
DIST_SUBDIR=	mpich
#PATCH_SITES=	ftp://ftp.mcs.anl.gov/pub/mpi/mpich2-patch/
#PATCHFILES=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A portable implementation of MPI-1 and MPI-2

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

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-romio --enable-sharedlibs=gcc
CONFIGURE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}" LDFLAGS="${PTHREAD_LIBS}" F77=${F77} FFLAGS=${FFLAGS}
FFLAGS?=	-O2
NOCCACHE=	yes
MAKE_ENV=	CCACHE_DISABLE=yes

WANT_FORTRAN=	yes
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
F90FLAGS+=	${FFLAGS}
CONFIGURE_ENV+=	F90=${FC} F90FLAGS=${F90FLAGS} F77=${FC}

NO_MTREE=	yes
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--disable-graphics
WITHOUT_JAVA=	yes
PLIST_SUB+=	X11="@comment "
.else
USE_XLIB=	yes
PLIST_SUB+=	X11=""
.endif
.if defined(WITHOUT_JAVA)
CONFIGURE_ARGS+=	--without-java
PLIST_SUB+=	JAVA="@comment "
.else
USE_JAVA=	yes
JAVA_VERSION=	1.4+
BUILD_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper
PLIST_SUB+=	JAVA=""
.endif

.if defined(WITH_SMPD)
CONFIGURE_ARGS+=	--with-pmi=smpd --with-pm=smpd
PLIST_SUB+=	PM_MPD="@comment " PM_SMPD=""
.else
CONFIGURE_ARGS+=	--with-pmi=simple --with-pm=mpd
PLIST_SUB+=	PM_MPD="" PM_SMPD="@comment "
.endif

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--without-docdir --without-htmldir
.else
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR} --with-htmldir=${DOCSDIR}
.endif

LIBSSO=		fmpich mpich

THREAD2FIX=	configure test/mpi/threads/comm/Makefile.in	\
		test/mpi/threads/pt2pt/Makefile.in
LOCALBASE2FIX=	src/mpe2/src/slog2sdk/trace_rlog/configure	\
		src/mpe2/src/slog2sdk/trace_sample/configure
X11BASE2FIX=	src/mpe2/src/graphics/configure

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000 && defined(PACKAGE_BUILDING)
WITHOUT_JAVA=	yo	# No package for Java ATM
.endif

.if ${ARCH} == "amd64"
# gmake should not be required, this is a work-around
USE_GMAKE=	yes
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
	${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${X11BASE2FIX:S|^|${WRKSRC}/|}

	${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/confdb/libtool-2.13.m4
	${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/confdb/libtool.m4
	${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/src/mpe2/src/slog2sdk/trace_rlog/libtool.m4
	${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/src/mpe2/src/slog2sdk/trace_sample/libtool.m4
	${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${THREAD2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${LOCALBASE2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${X11BASE2FIX:S|^|${WRKSRC}/|}

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/bin
.for lib in ${LIBSSO}
	${MV} ${PREFIX}/lib/lib${lib}.so ${PREFIX}/lib/lib${lib}.so.0
	${LN} -s ${PREFIX}/lib/lib${lib}.so.0 ${PREFIX}/lib/lib${lib}.so
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
	${PREFIX}/bin/mpd &
	(cd ${WRKSRC} && \
	PATH=${PATH}:${PREFIX}/bin VERBOSE=1 ${MAKE} testing)
	${PREFIX}/bin/mpdallexit
.endif

.include <bsd.port.post.mk>
