# Created by: jkh
# $FreeBSD$

PORTNAME=	tcl
DISTVERSION=	8.4.20
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	lang tcl
MASTER_SITES=	${MASTER_SITE_TCLTK} \
		SF/tcl/Tcl/${PORTVERSION}
MASTER_SITE_SUBDIR=	tcl8_4
DISTNAME=	${PORTNAME}${DISTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tool Command Language

LICENSE=	BSD

OPTIONS_DEFINE=	TCLMAN THREADS
OPTIONS_DEFAULT=THREADS
TCLMAN_DESC=	Install Tcl function manpages

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/unix

ALL_TARGET=	all
INSTALL_TARGET=	install install-libraries

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tcl${TCL_VER}
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}

TCL_VER=	8.4
SHORT_TCL_VER=	${TCL_VER:S/8./8/}
LATEST_LINK=	${PORTNAME}${SHORT_TCL_VER}
MAN_SUFFIX=	${LATEST_LINK}

MAKE_ENV=	SHORT_TCL_VER="${SHORT_TCL_VER}" \
		MAN_SUFFIX=.${MAN_SUFFIX} \
		LANG=C LC_ALL=C	# LANG=C is required for some of UTF-using tests

PLIST_SUB=	TCL_VER=${TCL_VER} \
		SHORT_TCL_VER=${SHORT_TCL_VER}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCLMAN}
INSTALL_TARGET+=install-doc
.include "${.CURDIR}/Makefile.man"
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
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

regression-test:	build
	cd ${WRKSRC} && LC_ALL=C ${MAKE} test

.include <bsd.port.mk>
