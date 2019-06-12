# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcl
PORTVERSION=	8.5.19
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	TCLTK/tcl8_5 \
		SF/tcl/Tcl/${PORTVERSION}
PKGNAMESUFFIX=	${SHORT_TCL_VER}
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tool Command Language

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Tcl/Tk 8.5 is nearing EOL, please consider switching to Tcl/Tk 8.6

OPTIONS_DEFINE=	TCLMAN TZDATA THREADS
OPTIONS_DEFAULT=TCLMAN TZDATA THREADS
TCLMAN_DESC=	Install Tcl function manpages
TZDATA_DESC=	Install Tcl timezone data
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//:S/rc1//}/unix
ALL_TARGET=	all
INSTALL_TARGET=	install-strip install-libraries install-tm
TEST_TARGET=	do-test

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tcl${TCL_VER}
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}

TCL_VER=	8.5
SHORT_TCL_VER=	${TCL_VER:S/8./8/}
MAN_SUFFIX=	${PORTNAME}${SHORT_TCL_VER}

MAKE_ENV=	SHORT_TCL_VER=${SHORT_TCL_VER} \
		MAN_SUFFIX=.${MAN_SUFFIX}

PLIST_SUB=	TCL_VER=${TCL_VER} \
		SHORT_TCL_VER=${SHORT_TCL_VER}

TCLMAN_VARS=	INSTALL_TARGET+=install-doc
THREADS_CONFIGURE_ENABLE=	threads
TZDATA_CONFIGURE_WITH=		tzdata

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

do-test:
	${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
