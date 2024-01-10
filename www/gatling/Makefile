PORTNAME=	gatling
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	www benchmarks ftp
MASTER_SITES=	https://www.fefe.de/gatling/

MAINTAINER=	coco@executive-computing.de
COMMENT=	High performance web server with scalability benchmark tools
WWW=		https://www.fefe.de/gatling/

LICENSE=	GPLv2

BROKEN_mips=	fails to compile: dirfd.c: error: expected ';', ',' or ')' before 'key'
BROKEN_mips64=	fails to compile: dirfd.c: error: expected ';', ',' or ')' before 'key'

BUILD_DEPENDS=	libowfat>=0.32:devel/libowfat

USES=		compiler:c++11-lang gmake localbase:ldflags ssl tar:xz
USE_RC_SUBR=	gatling

MAKEFILE=	GNUmakefile

CFLAGS+=	-I${LOCALBASE}/include/libowfat -I${OPENSSLINC}
# Make alloca() prototype visible
CFLAGS+=	-D__BSD_VISIBLE
# Make crypt() prototype visible
CFLAGS+=	-D__XSI_VISIBLE
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES=	${PLIST_BIN:S,^,bin/,} \
		${PLIST_SBIN:S,^,sbin/,} \
		share/man/man8/gatling.8.gz \
		sbin/gatling_wrapper

PORTDOCS=	CHANGES README README.antidos README.cgi README.ftp \
		README.htaccess README.http README.performance README.prefetch \
		README.proxy README.redirect
PORTEXAMPLES=	acc cgi getlinks hcat hitprofile matchiprange referrer \
		run-gatling

OPTIONS_DEFINE=		BENCHMARKS BROKEN_ITOJUN_V6 DEBUG DOCS EXAMPLES \
			OPTIMIZED_CFLAGS SMB TLS ZLIB
OPTIONS_DEFAULT=	BENCHMARKS OPTIMIZED_CFLAGS SMB TLS ZLIB
OPTIONS_SUB=		yes

BENCHMARKS_DESC=	Install some benchmark programs
BROKEN_ITOJUN_V6_DESC=	Works around problems binding to IPv4 addresses
TLS_DESC=		Build and install tlsgatling
ZLIB_DESC=		Compress outgoing data

BENCHMARKS_MAKE_ENV=		BENCHMARKS=1
BENCHMARKS_PLIST_FILES=		share/man/man1/bench.1.gz
BENCHMARKS_PORTDOCS=		README.bindbench README.forkbench \
				README.httpbench README.manymapbench \
				README.mmapbench
BENCHMARKS_PORTEXAMPLES=	prep run-bench
BENCHMARKS_VARS=		BENCH1=bench.1 \
		PLIST_BIN+=bindbench forkbench forksbench httpbench ioerr manymapbench mktestdata mmapbench pthreadbench
# Causes a warning about "KAME madness" but works around
# gatling failing to bind to IPv4 addresses.
BROKEN_ITOJUN_V6_CFLAGS=	-D__broken_itojun_v6__
DEBUG_MAKE_ENV=			DEBUG=1
DEBUG_VARS=			STRIP=
SMB_USES=			iconv
SMB_MAKE_ENV=			ICONV=1
SMB_EXTRA_PATCHES_OFF=		${PATCHDIR}/extra-patch-disable_smb
TLS_MAKE_ENV=			TLSGATLING=1
TLS_PORTDOCS=			README.tls
TLS_VARS=			PLIST_SBIN+=tlsgatling
ZLIB_MAKE_ENV=			ZLIB=1

PLIST_BIN=	dl
PLIST_SBIN=	gatling
GATLING8=	gatling.8

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS} && !defined(WITH_DEBUG)
CFLAGS+=	-O2 -fomit-frame-pointer
.endif

post-patch:
	${REINPLACE_CMD} -e 's/\(trymd5.c\) \(-lcrypto\)/\1 $$(LDFLAGS) \2/'	\
		${WRKSRC}/GNUmakefile

pre-install:
	cd ${WRKSRC} && ${CP} gatling.1 gatling.8

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PLIST_BIN} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PLIST_SBIN} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/gatling_wrapper ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.if !empty(BENCH1)
	cd ${WRKSRC} && ${INSTALL_MAN} ${BENCH1} ${STAGEDIR}${PREFIX}/share/man/man1
.endif
	cd ${WRKSRC} && ${INSTALL_MAN} ${GATLING8} ${STAGEDIR}${PREFIX}/share/man/man8

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
