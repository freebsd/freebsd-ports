# Created by: dbader@ece.unm.edu
# $FreeBSD$

PORTNAME=	mpich2
DISTVERSION=	1.5
PORTREVISION=	6
PORTEPOCH=	5
CATEGORIES=	net java parallel
MASTER_SITES=	http://www.mcs.anl.gov/research/projects/mpich2/downloads/tarballs/${DISTVERSION}/
DIST_SUBDIR=	mpich

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Portable implementation of MPI-1 and MPI-2

LICENSE=	MPICH
LICENSE_NAME=	MPICH
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

GNU_CONFIGURE=	yes
USES=		execinfo libtool:keepla localbase fortran perl5 \
		pkgconfig python
USE_GCC=	yes
USE_LDCONFIG=	yes
USE_PERL5=	build
INSTALL_TARGET=	install-strip

BROKEN_armv6=		fails to detect working compiler: undefined reference to _Unwind_GetIP@GCC_3.0

OPTIONS_DEFINE_i386=	JAVA
OPTIONS_DEFINE_amd64=	JAVA
OPTIONS_DEFINE=	SMPD X11 DOCS
OPTIONS_DEFAULT_i386=	JAVA
OPTIONS_DEFAULT_amd64=	JAVA
OPTIONS_DEFAULT=	X11
JAVA_DESC=	build MPE Jumpshot-4
SMPD_DESC=	use SMPD instead of MPD, for a mixed-OS cluster
X11_DESC=	build MPE graphics routines

CONFIGURE_ARGS=	--enable-romio --enable-shared	\
		--docdir="${DOCSDIR}" \
		--with-python="${PYTHON_CMD}"
CONFIGURE_ENV=	FCFLAGS="${FFLAGS}" \
		MPI_CFLAGS="-I${LOCALBASE}/include" \
		PACKAGE="${PORTNAME}" \
		PTHREAD_LIBS="-lpthread"

.if ${FFLAGS} == "-O"
FFLAGS=		-O2
.endif
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib -lexecinfo

MAKE_ENV=	CCACHE_DISABLE=yes PACKAGE=${PORTNAME}
NOCCACHE=	yes

CONFLICTS=	lam-7.* mpd-[0-9]* mpiexec-0.*

VERSO=		8.0.1
VERSOM=		${VERSO:R:R}
PLIST_SUB=	VER=${VERSO} VERM=${VERSOM}
SUB_FILES=	pkg-message

THREAD2FIX=	configure test/mpi/threads/comm/Makefile.in	\
		test/mpi/threads/pt2pt/Makefile.in		\
		src/mpe2/src/logging/configure			\
		src/mpi/romio/configure src/openpa/configure	\
		src/pm/hydra/configure
LOCALBASE2FIX=	src/mpe2/src/slog2sdk/trace_rlog/configure	\
		src/mpe2/src/slog2sdk/trace_sample/configure	\
		src/mpe2/src/graphics/configure
STAGE2FIX=	bin/mpicc bin/mpicxx bin/mpif77 bin/mpif90	\
		etc/mpicc.conf etc/mpicxx.conf etc/mpif77.conf	\
		etc/mpif90.conf sbin/mpeuninstall
DOC2PATCH=	Makefile.in src/mpe2/sbin/mpeinstall.in		\
		src/openpa/Makefile.in src/mpi/romio/util/romioinstall.in
CONFPFX2FIX1=	src/pm/mpd/mpd.py
CONFPFX2FIX2=	doc/installguide/install.tex.vin		\
		src/pm/mpd/mpdroot.c
BIN2STRIP=	check_callstack clog2_join clog2_print clog2_repair

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ENV+=	VERBOSE=1
.endif

.if ! ${PORT_OPTIONS:MJAVA}
CONFIGURE_ARGS+=	--without-java
PLIST_SUB+=	JAVA="@comment "
PLX11=		"@comment "
.else
.if ! ${PORT_OPTIONS:MX11}
IGNORE=		WITH_JAVA requires WITH_X11
.endif
CONFIGURE_ARGS+=	--with-java="${JAVA_HOME}"
USE_JAVA=	yes
JAVA_VERSION=	1.6+
PLIST_SUB+=	JAVA=""
PLX11=		""
BIN2STRIP+=	rlog_check_timeorder rlog_print
.endif

