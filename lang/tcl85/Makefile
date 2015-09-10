# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcl
PORTVERSION=	8.5.18
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	TCLTK/tcl8_5 \
		SF/tcl/Tcl/${PORTVERSION}
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

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}/unix
ALL_TARGET=	all
INSTALL_TARGET=	install install-libraries

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tcl${TCL_VER}
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}

TCL_VER=	8.5
SHORT_TCL_VER=	${TCL_VER:S/8./8/}
MAN_SUFFIX=	${PORTNAME}${PKGNAMESUFFIX}

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

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if ${PORT_OPTIONS:MMODULES}
INSTALL_TARGET+=install-tm
PLIST_SUB+=	MODULES=""
.else
PLIST_SUB+=	MODULES="@comment "
.endif

.if ${PORT_OPTIONS:MTZDATA}
PLIST_SUB+=		TZDATA=""
CONFIGURE_ARGS+=--with-tzdata
INSTALL_TARGET+=install-tzdata
.else
PLIST_SUB+=		TZDATA="@comment "
CONFIGURE_ARGS+=--without-tzdata
.endif

post-patch:
	${REINPLACE_CMD} -e \
	    's|@TCL_BUILD_LIB_SPEC@|@TCL_LIB_SPEC@|; \
	     s|@TCL_BUILD_STUB_LIB_SPEC@|@TCL_STUB_LIB_SPEC@|; \
	     s|@TCL_BUILD_STUB_LIB_PATH@|@TCL_STUB_LIB_PATH@|; \
	     s|@TCL_SRC_DIR@|${PREFIX}/include/tcl${TCL_VER}|' \
	     ${WRKSRC}/tclConfig.sh.in

post-configure:
	${REINPLACE_CMD} \
		-e 's,-DNO_MEMMOVE=1,,' -e 's,-DNO_STRING_H=1,,' \
		-e 's,^COMPAT_OBJS.*,,' ${WRKSRC}/Makefile

post-install:
	${LN} -fs libtcl${SHORT_TCL_VER}.so.1.0 \
	    ${STAGEDIR}${PREFIX}/lib/libtcl${SHORT_TCL_VER}.so.1

regression-test:	build
	cd ${WRKSRC} && LC_ALL=C ${MAKE} test

.include <bsd.port.mk>
