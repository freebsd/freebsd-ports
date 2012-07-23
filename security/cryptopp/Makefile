# New ports collection makefile for:   cryptopp
# Date created:        18 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		cryptopp
PORTVERSION=		5.6.1
PORTREVISION=		2
CATEGORIES=		security
MASTER_SITES=		SF \
			http://www.cryptopp.com/
DISTNAME=		cryptopp${PORTVERSION:S/.//g}

MAINTAINER=		delphij@FreeBSD.org
COMMENT=		A free C++ class library of Cryptographic Primitives

OPTIONS_DEFINE=		DEBUG DOCS GCC46 STATIC THREADS
OPTIONS_DEFAULT=	STATIC THREADS
STATIC_DESC=		Build static version only (no shared libs)
GCC46_DESC=		Build with GCC 4.6+

.include <bsd.port.options.mk>

NO_WRKSUBDIR=		yes
USE_ZIP=		yes
EXTRACT_BEFORE_ARGS=	-aq
USE_GMAKE=		yes
MAKE_JOBS_SAFE=		yes
MAKEFILE=		GNUmakefile

LIBVERSION=		0
PLIST_SUB+=		LIBVERSION=${LIBVERSION}
PLIST_SUB+=		PORTVERSION=${PORTVERSION}

.if !${PORT_OPTIONS:MDEBUG}
CXXFLAGS+=		-DNDEBUG
.endif

.if ${PORT_OPTIONS:MGCC46}
USE_GCC=		4.6+
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
	${INSTALL_PROGRAM} ${WRKSRC}/cryptest.exe ${PREFIX}/bin/cryptest
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/cryptopp
	(for i in `${FIND} ${WRKSRC}/ -name '*.h' \
			-and -not -name 'dll.h' \
			-and -not -name 'resource.h'`; do \
		${INSTALL_DATA} $$i ${PREFIX}/include/cryptopp; \
	done)
.if !${PORT_OPTIONS:MSTATIC}
	${INSTALL_LIB} ${WRKSRC}/libcryptopp.so ${PREFIX}/lib/libcryptopp.so.${PORTVERSION}
	${LN} -fs libcryptopp.so.${PORTVERSION} ${PREFIX}/lib/libcryptopp.so.${LIBVERSION}
	${LN} -fs libcryptopp.so.${LIBVERSION} ${PREFIX}/lib/libcryptopp.so
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${PREFIX}/share/doc/cryptopp
	${CP} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/cryptopp/README
	${CP} ${WRKSRC}/License.txt ${PREFIX}/share/doc/cryptopp/License
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: unrecognized C++ options
.endif

.include <bsd.port.post.mk>
