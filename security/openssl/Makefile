# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	1.0.2
DISTVERSIONSUFFIX=	h
PORTREVISION=	15
PORTEPOCH=	1
CATEGORIES=	security devel
MASTER_SITES=	http://www.openssl.org/source/ \
		ftp://ftp.openssl.org/source/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	SSL and crypto library

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_JOBS_UNSAFE=	yes
CPE_VERSION=	${PORTVERSION}${DISTVERSIONSUFFIX}
CONFLICTS=	libressl-[0-9]* \
		libressl-devel-[0-9]* \
		openssl-devel-[0-9]*

OPTIONS_DEFINE=	SHARED THREADS SSE2 PADLOCK ZLIB SCTP SSL2 SSL3 RFC3779 MD2 RC5 EXPCIPHERS DOCS MAN3
OPTIONS_DEFAULT=SHARED THREADS SSE2 SCTP SSL2 SSL3 MD2 MAN3
OPTIONS_DEFINE_i386=	I386
OPTIONS_DEFINE_amd64=	EC
OPTIONS_DEFAULT_amd64=	EC
OPTIONS_DEFINE_ia64=	EC
OPTIONS_DEFAULT_ia64=	EC
TARGET_ARCH?=	${MACHINE_ARCH}
.if ${TARGET_ARCH} == "mips64el"
OPTIONS_DEFINE_mips=	EC
OPTIONS_DEFAULT_mips=	EC
.endif
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
I386_DESC?=	Optimize for i386 (instead of i486+)
SSE2_DESC?=	runtime SSE2 detection
PADLOCK_DESC?=	VIA Padlock support
SHARED_DESC?=	build of shared libs
ZLIB_DESC?=	zlib compression support
SCTP_DESC?=	SCTP protocol support
SSL2_DESC?=	SSLv2 protocol support
SSL3_DESC?=	SSLv3 protocol support
RFC3779_DESC?=	RFC3779 support (BGP)
MD2_DESC?=	MD2 hash (obsolete)
RC5_DESC?=	RC5 cipher (patented)
EXPCIPHERS_DESC?=	Include experimental ciphers
EC_DESC?=	Optimize NIST elliptic curves
MAN3_DESC?=	Install API manpages (section 3)

USES=		cpe perl5
USE_PERL5=	build
MAKE_ARGS+=	WHOLE_ARCHIVE_FLAG=--whole-archive
MAKE_ENV+=	LIBRPATH="${PREFIX}/lib" GREP_OPTIONS=
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PREFIX} == /usr
IGNORE=	the OpenSSL port can not be installed over the base version
.endif

OPENSSLDIR?=	${PREFIX}/openssl
PLIST_SUB+=	OPENSSLDIR=${OPENSSLDIR:S=^${PREFIX}/==}

OPENSSL_BASE_SONAME!=	readlink ${DESTDIR}/usr/lib/libcrypto.so || true
OPENSSL_SHLIBVER_BASE=	${OPENSSL_BASE_SONAME:E}
OPENSSL_BASE_SOPATH=	${OPENSSL_BASE_SONAME:H}

.include "version.mk"

.if ${PORT_OPTIONS:MI386}
.if ${ARCH} == "i386"
EXTRACONFIGURE+=	386
.endif
.endif

.if empty(PORT_OPTIONS:MSSE2)
# disable runtime SSE2 detection
EXTRACONFIGURE+=	no-sse2
.endif

EXTRACONFIGURE+=	no-asm

.if ${PORT_OPTIONS:MTHREADS}
EXTRACONFIGURE+=	threads
.else
EXTRACONFIGURE+=	no-threads
.endif

.if ${PORT_OPTIONS:MSHARED}
EXTRACONFIGURE+=	shared
MAKE_ENV+=	SHLIBVER=${OPENSSL_SHLIBVER}
PLIST_SUB+=	SHLIBVER=${OPENSSL_SHLIBVER}
USE_LDCONFIG=	yes
.endif

.if ${PORT_OPTIONS:MZLIB}
EXTRACONFIGURE+=	zlib zlib-dynamic
.else
EXTRACONFIGURE+=	no-zlib no-zlib-dynamic
.endif

.if ${PORT_OPTIONS:MSCTP}
EXTRACONFIGURE+=	sctp
.else
EXTRACONFIGURE+=	no-sctp
.endif

.if ${PORT_OPTIONS:MSSL2}
EXTRACONFIGURE+=	enable-ssl2
.else
EXTRACONFIGURE+=	no-ssl2
.endif

.if ${PORT_OPTIONS:MSSL3}
EXTRACONFIGURE+=	enable-ssl3
.else
EXTRACONFIGURE+=	no-ssl3 no-ssl3-method
.endif

