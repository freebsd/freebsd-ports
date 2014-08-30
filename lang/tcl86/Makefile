# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcl
PORTVERSION=	8.6.2
CATEGORIES=	lang
MASTER_SITES=	SF/tcl/Tcl/${PORTVERSION} \
		${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=tcl8_6
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tool Command Language

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	TCLMAN TZDATA MODULES THREADS
OPTIONS_DEFAULT=MODULES THREADS
TCLMAN_DESC=	Install Tcl function manpages
TZDATA_DESC=	Install Tcl timezone data
MODULES_DESC=	Install Tcl common modules

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/unix

ALL_TARGET=	all
INSTALL_TARGET=	install-strip install-libraries

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tcl${TCL_VER} \
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}

TCL_VER=	${PORTVERSION:R}
SHORT_TCL_VER=	${TCL_VER:S/.//}
MAN_SUFFIX=	${LATEST_LINK}

MAKE_ENV=	SHORT_TCL_VER=${SHORT_TCL_VER} \
		MAN_SUFFIX=.${MAN_SUFFIX} \
		LANG=C LC_ALL=C	# LANG=C is required for some of UTF-using tests

PLIST_SUB=	TCL_VER=${TCL_VER} \
		SHORT_TCL_VER=${SHORT_TCL_VER}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCLMAN}
INSTALL_TARGET+=install-doc
PLIST_SUB+=	MAN=""
.else
PLIST_SUB+=	MAN="@comment "
.endif

.if ${PORT_OPTIONS:MTZDATA}
PLIST_SUB+=	TZDATA=""
INSTALL_TARGET+=install-tzdata
.else
PLIST_SUB+=	TZDATA="@comment "
.endif

.if ${PORT_OPTIONS:MMODULES}
PLIST_SUB+=	MODULES=""
INSTALL_TARGET+=install-modules
.else
PLIST_SUB+=	MODULES="@comment "
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-threads
.else
CONFIGURE_ARGS+=--disable-threads
.endif

post-patch:
	${REINPLACE_CMD} -e \
	    's|@TCL_BUILD_LIB_SPEC@|@TCL_LIB_SPEC@|; \
	     s|@TCL_BUILD_STUB_LIB_SPEC@|@TCL_STUB_LIB_SPEC@|; \
	     s|@TCL_BUILD_STUB_LIB_PATH@|@TCL_STUB_LIB_PATH@|; \
	     s|@TCL_SRC_DIR@|${PREFIX}/include/tcl${TCL_VER}|' \
	     ${WRKSRC}/tclConfig.sh.in
.if !${PORT_OPTIONS:MTCLMAN}
	@${FIND} ${WRKSRC}/../pkgs -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
	    -e '/^install:/s|install-doc||'
.endif

post-configure:
	${REINPLACE_CMD} \
		-e 's,-DNO_MEMMOVE=1,,' -e 's,-DNO_STRING_H=1,,' \
		-e 's,^COMPAT_OBJS.*,,' ${WRKSRC}/Makefile

regression-test:	build
	cd ${WRKSRC} && LC_ALL=C ${MAKE} test

.include <bsd.port.mk>