#define WITH_RECV_TIMEOUT to be an appropriate value (>20 for slow machines),
#in order to set a different default MPIEXEC_RECV_TIMEOUT
.if defined(MAINTAINER_MODE)
WITH_RECV_TIMEOUT?=	100
.else
WITH_RECV_TIMEOUT?=	20
.endif

.if ${PORT_OPTIONS:MSMPD}
CONFIGURE_ARGS+=	--with-pmi=smpd --with-pm=smpd
PLIST_SUB+=	PM_MPD="@comment " PM_SMPD=""
.else
CONFIGURE_ARGS+=	--with-pmi=simple --with-pm=mpd
PLIST_SUB+=	PM_MPD="" PM_SMPD="@comment "
BIN2STRIP+=	mpdroot
.endif

.if ! ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--disable-graphics
PLIST_SUB+=	X11="@comment "
.else
CONFIGURE_ARGS+=	--x-includes=${LOCALBASE}/include --x-libraries==${LOCALBASE}/lib
USE_XORG=	x11 xt
PLIST_SUB+=	X11=${PLX11}
.endif

.include <bsd.port.pre.mk>

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${LOCALBASE2FIX:S|^|${WRKSRC}/|}
	${FIND} ${WRKSRC} -name configure | ${XARGS}	\
		${REINPLACE_CMD} -e 's|doc/$${PACKAGE}|doc/${PORTNAME}|'
.for fin in ${DOC2PATCH}
. if ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|%%PORTDOCS%%||' ${WRKSRC}/${fin}
. else
	${REINPLACE_CMD} -e 's|%%PORTDOCS%%|#|' ${WRKSRC}/${fin}
. endif
.endfor
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|lib doc share|lib share|'	\
		${WRKSRC}/src/mpe2/src/slog2sdk/sbin/install-package.in
.endif
	${REINPLACE_CMD} -e '/MPIEXEC_RECV_TIMEOUT/s|20,|${WITH_RECV_TIMEOUT},|' \
		${WRKSRC}/src/pm/mpd/mpiexec.py
	${REINPLACE_CMD} -e 's|%%SRCDIR%%|${WRKSRC}|' ${WRKSRC}/${CONFIGURE_SCRIPT}
.for cnf in ${CONFPFX2FIX1}
	${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/${cnf}
.endfor
.for cnf in ${CONFPFX2FIX2}
	${REINPLACE_CMD} -e 's|/etc/mpd.conf|${PREFIX}/etc/mpd.conf|'	\
		${WRKSRC}/${cnf}
.endfor

post-install:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py	\
		-d ${PREFIX} -f bin)
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py	\
		-d ${PREFIX} -f bin)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${WRKDIR}/mpd.conf.dist
	${INSTALL_DATA} ${WRKDIR}/mpd.conf.dist ${STAGEDIR}${PREFIX}/etc/
.for pg in ${STAGE2FIX}
	${REINPLACE_CMD} -e '/${STAGEDIR:C|/|\/|g}/s|${STAGEDIR}||'	\
		${STAGEDIR}${PREFIX}/${pg}
	${RM} ${STAGEDIR}${PREFIX}/${pg}.bak
.endfor
.for pg in ${BIN2STRIP}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${pg}
.endfor
.if ${PORT_OPTIONS:MJAVA}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/trace_rlog/libTraceInput.so
.endif

.if defined(MAINTAINER_MODE)
regression-test:	install
.if !exists(${HOME}/.mpd.conf)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${HOME}/.mpd.conf
	${CHMOD} go-r ${HOME}/.mpd.conf
	@${ECHO_MSG} "${HOME}/.mpd.conf has been generated - please change the secret word!"
.endif
	@${ECHO_MSG} "Increase MPIEXEC_RECV_TIMEOUT if needed!"
	${PREFIX}/bin/mpd &
	(cd ${WRKSRC} && \
	PATH=${PATH}:${PREFIX}/bin VERBOSE=1 ${MAKE} testing)
	${PREFIX}/bin/mpdallexit
.endif

.include <bsd.port.post.mk>
