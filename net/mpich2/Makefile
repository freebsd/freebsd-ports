# Created by: dbader@ece.unm.edu
# $FreeBSD$

PORTNAME=	mpich2
DISTVERSION=	1.3.2p1
PORTREVISION=	3
PORTEPOCH=	5
CATEGORIES=	net java parallel
MASTER_SITES=	http://www.mcs.anl.gov/research/projects/mpich2/downloads/tarballs/${DISTVERSION}/
DIST_SUBDIR=	mpich

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A portable implementation of MPI-1 and MPI-2

LICENSE=	MPICH
LICENSE_NAME=	MPICH
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USES=		fortran perl5 pkgconfig
USE_GCC=	yes
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_PYTHON=	yes

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
		PACKAGE=${PORTNAME} \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

CPPFLAGS+=	-I${LOCALBASE}/include
.if ${FFLAGS} == "-O"
FFLAGS =	-O2
.endif
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo ${PTHREAD_LIBS}

MAKE_ENV=	CCACHE_DISABLE=yes PACKAGE=${PORTNAME}
NOCCACHE=	yes

CONFLICTS=	lam-7.* mpd-[0-9]* mpiexec-0.*
MAKE_JOBS_UNSAFE=	yes

VERSO=		2.2
VERSOM=		${VERSO:R}
PLIST_SUB=	VER=${VERSO} VERM=${VERSOM}
SUB_FILES=	pkg-message

NO_STAGE=	yes
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
IGNORE =	WITH_JAVA requires WITH_X11
.endif
CONFIGURE_ARGS+=	--with-java="${JAVA_HOME}"
USE_JAVA=	yes
JAVA_VERSION=	1.6+
BUILD_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper
PLIST_SUB+=	JAVA=""
PLX11=		""
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

.if ${PORT_OPTIONS:MDOCS}
.include "${FILESDIR}/manpages"
.endif

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
CONFPFX2FIX1=	src/pm/mpd/mpd.py
CONFPFX2FIX2=	doc/installguide/install.tex.vin		\
		src/pm/mpd/mpdroot.c

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${THREAD2FIX:S|^|${WRKSRC}/|}
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

pre-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/bin
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py  ${WRKSRC}/bin

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.pyc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.pyo ${PREFIX}/bin
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${WRKDIR}/mpd.conf.dist
	${INSTALL_DATA} ${WRKDIR}/mpd.conf.dist ${PREFIX}/etc/
	if [ ! -e ${PREFIX}/etc/mpd.conf ]; then \
		${INSTALL_DATA} ${WRKDIR}/mpd.conf.dist ${PREFIX}/etc/mpd.conf ; \
	fi
	${CHMOD} 600 ${PREFIX}/etc/mpd.conf ${PREFIX}/etc/mpd.conf.dist
	@${CAT} ${PKGMESSAGE}

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
