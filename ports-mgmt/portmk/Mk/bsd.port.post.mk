#-*- mode: makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if defined(_POSTMKINCLUDED)
check-makefile::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: you cannot include bsd.port[.post].mk twice"
	@${FALSE}
.endif

_POSTMKINCLUDED=	yes

OPTIONS_DBDIR?=	/var/db/options
OPTIONS_FILE?=	${OPTIONS_DBDIR}/${UNIQUENAME}

.if defined(_OPTIONSNG_READ) && exists(${OPTIONS_FILE})
.if ${_OPTIONSNG_READ} == "default"
_ONG_REEXEC=	yes
check-makefile::
	@${ECHO_MSG} "===>  Configuration error, \`make rmconfig' to remove custom options."
	@${FALSE}
.else
.undef _ONG_REEXEC
.endif
_ONG_MAKEFLAGS=	-f '${OPTIONS_FILE}' -f Makefile
.else
.undef _ONG_REEXEC
_ONG_MAKEFLAGS=	-f Makefile
.endif

WRKDIR?=		${WRKDIRPREFIX}${.CURDIR}/work
.if defined(NO_WRKSUBDIR)
WRKSRC?=		${WRKDIR}
.else
WRKSRC?=		${WRKDIR}/${DISTNAME}
.endif

PATCH_WRKSRC?=	${WRKSRC}
CONFIGURE_WRKSRC?=	${WRKSRC}
BUILD_WRKSRC?=	${WRKSRC}
INSTALL_WRKSRC?=${WRKSRC}

WRKINST?=		${WRKDIR}/.inst

.if defined(DESTDIR)
check-makefile::
	@${ECHO_CMD} "${PKGNAME}: DESTDIR is not a user settable variable"
	@${FALSE}
.endif

.if defined(CLEANROOM_INSTALL)
DESTDIR=		${WRKINST}
.endif

