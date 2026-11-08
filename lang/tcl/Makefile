PORTNAME=	tcl
DISTVERSION=	9.1.0
CATEGORIES=	lang
MASTER_SITES=	SF/tcl/Tcl/${DISTVERSION}
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

WRKSRC=		${WRKDIR}/${PORTNAME}${DISTVERSION}
WRKSRC_SUBDIR=	unix

ALL_TARGET=	binaries libraries doc
TEST_TARGET=	test-tcl
INSTALL_TARGET=	install-libraries \
		install-msgs \
		install-private-headers

TCL_VER=	${DISTVERSION:R}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tcl${TCL_VER} \
		--with-system-libtommath
LDFLAGS+=	-Wl,-z,muldefs
PLIST_SUB+=	TCL_VER=${TCL_VER}

MAN_SUFFIX=	${PORTNAME}

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
	     s|@TCL_SRC_DIR@|${PREFIX}/lib/tcl${TCL_VER}|' \
	     ${WRKSRC}/tclConfig.sh.in
	${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	${REINPLACE_CMD} \
		-e '/^INSTALL_PACKAGE_TARGETS/d' \
		-e '/^CONFIG_INSTALL_DIR/s|= .*$$|= $${SCRIPT_INSTALL_DIR}|' \
		-e 's|$$(LIB_INSTALL_DIR)/pkgconfig|${STAGEDIR}${PREFIX}/libdata/pkgconfig|g' \
		-e 's|strip -x|strip --strip-unneeded|' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} \
		-e '/Target=/s|.$$Section$$Suffix|$$Suffix.$$Section|' \
		${WRKSRC}/installManPage

.include <bsd.port.mk>
