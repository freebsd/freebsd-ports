# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	1.0.2t
PORTEPOCH=	1
CATEGORIES=	security devel
MASTER_SITES=	http://www.openssl.org/source/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION:C/[a-z]$//}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	SSL and crypto library

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		OpenSSL 1.0.2 is End-of-Life 2019-12-31 at which \
			time this port will update to 1.1.1 branch
EXPIRATION_DATE=	2019-12-31

OPTIONS_DEFINE=		DOCS MAN3 PADLOCK RFC3779 SHARED THREADS ZLIB
CONFLICTS_INSTALL=	libressl-[0-9]* \
			libressl-devel-[0-9]* \
			openssl111-[0-9]*

OPTIONS_DEFAULT=	ASM MD2 MAN3 SCTP SHARED SSE2 SSL2 SSL3 THREADS
OPTIONS_DEFINE_amd64=	EC
OPTIONS_DEFAULT_amd64=	EC
TARGET_ARCH?=	${MACHINE_ARCH}
.if ${TARGET_ARCH} == "mips64el"
OPTIONS_DEFINE_mips=	EC
OPTIONS_DEFAULT_mips=	EC
.endif
OPTIONS_GROUP=	CIPHERS HASHES OPTIMIZE PROTOCOLS
OPTIONS_GROUP_CIPHERS=	RC5
OPTIONS_GROUP_HASHES=	MD2
OPTIONS_GROUP_OPTIMIZE=	ASM SSE2
OPTIONS_GROUP_PROTOCOLS=	SCTP SSL2 SSL3
.if ${TARGET_ARCH} == "i386"
OPTIONS_GROUP_OPTIMIZE+=	I386
.endif
OPTIONS_SUB=	yes
ASM_DESC=	Optimized Assembler code
CIPHERS_DESC=	Cipher Suite support
EC_DESC=	Optimize NIST elliptic curves
HASHES_DESC=	Hash Function Support
I386_DESC=	Optimize for i386 (instead of i486+)
MAN3_DESC=	Install API manpages (section 3)
MD2_DESC=	MD2 hash (obsolete)
OPTIMIZE_DESC=	Optimizations
PADLOCK_DESC=	VIA Padlock support
PROTOCOLS_DESC=	Protocol Support
RC5_DESC=	RC5 cipher (patented)
RFC3779_DESC=	RFC3779 support (BGP)
SCTP_DESC=	SCTP protocol support
SHARED_DESC=	Build shared libs
SSE2_DESC=	Runtime SSE2 detection
SSL2_DESC=	SSLv2 protocol support
SSL3_DESC=	SSLv3 protocol support
ZLIB_DESC=	zlib compression support

USES=		compiler cpe perl5
USE_PERL5=	build
MAKE_ARGS+=	WHOLE_ARCHIVE_FLAG=--whole-archive
MAKE_ENV+=	LIBRPATH="${PREFIX}/lib" GREP_OPTIONS=
SUB_FILES=	pkg-message
TEST_TARGET=	test

MAKE_JOBS_UNSAFE=	yes

ASM_CONFIGURE_OFF=	no-asm
EC_CONFIGURE_ON=	enable-ec_nistp_64_gcc_128
EC_CONFIGURE_OFF=	no-ec_nistp_64_gcc_128
I386_CONFIGURE_ON=	386
MD2_CONFIGURE_ON=	enable-md2
MD2_CONFIGURE_OFF=	no-md2
PADLOCK_CFLAGS=		-Wno-unused-function
PADLOCK_CONFIGURE_OFF=	no-padlock
PADLOCK_PATCH_SITES=	http://git.alpinelinux.org/cgit/aports/plain/main/openssl1.0/:padlock
PADLOCK_PATCHFILES=	1001-crypto-hmac-support-EVP_MD_CTX_FLAG_ONESHOT-and-set-.patch:padlock \
			1002-backport-changes-from-upstream-padlock-module.patch:padlock \
			1003-engines-e_padlock-implement-sha1-sha224-sha256-accel.patch:padlock \
			1004-crypto-engine-autoload-padlock-dynamic-engine.patch:padlock
