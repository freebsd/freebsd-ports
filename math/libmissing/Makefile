# $FreeBSD$

PORTNAME=	libmissing
DISTVERSION=	20130815
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	LOCAL/bf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard math functions missing from the FreeBSD libm

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libmpc.so:math/mpc

USE_LDCONFIG=	yes
USES=		tar:xz uidfix

MAKE_ENV=	LDADD=-lmpc LIB=missing SHLIB_MAJOR="${SHLIB_MAJOR}" \
		SRCCONF=/dev/null SRCS="${SRCS}" __MAKE_CONF=/dev/null

OPTIONS_DEFINE=	PROFILE EXAMPLES

PLIST_FILES=	include/missing_complex.h \
		include/missing_math.h \
		lib/libmissing.a lib/libmissing.so \
		lib/libmissing.so.${SHLIB_MAJOR}

SHLIB_MAJOR=	2
SRCS=		libmissing.c

CFLAGS+=	-fno-builtin -fno-math-errno -I. -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,-z,interpose
PORTEXAMPLES=	${SRCS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPROFILE}
.if !exists(/usr/lib/libc_p.a)
IGNORE=		you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/libmissing_p.a
.else
MAKE_ENV+=	NO_PROFILE=yes
.endif

post-patch:
	@${PRINTF} "LIBDIR=\t${PREFIX}/lib\n.include <bsd.lib.mk>\n" > \
		${WRKSRC}/Makefile
.for t in d q s
	@cd ${WRKSRC}/c/common; ${CP} initseed.c maxtest.c ${WRKSRC}/c/${t}p/
.endfor
	@${REINPLACE_CMD} -E \
		'/(XCFLAGS|XDEFINES|XINCLUDES|XLDFLAGS|XLIBS|XMFLAGS|XOPT)[[:blank:]]+=/d' \
		${WRKSRC}/c/Makefile
	@${REINPLACE_CMD} -e \
		'/#include <math.h>/{x;s|^.*$$|#include "missing_math.h"|;H;x;}' \
		${WRKSRC}/c/common/elefunt.h
	@${REINPLACE_CMD} -e '\|COMMONOBJS[[:blank:]]*=|s|../common/||g' \
		${WRKSRC}/c/dp/Makefile \
		${WRKSRC}/c/qp/Makefile \
		${WRKSRC}/c/sp/Makefile

do-test:
	@cd ${WRKSRC}/c; ${SETENV} ${MAKE_ENV} XCFLAGS="${CFLAGS} -frounding-math" \
		XINCLUDES="-I${WRKSRC}" XLDFLAGS="${LDFLAGS}" XLIBS="-L${WRKSRC} -lmissing" \
		LD_LIBRARY_PATH="/lib:/usr/lib:${LOCALBASE}/lib:${WRKSRC}" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} all3
.for t in d q s
	@${PRINTF} "\n\n\n\t\t%s\n\n\n" "REPORT OF ${t:tu}. PRECISION TEST RESULTS:"
	@${CAT} ${WRKSRC}/c/${t}p/tall${t}p.lst-xxx
.endfor

post-install:
	@cd ${WRKSRC}; ${INSTALL_DATA} missing_complex.h missing_math.h \
	${STAGEDIR}${PREFIX}/include

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
