# Created by: gahr
# $FreeBSD$

PORTNAME=	tcl
DISTVERSION=	${TCL_VERSION}${TCL_RC}
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/tcl/Tcl/${TCL_VERSION} \
		TCLTK/tcl8_7
PKGNAMESUFFIX=	${SHORT_TCL_VER}
DISTNAME=	${PORTNAME}${DISTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tool Command Language

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler:c11 pathfix

OPTIONS_DEFINE=	TCLMAN TZDATA DEBUG
OPTIONS_DEFAULT=TCLMAN TZDATA
OPTIONS_DEFINE_amd64=	DTRACE
OPTIONS_DEFAULT_amd64=	DTRACE
TCLMAN_DESC=	Install Tcl function manpages
TZDATA_DESC=	Install Tcl timezone data
OPTIONS_SUB=	yes

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}${TCL_VERSION}
WRKSRC=		${PATCH_WRKSRC}/unix

ALL_TARGET=	binaries libraries doc
TEST_TARGET=	test-tcl
INSTALL_TARGET+=install-libraries \
		install-msgs \
		install-private-headers

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tcl${TCL_VER} \
		--enable-symbols

TCL_VERSION=	8.7a3
TCL_VER=	8.7
TCL_RC=
SHORT_TCL_VER=	${PORTVERSION:R:S/.//}
MAN_SUFFIX=	${PKGBASE}

MAKE_ENV=	SHORT_TCL_VER=${SHORT_TCL_VER} \
		MAN_SUFFIX=.${MAN_SUFFIX} \

PLIST_SUB=	TCL_VER=${TCL_VER} \
		PKGNAMESUFFIX=${PKGNAMESUFFIX}

TCLMAN_INSTALL_TARGET=	install-doc
TZDATA_INSTALL_TARGET=	install-tzdata
DEBUG_CONFIGURE_ENABLE=	symbols
DTRACE_CONFIGURE_ENABLE=	dtrace

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
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
	     ${PATCH_WRKSRC}/unix/tclConfig.sh.in

post-patch-TCLMAN-off:
	@${FIND} ${PATCH_WRKSRC}/pkgs -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
	    -e '/^install:/s|install-doc||'

post-configure:
	${REINPLACE_CMD} \
		-e 's,-DNO_MEMMOVE=1,,' -e 's,-DNO_STRING_H=1,,' \
		-e 's,^COMPAT_OBJS.*,,' ${WRKSRC}/Makefile
post-install:
	# Make sure users of USES=tcl:87 are able to look up the library
	${LN} -fs libtcl${TCL_VER}.so ${STAGEDIR}${PREFIX}/lib/libtcl${PKGNAMESUFFIX}.so
	${LN} -fs libtcl${PKGNAMESUFFIX}.so ${STAGEDIR}${PREFIX}/lib/libtcl${PKGNAMESUFFIX}.so.1
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tcl${TCL_VER}/doc
	${INSTALL_DATA} ${WRKSRC}/../doc/man.macros ${STAGEDIR}${PREFIX}/include/tcl${TCL_VER}/doc/man.macros

.include <bsd.port.mk>
