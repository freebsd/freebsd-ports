# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	cryptopp
PORTVERSION=	8.2.0
CATEGORIES=	security
MASTER_SITES=	http://www.cryptopp.com/
DISTNAME=	cryptopp${PORTVERSION:S/.//g}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Free C++ class library of Cryptographic Primitives

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cpe compiler:c++11-lang gmake zip
USE_LDCONFIG=	yes
CPE_PRODUCT=	crypto++
CPE_VENDOR=	cryptopp

EXTRACT_BEFORE_ARGS=	-aq
NO_WRKSUBDIR=		yes

CXXFLAGS+=	-Wno-deprecated-declarations -fPIC
MAKEFILE=	GNUmakefile
ALL_TARGET=	static shared libcryptopp.pc

SOVERSION=	${PORTVERSION:R:R}
PLIST_SUB+=	SOVERSION=${SOVERSION} \
		PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		DEBUG DOCS FULL_DEBUG TOOLS
OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFINE_powerpc=	SIMD
OPTIONS_DEFINE_powerpc64=	SIMD
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes

# Always compile with -DNDEBUG for release. Otherwise, sensitive
# information could be accessed if an assert triggers.
# See ${WRKSRC}/Readme.txt for more details.
FULL_DEBUG_DESC=	Build with full debugging support (SECURITY RISK!!!)
FULL_DEBUG_CXXFLAGS=	-DCRYPTOPP_DEBUG
FULL_DEBUG_CXXFLAGS_OFF=-DNDEBUG
FULL_DEBUG_IMPLIES=	DEBUG

# Disable this option to run the regression tests.
TOOLS_DESC=		Install encryption/decryption tools
TOOLS_MAKE_ENV=		CRYPTOPP_DATA_DIR=${DATADIR}/
TOOLS_ALL_TARGET=	cryptest.exe
TOOLS_TEST_TARGET_OFF=	test

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSIMD}
.  if ${ARCH} == i386 || ${ARCH} == amd64
.    if !${MACHINE_CPU:Msse2}
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM -DCRYPTOPP_DISABLE_SSE2
.    endif
.    if !${MACHINE_CPU:Mssse3}
CXXFLAGS+=	-DCRYPTOPP_DISABLE_SSSE3
.    endif
.    if !${MACHINE_CPU:Msse41}
CXXFLAGS+=	-DCRYPTOPP_DISABLE_SSE4
.    endif
.  elif ${ARCH} == powerpc || ${ARCH} == powerpc64
CXXFLAGS+=	-DCRYPTOPP_ALTIVEC_AVAILABLE -maltivec -mcrypto -mvsx
.  endif
.else
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM -DCRYPTOPP_DISABLE_SSE2 \
		-DCRYPTOPP_DISABLE_SSSE3 -DCRYPTOPP_DISABLE_SSE4 \
		-DCRYPTOPP_DISABLE_ALTIVEC
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
.  if !(defined(PACKAGE_BUILDING) || defined(BATCH))
	@sleep 10
.  endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libcryptopp.so ${STAGEDIR}${PREFIX}/lib/libcryptopp.so.${PORTVERSION}
	${LN} -fs libcryptopp.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libcryptopp.so.${SOVERSION}
	${LN} -fs libcryptopp.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libcryptopp.so
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/cryptopp
	(for i in `${FIND} ${WRKSRC}/ -name '*.h' \
			-and -not -name 'dll.h' \
			-and -not -name 'resource.h'`; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/include/cryptopp; \
	done)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${STAGEDIR}${DOCSDIR}/README

do-install-TOOLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/TestData
	${INSTALL_PROGRAM} ${WRKSRC}/cryptest.exe ${STAGEDIR}${PREFIX}/bin/cryptest
	${INSTALL_DATA} ${WRKSRC}/TestData/usage.dat ${STAGEDIR}${DATADIR}/TestData

.include <bsd.port.mk>
