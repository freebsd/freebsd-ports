# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
DISTVERSION=	1.1.0-pre5
CATEGORIES=	security devel
MASTER_SITES=	https://www.openssl.org/source/ \
		ftp://ftp.openssl.org/source/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/
PKGNAMESUFFIX=	-devel

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	SSL and crypto library (1.1.x)

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	libressl-[0-9]* libressl-devel-[0-9]* openssl-[0-9]*

OPTIONS_GROUP=	CIPHERS HASHES OPTIMIZE PROTOCOLS
OPTIONS_GROUP_CIPHERS=	IDEA JPAKE RC2 RC4 RC5
OPTIONS_GROUP_HASHES=	MD2 MD4 MDC2 RMD160
OPTIONS_GROUP_OPTIMIZE=	ASM SSE2
OPTIONS_GROUP_PROTOCOLS=	NEXTPROTONEG SCTP SSL3

OPTIONS_DEFINE=	SHARED THREADS ZLIB RFC3779 MAN3
OPTIONS_DEFAULT=	ASM MAN3 RMD160 SCTP SHARED SSE2 THREADS
.for a in amd64 ia64
OPTIONS_GROUP_OPTIMIZE_${a}=	EC
OPTIONS_DEFAULT_${a}=	EC
.endfor
TARGET_ARCH?=	${MACHINE_ARCH}
.if ${TARGET_ARCH} == "mips64el"
OPTIONS_GROUP_OPTIMIZE+=	EC
OPTIONS_DEFAULT+=	EC
.endif
ASM_DESC=	Assembler code
CIPHERS_DESC=	Cipher Suite Support
EC_DESC=	NIST elliptic curves
HASHES_DESC=	Hash Function Support
I386_DESC=	i386 (instead of i486+)
IDEA_DESC=	IDEA
JPAKE_DESC=	J-PAKE (experimental)
MAN3_DESC=	Install API manpages (section 3)
MD2_DESC=	MD2 (obsolete)
MD4_DESC=	MD4 (unsafe)
MDC2_DESC=	MDC-2
MD_GHOST94_DESC=	GHOST94 (obscure)
NEXTPROTONEG_DESC=	Next Protocol Negotiation (SPDY)
OPTIMIZE_DESC=	Optimizations
PROTOCOLS_DESC=	Protocols Support
RC2_DESC=	RC2 (unsafe)
RC4_DESC=	RC4 (unsafe)
RC5_DESC=	RC5 (patented)
RMD160_DESC=	RIPEMD-160
RFC3779_DESC=	RFC3779 support (BGP)
SCTP_DESC=	SCTP (Stream Control Transmission)
SHARED_DESC=	Build shared libraries
SSE2_DESC=	Runtime SSE2 detection
SSL3_DESC=	SSLv3
ZLIB_DESC=	zlib compression support

NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config

NOPRECIOUSMAKEVARS=	Too many _MLINKS for fetch
NOPRECIOUSSOFTMAKEVARS=	Too many _MLINKS for fetch

USES=		cpe localbase perl5
USE_PERL5=	build
MAKE_ARGS+=	WHOLE_ARCHIVE_FLAG=--whole-archive
MAKE_ENV+=	LIBRPATH="${PREFIX}/lib" GREP_OPTIONS=
SUB_FILES=	pkg-message
TEST_TARGET=	test

CPE_VERSION=	${DISTVERSION}

.for _option in asm idea md2 md4 mdc2 md_ghost94 nextprotoneg rc5 rfc3779 rmd160 sctp sse2 ssl3 threads
${_option:tu}_CONFIGURE_ON=	enable-${_option}
${_option:tu}_CONFIGURE_OFF=	no-${_option}
.endfor
ASM_NOT_FOR_ARCHS=	sparc6
EC_CONFIGURE_ON=	enable-ec_nistp_64_gcc_128
EC_CONFIGURE_OFF=	no-ec_nistp_64_gcc_128
SHARED_CONFIGURE_ON=	shared
SHARED_MAKE_ENV=	SHLIBVER=${OPENSSL_SHLIBVER}
SHARED_PLIST_SUB=	SHLIBVER=${OPENSSL_SHLIBVER}
SHARED_USE_LDCONFIG=	yes
SSL3_CONFIGURE_OFF=	no-ssl3-method

.include <bsd.port.pre.mk>
.if ${PREFIX} == /usr
IGNORE=	the OpenSSL port can not be installed over the base version
.endif

OPENSSLDIR?=	${PREFIX}/openssl
PLIST_SUB+=	OPENSSLDIR=${OPENSSLDIR:S=^${PREFIX}/==}
CONFIGURE_ARGS+=	--openssldir=${OPENSSLDIR}

OPENSSL_BASE_SONAME!=	readlink ${DESTDIR}/usr/lib/libcrypto.so || true
OPENSSL_SHLIBVER_BASE=	${OPENSSL_BASE_SONAME:E}
OPENSSL_BASE_SOPATH=	${OPENSSL_BASE_SONAME:H}
OPENSSL_SHLIBVER?=	9

.if ${ARCH} == "i386"
OPTIONS_GROUP_OPTIMIZE+=	I386
.endif
I386_CONFIGURE_ON=	386

post-patch:
	${REINPLACE_CMD} -e 's|m4 -B 8192|m4|g' \
		${WRKSRC}/crypto/des/Makefile.in
	${REINPLACE_CMD} -e 's|ERR_R_MALLOC_ERROR|ERR_R_MALLOC_FAILURE|' \
		${WRKSRC}/crypto/bio/bss_dgram.c

post-configure:
	${REINPLACE_CMD} \
		-e 's|^MANDIR=.*$$|MANDIR=$$(PREFIX)/man|' \
		-e 's|LIBVERSION=[^ ]* |LIBVERSION=$(OPENSSL_SHLIBVER) |' \
		-e 's|$$(SHLIB_MAJOR).$$(SHLIB_MINOR)|$(OPENSSL_SHLIBVER)|g' \
		-e 's|$$(LIBDIR)/pkgconfig|libdata/pkgconfig|g' \
		-e 's| install_html_docs$$||' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e 's|^LIBVERSION=$$|LIBVERSION=$(OPENSSL_SHLIBVER) |' \
		${WRKSRC}/Makefile.shared

post-install-SHARED-on:
.for i in libcrypto libssl
	${INSTALL_DATA} ${WRKSRC}/$i.so.${OPENSSL_SHLIBVER} ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/$i.so.${OPENSSL_SHLIBVER}
	${LN} -sf $i.so.${OPENSSL_SHLIBVER} ${STAGEDIR}${PREFIX}/lib/$i.so
.endfor
.for i in capi dasync padlock
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/engines/${i}.so
.endfor

post-install-MAN3-off:
	${RM} -rf ${STAGEDIR}/${PREFIX}/man/man3
	${REINPLACE_CMD} -e 's|^man/man3/.*||' ${TMPPLIST}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/openssl

.include <bsd.port.post.mk>
