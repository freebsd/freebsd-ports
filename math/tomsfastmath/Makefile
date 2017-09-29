# $FreeBSD$

PORTNAME=	tomsfastmath
PORTVERSION=	0.13.1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable fixed precision math library for fast exponentiations

LICENSE=	PD WTFPL
LICENSE_COMB=	dual

BROKEN_powerpc=	internal compiler error at src/mul/fp_mul_comba_48.c:398

USES=		compiler:features gmake tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	libtom

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
ALL_TARGET=	default
CFLAGS+=	-fPIC

PLIST_FILES=	include/tfm.h lib/libtfm.a

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# on clang:
# src/mul/fp_mul_comba.c:349:11: error: inline assembly requires more registers than available
USE_GCC=	yes
.endif

# Unbreak against Clang ("cc" is not a register)
post-patch:
	@${REINPLACE_CMD} -e 's,"%cc","cc",' \
		${WRKSRC}/src/mont/fp_montgomery_reduce.c \
		${WRKSRC}/src/mul/fp_mul_comba.c \
		${WRKSRC}/src/sqr/fp_sqr_comba.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/headers/tfm.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libtfm.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.post.mk>
