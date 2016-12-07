# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

# Minor version bumps may not be ABI compatible and deskutils/cdcat
# links to the static library, so bump PORTREVISION of dependent
# ports when appropriate.

PORTNAME=		cryptopp
PORTVERSION=		5.6.5
CATEGORIES=		security
MASTER_SITES=		http://www.cryptopp.com/
DISTNAME=		cryptopp${PORTVERSION:S/.//g}

MAINTAINER=		jhale@FreeBSD.org
COMMENT=		Free C++ class library of Cryptographic Primitives

LICENSE=		BSL
LICENSE_FILE=		${WRKSRC}/License.txt

USES=			cpe gmake zip:infozip
USE_LDCONFIG=		yes

CPE_PRODUCT=		crypto++
CPE_VENDOR=		cryptopp

BROKEN_powerpc=		does not compile; unrecognized C++ options

EXTRACT_BEFORE_ARGS=	-aq
NO_WRKSUBDIR=		yes

CXXFLAGS+=		-Wno-deprecated-declarations -fPIC
MAKEFILE=		GNUmakefile
ALL_TARGET=		static shared
TEST_TARGET=		test

LIBVERSION=		${PORTVERSION:R:R}
PLIST_SUB+=		LIBVERSION=${LIBVERSION} \
			PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		DEBUG DOCS FULL_DEBUG THREADS
OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT=	THREADS
OPTIONS_SUB=		yes

# Always compile with -DNDEBUG for release. Otherwise, sensitive
# information could be accessed if an assert triggers.
# See ${WRKSRC}/Readme.txt for more details.
FULL_DEBUG_DESC=	Build with full debugging support (SECURITY RISK!!!)
FULL_DEBUG_CXXFLAGS=	-DCRYPTOPP_DEBUG
FULL_DEBUG_CXXFLAGS_OFF=-DNDEBUG
FULL_DEBUG_IMPLIES=	DEBUG

THREADS_LDFLAGS=	-lpthread

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSIMD}
.  if ${MACHINE_CPU:Msse2}
USES+=		compiler:c++14-lang
CXXFLAGS+=	-msse2
.  else
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM -DCRYPTOPP_DISABLE_SSE2
.  endif
.  if ${MACHINE_CPU:Msse3} && ${MACHINE_CPU:Mssse3}
CXXFLAGS+=	-msse3 -mssse3
.  else
CXXFLAGS+=	-DCRYPTOPP_DISABLE_SSE3
.  endif
.  if ${MACHINE_CPU:Msse41} && ${MACHINE_CPU:Msse42}
CXXFLAGS+=	-msse4.1 -msse4.2
.  else
CXXFLAGS+=	-DCRYPTOPP_DISABLE_SSE4
.  endif
.else
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSIMD} && ${MACHINE_CPU:Msse2} && ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif

pre-configure-FULL_DEBUG-on:
	@${ECHO_CMD}
	@${ECHO_CMD} "----------------------------- WARNING!!! ----------------------------"
	@${ECHO_CMD} "You have chosen to compile with full debugging support. If an assert"
	@${ECHO_CMD} "triggers, sensitive information could possibly be egressed to the"
	@${ECHO_CMD} "filesystem via a core dump. If this is not your intention, hit CTRL-C"
	@${ECHO_CMD} "now and run 'make config clean' and disable the FULL_DEBUG option."
	@${ECHO_CMD} "---------------------------------------------------------------------"
	@${ECHO_CMD}
	@sleep 10

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libcryptopp.so ${STAGEDIR}${PREFIX}/lib/libcryptopp.so.${PORTVERSION}
	${LN} -fs libcryptopp.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libcryptopp.so.${LIBVERSION}
	${LN} -fs libcryptopp.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libcryptopp.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/cryptopp
	(for i in `${FIND} ${WRKSRC}/ -name '*.h' \
			-and -not -name 'dll.h' \
			-and -not -name 'resource.h'`; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/include/cryptopp; \
	done)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.post.mk>