PLIST_SUB+=	OSREL=${OSREL} PREFIX=%D LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.if defined(WITHOUT_CPU_CFLAGS)
.if defined(_CPUCFLAGS)
.if !empty(_CPUCFLAGS)
CFLAGS:=	${CFLAGS:C/${_CPUCFLAGS}//}
.endif
.endif
.endif

.if defined(NOPORTDOCS)
PLIST_SUB+=	        PORTDOCS="@comment "
.else
PLIST_SUB+=	        PORTDOCS=""
.endif

CONFIGURE_SHELL?=	${SH}
MAKE_SHELL?=	${SH}

CONFIGURE_ENV+=	SHELL=${SH} CONFIG_SHELL=${SH} PORTOBJFORMAT=${PORTOBJFORMAT}
SCRIPTS_ENV+=	PORTOBJFORMAT=${PORTOBJFORMAT}
MAKE_ENV+=		SHELL=${SH} PORTOBJFORMAT=${PORTOBJFORMAT}
PLIST_SUB+=		PORTOBJFORMAT=${PORTOBJFORMAT}

.if defined(MANCOMPRESSED)
.if ${MANCOMPRESSED} != yes && ${MANCOMPRESSED} != no && \
	${MANCOMPRESSED} != maybe
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: value of MANCOMPRESSED (is \"${MANCOMPRESSED}\") can only be \"yes\", \"no\" or \"maybe\"".
	@${FALSE}
.endif
.endif

.if defined(USE_IMAKE) && !defined(NO_INSTALL_MANPAGES)
MANCOMPRESSED?=	yes
.else
MANCOMPRESSED?=	no
.endif

.if defined(PATCHFILES)
.if ${PATCHFILES:M*.bz2}x != x && defined(BZIP2DEPENDS)
PATCH_DEPENDS+=		bzip2:${PORTSDIR}/archivers/bzip2
.endif
.if ${PATCHFILES:M*.zip}x != x && defined(ZIPDEPENDS)
PATCH_DEPENDS+=		unzip:${PORTSDIR}/archivers/unzip
.endif
.endif

.if defined(USE_BZIP2) && defined(BZIP2DEPENDS)
EXTRACT_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif
.if defined(USE_ZIP) && defined(ZIPDEPENDS)
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif
.if defined(USE_GMAKE)
BUILD_DEPENDS+=		gmake:${PORTSDIR}/devel/gmake
CONFIGURE_ENV+=	MAKE=${GMAKE}
.endif

.if defined(USE_GCC)
.if ${OSVERSION} < 400012
GCCVERSION=		020702
.endif
.if ${OSVERSION} >= 400012 && ${OSVERSION} < 500035
GCCVERSION=		029500
.endif
.if ${OSVERSION} >= 500035 && ${OSVERSION} < 500039
GCCVERSION=		030100
.endif
.if ${OSVERSION} >= 500039 && ${OSVERSION} < 501103
GCCVERSION=		030200
.endif
.if ${OSVERSION} >= 501103
GCCVERSION=		030301
.endif
.if ${OSVERSION} >= 599999
GCCVERSION=		030400
.endif
.endif

.if defined(USE_GCC)
.if ${USE_GCC} == 2.95 && ( ${OSVERSION} < 400012 || ${OSVERSION} > 500034 )
CC=				gcc295
CXX=			g++295
BUILD_DEPENDS+=	gcc295:${PORTSDIR}/lang/gcc295
GCCVERSION=		029500
.endif
.if ${USE_GCC} == 3.1 && ( ${OSVERSION} < 500035 || ${OSVERSION} > 500038 )
CC=				gcc31
CXX=			g++31
F77=			g77-31
BUILD_DEPENDS+=	gcc31:${PORTSDIR}/lang/gcc31
GCCVERSION=		030100
.endif
.if ${USE_GCC} == 3.2 && ${OSVERSION} < 500039
CC=				gcc32
CXX=			g++32
F77=			g77-32
BUILD_DEPENDS+=	gcc32:${PORTSDIR}/lang/gcc32
GCCVERSION=		030200
.endif
.if ${USE_GCC} == 3.3 && ${OSVERSION} < 501103
CC=				gcc33
CXX=			g++33
F77=			g77-33
BUILD_DEPENDS+=	gcc33:${PORTSDIR}/lang/gcc33
GCCVERSION=		030301
.endif
.if ${USE_GCC} == 3.4 # Not yet available in any OSVERSION
CC=				gcc34
CXX=			g++34
F77=			g77-34
BUILD_DEPENDS+=	gcc34:${PORTSDIR}/lang/gcc34
GCCVERSION=		030400
.endif
MAKE_ENV+=	CC="${CC}" CXX="${CXX}"
.endif

.if defined(USE_OPENLDAP_VER)
USE_OPENLDAP?=		yes
WANT_OPENLDAP_VER=	${USE_OPENLDAP_VER}
.endif

.if defined(USE_OPENLDAP)
.if defined(WANT_OPENLDAP_SASL)
_OPENLDAP_FLAVOUR=	-sasl
.else
_OPENLDAP_FLAVOUR=
.endif
.if ${WANT_OPENLDAP_VER} == 22
LIB_DEPENDS+=		ldap-2.2.7:${PORTSDIR}/net/openldap22${_OPENLDAP_FLAVOUR}-client
.elif ${WANT_OPENLDAP_VER} == 21
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap21${_OPENLDAP_FLAVOUR}-client
.else
BROKEN=				"unknown OpenLDAP version: ${WANT_OPENLDAP_VER}"
.endif
.endif

.if defined(USE_GETOPT_LONG)
.if ${OSVERSION} < 500041
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib -lgnugetopt
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.endif
.endif

.if defined(USE_RC_SUBR)
.if ${OSVERSION} < 500037
RUN_DEPENDS+=	${LOCALBASE}/etc/rc.subr:${PORTSDIR}/sysutils/rc_subr
RC_SUBR=	${LOCALBASE}/etc/rc.subr
.else
RC_SUBR=	/etc/rc.subr
.endif
.endif

.if defined(USE_ICONV)
LIB_DEPENDS+=	iconv.3:${PORTSDIR}/converters/libiconv
.endif

.if defined(USE_GETTEXT)
.	if ${USE_GETTEXT:L} == "yes"
LIB_DEPENDS+=	intl:${PORTSDIR}/devel/gettext
.	else
LIB_DEPENDS+=	intl.${USE_GETTEXT}:${PORTSDIR}/devel/gettext
.	endif
.endif

.if defined(USE_LINUX)
RUN_DEPENDS+=	${LINUXBASE}/etc/redhat-release:${PORTSDIR}/emulators/linux_base
.endif

.if defined(USE_MOTIF)
USE_XPM=			yes
.if defined(WANT_LESSTIF)
LIB_DEPENDS+=		Xm:${PORTSDIR}/x11-toolkits/lesstif
NO_OPENMOTIF=		yes
.endif
.if !defined(NO_OPENMOTIF)
LIB_DEPENDS+=		Xm.3:${PORTSDIR}/x11-toolkits/open-motif
.endif
.endif

.if defined(USE_FREETYPE)
LIB_DEPENDS+=			ttf.4:${PORTSDIR}/print/freetype
.endif

.if defined(X_WINDOW_SYSTEM) && ${X_WINDOW_SYSTEM:L} == xorg
X_IMAKE_PORT=		${PORTSDIR}/devel/imake-6
X_LIBRARIES_PORT=	${PORTSDIR}/x11/xorg-libraries
X_CLIENTS_PORT=		${PORTSDIR}/x11/xorg-clients
X_SERVER_PORT=		${PORTSDIR}/x11-servers/xorg-server
X_FONTSERVER_PORT=	${PORTSDIR}/x11-servers/xorg-fontserver
X_PRINTSERVER_PORT=	${PORTSDIR}/x11-servers/xorg-printserver
X_VFBSERVER_PORT=	${PORTSDIR}/x11-servers/xorg-vfbserver
X_NESTSERVER_PORT=	${PORTSDIR}/x11-servers/xorg-nestserver
X_FONTS_ENCODINGS_PORT=	${PORTSDIR}/x11-fonts/xorg-fonts-encodings
X_FONTS_MISC_PORT=	${PORTSDIR}/x11-fonts/xorg-fonts-miscbitmaps
X_FONTS_100DPI_PORT=	${PORTSDIR}/x11-fonts/xorg-fonts-100dpi
X_FONTS_75DPI_PORT=	${PORTSDIR}/x11-fonts/xorg-fonts-75dpi
X_FONTS_CYRILLIC_PORT=	${PORTSDIR}/x11-fonts/xorg-fonts-cyrillic
X_FONTS_TTF_PORT=	${PORTSDIR}/x11-fonts/xorg-fonts-truetype
X_FONTS_TYPE1_PORT=	${PORTSDIR}/x11-fonts/xorg-fonts-type1
X_MANUALS_PORT=		${PORTSDIR}/x11/xorg-manpages
.elif defined(X_WINDOW_SYSTEM) && ${X_WINDOW_SYSTEM:L} == xfree86-4
X_IMAKE_PORT=		${PORTSDIR}/devel/imake-4
X_LIBRARIES_PORT=	${PORTSDIR}/x11/XFree86-4-libraries
X_CLIENTS_PORT=		${PORTSDIR}/x11/XFree86-4-clients
X_SERVER_PORT=		${PORTSDIR}/x11-servers/XFree86-4-Server
X_FONTSERVER_PORT=	${PORTSDIR}/x11-servers/XFree86-4-FontServer
X_PRINTSERVER_PORT=	${PORTSDIR}/x11-servers/XFree86-4-PrintServer
X_VFBSERVER_PORT=	${PORTSDIR}/x11-servers/XFree86-4-VirtualFramebufferServer
X_NESTSERVER_PORT=	${PORTSDIR}/x11-servers/XFree86-4-NestServer
X_FONTS_ENCODINGS_PORT=	${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings
X_FONTS_MISC_PORT=	${PORTSDIR}/x11-fonts/XFree86-4-fontDefaultBitmaps
X_FONTS_100DPI_PORT=	${PORTSDIR}/x11-fonts/XFree86-4-font100dpi
X_FONTS_75DPI_PORT=	${PORTSDIR}/x11-fonts/XFree86-4-font75dpi
X_FONTS_CYRILLIC_PORT=	${PORTSDIR}/x11-fonts/XFree86-4-fontCyrillic
X_FONTS_TTF_PORT=	${PORTSDIR}/x11-fonts/XFree86-4-fontScalable
X_FONTS_TYPE1_PORT=	${PORTSDIR}/x11-fonts/XFree86-4-fontScalable
X_MANUALS_PORT=		${PORTSDIR}/x11/XFree86-4-manuals
.elif defined(X_WINDOW_SYSTEM) && ${X_WINDOW_SYSTEM:L} == xfree86-3
X_IMAKE_PORT=		${PORTSDIR}/x11/XFree86
X_LIBRARIES_PORT=	${PORTSDIR}/x11/XFree86
X_CLIENTS_PORT=		${PORTSDIR}/x11/XFree86
X_SERVER_PORT=		${PORTSDIR}/x11/XFree86
X_FONTSERVER_PORT=	${PORTSDIR}/x11/XFree86
X_PRINTSERVER_PORT=	${PORTSDIR}/x11/XFree86
X_VFBSERVER_PORT=	${PORTSDIR}/x11/XFree86
X_NESTSERVER_PORT=	${PORTSDIR}/x11/XFree86
X_FONTS_ENCODINGS_PORT=	${PORTSDIR}/x11/XFree86
X_FONTS_MISC_PORT=	${PORTSDIR}/x11/XFree86
X_FONTS_100DPI_PORT=	${PORTSDIR}/x11/XFree86
X_FONTS_75DPI_PORT=	${PORTSDIR}/x11/XFree86
X_FONTS_CYRILLIC_PORT=	${PORTSDIR}/x11/XFree86
X_FONTS_TTF_PORT=	${PORTSDIR}/x11/XFree86
X_FONTS_TYPE1_PORT=	${PORTSDIR}/x11/XFree86
X_MANUALS_PORT=		${PORTSDIR}/x11/XFree86
.else
.error Bad X_WINDOW_SYSTEM setting
.endif

.if defined(USE_IMAKE)
BUILD_DEPENDS+=			imake:${X_IMAKE_PORT}
.endif

.if ${X_WINDOW_SYSTEM:L} == xfree86-3

.if defined(USE_XPM)
LIB_DEPENDS+=			Xpm.4:${PORTSDIR}/graphics/xpm
.endif
.if defined(USE_GL)
LIB_DEPENDS+=			GL.14:${PORTSDIR}/graphics/mesagl
.endif

XAWVER=				6
PKG_IGNORE_DEPENDS?=		'^XFree86-3\.'

.else

.if defined(USE_IMAKE)
RUN_DEPENDS+=			mkhtmlindex:${X_IMAKE_PORT}
.endif
.if defined(USE_XPM) || defined(USE_GL)
USE_XLIB=			yes
.endif

XAWVER=				7
PKG_IGNORE_DEPENDS?=		'this_port_does_not_exist'

.endif

PLIST_SUB+=			XAWVER=${XAWVER}

.if defined(USE_MESA)
LIB_DEPENDS+=			glut.3:${PORTSDIR}/graphics/libglut
.endif

.if defined(USE_BISON)
.if ${OSVERSION} >= 400014
BUILD_DEPENDS+=	bison:${PORTSDIR}/devel/bison
.endif
.endif

PLIST_SUB+=		PERL_VERSION=${PERL_VERSION} \
				PERL_VER=${PERL_VER} \
				PERL_ARCH=${PERL_ARCH} \
				SITE_PERL=${SITE_PERL_REL}

.if defined(PERL_MODBUILD)
PERL_CONFIGURE=		yes
CONFIGURE_SCRIPT?=	Build.PL
.if ${PORTNAME} != Module-Build
BUILD_DEPENDS+=		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build
.endif
ALL_TARGET?=
PL_BUILD?=		Build
CONFIGURE_ARGS+= \
	install_path=lib="${PREFIX}/${SITE_PERL_REL}" \
	install_path=arch="${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}" \
	install_path=script="${PREFIX}/bin" \
	install_path=bin="${PREFIX}/bin" \
	install_path=libdoc="${MAN3PREFIX}/man/man3" \
	install_path=bindoc="${MAN1PREFIX}/man/man1"
.endif

.if defined(PERL_CONFIGURE)
USE_PERL5=	yes
USE_REINPLACE=yes
.endif

.if ${PERL_LEVEL} >= 500600
.if defined(USE_PERL5) || defined(USE_PERL5_BUILD)
EXTRACT_DEPENDS+=${PERL5}:${PORTSDIR}/lang/${PERL_PORT}
PATCH_DEPENDS+=	${PERL5}:${PORTSDIR}/lang/${PERL_PORT}
BUILD_DEPENDS+=	${PERL5}:${PORTSDIR}/lang/${PERL_PORT}
.endif
.if defined(USE_PERL5) || defined(USE_PERL5_RUN)
RUN_DEPENDS+=	${PERL5}:${PORTSDIR}/lang/${PERL_PORT}
.endif
.endif

.if defined(USE_MYSQL)
DEFAULT_MYSQL_VER?=	40
# MySQL client version currently supported.
MYSQL323_LIBVER=	10
MYSQL40_LIBVER=		12
MYSQL41_LIBVER=		14
MYSQL50_LIBVER=		14

# Setting/finding MySQL version we want.
.if defined(WANT_MYSQL_VER)
MYSQL_VER=	${WANT_MYSQL_VER}
.elif defined(WITH_MYSQL_VER)
MYSQL_VER=	${WITH_MYSQL_VER}
.elif exists(${LOCALBASE}/bin/mysql)
MYSQL_VER!=	${LOCALBASE}/bin/mysql --version | ${SED} -e 's/.*Distrib \([0-9]\)\.\([0-9]*\).*/\1\2/'
.else
MYSQL_VER=	${DEFAULT_MYSQL_VER}
.endif # WANT_MYSQL_VER

# And now we are checking if we can use it
.if exists(${PORTSDIR}/databases/mysql${MYSQL_VER}-client)
.if defined(BROKEN_WITH_MYSQL)
.	for VER in ${BROKEN_WITH_MYSQL}
.		if (${MYSQL_VER} == "${VER}")
IGNORE=		Doesn't work with MySQL version : ${MYSQL_VER} (Doesn't support MySQL ${BROKEN_WITH_MYSQL})
.		endif
.	endfor
.endif # BROKEN_WITH_MYSQL
LIB_DEPENDS+=	mysqlclient.${MYSQL${MYSQL_VER}_LIBVER}:${PORTSDIR}/databases/mysql${MYSQL_VER}-client
.else
BROKEN=		"unknown MySQL version: ${MYSQL_VER}"
.endif # Check for correct libs
.endif # USE_MYSQL

.if defined(USE_XLIB)
LIB_DEPENDS+=	X11.6:${X_LIBRARIES_PORT}
# Add explicit X options to avoid problems with false positives in configure
.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include
.endif
.endif

# XXX: (not yet): .if defined(USE_AUTOTOOLS)
.include "${PORTSDIR}/Mk/bsd.autotools.mk"
# XXX: (not yet): .endif

.if defined(WANT_GNOME) || defined(USE_GNOME) || defined(USE_GTK)
.include "${PORTSDIR}/Mk/bsd.gnome.mk"
.endif

.if defined(USE_SDL) || defined(WANT_SDL)
.include "${PORTSDIR}/Mk/bsd.sdl.mk"
.endif

.if defined(USE_PYTHON)
.include "${PORTSDIR}/Mk/bsd.python.mk"
.endif

.if exists(${PORTSDIR}/../Makefile.inc)
.include "${PORTSDIR}/../Makefile.inc"
USE_SUBMAKE=	yes
.endif

# Set the default for the installation of Postscript(TM)-
# compatible functionality.
.if !defined(WITHOUT_X11)
.if defined(WITH_GHOSTSCRIPT_AFPL)
.if ${WITH_GHOSTSCRIPT_AFPL} == yes
GHOSTSCRIPT_PORT?=	print/ghostscript-afpl
.else
GHOSTSCRIPT_PORT?=	print/ghostscript-gnu
.endif
.else
GHOSTSCRIPT_PORT?=	print/ghostscript-gnu
.endif
.else
.if defined(WITH_GHOSTSCRIPT_AFPL)
.if ${WITH_GHOSTSCRIPT_AFPL} == yes
GHOSTSCRIPT_PORT?=	print/ghostscript-afpl-nox11
.else
GHOSTSCRIPT_PORT?=	print/ghostscript-gnu-nox11
.endif
.else
GHOSTSCRIPT_PORT?=	print/ghostscript-gnu-nox11
.endif
.endif

# Set up the ghostscript dependencies.
.if defined(USE_GHOSTSCRIPT) || defined(USE_GHOSTSCRIPT_BUILD)
BUILD_DEPENDS+=	gs:${PORTSDIR}/${GHOSTSCRIPT_PORT}
.endif
.if defined(USE_GHOSTSCRIPT) || defined(USE_GHOSTSCRIPT_RUN)
RUN_DEPENDS+=	gs:${PORTSDIR}/${GHOSTSCRIPT_PORT}
.endif

# Special macro for doing in-place file editing using regexps
.if defined(USE_REINPLACE)
REINPLACE_ARGS?=	-i.bak
.if ${OSVERSION} < 460101 || ( ${OSVERSION} >= 500000 && ${OSVERSION} < 500036 )
PATCH_DEPENDS+=	${LOCALBASE}/bin/sed_inplace:${PORTSDIR}/textproc/sed_inplace
REINPLACE_CMD?=	${LOCALBASE}/bin/sed_inplace ${REINPLACE_ARGS}
.else
REINPLACE_CMD?=	${SED} ${REINPLACE_ARGS}
.endif
.endif

# Names of cookies used to skip already completed stages
.for target in extract patch configure build install package
${target:U}_COOKIE?=${WRKDIR}/.${target}_done.${PKGNAME}.${PREFIX:S/\//_/g}
.endfor

# How to do nothing.  Override if you, for some strange reason, would rather
# do something.
DO_NADA?=		${TRUE}

# Use this as the first operand to always build dependency.
NONEXISTENT?=	/nonexistent

# Miscellaneous overridable commands:
GMAKE?=			gmake
XMKMF?=			xmkmf -a
MKHTMLINDEX?=		${X11BASE}/bin/mkhtmlindex
.if exists(/sbin/md5)
MD5?=			/sbin/md5
.elif exists(/bin/md5)
MD5?=			/bin/md5
.elif exists(/usr/bin/md5)
MD5?=			/usr/bin/md5
.else
MD5?=			md5
.endif
MD5_FILE?=		${MASTERDIR}/distinfo

MAKE_FLAGS?=	-f
MAKEFILE?=		Makefile
MAKE_ENV+=		PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} DESTDIR=${DESTDIR} MOTIFLIB="${MOTIFLIB}" LIBDIR="${LIBDIR}" CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" MANPREFIX="${MANPREFIX}"

.if ${OSVERSION} < 500016
PTHREAD_CFLAGS?=	-D_THREAD_SAFE
PTHREAD_LIBS?=		-pthread
.elif ${OSVERSION} < 502102
PTHREAD_CFLAGS?=	-D_THREAD_SAFE
PTHREAD_LIBS?=		-lc_r
.else
PTHREAD_CFLAGS?=
PTHREAD_LIBS?=		-lpthread
.endif

.if defined(FETCH_USE_CURL) && exists(${LOCALBASE}/bin/curl)
FETCH_CMD?=		${LOCALBASE}/bin/curl --create-dirs -L --max-redirs 1 -C -
.elif defined(FETCH_USE_WGET) && exists(${LOCALBASE}/bin/wget)
FETCH_CMD?=		${LOCALBASE}/bin/wget -c -t 1
.else
FETCH_CMD?=		/usr/bin/fetch -ARr
.endif

TOUCH?=			/usr/bin/touch
TOUCH_FLAGS?=	-f

DISTORIG?=	.bak.orig
PATCH?=			/usr/bin/patch
PATCH_STRIP?=	-p0
PATCH_DIST_STRIP?=	-p0
.if defined(PATCH_DEBUG)
PATCH_DEBUG_TMP=	yes
PATCH_ARGS?=	-d ${PATCH_WRKSRC} -E ${PATCH_STRIP}
PATCH_DIST_ARGS?=	-b ${DISTORIG} -d ${PATCH_WRKSRC} -E ${PATCH_DIST_STRIP}
.else
PATCH_DEBUG_TMP=	no
PATCH_ARGS?=	-d ${PATCH_WRKSRC} --forward --quiet -E ${PATCH_STRIP}
PATCH_DIST_ARGS?=	-b ${DISTORIG} -d ${PATCH_WRKSRC} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
.if defined(BATCH)
PATCH_ARGS+=		--batch
PATCH_DIST_ARGS+=	--batch
.endif

# Prevent breakage with VERSION_CONTROL=numbered
PATCH_ARGS+=	-V simple

.if defined(PATCH_CHECK_ONLY)
PATCH_ARGS+=	-C
PATCH_DIST_ARGS+=	-C
.endif

.if ${PATCH} == "/usr/bin/patch"
PATCH_ARGS+=	-b .orig
PATCH_DIST_ARGS+=	-b .orig
.endif

.if exists(/bin/tar)
TAR?=	/bin/tar
.else
TAR?=	/usr/bin/tar
.endif

# EXTRACT_SUFX is defined in .pre.mk section
.if defined(USE_ZIP)
EXTRACT_CMD?=		${UNZIP_CMD}
EXTRACT_BEFORE_ARGS?=	-qo
EXTRACT_AFTER_ARGS?=	-d ${WRKDIR}
.else
EXTRACT_BEFORE_ARGS?=	-dc
EXTRACT_AFTER_ARGS?=	| ${TAR} -xf -
.if defined(USE_BZIP2)
EXTRACT_CMD?=			${BZIP2_CMD}
.else
EXTRACT_CMD?=			${GZIP_CMD}
.endif
.endif

# Figure out where the local mtree file is
.if !defined(MTREE_FILE) && !defined(NO_MTREE)
.if defined(USE_X_PREFIX)
.if ${X_WINDOW_SYSTEM:L} == xfree86-3
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.else
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
.endif
.else
.if ${PREFIX} == /usr
MTREE_FILE=	/etc/mtree/BSD.usr.dist
.else
MTREE_FILE=	/etc/mtree/BSD.local.dist
.endif
.endif
.endif
MTREE_CMD?=	/usr/sbin/mtree
MTREE_ARGS?=	-U ${MTREE_FOLLOWS_SYMLINKS} -f ${MTREE_FILE} -d -e -p

# Determine whether or not we can use rootly owner/group functions.
.if ${UID} == 0
_BINOWNGRP=	-o ${BINOWN} -g ${BINGRP}
_SHROWNGRP=	-o ${SHAREOWN} -g ${SHAREGRP}
_MANOWNGRP=	-o ${MANOWN} -g ${MANGRP}
.else
_BINOWNGRP=
_SHROWNGRP=
_MANOWNGRP=
.endif

# A few aliases for *-install targets
INSTALL_PROGRAM= \
	${INSTALL} ${COPY} ${STRIP} ${_BINOWNGRP} -m ${BINMODE}
INSTALL_SCRIPT= \
	${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE}
INSTALL_DATA= \
	${INSTALL} ${COPY} ${_SHROWNGRP} -m ${SHAREMODE}
INSTALL_MAN= \
	${INSTALL} ${COPY} ${_MANOWNGRP} -m ${MANMODE}

INSTALL_MACROS=	BSD_INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			BSD_INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
			BSD_INSTALL_DATA="${INSTALL_DATA}" \
			BSD_INSTALL_MAN="${INSTALL_MAN}"
MAKE_ENV+=	${INSTALL_MACROS}
SCRIPTS_ENV+=	${INSTALL_MACROS}

# The user can override the NO_PACKAGE by specifying this from
# the make command line
.if defined(FORCE_PACKAGE)
.undef NO_PACKAGE
.endif

COMMENTFILE?=		${PKGDIR}/pkg-comment
DESCR?=			${PKGDIR}/pkg-descr
PLIST?=			${PKGDIR}/pkg-plist
PKGINSTALL?=	${PKGDIR}/pkg-install
PKGDEINSTALL?=	${PKGDIR}/pkg-deinstall
PKGREQ?=		${PKGDIR}/pkg-req
PKGMESSAGE?=	${PKGDIR}/pkg-message

TMPPLIST?=	${WRKDIR}/.PLIST.mktmp

.if ${OSVERSION} >= 400000
.for _CATEGORY in ${CATEGORIES}
PKGCATEGORY?=	${_CATEGORY}
.endfor
_PORTDIRNAME=	${.CURDIR:T}
PORTDIRNAME?=	${_PORTDIRNAME}
PKGORIGIN?=		${PKGCATEGORY}/${PORTDIRNAME}
.endif

.if exists(${LOCALBASE}/sbin/pkg_info)
PKG_CMD?=		${LOCALBASE}/sbin/pkg_create
PKG_ADD?=		${LOCALBASE}/sbin/pkg_add
PKG_DELETE?=	${LOCALBASE}/sbin/pkg_delete
PKG_INFO?=		${LOCALBASE}/sbin/pkg_info
PKG_VERSION?=		${LOCALBASE}/sbin/pkg_version
.elif ${OSVERSION} < 460102 && ${PKGORIGIN} != "sysutils/pkg_install"
BUILD_DEPENDS+=		${LOCALBASE}/sbin/pkg_info:${PORTSDIR}/sysutils/pkg_install
PKG_CMD?=		${LOCALBASE}/sbin/pkg_create
PKG_ADD?=		${LOCALBASE}/sbin/pkg_add
PKG_DELETE?=		${LOCALBASE}/sbin/pkg_delete
PKG_INFO?=		${LOCALBASE}/sbin/pkg_info
PKG_VERSION?=		${LOCALBASE}/sbin/pkg_version
.else
PKG_CMD?=		/usr/sbin/pkg_create
PKG_ADD?=		/usr/sbin/pkg_add
PKG_DELETE?=	/usr/sbin/pkg_delete
PKG_INFO?=		/usr/sbin/pkg_info
PKG_VERSION?=		/usr/sbin/pkg_version
.endif

# Does the pkg_create tool support conflict checking?
# XXX Slow?
.if !defined(PKGINSTALLVER)
PKGINSTALLVER!= ${PKG_INFO} -P 2>/dev/null | ${SED} -e 's/.*: //'
.endif
.if ${PKGINSTALLVER} < 20030417
DISABLE_CONFLICTS=	YES
.endif
.if !defined(PKG_ARGS)
PKG_ARGS=		-v -c -${COMMENT:Q} -d ${DESCR} -f ${TMPPLIST} -p ${PREFIX} -P "`cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} package-depends | ${GREP} -v -E ${PKG_IGNORE_DEPENDS} | ${SORT} -u`" ${EXTRA_PKG_ARGS} $${_LATE_PKG_ARGS}
.if !defined(NO_MTREE)
PKG_ARGS+=		-m ${MTREE_FILE}
.endif
.if defined(PKGORIGIN)
PKG_ARGS+=		-o ${PKGORIGIN}
.endif
.if defined(CONFLICTS) && !defined(DISABLE_CONFLICTS)
PKG_ARGS+=		-C "${CONFLICTS}"
.endif
.if defined(DESTDIR)
PKG_ARGS+=		-S "${DESTDIR}"
.endif
.endif
.if defined(PKG_NOCOMPRESS)
PKG_SUFX?=		.tar
.else
.if ${OSVERSION} >= 500039
PKG_SUFX?=		.tbz
.else
PKG_SUFX?=		.tgz
.endif
.endif
# where pkg_add records its dirty deeds.
PKG_DBDIR?=		/var/db/pkg
_PKG_DBDIR?=	${DESTDIR}${PKG_DBDIR}

MOTIFLIB?=	-L${X11BASE}/lib -lXm -lXp

ALL_TARGET?=		all
INSTALL_TARGET?=	install

# This is a mid-term solution patch while pkg-comment files are
# phased out.
# The final simpler patch will come afterwards
.if !defined(COMMENT)
check-makevars::
		@${ECHO_CMD} 'Makefile error: there is no COMMENT variable defined'
		@${ECHO_CMD} 'for this port. Please, rectify this.'
		@${FALSE}
.else
.if exists(${COMMENTFILE})
check-makevars::
		@${ECHO_CMD} 'Makefile error: There is a COMMENTFILE in this port.'
		@${ECHO_CMD} 'COMMENTFILEs have been deprecated in'
		@${ECHO_CMD} 'favor of COMMENT variables.'
		@${ECHO_CMD} 'Please, rectify this.'
		@${FALSE}
.endif
.endif

# Popular master sites
.include "${PORTSDIR}/Mk/bsd.sites.mk"

# The primary backup site.
MASTER_SITE_BACKUP?=	\
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
MASTER_SITE_BACKUP:=	${MASTER_SITE_BACKUP:S^\${DIST_SUBDIR}/^^}

# If the user has MASTER_SITE_FREEBSD set, go to the FreeBSD repository
# for everything, but don't search it twice by appending it to the end.
.if defined(MASTER_SITE_FREEBSD)
_MASTER_SITE_OVERRIDE:=	${MASTER_SITE_BACKUP}
_MASTER_SITE_BACKUP:=	# empty
.else
_MASTER_SITE_OVERRIDE=	${MASTER_SITE_OVERRIDE}
_MASTER_SITE_BACKUP=	${MASTER_SITE_BACKUP}
.endif

# Search CDROM first if mounted
.for MOUNTPT in ${CD_MOUNTPTS}
.if exists(${MOUNTPT}/ports/distfiles)
_MASTER_SITE_OVERRIDE:=	file:${MOUNTPT}/ports/distfiles/${DIST_SUBDIR}/ ${_MASTER_SITE_OVERRIDE}
.endif
.endfor

DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}

.if !defined(DISTFILES_KEEP_QUOTING)
_DISTFILES=		${DISTFILES:C/:[^:]+$//:C/\\\\(.)/\1/g}
_PATCHFILES=	${PATCHFILES:C/:[^:]+$//:C/\\\\(.)/\1/g}
.else
_DISTFILES=		${DISTFILES:C/:[^:]+$//}
_PATCHFILES=	${PATCHFILES:C/:[^:]+$//}
.endif

#
# Sort the master site list according to the patterns in MASTER_SORT
#
MASTER_SORT?=
MASTER_SORT_REGEX?=
MASTER_SORT_REGEX+=	${MASTER_SORT:S|.|\\.|g:S|^|://[^/]*|:S|$|/|}

MASTER_SORT_AWK=	BEGIN { RS = " "; ORS = " "; IGNORECASE = 1 ; gl = "${MASTER_SORT_REGEX:S|\\|\\\\|g}"; }
.for srt in ${MASTER_SORT_REGEX}
MASTER_SORT_AWK+=	/${srt:S|/|\\/|g}/ { good["${srt:S|\\|\\\\|g}"] = good["${srt:S|\\|\\\\|g}"] " " $$0 ; next; }
.endfor
MASTER_SORT_AWK+=	{ rest = rest " " $$0; } END { n=split(gl, gla); for(i=1;i<=n;i++) { print good[gla[i]]; } print rest; }

.if defined(MASTER_SORT_FPING) && exists(${PERL5}) && exists(${LOCALBASE}/sbin/fping)
MASTER_SORT_CMD?=	${PERL5} -w ${PORTSDIR}/devel/portmk/scripts/ranksites-fping.pl
.elif defined(MASTER_SORT_GEOIP) && defined(CC_HOME) && exists(${PERL5}) && exists(${SITE_PERL}/${PERL_ARCH}/Geo/IP.pm)
MASTER_SORT_CMD?=	${PERL5} -w ${PORTSDIR}/devel/portmk/scripts/ranksites-geoip.pl
MASTER_SORT_ENV+=	CC_HOME=${CC_HOME}
.endif

# This is what is actually going to be extracted, and is overridable
#  by user.
EXTRACT_ONLY?=	${_DISTFILES}

# Documentation
MAINTAINER?=	ports@FreeBSD.org

.PHONY: maintainer
.if !target(maintainer)
maintainer:
	@${ECHO_CMD} "${MAINTAINER}"
.endif

.PHONY: check-makefile
.if !target(check-makefile)
check-makefile::
	@${DO_NADA}
.endif

.PHONY: check-categories
.if !defined(CATEGORIES)
check-categories:
	@${ECHO_CMD} "${PKGNAME}: Makefile error: CATEGORIES is mandatory."
	@${FALSE}
.else

VALID_CATEGORIES+= accessibility afterstep arabic archivers astro audio \
	benchmarks biology cad chinese comms converters databases \
	deskutils devel dns editors elisp emulators finance french ftp \
	games german gnome graphics haskell hebrew hungarian \
	ipv6 irc japanese java kde korean lang linux lisp \
	mail math mbone misc multimedia net net-mgmt news \
	offix palm parallel pear perl5 picobsd plan9 polish portuguese print \
	python ruby russian \
	scheme science security shells sysutils \
	tcl76 tcl80 tcl81 tcl82 tcl83 tcl84 textproc \
	tk42 tk80 tk82 tk83 tk84 tkstep80 \
	ukrainian vietnamese windowmaker www \
	x11 x11-clocks x11-fm x11-fonts x11-servers x11-themes x11-toolkits \
	x11-wm xfce zope

check-categories:
.for cat in ${CATEGORIES}
	@if ${ECHO_CMD} ${VALID_CATEGORIES} | ${GREP} -wq ${cat}; then \
		${TRUE}; \
	else \
		${ECHO_CMD} "${PKGNAME}: Makefile error: category ${cat} not in list of valid categories."; \
		${FALSE}; \
	fi
.endfor
.endif

.PHONY: check-makevars
.if !target(check-makevars)
check-makevars::
	@${DO_NADA}
.endif

.PHONY: check-depends
.if !target(check-depends)
check-depends:
	@${DO_NADA}
.endif

PKGREPOSITORYSUBDIR?=	All
PKGREPOSITORY?=		${PACKAGES}/${PKGREPOSITORYSUBDIR}
.if exists(${PACKAGES})
PKGFILE?=		${PKGREPOSITORY}/${PKGNAME}${PKG_SUFX}
.else
PKGFILE?=		${.CURDIR}/${PKGNAME}${PKG_SUFX}
.endif

# The "latest version" link -- ${PKGNAME} minus everthing after the last '-'
PKGLATESTREPOSITORY?=	${PACKAGES}/Latest
PKGBASE?=			${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
LATEST_LINK?=		${PKGBASE}
PKGLATESTFILE=		${PKGLATESTREPOSITORY}/${LATEST_LINK}${PKG_SUFX}

.if defined(PERL_CONFIGURE)
CONFIGURE_ARGS+=	CC="${CC}" CCFLAGS="${CFLAGS}" PREFIX="${PREFIX}" \
			INSTALLPRIVLIB="${PREFIX}/lib" INSTALLARCHLIB="${PREFIX}/lib"
CONFIGURE_SCRIPT?=	Makefile.PL
MAN3PREFIX?=		${PREFIX}/lib/perl5/${PERL_VERSION}
.undef HAS_CONFIGURE
.endif

CONFIGURE_SCRIPT?=	configure
CONFIGURE_TARGET?=	${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_LOG?=		config.log

# A default message to print if do-configure fails.
CONFIGURE_FAIL_MESSAGE?=	"Please report the problem to ${MAINTAINER} [maintainer] and attach the \"${CONFIGURE_WRKSRC}/${CONFIGURE_LOG}\" including the output of the failure of your make command. Also, it might be a good idea to provide an overview of all packages installed on your system (e.g. an \`ls ${PKG_DBDIR}\`)."

.if defined(GNU_CONFIGURE)
# Maximum command line length
.if !defined(CONFIGURE_MAX_CMD_LEN)
.if exists(/sbin/sysctl)
CONFIGURE_MAX_CMD_LEN!=	/sbin/sysctl -n kern.argmax
.else
CONFIGURE_MAX_CMD_LEN!=	/usr/sbin/sysctl -n kern.argmax
.endif
.endif
CONFIGURE_ARGS+=	--prefix=${PREFIX} ${CONFIGURE_TARGET}
CONFIGURE_ENV+=		lt_cv_sys_max_cmd_len=${CONFIGURE_MAX_CMD_LEN}
HAS_CONFIGURE=		yes
.endif

# Passed to most of script invocations
SCRIPTS_ENV+=	CURDIR=${MASTERDIR} DISTDIR=${DISTDIR} \
		  WRKDIR=${WRKDIR} WRKSRC=${WRKSRC} PATCHDIR=${PATCHDIR} \
		  SCRIPTDIR=${SCRIPTDIR} FILESDIR=${FILESDIR} \
		  PORTSDIR=${PORTSDIR} DEPENDS="${DEPENDS}" \
		  PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} \
		  DESTDIR=${DESTDIR}

.if defined(BATCH)
SCRIPTS_ENV+=	BATCH=yes
.endif

.if ${PREFIX} == /usr
MANPREFIX?=	/usr/share
.else
MANPREFIX?=	${PREFIX}
.endif

.for sect in 1 2 3 4 5 6 7 8 9
MAN${sect}PREFIX?=	${MANPREFIX}
.endfor
MANLPREFIX?=	${MANPREFIX}
MANNPREFIX?=	${MANPREFIX}

MANLANG?=	""	# english only by default

.if !defined(NOMANCOMPRESS)
MANEXT=	.gz
.endif

.if (defined(MLINKS) || defined(_MLINKS_PREPEND)) && !defined(_MLINKS)
__pmlinks!=	${ECHO_CMD} '${MLINKS:S/	/ /}' | ${AWK} \
 '{ if (NF % 2 != 0) { print "broken"; exit; } \
	for (i=1; i<=NF; i++) { \
		if ($$i ~ /^-$$/ && i != 1 && i % 2 != 0) \
			{ $$i = $$(i-2); printf " " $$i " "; } \
		else if ($$i ~ /^[^ ]+\.[1-9ln][^. ]*$$/ || $$i ~ /^\//) \
			printf " " $$i " "; \
		else \
			{ print "broken"; exit; } \
	} \
  }' | ${SED} -e 's \([^/ ][^ ]*\.\(.\)[^. ]*\) $${MAN\2PREFIX}/$$$$$$$${__lang}/man\2/\1${MANEXT}g' -e 's/ //g' -e 's/MANlPREFIX/MANLPREFIX/g' -e 's/MANnPREFIX/MANNPREFIX/g'
.if ${__pmlinks:Mbroken} == "broken"
check-makevars::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: unable to parse MLINKS."
	@${FALSE}
.endif
_MLINKS=	${_MLINKS_PREPEND}
# XXX 20040119 This next line should read:
# .for lang in ${MANLANG:S%^%man/%:S%^man/""$%man%}
# but there is currently a bug in make(1) that prevents the double-quote
# substitution from working correctly.  Once that problem is addressed,
# and has had a enough time to mature, this hack should be removed.
.for lang in ${MANLANG:S%^%man/%:S%^man/""$%man%:S%^man/"$%man%}
.for ___pmlinks in ${__pmlinks}
.for __lang in ${lang}
_MLINKS+=	${___pmlinks:S// /g}
.endfor
.endfor
.endfor
.endif
_COUNT=0
.for ___tpmlinks in ${_MLINKS}
.if ${_COUNT} == "1"
_TMLINKS+=	${___tpmlinks}
_COUNT=0
.else
_COUNT=1
.endif
.endfor

# XXX 20040119 This next line should read:
# .for manlang in ${MANLANG:S%^%man/%:S%^man/""$%man%}
# but there is currently a bug in make(1) that prevents the double-quote
# substitution from working correctly.  Once that problem is addressed,
# and has had a enough time to mature, this hack should be removed.
.for manlang in ${MANLANG:S%^%man/%:S%^man/""$%man%:S%^man/"$%man%}

.for sect in 1 2 3 4 5 6 7 8 9 L N
.if defined(MAN${sect})
_MANPAGES+=	${MAN${sect}:S%^%${MAN${sect}PREFIX}/${manlang}/man${sect:L}/%}
.endif
.endfor

.endfor

.if !defined(_TMLINKS)
_TMLINKS=
.endif

.if defined(_MANPAGES)

.if defined(NOMANCOMPRESS)
__MANPAGES:=	${_MANPAGES:S%^${PREFIX}/%%}
.else
__MANPAGES:=	${_MANPAGES:S%^${PREFIX}/%%:S%$%.gz%}
.endif

.if ${MANCOMPRESSED} == "yes"
_MANPAGES:=	${_MANPAGES:S%$%.gz%}
.endif

.endif

.if ${PREFIX} == /usr
INFO_PATH?=	share/info
.else
INFO_PATH?=	info
.endif

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
XFREE86_HTML_MAN=	no
.else
.if defined(USE_IMAKE)
XFREE86_HTML_MAN?=	yes
.else
XFREE86_HTML_MAN?=	no
.endif
.endif

DOCSDIR?=	${PREFIX}/share/doc/${PORTNAME}
EXAMPLESDIR?=	${PREFIX}/share/examples/${PORTNAME}
DATADIR?=	${PREFIX}/share/${PORTNAME}

PLIST_SUB+=	DOCSDIR="${DOCSDIR:S,^${PREFIX}/,,}" \
		EXAMPLESDIR="${EXAMPLESDIR:S,^${PREFIX}/,,}" \
		DATADIR="${DATADIR:S,^${PREFIX}/,,}"

# Put this as far down as possible so it will catch all PLIST_SUB definitions.

.if defined(INSTALLS_SHLIB)
LDCONFIG_DIRS?=	%%PREFIX%%/lib
LDCONFIG_PLIST!=	${ECHO_CMD} ${LDCONFIG_DIRS} | ${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}
LDCONFIG_RUNLIST!=	${ECHO_CMD} ${LDCONFIG_PLIST} | ${SED} -e "s!%D!${PREFIX}!g"
.endif

.MAIN: all

################################################################
# Many ways to disable a port.
#
# If we're in BATCH mode and the port is interactive, or we're
# in interactive mode and the port is non-interactive, skip all
# the important targets.  The reason we have two modes is that
# one might want to leave a build in BATCH mode running
# overnight, then come back in the morning and do _only_ the
# interactive ones that required your intervention.
#
# Ignore ports that can't be resold if building for a CDROM.
#
# Don't build a port if it's restricted and we don't want to get
# into that.
#
# Don't build a port on an ELF machine if it's broken for ELF.
#
# Don't build a port if it's broken, unless we're running a parallel
# build (in case it's fixed).
#
# Don't build a port if it's forbidden for whatever reason.
#
# Don't build a port if the system is too old.
################################################################

.if ${OSVERSION} < 420000
# You need an upgrade kit or make world newer than this
IGNORE=	": Your system is too old to use this bsd.port.mk.  You need a fresh make world or an upgrade kit.  Please go to http://www.FreeBSD.org/ports/ or a mirror site and follow the instructions"
.endif

.if defined(ONLY_FOR_ARCHS)
.for __ARCH in ${ONLY_FOR_ARCHS}
.if ${MACHINE_ARCH:M${__ARCH}} != ""
__ARCH_OK?=     1
.endif
.endfor
.else
__ARCH_OK?=     1
.endif

.if defined(NOT_FOR_ARCHS)
.for __NARCH in ${NOT_FOR_ARCHS}
.if ${MACHINE_ARCH:M${__NARCH}} != ""
.undef __ARCH_OK
.endif
.endfor
.endif

.if !defined(__ARCH_OK)
.if defined(ONLY_FOR_ARCHS)
IGNORE=		"is only for ${ONLY_FOR_ARCHS},"
.else # defined(NOT_FOR_ARCHS)
IGNORE=		"does not run on ${NOT_FOR_ARCHS},"
.endif
IGNORE+=	"and you are running ${ARCH}"
.endif

.if !defined(NO_IGNORE)
.if (defined(IS_INTERACTIVE) && defined(BATCH))
IGNORE=	"is an interactive port"
.elif (!defined(IS_INTERACTIVE) && defined(INTERACTIVE))
IGNORE=	"is not an interactive port"
.elif (defined(NO_CDROM) && defined(FOR_CDROM))
IGNORE=	"may not be placed on a CDROM: ${NO_CDROM}"
.elif (defined(RESTRICTED) && defined(NO_RESTRICTED))
IGNORE=	"is restricted: ${RESTRICTED}"
.elif defined(BROKEN)
.if !defined(TRYBROKEN)
IGNORE=	"is marked as broken: ${BROKEN}"
.endif
.elif defined(FORBIDDEN)
IGNORE=	"is forbidden: ${FORBIDDEN}"
.endif

.if (defined(MANUAL_PACKAGE_BUILD) && defined(PACKAGE_BUILDING) && !defined(PARALLEL_PACKAGE_BUILD))
IGNORE=	"has to be built manually: ${MANUAL_PACKAGE_BUILD}"
clean:
	@${IGNORECMD}
.endif

.if defined(IGNORE)
.if defined(IGNORE_SILENT)
IGNORECMD=	${DO_NADA}
.else
IGNORECMD=	${ECHO_MSG} "===>  ${PKGNAME} ${IGNORE}."
.endif

.for target in check-sanity fetch checksum extract patch configure all build install reinstall package
${target}:
	@${IGNORECMD}
.if defined(INSTALLS_DEPENDS)
	@${FALSE}
.endif
.endfor

.endif

.endif

.if defined(IGNORE) || defined(NO_PACKAGE)
ignorelist: package-name
.else
ignorelist:
	@${DO_NADA}
.endif

################################################################
# Clean directories for ftp or CDROM.
################################################################

.if defined(RESTRICTED)
clean-restricted:	delete-distfiles delete-package
clean-restricted-list: delete-distfiles-list delete-package-list
RESTRICTED_FILES?=	${_DISTFILES} ${_PATCHFILES}
.else
clean-restricted:
clean-restricted-list:
.endif

.if defined(NO_CDROM)
clean-for-cdrom:	delete-distfiles delete-package
clean-for-cdrom-list:	delete-distfiles-list delete-package-list
RESTRICTED_FILES?=	${_DISTFILES} ${_PATCHFILES}
.else
clean-for-cdrom:
clean-for-cdrom-list:
.endif

.if defined(ALL_HOOK)
all:
	@cd ${.CURDIR} && ${SETENV} CURDIR=${.CURDIR} DISTNAME=${DISTNAME} \
	  DISTDIR=${DISTDIR} WRKDIR=${WRKDIR} WRKSRC=${WRKSRC} \
	  PATCHDIR=${PATCHDIR} SCRIPTDIR=${SCRIPTDIR} \
	  FILESDIR=${FILESDIR} PORTSDIR=${PORTSDIR} PREFIX=${PREFIX} \
	  DESTDIR=${DESTDIR} \
	  DEPENDS="${DEPENDS}" BUILD_DEPENDS="${BUILD_DEPENDS}" \
	  RUN_DEPENDS="${RUN_DEPENDS}" X11BASE=${X11BASE} \
	  CONFLICTS="${CONFLICTS}" \
	${ALL_HOOK}
.endif

.if !target(all)
all: build
.endif

.if !defined(DEPENDS_TARGET)
.if make(reinstall)
DEPENDS_TARGET=	reinstall
.else
DEPENDS_TARGET=	install
.endif
.if defined(DEPENDS_CLEAN)
DEPENDS_TARGET+=	clean
DEPENDS_ARGS+=	NOCLEANDEPENDS=yes
.endif
.else
DEPENDS_ARGS+=	FORCE_PKG_REGISTER=yes
.endif
.if defined(DEPENDS)
# pretty much guarantees overwrite of existing installation
.MAKEFLAGS:	FORCE_PKG_REGISTER=yes
.endif

################################################################
#
# Do preliminary work to detect if we need to run the config
# target or not.
#
################################################################
.if (defined(_OPTIONSNG_READ) || !defined(OPTIONS) || defined(CONFIG_DONE) || \
	defined(PACKAGE_BUILDING) || defined(BATCH) || \
	exists(${_OPTIONSFILE}) || exists(${_OPTIONSFILE}.local))
_OPTIONS_OK=yes
.endif

################################################################
# The following are used to create easy dummy targets for
# disabling some bit of default target behavior you don't want.
# They still check to see if the target exists, and if so don't
# do anything, since you might want to set this globally for a
# group of ports in a Makefile.inc, but still be able to
# override from an individual Makefile.
################################################################

# Disable checksum
.if defined(NO_CHECKSUM) && !target(checksum) && defined(_OPTIONS_OK)
checksum: fetch
	@${DO_NADA}
.endif

# Disable build
.if defined(NO_BUILD) && !target(build) && defined(_OPTIONS_OK)
build: configure
	@${TOUCH} ${TOUCH_FLAGS} ${BUILD_COOKIE}
.endif

# Disable install
.if defined(NO_INSTALL) && !target(install) && defined(_OPTIONS_OK)
install: build
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}
.endif

# Disable package
.if defined(NO_PACKAGE) && !target(package) && defined(_OPTIONS_OK)
package:
.if defined(IGNORE_SILENT)
	@${DO_NADA}
.else
	@${ECHO_MSG} "===>  ${PKGNAME} may not be packaged: ${NO_PACKAGE}."
.endif
.endif

# Disable describe
.if defined(NO_DESCRIBE) && !target(describe)
describe:
	@${DO_NADA}
.endif

################################################################
# More standard targets start here.
#
# These are the body of the build/install framework.  If you are
# not happy with the default actions, and you can't solve it by
# adding pre-* or post-* targets/scripts, override these.
################################################################

# Pre-everything

# XXX MCL suggests deprecating this in favor of something
# less likely to be abused by overloading
pre-everything::
	@${DO_NADA}

buildanyway-message:
.if defined(TRYBROKEN)
	@${ECHO_MSG} "Trying build of ${PKGNAME} even though it is marked BROKEN."
.else
	@${DO_NADA}
.endif

options-message:
.if defined(GNOME_OPTION_MSG) && (!defined(PACKAGE_BUILDING) || !defined(BATCH))
	@for m in ${GNOME_OPTION_MSG}; do \
		${ECHO_MSG} $$m; \
	done
.else
	@${DO_NADA}
.endif
.if defined(_OPTIONSNG_READ)
.if ${_OPTIONSNG_READ} == "default"
	@${ECHO_MSG} "===>  Building with default configuration, \`make config' to customize."
.else
	@${ECHO_MSG} "===>  Building with saved configuration for ${_OPTIONSNG_READ}, \`make config' to change."
.endif
.elif defined(_OPTIONS_READ)
	@${ECHO_MSG} "===>  Found saved configuration for ${_OPTIONS_READ}"
.if ${OPTIONSFILE} != ${_OPTIONSFILE}
	@${ECHO_MSG} "===>  *** CAUTION *** Using wrong configuration file ${_OPTIONSFILE}"
.endif
.endif

# Warn user about deprecated packages.  Advisory only.

.if !target(check-deprecated)
check-deprecated:
.if defined(DEPRECATED)
	@${ECHO_MSG} "===>   NOTICE:"
	@${ECHO_MSG}
	@${ECHO_MSG} "This port is deprecated; you may wish to reconsider installing it:"
	@${ECHO_MSG}
	@${ECHO_MSG} "${DEPRECATED}."
	@${ECHO_MSG}
.if defined(EXPIRATION_DATE)
	@${ECHO_MSG} "It is scheduled to be removed on or after ${EXPIRATION_DATE}."
	@${ECHO_MSG}
.endif
.endif
.endif

# Check if the port is listed in the vulnerability database

.if ${PKGINSTALLVER} < 20040623 || ${OSVERSION} < 420001 || ${OSVERSION} >= 500000 && ${OSVERSION} < 500014
DISABLE_VULNERABILITIES=	yes
.endif

AUDITFILE?=		/var/db/portaudit/auditfile.tbz
AUDITURL?=		http://www.FreeBSD.org/ports
AUDITEXPIRY?=	14
_EXTRACT_AUDITFILE=	${TAR} -jxOf "${AUDITFILE}" auditfile

.PHONY: update-auditfile
update-auditfile:
.if !defined(DISABLE_VULNERABILITIES) && !defined(PACKAGE_BUILDING)
	@audit_expired=${TRUE}; \
	if [ -f "${AUDITFILE}" ]; then \
		audit_created=`${_EXTRACT_AUDITFILE} | \
			${SED} -nEe "1s/^#CREATED: *([0-9]{4})-?([0-9]{2})-?([0-9]{2}).*$$/\1\2\3/p"`; \
		audit_expiry=`${DATE} -u -v-${AUDITEXPIRY}d "+%Y%m%d"`; \
		if [ "$$audit_created" -lt "$$audit_expiry" ]; then \
			${ECHO_MSG} ">>  Vulnerability database out of date."; \
		else \
			audit_expired=${FALSE}; \
		fi; \
	fi; \
	if $$audit_expired; then \
		if [ ! -w "${AUDITFILE:H}" -a `${ID} -u` != 0 ]; then \
			if [ -z "${INSTALL_AS_USER}" ]; then \
				${ECHO_MSG} "===>  Switching to root credentials to fetch the vulnerability database."; \
				${SU_CMD} "cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${.TARGET}"; \
				${ECHO_MSG} "===>  Returning to user credentials"; \
			else \
				${ECHO_MSG} "===>  Can't fetch the vulnerability database."; \
			fi; \
		else \
			${ECHO_MSG} ">>  Fetching vulnerability database from ${AUDITURL}."; \
			if [ -f "${AUDITFILE}" ]; then \
				${MV} -f "${AUDITFILE}" "${AUDITFILE}.old"; \
			else \
				${MKDIR} "${AUDITFILE:H}"; \
			fi; \
			if ${SETENV} ${FETCH_ENV} ${FETCH_CMD} -o "${AUDITFILE}" "${AUDITURL}/${AUDITFILE:T}"; then \
				${CHMOD} a+r "${AUDITFILE}"; \
				if [ -f "${AUDITFILE}.old" ]; then \
					${RM} -f "${AUDITFILE}.old"; \
				fi; \
			else \
				if [ -f "${AUDITFILE}.old" ]; then \
					${ECHO_MSG} ">>  Failed, using old database."; \
					${MV} -f "${AUDITFILE}.old" "${AUDITFILE}"; \
				fi; \
			fi; \
		fi; \
	fi
.else
	@${DO_NADA}
.endif

.PHONY: check-vulnerable
check-vulnerable: update-auditfile
.if !defined(DISABLE_VULNERABILITIES) && !defined(PACKAGE_BUILDING)
	@if [ -r "${AUDITFILE}" ]; then \
		if vlist=`${_EXTRACT_AUDITFILE} | ${GREP} -v '^#' | ${PKG_VERSION} -T '${PKGNAME}' -`; then \
			${ECHO_MSG} "===>  ${PKGNAME} has known vulnerabilities:"; \
			${ECHO_MSG} "$$vlist" | ${AWK} -F\| '{ \
				print ">> " $$3 "."; \
				split($$2, ref, / /); \
				for(r in ref) \
					print "   Reference: <" ref[r] ">" \
			}'; \
			${ECHO_MSG} ">> Please update your ports tree and try again."; \
			exit 1; \
		fi; \
	else \
		${ECHO_MSG} "===>  Vulnerability check disabled, database not found."; \
	fi
.else
	@${ECHO_MSG} "===>  Vulnerability check disabled."
.endif


# Next generation options handling

.if exists(${PERL5})
OPTIONS_CMD?=	${PERL} -w ${PORTSDIR}/devel/portmk/scripts/options.pl
.else
OPTIONS_CMD?=	eval ${ECHO_CMD} ">> ${PKGNAME}: ${PERL5} requried, please install ${PERL_PORT}."; exit 1
.endif

OPTIONS_SH?=	${PORTSDIR}/devel/portmk/scripts/options.sh

_OPTIONS_ENV= \
	CURDIR='${.CURDIR}' \
	OBJDIR='${.OBJDIR}' \
	MASTERDIR='${MASTERDIR}' \
	PKGNAME='${PKGNAME}' \
	PKGNAMESUFFIX='${PKGNAMESUFFIX}' \
	OPTIONS_MASTER='${OPTIONS_MASTER}' \
	OPTIONS_OVERRIDE='${OPTIONS_OVERRIDE}' \
	OPTIONS_FILE='${OPTIONS_FILE}' \
	OPTIONS_CMD='${OPTIONS_CMD}'

.PHONY: config
.PHONY: showconfig
.PHONY: rmconfig
.PHONY: menuconfig

.if defined(_OPTIONSNG_READ)

.if !target(config)
config:
	@${_OPTIONS_ENV}; \
	set -- -e; \
	. '${OPTIONS_SH}'
.endif

.if !target(menuconfig)
menuconfig:
	@${ECHO_MSG} "===>  ${PKGNAME}: menuconfig is a reserved target."
	@${FALSE}
	@${_OPTIONS_ENV}; \
	set -- -g; \
	. '${OPTIONS_SH}'
.endif

.if !target(rmconfig)
rmconfig:
	@${ECHO_MSG} "===>  ${PKGNAME}: Reverting to default configuration."
	@${_OPTIONS_ENV}; \
	set -- -d; \
	. '${OPTIONS_SH}'
.endif

.if !target(showconfig)
showconfig:
	@${ECHO_MSG} "===>  ${PKGNAME}: menuconfig is a reserved target."
	@${FALSE}
	@${_OPTIONS_ENV}; \
	set -- -l; \
	. '${OPTIONS_SH}'
.endif

.elif !defined(OPTIONS)

.if !target(config)
config:
	@${ECHO_MSG} "===>  ${PKGNAME} has no configurable options."
.endif

.if !target(menuconfig)
menuconfig:
	@${ECHO_MSG} "===>  ${PKGNAME} has no configurable options."
.endif

.if !target(rmconfig)
rmconfig:
	@${ECHO_MSG} "===>  ${PKGNAME} has no configurable options."
.endif

.if !target(showconfig)
showconfig:
	@${ECHO_MSG} "===>  ${PKGNAME} has no configurable options."
.endif

.else

menuconfig: config
	@${DO_NADA}

.endif

.PHONY: makeconfig
.if !target(makeconfig)
makeconfig:
	@${_OPTIONS_ENV}; \
	set -- -c; \
	. '${OPTIONS_SH}'
.endif

.PHONY: config-recursive
.if !target(config-recursive)
config-recursive:
	@${ECHO_MSG} "===>  ${PKGNAME}: config-recursive is a reserved target."
	@${FALSE}
.endif

# New style distfile handling

DISTFILES_SH?=			${PORTSDIR}/devel/portmk/scripts/distfiles.sh

DISTINFO_ALGORITHMS?=	MD5
VALID_ALGORITHMS=		MD5 SHA1 RMD160

MK_FILE?=				${MASTERDIR}/Makefile

.if !defined(DISTFILES_KEEP_QUOTING)
_FETCHDISTFILES_ENV=	\
	DISTFILES=${DISTFILES:C/\\\\(.)/\1/g:Q}; \
	PATCHFILES=${PATCHFILES:C/\\\\(.)/\1/g:Q}
.else
_FETCHDISTFILES_ENV=	\
	DISTFILES=${DISTFILES:Q}; \
	PATCHFILES=${PATCHFILES:Q}
.endif
.for env in \
	MASTER_SITES MASTER_SITE_SUBDIR PATCH_SITES PATCH_SITE_SUBDIR \
	_MASTER_SITE_BACKUP _MASTER_SITE_OVERRIDE \
	DISABLE_SIZE DISTDIR DISTINFO_ALGORITHMS DISTINFO_LABEL \
	DIST_SUBDIR ECHO_MSG FETCH_AFTER_ARGS FETCH_BEFORE_ARGS \
	FETCH_CMD FETCH_SYMLINK_DISTFILES IGNOREFILES LOCALBASE \
	MASTER_SORT_AWK MASTER_SORT_CMD MASTER_SORT_ENV MD5_FILE \
	MK_FILE NO_CHECKSUM NO_SIZE OSVERSION PERL5 VALID_ALGORITHMS
_FETCHDISTFILES_ENV+=	; ${env}='${${env}}'
.endfor
.if ${OSVERSION} >= 460000 # XXX This does not work with older make(1)s
.for env in ${VALID_ALGORITHMS} SIZE
_FETCHDISTFILES_ENV+=	; DISTINFO_${env}='${DISTINFO${DISTINFO_LABEL:C/^./_&/}_${env}}'
.endfor
.endif

.PHONY: do-fetch
.if !target(do-fetch)
do-fetch:
	@${_FETCHDISTFILES_ENV}; \
	set -- -f; \
	. '${DISTFILES_SH}'
.endif

.PHONY: checksum
.if !target(checksum)
checksum: fetch
	@${DO_NADA}
.endif

.PHONY: makesum
.if !target(makesum)
makesum:
.if !defined(FETCH_ALL)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} FETCH_ALL=yes ${__softMAKEFLAGS} ${.TARGET}
.else
	@${_FETCHDISTFILES_ENV}; \
	set -- -m; \
	. '${DISTFILES_SH}'
.endif
.endif

.PHONY: master-sites-all
.if !target(master-sites-all)
master-sites-all:
	@${_FETCHDISTFILES_ENV}; \
	set -- -t ''; \
	. '${DISTFILES_SH}'
.endif

.PHONY: master-sites
.if !target(master-sites)
master-sites:
	@${_FETCHDISTFILES_ENV}; \
	set -- -t 'DEFAULT'; \
	. '${DISTFILES_SH}'
.endif

.PHONY: patch-sites-all
.if !target(patch-sites-all)
patch-sites-all:
	@${_FETCHDISTFILES_ENV}; \
	set -- -T ''; \
	. '${DISTFILES_SH}'
.endif

.PHONY: patch-sites
.if !target(patch-sites)
patch-sites:
	@${_FETCHDISTFILES_ENV}; \
	set -- -T 'DEFAULT'; \
	. '${DISTFILES_SH}'
.endif

.PHONY: migratesum
.if !target(migratesum)
migratesum:
	@${_FETCHDISTFILES_ENV}; \
	set -- -M; \
	. '${DISTFILES_SH}'
.endif

.PHONY: migratesum2
.if !target(migratesum2)
migratesum2:
	@${_FETCHDISTFILES_ENV}; \
	set -- -N; \
	. '${DISTFILES_SH}'
.endif

.PHONY: checkdistsites
.if !target(checkdistsites)
checkdistsites:
.if !defined(FETCH_ALL)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} FETCH_ALL=yes ${__softMAKEFLAGS} ${.TARGET}
.else
	@${_FETCHDISTFILES_ENV}; \
	set -- -F; \
	. '${DISTFILES_SH}'
.endif
.endif

.PHONY: checkdistfiles-recursive
.if !target(checkdistfiles-recursive)
checkdistfiles-recursive:
.if defined(_ONG_REEXEC)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.else
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} ${__softMAKEFLAGS} checkdistfiles); \
	done
.endif
.endif

# Prints out the total size of files missing in ${DISTDIR}

_MISSING_SIZE_SUMMARY=	\
	${AWK} ' \
		BEGIN {t=0; f=0; u=0} \
		{if ($$1 > 0) {t+=$$1; f+=1} else {u+=1}} \
		END { \
			if (t >= 10^9) \
				s=sprintf("%.2f GBytes", t/10^9); \
			else if (t >= 10^6) \
				s=sprintf("%.2f MBytes", t/10^6); \
			else if (t >= 10^3) \
				s=sprintf("%.2f KBytes", t/10^3); \
			else \
				s=t " Bytes"; \
			msg=ENVIRON["MISSING_MSG"] \
				f " file(s) with a total size of " s; \
			if (u) msg=msg " and " u " file(s) with unknown size."; \
			print msg \
		} \
	'

.PHONY: missing-size
.if !target(missing-size)
missing-size:
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} print-missing-files \
	| ${SETENV} MISSING_MSG="To install ${PKGNAME}, you have to fetch " ${_MISSING_SIZE_SUMMARY}
.endif

.PHONY: missing-recursive-size
.if !target(missing-recursive-size)
missing-recursive-size:
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} print-missing-recursive-files \
	| ${SETENV} MISSING_MSG="To install ${PKGNAME} and its dependencies, you have to fetch " ${_MISSING_SIZE_SUMMARY}
.endif

.PHONY: print-missing-recursive-files
.if !target(print-missing-recursive-files)
print-missing-recursive-files:
.if defined(_ONG_REEXEC)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.else
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} print-missing-files); \
	done | ${SORT} -u +1;
.endif
.endif

.PHONY: print-missing-files
.if !target(print-missing-files)
print-missing-files:
	@${_FETCHDISTFILES_ENV}; \
	set -- -S; \
	. '${DISTFILES_SH}'
.endif

.PHONY: fetch-list
.if !target(fetch-list)
fetch-list:
	@${_FETCHDISTFILES_ENV}; \
	set -- -L; \
	. '${DISTFILES_SH}'
.endif

# Extract

.PHONY: do-extract
.if !target(do-extract)
do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
.for file in ${EXTRACT_ONLY}
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} "${_DISTDIR}/${file}" ${EXTRACT_AFTER_ARGS}
.endfor
.if !defined(EXTRACT_PRESERVE_OWNERSHIP)
	@if [ `${ID} -u` = 0 ]; then \
		${CHMOD} -R ug-s ${WRKDIR}; \
		${CHOWN} -R 0:0 ${WRKDIR}; \
	fi
