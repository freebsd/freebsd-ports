# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=		cryptopp
PORTVERSION=		5.6.2
PORTREVISION=		1
CATEGORIES=		security
MASTER_SITES=		SF \
			http://www.cryptopp.com/
DISTNAME=		cryptopp${PORTVERSION:S/.//g}

MAINTAINER=		delphij@FreeBSD.org
COMMENT=		Free C++ class library of Cryptographic Primitives

OPTIONS_DEFINE=		DEBUG DOCS GCC STATIC THREADS
OPTIONS_DEFAULT=	STATIC THREADS
STATIC_DESC=		Build static version only (no shared libs)
GCC_DESC=		Build with current GCC

.include <bsd.port.options.mk>

NO_WRKSUBDIR=		yes
EXTRACT_BEFORE_ARGS=	-aq
USES=			gmake zip:infozip
MAKEFILE=		GNUmakefile

LIBVERSION=		0
PLIST_SUB+=		LIBVERSION=${LIBVERSION}
PLIST_SUB+=		PORTVERSION=${PORTVERSION}

.if !${PORT_OPTIONS:MDEBUG}
CXXFLAGS+=		-DNDEBUG
.endif

.if ${PORT_OPTIONS:MGCC}
USE_GCC=		yes
.endif

.if ${PORT_OPTIONS:MSTATIC}
PLIST_SUB+=		DYNAMIC_ENABLED="@comment "
.else
PLIST_SUB+=		DYNAMIC_ENABLED=""
MAKE_ARGS=		all libcryptopp.so
CXXFLAGS+=		-fPIC
USE_LDCONFIG=		yes
.endif

.if ${PORT_OPTIONS:MTHREADS}
CXXFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_LIBS}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptest.exe ${STAGEDIR}${PREFIX}/bin/cryptest
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/cryptopp
	(for i in `${FIND} ${WRKSRC}/ -name '*.h' \
			-and -not -name 'dll.h' \
			-and -not -name 'resource.h'`; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/include/cryptopp; \
	done)
.if !${PORT_OPTIONS:MSTATIC}
	${INSTALL_LIB} ${WRKSRC}/libcryptopp.so ${STAGEDIR}${PREFIX}/lib/libcryptopp.so.${PORTVERSION}
	${LN} -fs libcryptopp.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libcryptopp.so.${LIBVERSION}
	${LN} -fs libcryptopp.so.${LIBVERSION} ${STAGEDIR}${PREFIX}/lib/libcryptopp.so
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/cryptopp
	${CP} ${WRKSRC}/Readme.txt ${STAGEDIR}${PREFIX}/share/doc/cryptopp/README
	${CP} ${WRKSRC}/License.txt ${STAGEDIR}${PREFIX}/share/doc/cryptopp/License

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: unrecognized C++ options
.endif

.include <bsd.port.mk>
