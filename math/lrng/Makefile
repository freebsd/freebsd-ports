# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lrng
PORTVERSION=	20130314
CATEGORIES=	math
MASTER_SITES=	http://www.iro.umontreal.ca/~simardr/rng/:1 \
		http://www.iro.umontreal.ca/~lecuyer/myftp/papers/:2 \
		LOCAL/bf/${PORTNAME}/${PORTVERSION}/:1,2
DISTFILES=	ex1.c:1 lfsr258.c:1 lfsr113.c:1 WELL1024a.h:1 WELL19937a.h:1 WELL512a.h:1 \
		WELL44497a.h:1 WELL19937a.c:1 WELL1024a.c:1 WELL512a.c:1 WELL44497a.c:1 \
		MRG63k3a.c:1 MRG32k3a.c:1 MRG32k5a.c:1 MRG63k3a.h:1 MRG32k5a.h:1 MRG32k3a.h:1 \
		lfsr258.h:1 lfsr113.h:1
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Uniform random number generators of P. L'Ecuyer and his colleagues

LICENSE=	GPLv3

CLEANFILES=	${SRCS}
LIB=		${PORTNAME}
LIBDIR=		${PREFIX}/lib
MAKE_ENV+=	CLEANFILES="${CLEANFILES}" \
		LIB="${LIB}" LIBDIR="${LIBDIR}" SHLIB_MAJOR="${SHLIB_MAJOR}" \
		SRCS="${SRCS}" SRCCONF="${SRCCONF}"
NO_WRKSUBDIR=	yes
OPTIONS_DEFINE=	PROFILE DOCS EXAMPLES
PLIST_FILES=	${DISTFILES:M*.h\:1:S|:1$||:S|^|include/${PORTNAME}/|:} \
		lib/lib${LIB}.a lib/lib${LIB}.so \
		lib/lib${LIB}.so.${SHLIB_MAJOR}
SHLIB_MAJOR=	0
SRCCONF=	/dev/null
SRCS=	${DISTFILES:M*.c\:1:Nex1.c\:1:S|:1$||}
USE_LDCONFIG=	yes
USES=		uidfix

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || make(makesum)
DISTFILES+=	combmrg2.ps:2 lfsr04.pdf:2 tausme2.ps:2
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	${DISTFILES:M*\:2:S|:2||}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	ex1.c
.endif

.if ${PORT_OPTIONS:MPROFILE}
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE=		you have defined WITH_PROFILE, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE=		you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/lib${LIB}_p.a
.else
MAKE_ENV+=	WITHOUT_PROFILE=yes
.endif

post-extract:
	@${CP} ${_DISTDIR}/* ${WRKSRC}
	@${ECHO_CMD} ".include <bsd.lib.mk>" > ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

do-test:
	@${CC} ${CFLAGS} -o ${WRKSRC}/ex1 ${WRKSRC}/ex1.c ${WRKSRC}/lib${LIB}.a
	@${WRKSRC}/ex1
	@${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/ex1s ${WRKSRC}/ex1.c -L${WRKSRC} -l${LIB}
	@${SETENV} LD_LIBRARY_PATH=${WRKSRC} ${WRKSRC}/ex1s

.include <bsd.port.mk>
