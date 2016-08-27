# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	1.1.0
#DISTVERSIONSUFFIX=	a
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

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config
CONFIGURE_ENV=	PERL="${PERL}"
CONFIGURE_ARGS=	--openssldir=${OPENSSLDIR} ${EXTRACONFIGURE}

OPTIONS_DEFINE=	SHARED THREADS SSE2 ASM ZLIB SCTP SSL3 RFC3779 RC5 DOCS MAN3
OPTIONS_DEFAULT=SHARED THREADS SSE2 SCTP MAN3
OPTIONS_DEFINE_i386=	I386
.for a in amd64 ia64
OPTIONS_DEFINE_${a}=	EC
OPTIONS_DEFAULT_${a}=	EC
.endfor
TARGET_ARCH?=	${MACHINE_ARCH}
.if ${TARGET_ARCH} == "mips64el"
OPTIONS_DEFINE_mips=	EC
OPTIONS_DEFAULT_mips=	EC
.endif
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
I386_DESC?=	Optimize for i386 (instead of i486+)
SSE2_DESC?=	runtime SSE2 detection
ASM_DESC?=	optimized Assembler code
SHARED_DESC?=	build of shared libs
ZLIB_DESC?=	zlib compression support
GMP_DESC?=	gmp support (LGPLv3)
SCTP_DESC?=	SCTP protocol support
SSL3_DESC?=	SSLv3 protocol support
RFC3779_DESC?=	RFC3779 support (BGP)
RC5_DESC?=	RC5 cipher (patented)
EC_DESC?=	Optimize NIST elliptic curves
MAN3_DESC?=	Install API manpages (section 3)

USES=		cpe perl5
USE_PERL5=	build
MAKE_ARGS+=	WHOLE_ARCHIVE_FLAG=--whole-archive
MAKE_ENV+=	LIBRPATH="${PREFIX}/lib" GREP_OPTIONS=
SUB_FILES=	pkg-message

SHARED_CONFIGURE_ON=	shared
SHARED_PLIST_SUB=	SHLIBVER=${OPENSSL_SHLIBVER}
THREADS_CONFIGURE_ON=	threads
THREADS_CONFIGURE_OFF=	no-threads
ZLIB_CONFIGURE_ON=	zlib zlib-dynamic
ZLIB_CONFIGURE_OFF=	no-zlib no-zlib-dynamic
SCTP_CONFIGURE_ON=	sctp
SCTP_CONFIGURE_OFF=	no-sctp
SSE2_CONFIGURE_OFF=	no-sse2
ASM_CONFIGURE_ON=	asm
ASM_CONFIGURE_OFF=	no-asm
SSL3_CONFIGURE_ON=	enable-ssl3
SSL3_CONFIGURE_OFF=	no-ssl3 no-ssl3-method
RFC3779_CONFIGURE_ON=	enable-rfc3779
RFC3779_CONFIGURE_OFF=	no-rfc3779
RC5_CONFIGURE_ON=	enable-rc5
RC5_CONFIGURE_OFF=	no-rc5
I386_CONFIGURE_ON=	386
EC_CONFIGURE_ON=	enable-ec_nistp_64_gcc_128
EC_CONFIGURE_OFF=	no-ec_nistp_64_gcc_128

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

.if ${PORT_OPTIONS:MASM}
BROKEN_sparc64=	option ASM generates illegal instructions
.endif

.if ${PORT_OPTIONS:MSHARED}
USE_LDCONFIG=	yes
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
	${REINPLACE_CMD} \
		-e 's|^MANDIR=.*$$|MANDIR=$$(INSTALLTOP)/man|' \
		-e 's| install_html_docs$$||' \
		-e 's|$$(LIBDIR)/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/Configurations/unix-Makefile.tmpl

post-configure:
	${REINPLACE_CMD} \
		-e 's|.(SHLIB_MAJOR)[.].(SHLIB_MINOR)|${OPENSSL_SHLIBVER}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e 's|SHLIB_VERSION_NUMBER "1.1"|SHLIB_VERSION_NUMBER "${OPENSSL_SHLIBVER}"|' \
		${WRKSRC}/include/openssl/opensslv.h

post-install:
	${RM} -f ${STAGEDIR}${OPENSSLDIR}/openssl.cnf
	${RM} -f ${STAGEDIR}${PREFIX}/man/man7/ct.7.gz

post-install-MAN3-off:
.if empty(PORT_OPTIONS:MMAN3)
	${RM} -rf ${STAGEDIR}/${PREFIX}/man/man3
	${REINPLACE_CMD} -e 's|^man/man3/.*||' ${TMPPLIST}
.endif

test: build
	cd ${WRKSRC} && ${MAKE} test

regression-test:	test

.include <bsd.port.post.mk>
