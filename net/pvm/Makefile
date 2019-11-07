# Created by: Dima Sivachenko <dima@chg.ru>
# $FreeBSD$

PORTNAME=	pvm
PORTVERSION=	3.4.6
PORTREVISION=	5
CATEGORIES=	net parallel
MASTER_SITES=	NL/pvm3 ftp://ftp.chg.ru/pub/prog/parallel/pvm3/
DISTNAME=	pvm${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel Virtual Machine libraries and environment

LICENSE=	MIT

BROKEN_mips=		fails to compile: 'SIGCLD' undeclared (first use in this function)
BROKEN_mips64=		fails to compile: 'SIGCLD' undeclared (first use in this function)

USES=		tar:tgz
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/pvm3
MAKE_ENV=	PVM_ROOT=${WRKSRC} SHAREDLDFLAGS="${LDFLAGS} -shared"
PVM_ROOT_REL=	lib/pvm
PVM_ROOT=	${PREFIX}/${PVM_ROOT_REL}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

X11_USES=	xorg
X11_USE=	XORG=x11,xaw,xext,xmu,xt

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/tracer/tracer.h ${WRKSRC}/tracer/trclib.h \
		${WRKSRC}/tracer/trcsort.c
	@${FIND} ${WRKSRC} -name Makefile.aimk | ${XARGS} ${REINPLACE_CMD} \
		-e 's,-[gO],,g'
	@${REINPLACE_CMD} \
		-e 's/$$(XCFLAGS) $$(CFLAGS)/$$(CFLAGS) $$(XCFLAGS)/' \
		${WRKSRC}/xep/Makefile.aimk
.if ! ${PORT_OPTIONS:MX11}
	@${REINPLACE_CMD} -e '/default/s/xep[^ ]*//' ${WRKSRC}/xep/Makefile.aimk
.endif

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} \
		EXTRACFLAGS="${CFLAGS}" all)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} clean)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} \
		EXTRACFLAGS="${CFLAGS} -fpic" shared)

do-install:
	@${MKDIR} ${STAGEDIR}${PVM_ROOT}/lib/FREEBSD
	@${MKDIR} ${STAGEDIR}${PVM_ROOT}/bin/FREEBSD
	@${MKDIR} ${STAGEDIR}${PVM_ROOT}/conf
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FREEBSD/* ${STAGEDIR}${PVM_ROOT}/bin/FREEBSD
	${INSTALL_PROGRAM} ${WRKSRC}/lib/FREEBSD/pvmd3 ${STAGEDIR}${PVM_ROOT}/lib/FREEBSD
	${INSTALL_PROGRAM} ${WRKSRC}/lib/FREEBSD/pvm ${STAGEDIR}${PVM_ROOT}/lib/FREEBSD
	${INSTALL_SCRIPT} ${WRKSRC}/lib/pvm ${STAGEDIR}${PVM_ROOT}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/lib/pvmd ${STAGEDIR}${PVM_ROOT}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/lib/pvmgetarch ${STAGEDIR}${PVM_ROOT}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/lib/aimk ${STAGEDIR}${PVM_ROOT}/lib
	${LN} -sf ../${PVM_ROOT_REL}/lib/pvm ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ../${PVM_ROOT_REL}/lib/pvmd ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ../${PVM_ROOT_REL}/lib/aimk ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libpvm3.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libfpvm3.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libgpvm3.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/FREEBSD/libpvmtrc.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/FREEBSD/libpvm3.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/FREEBSD/libgpvm3.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/conf/FREEBSD.def ${STAGEDIR}${PVM_ROOT}/conf
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man3/* ${STAGEDIR}${PREFIX}/man/man3

.include <bsd.port.mk>
