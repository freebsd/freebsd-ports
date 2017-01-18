# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcl
PORTVERSION=	8.5.19
PORTREVISION=	1
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

OPTIONS_DEFINE=	TCLMAN TZDATA MODULES THREADS
OPTIONS_DEFAULT=MODULES THREADS
TCLMAN_DESC=	Install Tcl function manpages
TZDATA_DESC=	Install Tcl timezone data
MODULES_DESC=	Install Tcl common modules
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//:S/rc1//}/unix
ALL_TARGET=	all
INSTALL_TARGET=	install install-libraries
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
MODULES_VARS=	INSTALL_TARGET+=install-tm
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