.endif
.endif

# Patch

.if !target(do-patch)
do-patch:
.if defined(PATCHFILES)
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@(cd ${_DISTDIR}; \
	  for i in ${_PATCHFILES}; do \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying distribution patch $$i" ; \
		fi; \
		case $$i in \
			*.Z|*.gz) \
				${GZCAT} "$$i" | ${PATCH} ${PATCH_DIST_ARGS}; \
				;; \
			*.bz2) \
				${BZCAT} "$$i" | ${PATCH} ${PATCH_DIST_ARGS}; \
				;; \
			*) \
				${PATCH} ${PATCH_DIST_ARGS} < "$$i"; \
				;; \
		esac; \
	  done)
.endif
.if defined(EXTRA_PATCHES)
	@for i in ${EXTRA_PATCHES}; do \
		${ECHO_MSG} "===>  Applying extra patch $$i"; \
		${PATCH} ${PATCH_ARGS} < "$$i"; \
	done
.endif
	@if [ -d ${PATCHDIR} ]; then \
		if [ "`${ECHO_CMD} ${PATCHDIR}/patch-*`" != "${PATCHDIR}/patch-*" ]; then \
			${ECHO_MSG} "===>  Applying ${OPSYS} patches for ${PKGNAME}" ; \
			PATCHES_APPLIED="" ; \
			for i in ${PATCHDIR}/patch-*; do \
				case $$i in \
					*.orig|*.rej|*~|*,v) \
						${ECHO_MSG} "===>   Ignoring patchfile $$i" ; \
						;; \
					*) \
						if [ ${PATCH_DEBUG_TMP} = yes ]; then \
							${ECHO_MSG} "===>   Applying ${OPSYS} patch $$i" ; \
						fi; \
						if ${PATCH} ${PATCH_ARGS} < "$$i" ; then \
							PATCHES_APPLIED="$$PATCHES_APPLIED $$i" ; \
						else \
							${ECHO_MSG} `${ECHO_CMD} ">> Patch $$i failed to apply cleanly." | ${SED} "s|${PATCHDIR}/||"` ; \
							if [ x"$$PATCHES_APPLIED" != x"" ]; then \
								${ECHO_MSG} `${ECHO_CMD} ">> Patch(es) $$PATCHES_APPLIED applied cleanly." | ${SED} "s|${PATCHDIR}/||g"` ; \
							fi; \
							${FALSE} ; \
						fi; \
						;; \
				esac; \
			done; \
		fi; \
	fi
