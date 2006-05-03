# Include before bsd.port.pre.mk for XFree86-4 ports which share 
# XFree86-4-libraries's patches.
# The purpose of this file is to reduce the duplicated code among the XFree86-4
# ports which each do only part of a standard XFree86 build.
#
# XBUILD_DIRS is the group of directories under ${WRKSRC} that will 
#   be built in.
# XINCLUDE_DIRS is the group of directories under ${WRKSRC} that need
#   to be Makefilesed or included in besides XBUILD_DIRS
# XINSTALL_DIRS is the group of directories which will have 
#   their install targets run.
# XMAN_DIRS is the group of directories which will have 
#   their install.man targets run.

DIST_SUBDIR?=	xorg
WRKSRC?=	${WRKDIR}/xc
USE_X_PREFIX?=	no
PREFIX?=	${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/*

USE_IMAKE=	YES
.if defined(XMAN_DIRS)
XFREE86_HTML_MAN?=	yes
.else
XFREE86_HTML_MAN?=	no
.endif
SCRIPTS_ENV+=	CC="${CC}" \
		CXX="${CXX}" \
		CFLAGS="${CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

XINSTALL_DIRS?=	${XBUILD_DIRS}
_XINCLUDE_DIRS=	include ${XBUILD_DIRS} ${XINCLUDE_DIRS}

CF_PATCHES=	${PORTSDIR}/x11-servers/xorg-server/files/patch-FreeBSD.cf \
		${PORTSDIR}/x11-servers/xorg-server/files/patch-Imake.rules \
		${PORTSDIR}/x11-servers/xorg-server/files/patch-Imake.tmpl \
		${PORTSDIR}/x11-servers/xorg-server/files/patch-Library.tmpl \
		${PORTSDIR}/x11-servers/xorg-server/files/patch-X11.rules \
		${PORTSDIR}/x11-servers/xorg-server/files/patch-X11.tmpl

SERVER_PATCHES=	${PORTSDIR}/x11-servers/xorg-server/files/patch-Xserver-Imakefile \
		${PORTSDIR}/x11-servers/xorg-server/files/patch-Xserver-Xext-xvmc.c \
		${PORTSDIR}/x11-servers/xorg-server/files/patch-Xserver-os-xprintf.c \
		${PORTSDIR}/x11-servers/xorg-server/files/patch-mitri.c \
		${PORTSDIR}/x11-servers/xorg-server/files/patch-servermd.h \
		${PORTSDIR}/x11-servers/xorg-server/files/patch-xf86sym.c

.if !target(do-configure)
do-configure:
	@cp ${X11BASE}/lib/X11/config/version.def ${WRKSRC}/config/cf
	@cp ${X11BASE}/lib/X11/config/date.def ${WRKSRC}/config/cf
	@cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} Makefile.boot
	@for dir in ${_XINCLUDE_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${WRKSRC}/config/imake/imake \
			-DTOPDIR=${WRKSRC} -DCURDIR=$${dir} -I${WRKSRC}/config/cf; \
	done
	@for dir in ${_XINCLUDE_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} Makefiles; \
	done
	@for dir in ${_XINCLUDE_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} includes; \
	done
	@for dir in include ${XBUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} depend; \
	done
.endif

.if !target(do-build)
do-build:
	@for dir in ${XBUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} all; \
	done
.endif

.if !target(do-install)
do-install:
	@for dir in ${XINSTALL_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} install; \
	done
	@for dir in ${XMAN_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} install.man; \
	done
.endif

