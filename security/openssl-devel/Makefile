# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	1.1.0c
CATEGORIES=	security devel
MASTER_SITES=	https://www.openssl.org/source/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/
PKGNAMESUFFIX=	-devel

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	SSL and crypto library (1.1.x)

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	libressl-[0-9]* \
			libressl-devel-[0-9]* \
			openssl-[0-9]*

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config
CONFIGURE_ENV=	PERL="${PERL}"
CONFIGURE_ARGS=	--openssldir=${OPENSSLDIR}

OPTIONS_GROUP=	CIPHERS HASHES OPTIMIZE PROTOCOLS
OPTIONS_GROUP_CIPHERS=	IDEA JPAKE RC2 RC4 RC5
OPTIONS_GROUP_HASHES=	MD2 MD4 MDC2 RMD160
OPTIONS_GROUP_OPTIMIZE=	ASM SSE2 THREADS
OPTIONS_DEFINE_i386=	I386
OPTIONS_GROUP_PROTOCOLS=	NEXTPROTONEG SCTP SSL3

OPTIONS_DEFINE=	MAN3 RFC3779 SHARED THREADS ZLIB

.if ${MACHINE_ARCH} == "amd64"
OPTIONS_GROUP_OPTIMIZE+=	EC
OPTIONS_DEFAULT+=		EC
.elif ${MACHINE_ARCH} == "ia64"
OPTIONS_GROUP_OPTIMIZE+=	EC
OPTIONS_DEFAULT+=		EC
.elif ${MACHINE_ARCH} == "mips64el"
OPTIONS_GROUP_OPTIMIZE+=	EC
OPTIONS_DEFAULT+=		EC
.endif
OPTIONS_DEFAULT=	ASM MAN3 MD4 RC2 RC4 RMD160 SCTP SHARED SSE2 THREADS

ASM_DESC=	Assembler code
CIPHERS_DESC=	Cipher Suite Support
EC_DESC=	Optimize NIST elliptic curves
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
PROTOCOLS_DESC=	Protocol Support
RC2_DESC=	RC2 (unsafe)
RC4_DESC=	RC4 (unsafe)
RC5_DESC=	RC5 (patented)
RMD160_DESC=	RIPEMD-160
RFC3779_DESC=	RFC3779 support (BGP)
SCTP_DESC=	SCTP (Stream Control Transmission)
SHARED_DESC=	Build shared libraries
SSE2_DESC=	Runtime SSE2 detection
SSL3_DESC=	SSLv3 (unsafe)
ZLIB_DESC=	zlib compression support

OPTIONS_SUB=	yes

USES=		cpe perl5
USE_PERL5=	build
MAKE_ARGS+=	WHOLE_ARCHIVE_FLAG=--whole-archive
MAKE_ENV+=	LIBRPATH="${PREFIX}/lib" GREP_OPTIONS=
TEST_TARGET=	test

# Upstream default disabled options
.for _option in md2 rc5 sctp ssl3 zlib
${_option:tu}_CONFIGURE_ON=	enable-${_option}
.endfor

# Upstream default enabled options
.for _option in asm idea md4 mdc2 md_ghost94 nextprotoneg rfc3779 rmd160 sse2 threads zlib
${_option:tu}_CONFIGURE_OFF=	no-${_option}
.endfor

EC_CONFIGURE_ON=	enable-ec_nistp_64_gcc_128
I386_CONFIGURE_ON=	386
SHARED_MAKE_ENV=	SHLIBVER=${OPENSSL_SHLIBVER}
SHARED_PLIST_SUB=	SHLIBVER=${OPENSSL_SHLIBVER}
SHARED_USE=		ldconfig=yes
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
BROKEN_sparc64= option ASM generates illegal instructions
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's|^MANDIR=.*$$|MANDIR=$$(INSTALLTOP)/man|' \
		-e 's| install_html_docs$$||' \
		-e 's|$$(LIBDIR)/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/Configurations/unix-Makefile.tmpl

post-patch-MAN3-off:
	${GREP} -L openssl_manual_section ${WRKSRC}/doc/crypto/*.pod | ${XARGS} ${RM}
	${GREP} -L openssl_manual_section ${WRKSRC}/doc/ssl/*.pod | ${XARGS} ${RM}

post-configure:
	${REINPLACE_CMD} \
		-e 's|$$(SHLIB_MAJOR).$$(SHLIB_MINOR)|${OPENSSL_SHLIBVER}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e 's|SHLIB_VERSION_NUMBER "1.1"|SHLIB_VERSION_NUMBER "${OPENSSL_SHLIBVER}"|' \
		${WRKSRC}/include/openssl/opensslv.h

post-install-SHARED-on:
.for i in libcrypto libssl
	${INSTALL_DATA} ${WRKSRC}/$i.so.${OPENSSL_SHLIBVER} ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/$i.so.${OPENSSL_SHLIBVER}
	${LN} -sf $i.so.${OPENSSL_SHLIBVER} ${STAGEDIR}${PREFIX}/lib/$i.so
.endfor
.for i in capi padlock
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/engines-1.1/${i}.so
.endfor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/openssl

.include <bsd.port.post.mk>