.endif

# Configure

.if !target(do-configure)
do-configure:
	@if [ -f ${SCRIPTDIR}/configure ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
		  ${SCRIPTDIR}/configure; \
	fi
.if defined(GNU_CONFIGURE)
	@CONFIG_GUESS_DIRS=$$(${FIND} ${WRKDIR} -name config.guess -o -name config.sub \
		| ${XARGS} -n 1 ${DIRNAME}); \
	for _D in $${CONFIG_GUESS_DIRS}; do \
		${CP} -f ${TEMPLATES}/config.guess $${_D}/config.guess; \
		${CHMOD} a+rx $${_D}/config.guess; \
	    ${CP} -f ${TEMPLATES}/config.sub $${_D}/config.sub; \
		${CHMOD} a+rx $${_D}/config.sub; \
	done
.endif
.if defined(HAS_CONFIGURE)
	@(cd ${CONFIGURE_WRKSRC} && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
			 ${ECHO_CMD} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
			 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
			 ${FALSE}; \
		fi)
.endif
.if defined(PERL_CONFIGURE)
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
.if !defined(PERL_MODBUILD)
	@cd ${CONFIGURE_WRKSRC} && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile
.if ${PERL_LEVEL} <= 500503
	@cd ${CONFIGURE_WRKSRC} && \
		${PERL5} -pi -e 's/^(INSTALLSITELIB|INSTALLSITEARCH|SITELIBEXP|SITEARCHEXP|INSTALLMAN1DIR|INSTALLMAN3DIR) = \/usr\/local/$$1 = \$$(PREFIX)/' Makefile
.endif
.endif
.endif
.if defined(USE_IMAKE)
	@(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF})