PADLOCK_VARS=		PATCH_DIST_STRIP=-p1
RC5_CONFIGURE_ON=	enable-rc5
RC5_CONFIGURE_OFF=	no-rc5
RFC3779_CONFIGURE_ON=	enable-rfc3779
RFC3779_CONFIGURE_OFF=	no-rfc3779
SCTP_CONFIGURE_ON=	sctp
SCTP_CONFIGURE_OFF=	no-sctp
SHARED_CONFIGURE_ON=	shared
SHARED_MAKE_ENV=	SHLIBVER=${OPENSSL_SHLIBVER}
SHARED_PLIST_SUB=	SHLIBVER=${OPENSSL_SHLIBVER}
SHARED_USE=		ldconfig=yes
SSE2_CONFIGURE_OFF=	no-sse2
SSL2_CONFIGURE_ON=	enable-ssl2
SSL2_CONFIGURE_OFF=	no-ssl2
SSL3_CONFIGURE_ON=	enable-ssl3
SSL3_CONFIGURE_OFF=	no-ssl3 no-ssl3-method
SSL3_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-test_testssl
THREADS_CONFIGURE_ON=	threads
THREADS_CONFIGURE_OFF=	no-threads
ZLIB_CONFIGURE_ON=	zlib zlib-dynamic
ZLIB_CONFIGURE_OFF=	no-zlib no-zlib-dynamic

CONFIGURE_ARGS=		no-gmp

.include "version.mk"

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} != gcc && ${COMPILER_VERSION} != 42
CFLAGS+= -Werror -Qunused-arguments
.endif

.if ${PREFIX} == /usr
IGNORE=	the OpenSSL port cannot be installed over the base version
.endif

OPENSSLDIR?=	${PREFIX}/openssl
PLIST_SUB+=	OPENSSLDIR=${OPENSSLDIR:S=^${PREFIX}/==}

.if ${PORT_OPTIONS:MASM}
BROKEN_sparc64=		option ASM generates illegal instructions
.endif

post-patch:
	${REINPLACE_CMD} -e 's|m4 -B 8192|m4|g' \
		${WRKSRC}/crypto/des/Makefile
	${REINPLACE_CMD} -e 's|SHLIB_VERSION_NUMBER "1.0.0"|SHLIB_VERSION_NUMBER "${OPENSSL_SHLIBVER}"|' \
		${WRKSRC}/crypto/opensslv.h
	${REINPLACE_CMD} -e 's|\^GNU ld|GNU|' ${WRKSRC}/Makefile.shared

post-patch-MAN3-off:
	${GREP} -L openssl_manual_section ${WRKSRC}/doc/crypto/*.pod | ${XARGS} ${RM}
	${REINPLACE_CMD} -e 's|pod doc/ssl/\*\.pod|pod|' ${WRKSRC}/Makefile.org

do-configure:
	${REINPLACE_CMD} -e "s|options 386|options|" ${WRKSRC}/config
	cd ${WRKSRC} \
	&& ${SETENV} CC="${CC}" FREEBSDCC="${CC}" CFLAGS="${CFLAGS}" PERL="${PERL}" \
	./config --prefix=${PREFIX} --openssldir=${OPENSSLDIR} \
		--install_prefix=${STAGEDIR} \
		-L${PREFIX}/lib ${CONFIGURE_ARGS}

post-configure:
	${REINPLACE_CMD} \
		-e 's|^MANDIR=.*$$|MANDIR=$$(PREFIX)/man|' \
		-e 's|$$(LIBDIR)/pkgconfig|libdata/pkgconfig|g' \
		-e 's|LIBVERSION=[^ ]* |LIBVERSION=${OPENSSL_SHLIBVER} |' \
		${WRKSRC}/Makefile

post-install-SHARED-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/openssl \
	${STAGEDIR}${PREFIX}/lib/lib*.so.${OPENSSL_SHLIBVER} \
	${STAGEDIR}${PREFIX}/lib/engines/lib*.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/openssl.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