.if ${PORT_OPTIONS:MMD2}
EXTRACONFIGURE+=	enable-md2
.else
EXTRACONFIGURE+=	no-md2
.endif

.if ${PORT_OPTIONS:MRC5}
EXTRACONFIGURE+=	enable-rc5
.else
EXTRACONFIGURE+=	no-rc5
.endif

.if ${PORT_OPTIONS:MPADLOCK}
PATCH_DIST_STRIP=	-p1
PATCH_SITES+=	http://git.alpinelinux.org/cgit/aports/plain/main/openssl/:padlock
PATCHFILES+=	1001-crypto-hmac-support-EVP_MD_CTX_FLAG_ONESHOT-and-set-.patch:padlock \
		1002-backport-changes-from-upstream-padlock-module.patch:padlock \
		1003-engines-e_padlock-implement-sha1-sha224-sha256-accel.patch:padlock \
		1004-crypto-engine-autoload-padlock-dynamic-engine.patch:padlock
.endif

EXTRACONFIGURE+=	no-gmp

.if ${PORT_OPTIONS:MRFC3779}
EXTRACONFIGURE+=	enable-rfc3779
.else
EXTRACONFIGURE+=	no-rfc3779
.endif

.if ${PORT_OPTIONS:MEC}
EXTRACONFIGURE+=	enable-ec_nistp_64_gcc_128
.else
EXTRACONFIGURE+=	no-ec_nistp_64_gcc_128
.endif

.if ${OPENSSL_SHLIBVER_BASE} > ${OPENSSL_SHLIBVER}
pre-everything::
	@${ECHO_CMD} "#"
	@${ECHO_CMD} "# this ports conflicts with your base system"
	@${ECHO_CMD} "# you have to uninstall your ssl port"
	@${ECHO_CMD} "# please use DEFAULT_VERSIONS+= ssl=base instead."
	@${ECHO_CMD} "#"
	@${FALSE}

.endif

post-patch:
	${REINPLACE_CMD} -e 's|m4 -B 8192|m4|g' \
		${WRKSRC}/crypto/des/Makefile
	${REINPLACE_CMD} -e 's|SHLIB_VERSION_NUMBER "1.0.0"|SHLIB_VERSION_NUMBER "${OPENSSL_SHLIBVER}"|' \
		${WRKSRC}/crypto/opensslv.h
	${REINPLACE_CMD} -e 's|ERR_R_MALLOC_ERROR|ERR_R_MALLOC_FAILURE|' \
		${WRKSRC}/crypto/bio/bss_dgram.c
.if ${PORT_OPTIONS:MEXPCIPHERS}
	${REINPLACE_CMD} -e 's|TLS1_ALLOW_EXPERIMENTAL_CIPHERSUITES	0|TLS1_ALLOW_EXPERIMENTAL_CIPHERSUITES	1|' \
		${WRKSRC}/ssl/tls1.h
.endif

do-configure:
	${REINPLACE_CMD} -e "s|options 386|options|" \
		${WRKSRC}/config
	cd ${WRKSRC} \
	&& ${SETENV} CC="${CC}" FREEBSDCC="${CC}" CFLAGS="${CFLAGS}" PERL="${PERL}" \
	./config --prefix=${PREFIX} --openssldir=${OPENSSLDIR} \
		--install_prefix=${STAGEDIR} \
		-L${PREFIX}/lib ${EXTRACONFIGURE}

post-configure:
	${REINPLACE_CMD} \
		-e 's|^MANDIR=.*$$|MANDIR=$$(PREFIX)/man|' \
		-e 's|$$(LIBDIR)/pkgconfig|libdata/pkgconfig|g' \
		-e 's|LIBVERSION=[^ ]* |LIBVERSION=${OPENSSL_SHLIBVER} |' \
		${WRKSRC}/Makefile

post-install-SHARED-on:
.for i in libcrypto libssl
	${INSTALL_DATA} ${WRKSRC}/$i.so.${OPENSSL_SHLIBVER} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf $i.so.${OPENSSL_SHLIBVER} ${STAGEDIR}${PREFIX}/lib/$i.so
.endfor

post-install-MAN3-off:
	${RM} -rf ${STAGEDIR}/${PREFIX}/man/man3
	${REINPLACE_CMD} -e 's|^man/man3/.*||' ${TMPPLIST}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/openssl.txt ${STAGEDIR}${DOCSDIR}/

test: build
	cd ${WRKSRC} && ${MAKE} test

regression-test:	test

.include <bsd.port.post.mk>