.endif
.endif

# Build

.PHONY: do-build
.if !target(do-build)
do-build:
.if defined(USE_GMAKE)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.else
.if defined(PERL_MODBUILD)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${MAKE_ARGS} ${ALL_TARGET})
.else
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endif
.endif
.endif

# Check conflicts

.PHONY: check-conflicts
.if !target(check-conflicts)
check-conflicts:
.if defined(CONFLICTS) && !defined(DISABLE_CONFLICTS)
	@found=`${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO} -I ${CONFLICTS:C/.+/'&'/} 2>/dev/null | ${AWK} '{print $$1}'`; \
	conflicts_with=; \
	for entry in $${found}; do \
		prfx=`${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO} -q -p "$${entry}" 2> /dev/null | ${SED} -ne '1s/^@cwd //p'`; \
		orgn=`${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO} -q -o "$${entry}" 2> /dev/null`; \
		if [ "/${PREFIX}" = "/$${prfx}" -a "/${PKGORIGIN}" != "/$${orgn}" ]; then \
			conflicts_with="$${conflicts_with} $${entry}"; \
		fi; \
	done; \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      They install files into the same place."; \
		${ECHO_MSG} "      Please remove them first with pkg_delete(1)."; \
		exit 1; \
	fi
.endif  # CONFLICTS
.endif

# Install

.PHONY: do-install
.if !target(do-install)
do-install:
.if defined(USE_GMAKE)
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if defined(USE_IMAKE) && !defined(NO_INSTALL_MANPAGES)
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install.man)
.if ${XFREE86_HTML_MAN:L} == yes
	@${MKHTMLINDEX} ${PREFIX}/lib/X11/doc/html
.endif
.endif
.else # !defined(USE_GMAKE)
.if defined(PERL_MODBUILD)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${MAKE_ARGS} ${INSTALL_TARGET})
.else
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if defined(USE_IMAKE) && !defined(NO_INSTALL_MANPAGES)
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install.man)
.if ${XFREE86_HTML_MAN:L} == yes
	@${MKHTMLINDEX} ${PREFIX}/lib/X11/doc/html
.endif
.endif
.endif
.endif
.endif

# Package

.if defined(DESTDIR) && ${PKGINSTALLVER} < 20040426
check-makefile::
	@${ECHO_CMD} "${PKGNAME}: Makefile error: please upgrade pkg_install to use DESTDIR"
	@${FALSE}
.endif

.PHONY: do-package
.if !target(do-package)
do-package: ${TMPPLIST}
	@if [ -d ${PACKAGES} ]; then \
		if [ ! -d ${PKGREPOSITORY} ]; then \
			if ! ${MKDIR} ${PKGREPOSITORY}; then \
				${ECHO_MSG} ">> Can't create directory ${PKGREPOSITORY}."; \
				exit 1; \
			fi; \
		fi; \
	fi
	@__softMAKEFLAGS='${__softMAKEFLAGS:S/'/'\''/g}'; \
	_LATE_PKG_ARGS=""; \
	if [ -f ${PKGINSTALL} ]; then \
		_LATE_PKG_ARGS="$${_LATE_PKG_ARGS} -i ${PKGINSTALL}"; \
	fi; \
	if [ -f ${PKGDEINSTALL} ]; then \
		_LATE_PKG_ARGS="$${_LATE_PKG_ARGS} -k ${PKGDEINSTALL}"; \
	fi; \
	if [ -f ${PKGREQ} ]; then \
		_LATE_PKG_ARGS="$${_LATE_PKG_ARGS} -r ${PKGREQ}"; \
	fi; \
	if [ -f ${PKGMESSAGE} ]; then \
		_LATE_PKG_ARGS="$${_LATE_PKG_ARGS} -D ${PKGMESSAGE}"; \
	fi; \
	if ${PKG_CMD} ${PKG_ARGS} ${PKGFILE}; then \
		if [ -d ${PACKAGES} ]; then \
			cd ${.CURDIR} && eval ${MAKE} ${_ONG_MAKEFLAGS} $${__softMAKEFLAGS} package-links; \
		fi; \
	else \
		cd ${.CURDIR} && eval ${MAKE} ${_ONG_MAKEFLAGS} $${__softMAKEFLAGS} delete-package; \
		exit 1; \
	fi
.endif

# Some support rules for do-package

.PHONY: package-links
.if !target(package-links)
package-links: delete-package-links
	@for cat in ${CATEGORIES}; do \
		if [ ! -d ${PACKAGES}/$$cat ]; then \
			if ! ${MKDIR} ${PACKAGES}/$$cat; then \
				${ECHO_MSG} ">> Can't create directory ${PACKAGES}/$$cat."; \
				exit 1; \
			fi; \
		fi; \
		${LN} -sf `${ECHO_CMD} $$cat | ${SED} -e 'sa[^/]*a..ag'`/${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX} ${PACKAGES}/$$cat; \
	done
.if !defined(NO_LATEST_LINK)
	@if [ ! -d ${PKGLATESTREPOSITORY} ]; then \
		if ! ${MKDIR} ${PKGLATESTREPOSITORY}; then \
			${ECHO_MSG} ">> Can't create directory ${PKGLATESTREPOSITORY}."; \
			exit 1; \
		fi; \
	fi
	@${LN} -s ../${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX} ${PKGLATESTFILE}
.endif
.endif

.PHONY: delete-package-links
.if !target(delete-package-links)
delete-package-links:
	@for cat in ${CATEGORIES}; do \
		${RM} -f ${PACKAGES}/$$cat/${PKGNAME}${PKG_SUFX}; \
	done
.if !defined(NO_LATEST_LINK)
	@${RM} -f ${PKGLATESTFILE}
.endif
.endif

.PHONY: delete-package
.if !target(delete-package)
delete-package: delete-package-links
	@${RM} -f ${PKGFILE}
.endif

.PHONY: delete-package-links-list
.if !target(delete-package-links-list)
delete-package-links-list:
	@for cat in ${CATEGORIES}; do \
		${ECHO_CMD} ${RM} -f ${PACKAGES}/$$cat/${PKGNAME}${PKG_SUFX}; \
	done
.if !defined(NO_LATEST_LINK)
	@${ECHO_CMD} ${RM} -f ${PKGLATESTFILE}
.endif
.endif

.PHONY: delete-package-list
.if !target(delete-package-list)
delete-package-list: delete-package-links-list
	@${ECHO_CMD} "[ -f ${PKGFILE} ] && (${ECHO_CMD} deleting ${PKGFILE}; ${RM} -f ${PKGFILE})"
.endif

# Utility targets follow

.PHONY: check-already-installed
.if !target(check-already-installed)
check-already-installed:
.if !defined(NO_PKG_REGISTER) && !defined(FORCE_PKG_REGISTER)
		@${ECHO_MSG} "===>  Checking if ${PKGORIGIN} already installed"
		@${MKDIR} ${_PKG_DBDIR}
		@already_installed=`${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO} -q -O ${PKGORIGIN}`; \
		if [ -n "$${already_installed}" ]; then \
				for p in $${already_installed}; do \
						prfx=`${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO} -q -p $${p} 2> /dev/null | ${SED} -ne '1s|^@cwd ||p'`; \
						if [ "x${PREFIX}" = "x$${prfx}" ]; then \
								found_package=$${p}; \
								break; \
						fi; \
				done; \
		fi; \
		if [ -n "$${found_package}" ]; then \
				if [ "${PKGNAME}" = "$${found_package}" ]; then \
						${ECHO_CMD} "===>   ${PKGNAME} is already installed"; \
				else \
						${ECHO_CMD} "===>   An older version of ${PKGORIGIN} is already installed ($${found_package})"; \
				fi; \
				${ECHO_CMD} "      You may wish to \`\`make deinstall'' and install this port again"; \
				${ECHO_CMD} "      by \`\`make reinstall'' to upgrade it properly."; \
				${ECHO_CMD} "      If you really wish to overwrite the old port of ${PKGORIGIN}"; \
				${ECHO_CMD} "      without deleting it first, set the variable \"FORCE_PKG_REGISTER\""; \
				${ECHO_CMD} "      in your environment or the \"make install\" command line."; \
				exit 1; \
		fi
.else
	@${DO_NADA}
.endif
.endif

