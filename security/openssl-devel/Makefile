# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
DISTVERSION=	3.0.0-alpha12
CATEGORIES=	security devel
MASTER_SITES=	https://www.openssl.org/source/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/
PKGNAMESUFFIX=	-devel

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	TLSv1.3 capable SSL and crypto library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

CONFLICTS_INSTALL=	libressl-[0-9]* \
			libressl-devel-[0-9]* \
			openssl-[0-9]*

BROKEN_i386=	ld: error: undefined symbol: __atomic_is_lock_free

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config
CONFIGURE_ENV=	PERL="${PERL}"
CONFIGURE_ARGS=	--openssldir=${OPENSSLDIR} \
		--prefix=${PREFIX}

USES=		cpe perl5
USE_PERL5=	build
TEST_TARGET=	test

LDFLAGS_i386=	-Wl,-znotext

MAKE_ARGS+=	WHOLE_ARCHIVE_FLAG=--whole-archive CNF_LDFLAGS="${LDFLAGS}"
MAKE_ENV+=	LIBRPATH="${PREFIX}/lib" GREP_OPTIONS=

OPTIONS_GROUP=		CIPHERS HASHES MODULES OPTIMIZE PROTOCOLS
OPTIONS_GROUP_CIPHERS=	ARIA DES GOST IDEA SM4 RC2 RC4 RC5 WEAK-SSL-CIPHERS
OPTIONS_GROUP_HASHES=	MD2 MD4 MDC2 RMD160 SM2 SM3
OPTIONS_GROUP_OPTIMIZE=	ASM SSE2 THREADS
OPTIONS_GROUP_MODULES=	FIPS LEGACY
OPTIONS_DEFINE_i386=	I386
OPTIONS_GROUP_PROTOCOLS=NEXTPROTONEG SCTP SSL3 TLS1 TLS1_1 TLS1_2

OPTIONS_DEFINE=	ASYNC CT KTLS MAN3 RFC3779 SHARED ZLIB

OPTIONS_DEFAULT=ASM ASYNC CT DES EC FIPS GOST KTLS MAN3 MD4 NEXTPROTONEG \
		RC2 RC4 RMD160 SCTP SHARED SSE2 THREADS TLS1 TLS1_1 TLS1_2

OPTIONS_EXCLUDE=${${OSVERSION} < 1300042:?KTLS:}

OPTIONS_GROUP_OPTIMIZE_amd64=	EC

.if ${MACHINE_ARCH} == "amd64"
OPTIONS_GROUP_OPTIMIZE+=	EC
.elif ${MACHINE_ARCH} == "mips64el"
OPTIONS_GROUP_OPTIMIZE+=	EC
.endif

OPTIONS_SUB=	yes

ARIA_DESC=	ARIA (South Korean standard)
ASM_DESC=	Assembler code
ASYNC_DESC=	Asynchronous mode
CIPHERS_DESC=	Block Cipher Support
CT_DESC=	Certificate Transparency Support
DES_DESC=	(Triple) Data Encryption Standard
EC_DESC=	Optimize NIST elliptic curves
FIPS_DESC=	Build FIPS provider (Note: NOT yet FIPS validated)
GOST_DESC=	GOST (Russian standard)
HASHES_DESC=	Hash Function Support
I386_DESC=	i386 (instead of i486+)
IDEA_DESC=	International Data Encryption Algorithm
KTLS_DESC=	Use in-kernel TLS (FreeBSD >13)
LEGACY_DESC=	Older algorithms
MAN3_DESC=	Install API manpages (section 3, 7)
MD2_DESC=	MD2 (obsolete) (requires LEGACY)
MD4_DESC=	MD4 (unsafe)
MDC2_DESC=	MDC-2 (patented, requires DES)
MODULES_DESC=	Provider modules
NEXTPROTONEG_DESC=	Next Protocol Negotiation (SPDY)
OPTIMIZE_DESC=	Optimizations
PROTOCOLS_DESC=	Protocol Support
RC2_DESC=	RC2 (unsafe)
RC4_DESC=	RC4 (unsafe)
RC5_DESC=	RC5 (patented)
RMD160_DESC=	RIPEMD-160
RFC3779_DESC=	RFC3779 support (BGP)
SCTP_DESC=	SCTP (Stream Control Transmission)
SHARED_DESC=	Build shared libraries
SM2_DESC=	SM2 Elliptic Curve DH (Chinese standard)
SM3_DESC=	SM3 256bit (Chinese standard)
SM4_DESC=	SM4 128bit (Chinese standard)
SSE2_DESC=	Runtime SSE2 detection
SSL3_DESC=	SSLv3 (unsafe)
TLS1_DESC=	TLSv1.0 (requires TLS1_1, TLS1_2)
TLS1_1_DESC=	TLSv1.1 (requires TLS1_2)
TLS1_2_DESC=	TLSv1.2
WEAK-SSL-CIPHERS_DESC=	Weak cipher support (unsafe)

