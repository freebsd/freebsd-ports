# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	lp_solve
PORTVERSION=	5.5.2.0
CATEGORIES=	math
MASTER_SITES=	SF/lpsolve/lpsolve/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_source

MAINTAINER=	mayo@oyam.ca
COMMENT=	Linear Programming Solver

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:R:R}

USE_LDCONFIG=	yes

.if defined(TMPDIR)
BUILDENV=	${SETENV} TMPDIR="${TMPDIR}"
.endif

.include <bsd.port.pre.mk>

# probably need to add mips here as well
.if ${ARCH} == "i386" || ${ARCH} == "powerpc" || ${ARCH} == armv6
LPSOLVE_ARCH=	ux32
.else
LPSOLVE_ARCH=	ux64
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "ccc" | ${XARGS} ${REINPLACE_CMD} -e \
		"s|^c=.*$$|c='${CC}'|g ; \
		 s|^opts=.*$$|opts='${CFLAGS}'|g ; \
		 s|-fpic|-fPIC|g ; \
		 s|-ldl||g"

do-build:
	cd ${WRKSRC}/lp_solve  ; ${BUILDENV} ${SH} -x ccc
	cd ${WRKSRC}/demo      ; ${BUILDENV} ${SH} -x ccc
	cd ${WRKSRC}/lpsolve55 ; ${BUILDENV} ${SH} -x ccc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lp_solve/bin/${LPSOLVE_ARCH}/lp_solve ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/lpsolve
.for i in declare.h fortify.h ini.h lp_*.h lpkit.h lpsolve.h ufortify.h yacc_read.h
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/include/lpsolve
.endfor
.for i in liblpsolve55.a liblpsolve55.so
	${INSTALL_DATA} ${WRKSRC}/lpsolve55/bin/${LPSOLVE_ARCH}/${i} ${STAGEDIR}${PREFIX}/lib
.endfor
	${LN} -sf liblpsolve55.so ${STAGEDIR}${PREFIX}/lib/liblpsolve55.so.1

.include <bsd.port.post.mk>