.PHONY: check-umask
.if !target(check-umask)
check-umask:
	@if [ `${SH} -c umask` != 0022 ]; then \
		${ECHO_MSG} "===>  Warning: your umask is \"`${SH} -c umask`"\".; \
		${ECHO_MSG} "      If this is not desired, set it to an appropriate value"; \
		${ECHO_MSG} "      and install this port again by \`\`make reinstall''."; \
	fi
.endif

.PHONY: install-mtree
.if !target(install-mtree)
install-mtree:
	@${MKDIR} ${DESTDIR}${PREFIX}
	@if [ `${ID} -u` != 0 ]; then \
		if [ -w ${DESTDIR}${PREFIX}/ ]; then \
			${ECHO_MSG} "Warning: not superuser, you may get some errors during installation."; \
		else \
			${ECHO_MSG} "Error: ${DESTDIR}${PREFIX}/ not writable."; \
			${FALSE}; \
		fi; \
	fi
.if !defined(NO_MTREE)
	@if [ `${ID} -u` = 0 ]; then \
		if [ ! -f ${MTREE_FILE} ]; then \
			${ECHO_CMD} "Error: mtree file \"${MTREE_FILE}\" is missing."; \
			${ECHO_CMD} "Copy it from a suitable location (e.g., /usr/src/etc/mtree) and try again."; \
			exit 1; \
		else \
			${MTREE_CMD} ${MTREE_ARGS} ${DESTDIR}${PREFIX}/ >/dev/null; \
			if [ ${MTREE_FILE} = "/etc/mtree/BSD.local.dist" ]; then \
				cd ${DESTDIR}${PREFIX}/share/nls; \
				${LN} -shf C POSIX; \
				${LN} -shf C en_US.US-ASCII; \
			fi; \
		fi; \
	else \
		${ECHO_MSG} "Warning: not superuser, can't run mtree."; \
		${ECHO_MSG} "You may want to become root and try again to ensure correct permissions."; \
	fi
.endif
.endif

.PHONY: run-ldconfig
.if !target(run-ldconfig)
run-ldconfig:
.if defined(INSTALLS_SHLIB)
.if !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>   Running ldconfig"
	${LDCONFIG} -m ${LDCONFIG_RUNLIST}
.else
	@${ECHO_MSG} "===>   Running ldconfig (errors are ignored)"
	-${LDCONFIG} -m ${LDCONFIG_RUNLIST}
.endif
.else
	@${DO_NADA}
.endif
.endif

.PHONY: security-check
.if !target(security-check)
security-check:
# Scan PLIST for:
#   1.  setugid files
#   2.  accept()/recvfrom() which indicates network listening capability
#   3.  insecure functions (gets/mktemp/tempnam/[XXX])
#   4.  startup scripts, in conjunction with 2.
#   5.  world-writable files/dirs
#
	-@${RM} -f ${WRKDIR}/.PLIST.setuid ${WRKDIR}/.PLIST.writable ${WRKDIR}/.PLIST.objdump; \
	${AWK} -v prefix='${PREFIX}' ' \
		match($$0, /^@cwd /) { prefix = substr($$0, RSTART + RLENGTH); next; } \
		/^@/ { next; } \
		/^\// { print; next; } \
		{ print prefix "/" $$0; } \
	' ${TMPPLIST} > ${WRKDIR}/.PLIST.flattened; \
	${TR} '\n' '\0' < ${WRKDIR}/.PLIST.flattened \
	| ${XARGS} -0 -J % ${FIND} % -prune ! -type l -type f \( -perm -4000 -o -perm -2000 \) \( -perm -0010 -o -perm -0001 \) 2> /dev/null > ${WRKDIR}/.PLIST.setuid; \
	${TR} '\n' '\0' < ${WRKDIR}/.PLIST.flattened \
	| ${XARGS} -0 -J % ${FIND} % -prune -perm -0002 \! -type l 2> /dev/null > ${WRKDIR}/.PLIST.writable; \
	${TR} '\n' '\0' < ${WRKDIR}/.PLIST.flattened \
	| ${XARGS} -0 -J % ${FIND} % -prune ! -type l -type f -print0 2> /dev/null \
	| ${XARGS} -0 -n 1 ${OBJDUMP} -R 2> /dev/null > ${WRKDIR}/.PLIST.objdump; \
	if \
		! ${AWK} -v audit="$${PORTS_AUDIT}" -f ${PORTSDIR}/Tools/scripts/security-check.awk \
		  ${WRKDIR}/.PLIST.flattened ${WRKDIR}/.PLIST.objdump ${WRKDIR}/.PLIST.setuid ${WRKDIR}/.PLIST.writable; \
	then \
		www_site=$$(cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} www-site); \
	    if [ ! -z "$${www_site}" ]; then \
			${ECHO_MSG}; \
			${ECHO_MSG} "      For more information, and contact details about the security"; \
			${ECHO_MSG} "      status of this software, see the following webpage: "; \
			${ECHO_MSG} "$${www_site}"; \
		fi; \
	fi
.endif

################################################################
# Skeleton targets start here
#
# You shouldn't have to change these.  Either add the pre-* or
# post-* targets/scripts or redefine the do-* targets.  These
# targets don't do anything other than checking for cookies and
# call the necessary targets/scripts.
################################################################

# Please note that the order of the following targets is important, and
# should not be modified.

_BOOTSTRAP_SEQ=		bootstrap-depends
_SANITY_DEP=		bootstrap
_SANITY_SEQ=		pre-everything check-makefile check-categories \
			check-makevars check-depends check-deprecated \
			check-vulnerable buildanyway-message options-message
_FETCH_DEP=		check-sanity
_FETCH_SEQ=		fetch-depends pre-fetch pre-fetch-script \
				do-fetch post-fetch post-fetch-script
_EXTRACT_DEP=	fetch
_EXTRACT_SEQ=	extract-message extract-depends pre-extract \
				pre-extract-script do-extract \
				post-extract post-extract-script
_PATCH_DEP=		extract
_PATCH_SEQ=		patch-message patch-depends pre-patch pre-patch-script \
				do-patch post-patch post-patch-script
_CONFIGURE_DEP=	patch
_CONFIGURE_SEQ=	build-depends lib-depends misc-depends configure-message \
		pre-configure pre-configure-script patch-autotools \
		run-autotools do-configure post-configure post-configure-script
_BUILD_DEP=		configure
_BUILD_SEQ=		build-message pre-build pre-build-script do-build \
				post-build post-build-script
_INSTALL_DEP=	build
_INSTALL_SEQ=	install-message check-conflicts \
			    run-depends lib-depends pre-install pre-install-script \
				generate-plist check-already-installed
_INSTALL_SUSEQ= check-umask install-mtree pre-su-install \
				pre-su-install-script do-install post-install \
				post-install-script add-plist-info add-plist-docs \
				compress-man run-ldconfig fake-pkg security-check
_PACKAGE_DEP=	install
_PACKAGE_SEQ=	package-message pre-package pre-package-script \
				do-package post-package post-package-script

.PHONY: bootstrap
.if !target(bootstrap)
bootstrap: ${_BOOTSTRAP_SEQ}
.endif

.PHONY: check-sanity
.if !target(check-sanity) && defined(_ONG_REEXEC)
check-sanity:
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.elif !target(check-sanity)
check-sanity: ${_SANITY_DEP} ${_SANITY_SEQ}
.endif

# XXX MCL might need to move in loop below?
.PHONY: fetch
.if !target(fetch) && defined(_ONG_REEXEC)
fetch:
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.elif !target(${target})
fetch: ${_FETCH_DEP} ${_FETCH_SEQ}
.endif

# Main logic. The loop generates 6 main targets and using cookies
# ensures that those already completed are skipped.

.for target in extract patch configure build install package

.PHONY: ${target}
.if !target(${target}) && defined(_ONG_REEXEC)
${target}:
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.elif !target(${target}) && defined(_OPTIONS_OK)
${target}: ${${target:U}_COOKIE}
.elif !target(${target})
${target}: config
	@cd ${.CURDIR} && ${MAKE} CONFIG_DONE=1 ${__softMAKEFLAGS} ${${target:U}_COOKIE}
.endif

.if !exists(${${target:U}_COOKIE})

.if ${UID} != 0 && defined(_${target:U}_SUSEQ) && !defined(INSTALL_AS_USER)
.if defined(USE_SUBMAKE) || defined(_ONG_REEXEC)
${${target:U}_COOKIE}: ${_${target:U}_DEP}
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${_${target:U}_SEQ}
.else
${${target:U}_COOKIE}: ${_${target:U}_DEP} ${_${target:U}_SEQ}
.endif
	@${ECHO_MSG} "===>  Switching to root credentials for '${target}' target"
	@cd ${.CURDIR} && \
		${SU_CMD} "${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${_${target:U}_SUSEQ}"
	@${ECHO_MSG} "===>  Returning to user credentials"
	@${TOUCH} ${TOUCH_FLAGS} ${.TARGET}
.elif defined(USE_SUBMAKE) || defined(_ONG_REEXEC)
${${target:U}_COOKIE}: ${_${target:U}_DEP}
	@cd ${.CURDIR} && \
		${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${_${target:U}_SEQ} ${_${target:U}_SUSEQ}
	@${TOUCH} ${TOUCH_FLAGS} ${.TARGET}
.else
${${target:U}_COOKIE}: ${_${target:U}_DEP} ${_${target:U}_SEQ} ${_${target:U}_SUSEQ}
	@${TOUCH} ${TOUCH_FLAGS} ${.TARGET}
.endif

.else
${${target:U}_COOKIE}::
	@if [ -e ${.TARGET} ]; then \
		${DO_NADA}; \
	else \
		cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}; \
	fi
.endif

.endfor

# Enforce order for -jN builds

.ORDER: ${_BOOTSTRAP_SEQ}
.ORDER: ${_SANITY_DEP} ${_SANITY_SEQ}
.ORDER: ${_FETCH_DEP} ${_FETCH_SEQ}
.ORDER: ${_EXTRACT_DEP} ${_EXTRACT_SEQ}
.ORDER: ${_PATCH_DEP} ${_PATCH_SEQ}
.ORDER: ${_CONFIGURE_DEP} ${_CONFIGURE_SEQ}
.ORDER: ${_BUILD_DEP} ${_BUILD_SEQ}
.ORDER: ${_INSTALL_DEP} ${_INSTALL_SEQ}
.ORDER: ${_PACKAGE_DEP} ${_PACKAGE_SEQ}

.PHONY: extract-message patch-message configure-message build-message install-message package-message
extract-message:
	@${ECHO_MSG} "===>  Extracting for ${PKGNAME}"
patch-message:
	@${ECHO_MSG} "===>  Patching for ${PKGNAME}"
configure-message:
	@${ECHO_MSG} "===>  Configuring for ${PKGNAME}"
build-message:
	@${ECHO_MSG} "===>  Building for ${PKGNAME}"
install-message:
	@${ECHO_MSG} "===>  Installing for ${PKGNAME}"
package-message:
	@${ECHO_MSG} "===>  Building package for ${PKGNAME}"

# Empty pre-* and post-* targets

.for stage in pre post
.for name in fetch extract patch configure build install package

.PHONY: ${stage}-${name} ${stage}-${name}-script

.if !target(${stage}-${name})
${stage}-${name}:
	@${DO_NADA}
.endif

.if !target(${stage}-${name}-script)
${stage}-${name}-script:
	@if [ -f ${SCRIPTDIR}/${.TARGET:S/-script$//} ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
			${SCRIPTDIR}/${.TARGET:S/-script$//}; \
	fi
.endif

.endfor
.endfor

# Special cases for su
.PHONY: pre-su-install pre-su-install-script

.if !target(pre-su-install)
pre-su-install:
	@${DO_NADA}
.endif

.if !target(pre-su-install-script)
pre-su-install-script:
	@${DO_NADA}
.endif


.PHONY: pretty-print-www-site
.if !target(pretty-print-www-site)
pretty-print-www-site:
	@www_site=$$(cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} www-site); \
	if [ -n "$${www_site}" ]; then \
		${ECHO_CMD} -n " and/or visit the "; \
		${ECHO_CMD} -n "<a href=\"$${www_site}\">web site</a>"; \
		${ECHO_CMD} " for futher informations"; \
	fi
.endif

################################################################
# Some more targets supplied for users' convenience
################################################################

# Checkpatch
#
# Special target to verify patches

.PHONY: checkpatch
.if !target(checkpatch)
checkpatch:
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} PATCH_CHECK_ONLY=yes ${_PATCH_DEP} ${_PATCH_SEQ}
.endif

# Reinstall
#
# Special target to re-run install

.PHONY: reinstall
.if !target(reinstall)
reinstall:
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
	@cd ${.CURDIR} && DEPENDS_TARGET="${DEPENDS_TARGET}" DESTDIR=${DESTDIR} ${MAKE} ${_ONG_MAKEFLAGS} install
.endif

# Deinstall
#
# Special target to remove installation

.PHONY: deinstall
.if !target(deinstall)
deinstall:
	@if [ -n "${DESTDIR}" ]; then \
		${ECHO_MSG} "===>   Can't deinstall from DESTDIR: ${DESTDIR}"; \
		${FALSE}; \
	fi
.if ${UID} != 0 && !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>  Switching to root credentials for '${.TARGET}' target"
	@cd ${.CURDIR} && \
		${SU_CMD} "${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}"
	@${ECHO_MSG} "===>  Returning to user credentials"
.else
	@${ECHO_MSG} "===>  Deinstalling for ${PKGORIGIN}"
	@found_names=`${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO} -q -O ${PKGORIGIN}`; \
	for p in $${found_names}; do \
			check_name=`${ECHO_CMD} $${p} | ${SED} -e 's/-[^-]*$$//'`; \
			if [ "$${check_name}" = "${PKGBASE}" ]; then \
					prfx=`${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO} -q -p $${p} 2> /dev/null | ${SED} -ne '1s|^@cwd ||p'`; \
					if [ "x${PREFIX}" = "x$${prfx}" ]; then \
							${ECHO_MSG} "===>   Deinstalling $${p}"; \
							${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_DELETE} -f $${p}; \
					else \
							${ECHO_MSG} "===>   $${p} has a different PREFIX: $${prfx}, skipping"; \
					fi; \
			fi; \
	done; \
	if [ -z "$${found_names}" ]; then \
			${ECHO_MSG} "===>   ${PKGBASE} not installed, skipping"; \
	fi
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
.endif
.endif

# Deinstall-all
#
# Special target to remove installation of all ports of the same origin

.PHONY: deinstall-all
.if !target(deinstall-all)
deinstall-all:
	@if [ -n "${DESTDIR}" ]; then \
		${ECHO_MSG} "===>   Can't deinstall from DESTDIR: ${DESTDIR}"; \
		${FALSE}; \
	fi
.if ${UID} != 0 && !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>  Switching to root credentials for '${.TARGET}' target"
	@cd ${.CURDIR} && \
		${SU_CMD} "${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}"
	@${ECHO_MSG} "===>  Returning to user credentials"
.else
	@${ECHO_MSG} "===>  Deinstalling for ${PKGORIGIN}"
	@deinstall_names=`${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO} -q -O ${PKGORIGIN}`; \
	if [ -n "$${deinstall_names}" ]; then \
		for d in $${deinstall_names}; do \
			${ECHO_MSG} "===>   Deinstalling $${d}"; \
			${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_DELETE} -f $${d}; \
		done; \
	else \
		${ECHO_MSG} "===>   ${PKGORIGIN} not installed, skipping"; \
	fi
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
.endif
.endif

# Cleaning up

.PHONY: do-clean
.if !target(do-clean)
do-clean:
	@if [ -d ${WRKDIR} ]; then \
		if [ -w ${WRKDIR} ]; then \
			${RM} -rf ${WRKDIR}; \
		else \
			${ECHO_MSG} "===>   ${WRKDIR} not writable, skipping"; \
		fi; \
	fi
.endif

.PHONY: clean
.if !target(clean)
clean:
.if !defined(NOCLEANDEPENDS)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} clean-depends
.endif
	@${ECHO_MSG} "===>  Cleaning for ${PKGNAME}"
.if target(pre-clean)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} pre-clean
.endif
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} do-clean
.if target(post-clean)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} post-clean
.endif
.endif

.PHONY: pre-distclean
.if !target(pre-distclean)
pre-distclean:
	@${DO_NADA}
.endif

.PHONY: distclean
.if !target(distclean)
distclean: pre-distclean clean
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} delete-distfiles RESTRICTED_FILES='$${_DISTFILES} $${_PATCHFILES}'
.endif

.PHONY: delete-distfiles
.if !target(delete-distfiles)
delete-distfiles:
	@${ECHO_MSG} "===>  Deleting distfiles for ${PKGNAME}"
.if defined(RESTRICTED_FILES)
	@if [ -d "${_DISTDIR}" ]; then ( \
		cd "${_DISTDIR}"; \
		RESTRICTED_FILES="${RESTRICTED_FILES}"; \
		for file in $${RESTRICTED_FILES}; do \
			${RM} -f "$${file}"; \
			dir="$${file%/*}"; \
			if [ "$${dir}" != "$${file}" ]; then \
				${RMDIR} -p "$${dir}" >/dev/null 2>&1 || ${TRUE}; \
			fi; \
		done \
	); fi
.endif
.if defined(DIST_SUBDIR)
	@${RMDIR} "${_DISTDIR}" >/dev/null 2>&1 || ${TRUE}
.endif
.endif

.PHONY: delete-distfiles-list
.if !target(delete-distfiles-list)
delete-distfiles-list:
	@${ECHO_CMD} "# ${PKGNAME}"
	@if [ "X${RESTRICTED_FILES}" != "X" ]; then \
		for file in ${RESTRICTED_FILES}; do \
			${ECHO_CMD} "[ -f ${_DISTDIR}/$$file ] && (${ECHO_CMD} deleting ${_DISTDIR}/$$file; ${RM} -f ${_DISTDIR}/$$file)"; \
			dir=$${file%/*}; \
			if [ "$${dir}" != "$${file}" ]; then \
				${ECHO_CMD} "(cd ${_DISTDIR} && ${RMDIR} -p $${dir} 2>/dev/null)"; \
			fi; \
		done; \
	fi
.if defined(DIST_SUBDIR)
	@${ECHO_CMD} "${RMDIR} ${_DISTDIR} 2>/dev/null || ${TRUE}"
.endif
.endif

# Generates patches.

.PHONY: update-patches
.if !target(update-patches)
update-patches:
	@toedit=`PATCH_WRKSRC=${PATCH_WRKSRC} \
		PATCHDIR=${PATCHDIR} \
		PATCH_LIST=${PATCHDIR}/patch-* \
		DIFF_ARGS=${DIFF_ARGS} \
		DISTORIG=${DISTORIG} \
		${SH} ${PORTSDIR}/Tools/scripts/update-patches`; \
	case $$toedit in "");; \
	*) ${ECHO_CMD} -n 'edit patches: '; read i; \
	cd ${PATCHDIR} && $${VISUAL:-$${EDIT:-/usr/bin/vi}} $$toedit;; esac
.endif

################################################################
# The special package-building targets
# You probably won't need to touch these
################################################################

# Nobody should want to override this unless PKGNAME is simply bogus.

.PHONY: package-name
.if !target(package-name)
package-name:
	@${ECHO_CMD} ${PKGNAME}
.endif

# Build a package but don't check the package cookie

.PHONY: repackage
.if !target(repackage)
.PHONY: repackage pre-repackage
.ORDER: pre-repackage package
repackage: pre-repackage package

pre-repackage:
	@${RM} -f ${PACKAGE_COOKIE}
.endif

# Build a package but don't check the cookie for installation, also don't
# install package cookie

.PHONY: package-noinstall
.if !target(package-noinstall)
package-noinstall:
	@${MKDIR} ${WRKDIR}
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} pre-package \
		pre-package-script do-package post-package post-package-script
	@${RM} -f ${TMPPLIST}
	-@${RMDIR} ${WRKDIR}
.endif

################################################################
# Dependency checking
################################################################

.PHONY: depends
.if !target(depends)
depends: extract-depends patch-depends lib-depends misc-depends fetch-depends build-depends run-depends

.if defined(ALWAYS_BUILD_DEPENDS)
_DEPEND_ALWAYS=	1
.else
_DEPEND_ALWAYS=	0
.endif

.if defined(INSTALLS_DEPENDS) && defined(INSTALLS_BOOTSTRAP)
bootstrap-depends:
	@${DO_NADA}
.endif

.for deptype in BOOTSTRAP FETCH EXTRACT PATCH BUILD RUN
.PHONY: ${deptype:L}-depends
.if !target(${deptype:L}-depends)
${deptype:L}-depends:
.if defined(${deptype}_DEPENDS)
.if !defined(NO_DEPENDS)
	@if [ -n "INSTALLS_BOOTSTRAP" -o "${deptype:L}" = "bootstrap" ]; then \
		submake_args="-DINSTALLS_BOOTSTRAP -DINSTALLS_DEPENDS"; \
	else \
		submake_args="-DINSTALLS_DEPENDS"; \
	fi; \
	for i in ${${deptype}_DEPENDS}; do \
		prog=`${ECHO_CMD} $$i | ${SED} -e 's/:.*//'`; \
		dir=`${ECHO_CMD} $$i | ${SED} -e 's/[^:]*://'`; \
		if ${EXPR} "$$dir" : '.*:' > /dev/null; then \
			target=`${ECHO_CMD} $$dir | ${SED} -e 's/.*://'`; \
			dir=`${ECHO_CMD} $$dir | ${SED} -e 's/:.*//'`; \
		else \
			target="${DEPENDS_TARGET}"; \
			depends_args="${DEPENDS_ARGS}"; \
		fi; \
		if ${EXPR} "$$prog" : \\/ >/dev/null; then \
			if [ -e "$$prog" ]; then \
				if [ "$$prog" = "${NONEXISTENT}" ]; then \
					${ECHO_MSG} "Error: ${NONEXISTENT} exists.  Please remove it, and restart the build."; \
					${FALSE}; \
				else \
					${ECHO_MSG} "===>   ${PKGNAME} depends on file: $$prog - found"; \
					if [ ${_DEPEND_ALWAYS} = 1 ]; then \
						${ECHO_MSG} "       (but building it anyway)"; \
						notfound=1; \
					else \
						notfound=0; \
					fi; \
				fi; \
			else \
				${ECHO_MSG} "===>   ${PKGNAME} depends on file: $$prog - not found"; \
				notfound=1; \
			fi; \
		else \
			if ${WHICH} "$$prog" > /dev/null 2>&1 ; then \
				${ECHO_MSG} "===>   ${PKGNAME} depends on executable: $$prog - found"; \
				if [ ${_DEPEND_ALWAYS} = 1 ]; then \
					${ECHO_MSG} "       (but building it anyway)"; \
					notfound=1; \
				else \
					notfound=0; \
				fi; \
			else \
				${ECHO_MSG} "===>   ${PKGNAME} depends on executable: $$prog - not found"; \
				notfound=1; \
			fi; \
		fi; \
		if [ $$notfound != 0 ]; then \
			${ECHO_MSG} "===>    Verifying $$target for $$prog in $$dir"; \
			if [ ! -d "$$dir" ]; then \
				${ECHO_MSG} "     >> No directory for $$prog.  Skipping.."; \
			else \
				if [ X${USE_PACKAGE_DEPENDS} != "X" ]; then \
					subpkgfile=`(cd $$dir; ${MAKE} $$depends_args -V PKGFILE)`; \
					if [ -r "$${subpkgfile}" -a "$$target" = "${DEPENDS_TARGET}" ]; then \
						${ECHO_MSG} "===>   Installing existing package $${subpkgfile}"; \
						${PKG_ADD} $${subpkgfile}; \
					else \
					  (cd $$dir; ${MAKE} $$submake_args $$target $$depends_args) ; \
					fi; \
				else \
					(cd $$dir; ${MAKE} $$submake_args $$target $$depends_args) ; \
				fi ; \
				${ECHO_MSG} "===>   Returning to build of ${PKGNAME}"; \
			fi; \
		fi; \
	done
.endif
.else
	@${DO_NADA}
.endif
.endif
.endfor

.PHONY: lib-depends
.if !target(lib-depends)
lib-depends:
.if defined(LIB_DEPENDS) && !defined(NO_DEPENDS)
	@for i in ${LIB_DEPENDS}; do \
		lib=$${i%%:*}; \
		case $$lib in \
			*.*.*)	pattern="`${ECHO_CMD} $$lib | ${SED} -e 's/\./\\\\./g'`" ;;\
			*.*)	pattern="$${lib%%.*}\.$${lib#*.}" ;;\
			*)	pattern="$$lib" ;;\
		esac; \
		dir=$${i#*:}; \
		target=$${i##*:}; \
		if ${TEST} $$dir = $$target; then \
			target="${DEPENDS_TARGET}"; \
			depends_args="${DEPENDS_ARGS}"; \
		else \
			dir=$${dir%%:*}; \
		fi; \
		${ECHO_MSG} -n "===>   ${PKGNAME} depends on shared library: $$lib"; \
		if ${LDCONFIG} -r | ${GREP} -vwF -e "${PKGCOMPATDIR}" | ${GREP} -qwE -e "-l$$pattern"; then \
			${ECHO_MSG} " - found"; \
			if [ ${_DEPEND_ALWAYS} = 1 ]; then \
				${ECHO_MSG} "       (but building it anyway)"; \
				notfound=1; \
			else \
				notfound=0; \
			fi; \
		else \
			${ECHO_MSG} " - not found"; \
			notfound=1; \
		fi; \
		if [ $$notfound != 0 ]; then \
			${ECHO_MSG} "===>    Verifying $$target for $$lib in $$dir"; \
			if [ ! -d "$$dir" ]; then \
				${ECHO_MSG} "     >> No directory for $$lib.  Skipping.."; \
			else \
				if [ X${USE_PACKAGE_DEPENDS} != "X" ]; then \
					subpkgfile=`(cd $$dir; ${MAKE} $$depends_args -V PKGFILE)`; \
					if [ -r "$${subpkgfile}" -a "$$target" = "${DEPENDS_TARGET}" ]; then \
						${ECHO_MSG} "===>   Installing existing package $${subpkgfile}"; \
						${PKG_ADD} $${subpkgfile}; \
					else \
					  (cd $$dir; ${MAKE} -DINSTALLS_DEPENDS $$target $$depends_args) ; \
					fi; \
				else \
					(cd $$dir; ${MAKE} -DINSTALLS_DEPENDS $$target $$depends_args) ; \
				fi ; \
				${ECHO_MSG} "===>   Returning to build of ${PKGNAME}"; \
				if ! ${LDCONFIG} -r | ${GREP} -vwF -e "${PKGCOMPATDIR}" | ${GREP} -qwE -e "-l$$pattern"; then \
					${ECHO_MSG} "Error: shared library \"$$lib\" does not exist"; \
					${FALSE}; \
				fi; \
			fi; \
		fi; \
	done
.endif
.endif

.PHONY: misc-depends
.if !target(misc-depends)
misc-depends:
.if defined(DEPENDS)
.if !defined(NO_DEPENDS)
	@for dir in ${DEPENDS}; do \
		if ${EXPR} "$$dir" : '.*:' > /dev/null; then \
			target=`${ECHO_CMD} $$dir | ${SED} -e 's/.*://'`; \
			dir=`${ECHO_CMD} $$dir | ${SED} -e 's/:.*//'`; \
		else \
			target="${DEPENDS_TARGET}"; \
			depends_args="${DEPENDS_ARGS}"; \
		fi; \
		${ECHO_MSG} "===>   ${PKGNAME} depends on: $$dir"; \
		${ECHO_MSG} "===>    Verifying $$target for $$dir"; \
		if [ ! -d $$dir ]; then \
			${ECHO_MSG} "     >> No directory for $$dir.  Skipping.."; \
		else \
			(cd $$dir; ${MAKE} $$target $$depends_args) ; \
		fi \
	done
	@${ECHO_MSG} "===>   Returning to build of ${PKGNAME}"
.endif
.else
	@${DO_NADA}
.endif
.endif

.endif

# Dependency lists: both build and runtime, recursive.  Print out directory names.

.PHONY: all-depends-list
all-depends-list:
.if defined(_ONG_REEXEC)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.elif defined(EXTRACT_DEPENDS) || defined(PATCH_DEPENDS) || defined(FETCH_DEPENDS) || defined(BUILD_DEPENDS) || defined(LIB_DEPENDS) || defined(RUN_DEPENDS) || defined(DEPENDS)
	@${ALL-DEPENDS-LIST}
.else
	@${DO_NADA}
.endif

.if defined(_ONG_REEXEC)
ALL-DEPENDS-LIST= \
	${ECHO_MSG} "${PKGNAME}: configuration error." >&2; ${FALSE}
.else
ALL-DEPENDS-LIST= \
	checked="${PARENT_CHECKED}"; \
	for dir in $$(${ECHO_CMD} "${EXTRACT_DEPENDS} ${PATCH_DEPENDS} ${FETCH_DEPENDS} ${BUILD_DEPENDS} ${LIB_DEPENDS} ${RUN_DEPENDS}" | ${SED} -e 'y/ /\n/' | ${CUT} -f 2 -d ':') $$(${ECHO_CMD} ${DEPENDS} | ${SED} -e 'y/ /\n/' | ${CUT} -f 1 -d ':'); do \
		if [ -d $$dir ]; then \
			if (${ECHO_CMD} $$checked | ${GREP} -qwv "$$dir"); then \
				child=$$(cd $$dir; ${MAKE} PARENT_CHECKED="$$checked" all-depends-list); \
				for d in $$child; do ${ECHO_CMD} $$d; done; \
				${ECHO_CMD} $$dir; \
				checked="$$dir $$child $$checked"; \
			fi; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done | ${SORT} -u
.endif

.PHONY: clean-depends
.if !target(clean-depends)
clean-depends:
.if defined(_ONG_REEXEC)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.else
	@for dir in $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} NOCLEANDEPENDS=yes clean); \
	done
.endif
.endif

.PHONY: deinstall-depends
.if !target(deinstall-depends)
deinstall-depends:
.if defined(_ONG_REEXEC)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.else
	@for dir in $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} deinstall); \
	done
.endif
.endif

.PHONY: fetch-recursive
.if !target(fetch-recursive)
fetch-recursive:
.if defined(_ONG_REEXEC)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.else
	@${ECHO_MSG} "===> Fetching all distfiles for ${PKGNAME} and dependencies"
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} fetch); \
	done
.endif
.endif

.PHONY: fetch-recursive-list
.if !target(fetch-recursive-list)
fetch-recursive-list:
.if defined(_ONG_REEXEC)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.else
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} fetch-list); \
	done
.endif
.endif

.PHONY: fetch-required
.if !target(fetch-required)
fetch-required: fetch
	@${ECHO_MSG} "===> Fetching all required distfiles for ${PKGNAME} and dependencies"
.for deptype in EXTRACT PATCH FETCH BUILD RUN
.if defined(${deptype}_DEPENDS)
.if !defined(NO_DEPENDS)
	@for i in ${${deptype}_DEPENDS}; do \
		prog=`${ECHO_CMD} $$i | ${CUT} -f 1 -d ':'`; \
		dir=`${ECHO_CMD} $$i | ${CUT} -f 2-999 -d ':'`; \
		if ${EXPR} "$$dir" : '.*:' > /dev/null; then \
			dir=`${ECHO_CMD} $$dir | ${CUT} -f 1 -d ':'`; \
			if ${EXPR} "$$prog" : \\/ >/dev/null; then \
				if [ ! -e "$$prog" ]; then \
					(cd $$dir; ${MAKE} fetch); \
				fi; \
			fi; \
		else \
			(cd $$dir; \
			if ! ${PKG_INFO} -e `${MAKE} -V PKGNAME`; then \
				${MAKE} fetch; \
			fi );  \
		fi; \
	done
.endif
.endif
.endfor
.endif

.PHONY: fetch-required-list
.if !target(fetch-required-list)
fetch-required-list: fetch-list
.for deptype in EXTRACT PATCH FETCH BUILD RUN
.if defined(${deptype}_DEPENDS)
.if !defined(NO_DEPENDS)
	@for i in ${${deptype}_DEPENDS}; do \
		prog=`${ECHO_CMD} $$i | ${CUT} -f 1 -d ':'`; \
		dir=`${ECHO_CMD} $$i | ${CUT} -f 2-999 -d ':'`; \
		if ${EXPR} "$$dir" : '.*:' > /dev/null; then \
			dir=`${ECHO_CMD} $$dir | ${CUT} -f 1 -d ':'`; \
			if ${EXPR} "$$prog" : \\/ >/dev/null; then \
				if [ ! -e "$$prog" ]; then \
					(cd $$dir; ${MAKE} fetch-list); \
				fi; \
			fi; \
		else \
			(cd $$dir; \
			if ! ${PKG_INFO} -e `${MAKE} -V PKGNAME`; then \
				${MAKE} fetch-list; \
			fi );  \
		fi; \
	done
.endif
.endif
.endfor
.endif

.PHONY: checksum-recursive
.if !target(checksum-recursive)
checksum-recursive:
.if defined(_ONG_REEXEC)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.else
	@${ECHO_MSG} "===> Fetching and checking checksums for ${PKGNAME} and dependencies"
	@for dir in ${.CURDIR} $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} checksum); \
	done
.endif
.endif

# Dependency lists: build and runtime.  Print out directory names.

.PHONY: build-depends-list
build-depends-list:
.if defined(EXTRACT_DEPENDS) || defined(PATCH_DEPENDS) || defined(FETCH_DEPENDS) || defined(BUILD_DEPENDS) || defined(LIB_DEPENDS) || defined(DEPENDS)
	@${BUILD-DEPENDS-LIST}
.endif

BUILD-DEPENDS-LIST= \
	for dir in $$(${ECHO_CMD} "${EXTRACT_DEPENDS} ${PATCH_DEPENDS} ${FETCH_DEPENDS} ${BUILD_DEPENDS} ${LIB_DEPENDS}" | ${TR} '\040' '\012' | ${SED} -e 's/^[^:]*://' -e 's/:.*//' | ${SORT} -u) $$(${ECHO_CMD} ${DEPENDS} | ${TR} '\040' '\012' | ${SED} -e 's/:.*//' | ${SORT} -u); do \
		if [ -d $$dir ]; then \
			${ECHO_CMD} $$dir; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done | ${SORT} -u

.PHONY: run-depends-list
run-depends-list:
.if defined(LIB_DEPENDS) || defined(RUN_DEPENDS) || defined(DEPENDS)
	@${RUN-DEPENDS-LIST}
.endif

RUN-DEPENDS-LIST= \
	for dir in $$(${ECHO_CMD} "${LIB_DEPENDS} ${RUN_DEPENDS}" | ${SED} -e 'y/ /\n/' | ${CUT} -f 2 -d ':' | ${SORT} -u) $$(${ECHO_CMD} ${DEPENDS} | ${SED} -e 'y/ /\n/' | ${CUT} -f 1 -d ':' | ${SORT} -u); do \
		if [ -d $$dir ]; then \
			${ECHO_CMD} $$dir; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done | ${SORT} -u

# Package (recursive runtime) dependency list.  Print out both directory names
# and package names.

.PHONY: package-depends-list
package-depends-list:
.if defined(CHILD_DEPENDS) || defined(LIB_DEPENDS) || defined(RUN_DEPENDS) || defined(DEPENDS)
	@${PACKAGE-DEPENDS-LIST}
.endif

PACKAGE-DEPENDS-LIST?= \
	if [ "${CHILD_DEPENDS}" ]; then \
		installed=$$(${PKG_INFO} -qO ${PKGORIGIN} 2>/dev/null || \
			${TRUE}); \
		if [ "$$installed" ]; then \
			break; \
		fi; \
		if [ -z "$$installed" ]; then \
			installed="${PKGNAME}"; \
		fi; \
		for pkgname in $$installed; do \
			${ECHO_CMD} "$$pkgname ${.CURDIR} ${PKGORIGIN}"; \
		done; \
	fi; \
	checked="${PARENT_CHECKED}"; \
	for dir in $$(${ECHO_CMD} "${LIB_DEPENDS} ${RUN_DEPENDS}" | ${SED} -e 'y/ /\n/' | ${CUT} -f 2 -d ':') $$(${ECHO_CMD} ${DEPENDS} | ${SED} -e 'y/ /\n/' | ${CUT} -f 1 -d ':'); do \
		dir=$$(${REALPATH} $$dir); \
		if [ -d $$dir ]; then \
			if (${ECHO_CMD} $$checked | ${GREP} -qwv "$$dir"); then \
				childout=$$(cd $$dir; ${MAKE} CHILD_DEPENDS=yes PARENT_CHECKED="$$checked" package-depends-list); \
				set -- $$childout; \
				childdir=""; \
				while [ $$\# != 0 ]; do \
					childdir="$$childdir $$2"; \
					${ECHO_CMD} "$$1 $$2 $$3"; \
					shift 3; \
				done; \
				checked="$$dir $$childdir $$checked"; \
			fi; \
		else \
			${ECHO_MSG} "${PKGNAME}: \"$$dir\" non-existent -- dependency list incomplete" >&2; \
		fi; \
	done

# Print out package names.

.PHONY: package-depends
package-depends:
.if ${OSVERSION} >= 460102 || exists(${LOCALBASE}/sbin/pkg_info)
	@${PACKAGE-DEPENDS-LIST} | ${AWK} '{print $$1":"$$3}'
.else
	@${PACKAGE-DEPENDS-LIST} | ${AWK} '{print $$1}'
.endif

# Build packages for port and dependencies

.PHONY: package-recursive
package-recursive: package
.if defined(_ONG_REEXEC)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.TARGET}
.else
	@for dir in $$(${ALL-DEPENDS-LIST}); do \
		(cd $$dir; ${MAKE} package-noinstall); \
	done
.endif

################################################################
# Everything after here are internal targets and really
# shouldn't be touched by anybody but the release engineers.
################################################################

# This target generates an index entry suitable for aggregation into
# a large index.  Format is:
#
# distribution-name|port-path|installation-prefix|comment| \
#  description-file|maintainer|categories|build deps|run deps|www site

.PHONY: describe
.if !target(describe)
describe:
.if defined(_ONG_REEXEC)
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS}  ${.TARGET}
.else
	@${ECHO_CMD} -n "${PKGNAME}|${.CURDIR}|${PREFIX}|"
.if defined(COMMENT)
	@${ECHO_CMD} -n ${COMMENT:Q}
.else
	@${ECHO_CMD} -n '** No Description'
.endif
	@${PERL5} -e ' \
		if ( -f q{${DESCR}} ) { \
			print q{|${DESCR}}; \
		} else { \
			print q{|/dev/null}; \
		} \
		print q{|${MAINTAINER}|${CATEGORIES}|}; \
		@edirs = map((split /:/)[1], split(q{ }, q{${EXTRACT_DEPENDS}})); \
		@pdirs = map((split /:/)[1], split(q{ }, q{${PATCH_DEPENDS}})); \
		@fdirs = map((split /:/)[1], split(q{ }, q{${FETCH_DEPENDS}})); \
		@bdirs = map((split /:/)[1], split(q{ }, q{${BUILD_DEPENDS}})); \
		@rdirs = map((split /:/)[1], split(q{ }, q{${RUN_DEPENDS}})); \
		@ddirs = map((split /:/)[0], split(q{ }, q{${DEPENDS}})); \
		@ldirs = map((split /:/)[1], split(q{ }, q{${LIB_DEPENDS}})); \
		for my $$i (\@edirs, \@pdirs, \@fdirs, \@bdirs, \@rdirs, \@ddirs, \@ldirs) { \
			my @dirs = @$$i; \
			@$$i = (); \
			for (@dirs) { \
				if (-d $$_) { \
					push @$$i, $$_; \
				} else { \
					print STDERR qq{${PKGNAME}: \"$$_\" non-existent -- dependency list incomplete\n}; \
					exit(1); \
				} \
			} \
		} \
		for (@edirs, @ddirs) { \
			$$xe{$$_} = 1; \
		} \
		print join(q{ }, sort keys %xe), q{|}; \
		for (@pdirs, @ddirs) { \
			$$xp{$$_} = 1; \
		} \
		print join(q{ }, sort keys %xp), q{|}; \
		for (@fdirs, @ddirs) { \
			$$xf{$$_} = 1; \
		} \
		print join(q{ }, sort keys %xf), q{|}; \
		for (@bdirs, @ddirs, @ldirs) { \
			$$xb{$$_} = 1; \
		} \
		print join(q{ }, sort keys %xb), q{|}; \
		for (@rdirs, @ddirs, @ldirs) { \
			$$xr{$$_} = 1; \
		} \
		print join(q{ }, sort keys %xr), q{|}; \
		if (open(DESCR, q{${DESCR}})) { \
			while (<DESCR>) { \
				if (/^WWW:\s+(\S+)/) { \
					print $$1; \
					last; \
				} \
			} \
		} \
		print qq{\n};'
.endif
.endif

.PHONY: www-site
.if !target(www-site)
www-site:
.if exists(${DESCR})
	@${GREP} '^WWW:[ 	]' ${DESCR} | ${AWK} '{print $$2}' | ${HEAD} -1
.else
	@${ECHO_CMD}
.endif
.endif

.PHONY: readmes
.if !target(readmes)
readmes:	readme
.endif

.PHONY: readme
.if !target(readme)
readme:
	@${RM} -f ${.CURDIR}/README.html
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} ${.CURDIR}/README.html
.endif

${.CURDIR}/README.html:
	@${ECHO_MSG} "===>   Creating README.html for ${PKGNAME}"
	@__softMAKEFLAGS='${__softMAKEFLAGS:S/'/'\''/g}'; \
	${SED} -e 's|%%PORT%%|'$$(${ECHO_CMD} ${.CURDIR} | \
							  ${SED} -e 's|.*/\([^/]*/[^/]*\)$$|\1|')'|g' \
			-e 's|%%PKG%%|${PKGNAME}|g' \
			-e 's|%%COMMENT%%|'"$$(${ECHO_CMD} ${COMMENT:Q})"'|' \
			-e '/%%COMMENT%%/d' \
			-e 's|%%DESCR%%|'"$$(${ECHO_CMD} ${DESCR} | \
								 ${SED} -e 's|${.CURDIR}/||')"'|' \
			-e 's|%%EMAIL%%|'"$$(${ECHO_CMD} "${MAINTAINER}" | \
								 ${SED} -e 's/([^)]*)//;s/.*<//;s/>.*//')"'|g' \
			-e 's|%%MAINTAINER%%|${MAINTAINER}|g' \
			-e 's|%%WEBSITE%%|'"$$(cd ${.CURDIR} && eval ${MAKE} ${_ONG_MAKEFLAGS} \
					$${__softMAKEFLAGS} pretty-print-www-site)"'|' \
			-e 's|%%BUILD_DEPENDS%%|'"$$(cd ${.CURDIR} && eval ${MAKE} ${_ONG_MAKEFLAGS} \
					$${__softMAKEFLAGS} pretty-print-build-depends-list)"'|' \
			-e 's|%%RUN_DEPENDS%%|'"$$(cd ${.CURDIR} && eval ${MAKE} ${_ONG_MAKEFLAGS} \
					$${__softMAKEFLAGS} pretty-print-run-depends-list)"'|' \
			-e 's|%%TOP%%|'"$$(${ECHO_CMD} ${CATEGORIES} | \
							   ${SED} -e 's| .*||' -e 's|[^/]*|..|g')"'/..|' \
		${TEMPLATES}/README.port >> $@

# The following two targets require an up-to-date INDEX in ${PORTSDIR}

.PHONY: pretty-print-build-depends-list
.if !target(pretty-print-build-depends-list)
pretty-print-build-depends-list:
.if defined(EXTRACT_DEPENDS) || defined(PATCH_DEPENDS) || \
	defined(FETCH_DEPENDS) || defined(BUILD_DEPENDS) || \
	defined(LIB_DEPENDS) || defined(DEPENDS)
	@${ECHO_CMD} -n 'This port requires package(s) "'
	@${ECHO_CMD} -n `${GREP} '^${PKGNAME}|' ${PORTSDIR}/${INDEXFILE} | ${AWK} -F\| '{print $$8;}'`
	@${ECHO_CMD} '" to build.'
.endif
.endif

.PHONY: pretty-print-run-depends-list
.if !target(pretty-print-run-depends-list)
pretty-print-run-depends-list:
.if defined(RUN_DEPENDS) || defined(LIB_DEPENDS) || defined(DEPENDS)
	@${ECHO_CMD} -n 'This port requires package(s) "'
	@${ECHO_CMD} -n `${GREP} '^${PKGNAME}|' ${PORTSDIR}/${INDEXFILE} | ${AWK} -F\| '{print $$9;}'`
	@${ECHO_CMD} '" to run.'
.endif
.endif

# Generate packing list.  Also tests to make sure all required package
# files exist.

.PHONY: generate-plist
.if !target(generate-plist)
generate-plist:
	@${ECHO_MSG} "===>   Generating temporary packing list"
	@${MKDIR} `${DIRNAME} ${TMPPLIST}`
	@if [ ! -f ${DESCR} ]; then ${ECHO_CMD} "** Missing pkg-descr for ${PKGNAME}."; exit 1; fi
	@>${TMPPLIST}
	@for file in ${PLIST_FILES}; do \
		${ECHO_CMD} $${file} | ${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} >> ${TMPPLIST}; \
	done
	@for man in ${__MANPAGES}; do \
		${ECHO_CMD} $${man} >> ${TMPPLIST}; \
	done
.for _PREFIX in ${PREFIX}
.if ${_TMLINKS:M${_PREFIX}*}x != x
	@for i in ${_TMLINKS:M${_PREFIX}*:S|^${_PREFIX}/||}; do \
		${ECHO_CMD} "$$i" >> ${TMPPLIST}; \
	done
.endif
.if ${_TMLINKS:N${_PREFIX}*}x != x
	@${ECHO_CMD} @cwd / >> ${TMPPLIST}
	@for i in ${_TMLINKS:N${_PREFIX}*:S|^/||}; do \
		${ECHO_CMD} "$$i" >> ${TMPPLIST}; \
	done
	@${ECHO_CMD} '@cwd ${PREFIX}' >> ${TMPPLIST}
.endif
	@for i in $$(${ECHO_CMD} ${__MANPAGES} ${_TMLINKS:M${_PREFIX}*:S|^${_PREFIX}/||} ' ' | ${SED} -E -e 's|man([1-9ln])/([^/ ]+) |cat\1/\2 |g'); do \
		${ECHO_CMD} "@unexec rm -f %D/$${i%.gz} %D/$${i%.gz}.gz" >> ${TMPPLIST}; \
	done
.if ${XFREE86_HTML_MAN:L} == "yes"
.for mansect in 1 2 3 4 5 6 7 8 9 L N
.for man in ${MAN${mansect}}
	@${ECHO_CMD} lib/X11/doc/html/${man}.html >> ${TMPPLIST}
.endfor
.endfor
	@${ECHO_CMD} "@unexec %D/bin/mkhtmlindex %D/lib/X11/doc/html" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec %D/bin/mkhtmlindex %D/lib/X11/doc/html" >> ${TMPPLIST}
.if defined(MLINKS)
	@${ECHO_CMD} ${MLINKS} | ${AWK} \
	'{ for (i=1; i<=NF; i++) { \
		if (i % 2 == 0) { printf "lib/X11/doc/html/%s.html\n", $$i } \
	} }' >> ${TMPPLIST}
.endif
.endif
.endfor
	@if [ -f ${PLIST} ]; then \
		${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${PLIST} >> ${TMPPLIST}; \
	fi
.for dir in ${PLIST_DIRS}
	@${ECHO_CMD} ${dir} | ${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} | ${SED} -e 's,^,@dirrm ,' >> ${TMPPLIST}
.endfor
.if defined(INSTALLS_SHLIB) && !defined(INSTALL_AS_USER)
	@${ECHO_CMD} "@exec ${LDCONFIG} -m ${LDCONFIG_PLIST}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LDCONFIG} -R" >> ${TMPPLIST}
.elif defined(INSTALLS_SHLIB)
	@${ECHO_CMD} "@exec ${LDCONFIG} -m ${LDCONFIG_PLIST} || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LDCONFIG} -R || ${TRUE}" >> ${TMPPLIST}
.endif
.if !defined(NO_FILTER_SHLIBS)
.if (${PORTOBJFORMAT} == "aout")
	@${SED} -e 's,\(/lib.*\.so\.[0-9]*\)$$,\1.0,' ${TMPPLIST} > ${TMPPLIST}.tmp
.else
	@${SED} -e 's,\(/lib.*\.so\.[0-9]*\)\.[0-9]*$$,\1,' ${TMPPLIST} > ${TMPPLIST}.tmp
.endif
	@${MV} -f ${TMPPLIST}.tmp ${TMPPLIST}
.endif
.endif

${TMPPLIST}:
	@cd ${.CURDIR} && ${MAKE} ${_ONG_MAKEFLAGS} ${__softMAKEFLAGS} generate-plist

.PHONY: add-plist-docs
.if !target(add-plist-docs)
add-plist-docs:
.if defined(PORTDOCS)
	@if ${EGREP} -qe '^@cw?d' ${TMPPLIST} && \
		[ "`${SED} -En -e '/^@cw?d[ 	]*/s,,,p' ${TMPPLIST} | ${TAIL} -n 1`" != "${PREFIX}" ]; then \
		${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}; \
	fi
	@${FIND} -P ${PORTDOCS:S/^/${DESTDIR}${DOCSDIR}\//} ! -type d 2>/dev/null | \
		${SED} -ne 's,^${DESTDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -P -d ${PORTDOCS:S/^/${DESTDIR}${DOCSDIR}\//} -type d 2>/dev/null | \
		${SED} -ne 's,^${DESTDIR}${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}
	@if [ -d "${DESTDIR}${DOCSDIR}" ]; then \
		${ECHO_CMD} "@unexec rmdir %D/${DOCSDIR:S,^${PREFIX}/,,} 2>/dev/null || true" >> ${TMPPLIST}; \
	fi
.else
	@${DO_NADA}
.endif
.endif

.PHONY: add-plist-info
.if !target(add-plist-info)
add-plist-info:
# Process GNU INFO files at package install/deinstall time
.for i in ${INFO}
	@${ECHO_CMD} "@unexec install-info --delete %D/${INFO_PATH}/$i.info %D/${INFO_PATH}/dir" \
		>> ${TMPPLIST}
	@${LS} ${DESTDIR}${PREFIX}/${INFO_PATH}/$i.info* | ${SED} -e s:${DESTDIR}${PREFIX}/::g >> ${TMPPLIST}
	@${ECHO_CMD} "@exec install-info %D/${INFO_PATH}/$i.info %D/${INFO_PATH}/dir" \
		>> ${TMPPLIST}
.endfor
.if !defined(NO_MTREE) && defined(INFO)
	@${ECHO_CMD} "@unexec if [ -f %D/${INFO_PATH}/dir ]; then if sed -e '1,/Menu:/d' %D/${INFO_PATH}/dir | grep -q '^[*] '; then true; else rm %D/${INFO_PATH}/dir; fi; fi" >> ${TMPPLIST}
.else
	@${DO_NADA}
.endif
.endif

# Compress (or uncompress) and symlink manpages.
.PHONY: compress-man
.if !target(compress-man)
compress-man:
.if defined(_MANPAGES) || defined(_MLINKS)
.if ${MANCOMPRESSED} == yes && defined(NOMANCOMPRESS)
	@${ECHO_MSG} "===>   Uncompressing manual pages for ${PKGNAME}"
	@_manpages='${_MANPAGES:S/^/${DESTDIR}/:S/'/'\''/g}' && [ "$${_manpages}" != "" ] && ( eval ${GUNZIP_CMD} $${_manpages} ) || ${TRUE}
.elif ${MANCOMPRESSED} == no && !defined(NOMANCOMPRESS)
	@${ECHO_MSG} "===>   Compressing manual pages for ${PKGNAME}"
	@_manpages='${_MANPAGES:S/^/${DESTDIR}/:S/'/'\''/g}' && [ "$${_manpages}" != "" ] && ( eval ${GZIP_CMD} $${_manpages} ) || ${TRUE}
.endif
.if defined(_MLINKS)
	@set ${_MLINKS}; \
	while :; do \
		[ $$# -eq 0 ] && break || ${TRUE}; \
		${RM} -f ${DESTDIR}$${2%.gz}; ${RM} -f ${DESTDIR}$$2.gz; \
		${LN} -fs `${ECHO_CMD} $$1 $$2 | ${AWK} '{ \
					z=split($$1, a, /\//); x=split($$2, b, /\//); \
					while (a[i] == b[i]) i++; \
					for (q=i; q<x; q++) printf "../"; \
					for (; i<z; i++) printf a[i] "/"; printf a[z]; }'` ${DESTDIR}$$2; \
		shift; shift; \
	done
.endif
.else
	@${DO_NADA}
.endif
.endif

# Fake installation of package so that user can pkg_delete it later.
# Also, make sure that an installed port is recognized correctly in
# accordance to the @pkgdep directive in the packing lists

.PHONY: fake-pkg
.if !target(fake-pkg)
fake-pkg:
.if !defined(NO_PKG_REGISTER)
	@if [ ! -d ${_PKG_DBDIR} ]; then ${RM} -f ${_PKG_DBDIR}; ${MKDIR} ${_PKG_DBDIR}; fi
	@${RM} -f /tmp/${PKGNAME}-required-by
.if defined(FORCE_PKG_REGISTER)
	@if [ -e ${_PKG_DBDIR}/${PKGNAME}/+REQUIRED_BY ]; then \
		${CP} ${_PKG_DBDIR}/${PKGNAME}/+REQUIRED_BY /tmp/${PKGNAME}-required-by; \
	fi
	@${RM} -rf ${_PKG_DBDIR}/${PKGNAME}
.endif
	@if [ ! -d ${_PKG_DBDIR}/${PKGNAME} ]; then \
		${ECHO_MSG} "===>   Registering installation for ${PKGNAME}"; \
		${MKDIR} ${_PKG_DBDIR}/${PKGNAME}; \
		${PKG_CMD} ${PKG_ARGS} -O ${PKGFILE} > ${_PKG_DBDIR}/${PKGNAME}/+CONTENTS; \
		${CP} ${DESCR} ${_PKG_DBDIR}/${PKGNAME}/+DESC; \
		${ECHO_CMD} ${COMMENT:Q} > ${_PKG_DBDIR}/${PKGNAME}/+COMMENT; \
		if [ -f ${PKGINSTALL} ]; then \
			${CP} ${PKGINSTALL} ${_PKG_DBDIR}/${PKGNAME}/+INSTALL; \
		fi; \
		if [ -f ${PKGDEINSTALL} ]; then \
			${CP} ${PKGDEINSTALL} ${_PKG_DBDIR}/${PKGNAME}/+DEINSTALL; \
		fi; \
		if [ -f ${PKGREQ} ]; then \
			${CP} ${PKGREQ} ${_PKG_DBDIR}/${PKGNAME}/+REQUIRE; \
		fi; \
		if [ -f ${PKGMESSAGE} ]; then \
			${CP} ${PKGMESSAGE} ${_PKG_DBDIR}/${PKGNAME}/+DISPLAY; \
		fi; \
		for dep in `${SETENV} PKG_DBDIR=${_PKG_DBDIR} ${PKG_INFO} -qf ${PKGNAME} | ${GREP} -w ^@pkgdep | ${AWK} '{print $$2}' | ${SORT} -u`; do \
			if [ -d ${_PKG_DBDIR}/$$dep -a -z `${ECHO_CMD} $$dep | ${GREP} -E ${PKG_IGNORE_DEPENDS}` ]; then \
				if ! ${GREP} ^${PKGNAME}$$ ${_PKG_DBDIR}/$$dep/+REQUIRED_BY \
					>/dev/null 2>&1; then \
					${ECHO_CMD} ${PKGNAME} >> ${_PKG_DBDIR}/$$dep/+REQUIRED_BY; \
				fi; \
			fi; \
		done; \
	fi
.if !defined(NO_MTREE)
	@if [ -f ${MTREE_FILE} ]; then \
		${CP} ${MTREE_FILE} ${_PKG_DBDIR}/${PKGNAME}/+MTREE_DIRS; \
	fi
.endif
	@if [ -e /tmp/${PKGNAME}-required-by ]; then \
		${CAT} /tmp/${PKGNAME}-required-by >> ${_PKG_DBDIR}/${PKGNAME}/+REQUIRED_BY; \
		${RM} -f /tmp/${PKGNAME}-required-by; \
	fi
.else
	@${DO_NADA}
.endif
.endif

# Depend is generally meaningless for arbitrary ports, but if someone wants
# one they can override this.  This is just to catch people who've gotten into
# the habit of typing `make depend all install' as a matter of course.
#
.PHONY: depend
.if !target(depend)
depend:
.endif

