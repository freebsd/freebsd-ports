PORTNAME=	tcl
DISTVERSION=	${TCL_VERSION}${TCL_RC}
PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	SF/tcl/Tcl/${TCL_VERSION}
PKGNAMESUFFIX=	${SHORT_TCL_VER}
DISTNAME=	${PORTNAME}${DISTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tool Command Language
WWW=		https://www.tcl.tk/

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libtommath.so:math/libtommath

USES=		compiler:c11 cpe localbase

OPTIONS_DEFINE=	TCLMAN TZDATA
OPTIONS_DEFAULT=TCLMAN TZDATA
OPTIONS_DEFINE_amd64=	DTRACE
OPTIONS_DEFAULT_amd64=	DTRACE
OPTIONS_DEFINE_powerpc64=	DTRACE
OPTIONS_DEFINE_powerpc64le=	DTRACE
OPTIONS_DEFAULT_powerpc64=	DTRACE
OPTIONS_DEFAULT_powerpc64le=	DTRACE
TCLMAN_DESC=	Install Tcl function manpages
TZDATA_DESC=	Install Tcl timezone data
OPTIONS_SUB=	yes

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}${TCL_VERSION}
WRKSRC_SUBDIR=	unix

ALL_TARGET=	binaries libraries doc
TEST_TARGET=	test-tcl
INSTALL_TARGET=	install-libraries \
		install-msgs \
		install-private-headers

USE_LDCONFIG=	${PREFIX}/lib/tcl${TCL_VER}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tcl${TCL_VER} \
		--with-system-libtommath
LDFLAGS+=	-Wl,-z,muldefs

TCL_VERSION=	9.0.2
TCL_VER=	${TCL_VERSION:R}
TCL_RC=
SHORT_TCL_VER=	${TCL_VER:S/.//}
MAN_SUFFIX=	${PKGBASE}

PLIST_SUB=	TCL_VER=${TCL_VER} \
		PKGNAMESUFFIX=${PKGNAMESUFFIX}

TCLMAN_INSTALL_TARGET=	install-doc
TZDATA_INSTALL_TARGET=	install-tzdata
DTRACE_CONFIGURE_ENABLE=	dtrace

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-symbols
INSTALL_TARGET+=install
.else
INSTALL_TARGET+=install-strip
.endif

.if ${PORT_OPTIONS:MDTRACE}
PLIST_SUB+=	DTRACE=""
.else
PLIST_SUB+=	DTRACE="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e \
	    's|@TCL_BUILD_LIB_SPEC@|@TCL_LIB_SPEC@|; \
	     s|@TCL_BUILD_STUB_LIB_SPEC@|@TCL_STUB_LIB_SPEC@|; \
	     s|@TCL_BUILD_STUB_LIB_PATH@|@TCL_STUB_LIB_PATH@|; \
	     s|@TCL_SRC_DIR@|${PREFIX}/include/tcl${TCL_VER}|' \
	     ${WRKSRC}/tclConfig.sh.in
	${REINPLACE_CMD} \
		-e 's|libtclstub.a|libtclstub${TCL_VER}.a|' \
		-e 's|-ltclstub|-ltclstub${TCL_VER}|' \
		-e 's|-O2||' \
		${WRKSRC}/configure
	${REINPLACE_CMD} \
		-e '/^INSTALL_PACKAGE_TARGETS/d' \
		-e '/^CONFIG_INSTALL_DIR/s|= .*$$|= $${SCRIPT_INSTALL_DIR}|' \
		-e 's|$$(LIB_INSTALL_DIR)/pkgconfig|${STAGEDIR}${PREFIX}/libdata/pkgconfig|g' \
		-e 's|pkgconfig/tcl.pc|pkgconfig/tcl${SHORT_TCL_VER}.pc|' \
		-e 's|strip -x|strip --strip-unneeded|' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} \
		-e '/Target=/s|.$$Section$$Suffix|$$Suffix.$$Section|' \
		${WRKSRC}/installManPage

post-install:
	${LN} -fs libtcl${TCL_VER}.so ${STAGEDIR}${PREFIX}/lib/libtcl${SHORT_TCL_VER}.so

.include <bsd.port.mk>