# Upstream default disabled options
.for _option in md2 ktls rc5 sctp ssl3 weak-ssl-ciphers zlib
${_option:tu}_CONFIGURE_ON=	enable-${_option}
.endfor

# Upstream default enabled options
.for _option in aria asm async ct des fips gost idea md4 mdc2 legacy \
	nextprotoneg rc2 rc4 rfc3779 rmd160 shared sm2 sm3 sm4 sse2 \
	threads tls1 tls1_1 tls1_2
${_option:tu}_CONFIGURE_OFF=	no-${_option}
.endfor

MD2_IMPLIES=	LEGACY
MDC2_IMPLIES=	DES
TLS1_IMPLIES=	TLS1_1
TLS1_1_IMPLIES=	TLS1_2

EC_CONFIGURE_ON=	enable-ec_nistp_64_gcc_128
FIPS_VARS=		shlibs+=lib/ossl-modules/fips.so
I386_CONFIGURE_ON=	386
LEGACY_VARS=		shlibs+=lib/ossl-modules/legacy.so
MAN3_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-util_find-doc-nits
SHARED_MAKE_ENV=	SHLIBVER=${OPENSSL_SHLIBVER}
SHARED_PLIST_SUB=	SHLIBVER=${OPENSSL_SHLIBVER}
SHARED_USE=		ldconfig=yes
SHARED_VARS=		shlibs+="lib/libcrypto.so.${OPENSSL_SHLIBVER} \
				lib/libssl.so.${OPENSSL_SHLIBVER} \
				lib/engines-${OPENSSL_SHLIBVER}/capi.so \
				lib/engines-${OPENSSL_SHLIBVER}/devcrypto.so \
				lib/engines-${OPENSSL_SHLIBVER}/padlock.so"
SSL3_CONFIGURE_ON+=	enable-ssl3-method
ZLIB_CONFIGURE_ON=	zlib-dynamic

.include <bsd.port.pre.mk>
.if ${PREFIX} == /usr
IGNORE=	the OpenSSL port can not be installed over the base version
.endif

OPENSSLDIR?=	${PREFIX}/openssl
PLIST_SUB+=	OPENSSLDIR=${OPENSSLDIR:S=^${PREFIX}/==}

.include "version.mk"

.if ${PORT_OPTIONS:MASM}
BROKEN_sparc64=	option ASM generates illegal instructions
.endif

post-patch:
	${REINPLACE_CMD} -Ee 's|^MANDIR=.*$$|MANDIR=$$(INSTALLTOP)/man|' \
		-e 's|^(build\|install)_docs: .*|\1_docs: \1_man_docs|' \
		${WRKSRC}/Configurations/unix-Makefile.tmpl
	${REINPLACE_CMD} 's|SHLIB_VERSION=3|SHLIB_VERSION=${OPENSSL_SHLIBVER}|' \
		${WRKSRC}/VERSION.dat

post-configure:
	( cd ${WRKSRC} ; ${PERL} configdata.pm --dump )

post-configure-MAN3-off:
	${REINPLACE_CMD} \
		-e 's|^build_man_docs:.*|build_man_docs: $$(MANDOCS1) $$(MANDOCS7)|' \
		-e 's|dummy $$(MANDOCS[37]); do |dummy; do continue |' \
		${WRKSRC}/Makefile

post-install-SHARED-on:
.for i in ${SHLIBS}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/$i
.endfor

post-install-SHARED-off:
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/engines-12

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/openssl

.include <bsd.port.post.mk>