# Same goes for tags
.PHONY: tags
.if !target(tags)
tags:
.endif

.if !defined(NOPRECIOUSMAKEVARS)
.for softvar in CKSUMFILES _MLINKS
.if defined(${softvar})
__softMAKEFLAGS+=      '${softvar}+=${${softvar}:S/'/'\''/g}'
.endif
.endfor
# These won't change, so we can pass them through the environment
.MAKEFLAGS: \
	ARCH="${ARCH:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OPSYS="${OPSYS:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OSREL="${OSREL:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OSVERSION="${OSVERSION:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	PORTOBJFORMAT="${PORTOBJFORMAT:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	SYSTEMVERSION="${SYSTEMVERSION:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}"
.endif

.if !target(config)
config:
.if !defined(OPTIONS)
	@${ECHO_MSG} "===> No options to configure"
.else
.if ${OPTIONSFILE} != ${_OPTIONSFILE}
	@${ECHO_MSG} "===> Using wrong configuration file ${_OPTIONSFILE}"
	@exit 1
.endif
.if ${UID} != 0 && !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>  Switching to root credentials to create `${DIRNAME} ${_OPTIONSFILE}`"
	@(${SU_CMD} "${SH} -c \"${MKDIR} `${DIRNAME} ${_OPTIONSFILE}` 2> /dev/null\"") || \
		(${ECHO_MSG} "===> Cannot create `${DIRNAME} ${_OPTIONSFILE}`, check permissions"; exit 1)
	@${ECHO_MSG} "===>  Returning to user credentials"
.else
	@(${MKDIR} `${DIRNAME} ${_OPTIONSFILE}` 2> /dev/null) || \
		(${ECHO_MSG} "===> Cannot create `${DIRNAME} ${_OPTIONSFILE}`, check permissions"; exit 1)
.endif
	-@if [ -e ${_OPTIONSFILE} ]; then \
		. ${_OPTIONSFILE}; \
	fi; \
	set ${OPTIONS} XXX; \
	while [ $$# -gt 3 ]; do \
		OPTIONSLIST="$${OPTIONSLIST} $$1"; \
		defaultval=$$3; \
		withvar=WITH_$$1; \
		withoutvar=WITHOUT_$$1; \
		withval=$$(eval ${ECHO_CMD} $$\{$${withvar}\}); \
		withoutval=$$(eval ${ECHO_CMD} $$\{$${withoutvar}\}); \
		if [ ! -z "$${withval}" ]; then \
			val=on; \
		elif [ ! -z "$${withoutval}" ]; then \
			val=off; \
		else \
			val=$$3; \
		fi; \
		DEFOPTIONS="$${DEFOPTIONS} $$1 \"$$2\" $${val}"; \
		shift 3; \
	done; \
	TMPOPTIONSFILE=$$(${MKTEMP} -t portoptions); \
	trap "${RM} -f $${TMPOPTIONSFILE}; exit 1" 1 2 3 5 10 13 15; \
	${SH} -c "${DIALOG} --checklist \"Options for ${PKGNAME:C/-([^-]+)$/ \1/}\" 21 70 15 $${DEFOPTIONS} 2> $${TMPOPTIONSFILE}"; \
	status=$$?; \
	if [ $${status} -ne 0 ] ; then \
		${RM} -f $${TMPOPTIONSFILE}; \
		${ECHO_MSG} "===> Options unchanged"; \
		exit 0; \
	fi; \
	if [ ! -e ${TMPOPTIONSFILE} ]; then \
		${ECHO_MSG} "===> No user-specified options to save for ${PKGNAME}"; \
		exit 0; \
	fi; \
	SELOPTIONS=$$(${CAT} $${TMPOPTIONSFILE}); \
	${RM} -f $${TMPOPTIONSFILE}; \
	TMPOPTIONSFILE=$$(${MKTEMP} -t portoptions); \
	trap "${RM} -f $${TMPOPTIONSFILE}; exit 1" 1 2 3 5 10 13 15; \
	${ECHO_CMD} "# This file is auto-generated by 'make config'." > $${TMPOPTIONSFILE}; \
	${ECHO_CMD} "# No user-servicable parts inside!" >> $${TMPOPTIONSFILE}; \
	${ECHO_CMD} "# Options for ${PKGNAME}" >> $${TMPOPTIONSFILE}; \
	${ECHO_CMD} "_OPTIONS_READ=${PKGNAME}" >> $${TMPOPTIONSFILE}; \
	for i in $${OPTIONSLIST}; do \
		${ECHO_CMD} $${SELOPTIONS} | ${GREP} -qw $${i}; \
		if [ $$? -eq 0 ]; then \
			${ECHO_CMD} WITH_$${i}=true >> $${TMPOPTIONSFILE}; \
		else \
			${ECHO_CMD} WITHOUT_$${i}=true >> $${TMPOPTIONSFILE}; \
		fi; \
	done; \
	if [ `${ID} -u` != 0 -a "x${INSTALL_AS_USER}" = "x" ]; then \
		${ECHO_MSG} "===>  Switching to root credentials to write ${_OPTIONSFILE}"; \
		${SU_CMD} "${CAT} $${TMPOPTIONSFILE} > ${_OPTIONSFILE}"; \
		${ECHO_MSG} "===>  Returning to user credentials"; \
	else \
		${CAT} $${TMPOPTIONSFILE} > ${_OPTIONSFILE}; \
	fi; \
	${RM} -f $${TMPOPTIONSFILE}
.endif
.endif

.if !target(showconfig)
showconfig:
.if defined(OPTIONS) && exists(${_OPTIONSFILE})
	@${ECHO_MSG} "===> The following configuration options are set for ${PKGNAME}:"
	-@if [ -e ${_OPTIONSFILE} ]; then \
		. ${_OPTIONSFILE}; \
	fi; \
	set ${OPTIONS} XXX; \
	while [ $$# -gt 3 ]; do \
		defaultval=$$3; \
		withvar=WITH_$$1; \
		withoutvar=WITHOUT_$$1; \
		withval=$$(eval ${ECHO_CMD} $$\{$${withvar}\}); \
		withoutval=$$(eval ${ECHO_CMD} $$\{$${withoutvar}\}); \
		if [ ! -z "$${withval}" ]; then \
			val=on; \
		elif [ ! -z "$${withoutval}" ]; then \
			val=off; \
		else \
			val="$$3 (default)"; \
		fi; \
		${ECHO_MSG} "     $$1=$${val} \"$$2\""; \
		shift 3; \
	done
.else
	@${ECHO_MSG} "===> No configuration options are set for this port"
.if defined(OPTIONS)
	@${ECHO_MSG} "	Use 'make config' to set default values"
.endif
.endif
.endif

.if !target(rmconfig)
rmconfig:
.if defined(OPTIONS) && exists(${_OPTIONSFILE})
	-@${ECHO_MSG} "===> Removing user-configured options for ${PKGNAME}"; \
	if [ `${ID} -u` != 0 -a "x${INSTALL_AS_USER}" = "x" ]; then \
		${ECHO_MSG} "===> Switching to root credentials to remove ${_OPTIONSFILE} and `${DIRNAME} ${_OPTIONSFILE}`"; \
		${SU_CMD} "${RM} -f ${_OPTIONSFILE} ; \
			${RMDIR} `${DIRNAME} ${_OPTIONSFILE}`"; \
		${ECHO_MSG} "===> Returning to user credentials"; \
	else \
		${RM} -f ${_OPTIONSFILE}; \
		${RMDIR} `${DIRNAME} ${_OPTIONSFILE}`; \
	fi
.else
	@${ECHO_MSG} "===> No user-specified options configured for ${PKGNAME}"
.endif
.endif
