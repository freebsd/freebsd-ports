# Created by: Thomas-Martin Seck <tmseck@netcologne.de>
# $FreeBSD$

PORTNAME=	gatling
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	www benchmarks ftp ipv6
MASTER_SITES=	http://dl.fefe.de/

MAINTAINER=	coco@executive-computing.de
COMMENT=	High performance webserver with scalability benchmark tools

LICENSE=	GPLv2

BUILD_DEPENDS=	libowfat>=0.29:devel/libowfat

USES=		gmake ssl tar:bzip2
USE_RC_SUBR=	gatling

CFLAGS+=	-I${LOCALBASE}/include/libowfat -I${OPENSSLINC} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}

MAKEFILE=	GNUmakefile

bin=		dl
sbin=		gatling
GATLING8=	gatling.8
PLIST_FILES=	man/man8/gatling.8.gz
PORTDOCS=	CHANGES README README.antidos README.cgi README.ftp \
		README.htaccess \
		README.http README.performance README.prefetch README.proxy \
		README.redirect
PORTEXAMPLES=	run-gatling cgi acc getlinks hcat hitprofile matchiprange \
		referrer

OPTIONS_DEFINE=	BENCHMARKS SMB TLS ZLIB OPTIMIZED_CFLAGS DOCS EXAMPLES DEBUG
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=	BENCHMARKS SMB TLS ZLIB OPTIMIZED_CFLAGS
BENCHMARKS_DESC=	Install some benchmark programs
TLS_DESC=		Build and install tlsgatling
ZLIB_DESC=		Compress outgoing data

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MBENCHMARKS}
PORTDOCS+=	README.bindbench README.forkbench README.httpbench \
		README.manymapbench README.mmapbench
bin+=		bindbench forkbench forksbench httpbench ioerr manymapbench \
		mktestdata mmapbench pthreadbench
PORTEXAMPLES+=	prep run-bench
BENCH1=		bench.1
PLIST_FILES+=	man/man1/bench.1.gz
MAKE_ENV+=	BENCHMARKS=1
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS} && !defined(WITH_DEBUG)
CFLAGS+=	-O2 -fomit-frame-pointer
.endif

.if ${PORT_OPTIONS:MSMB}
USES+=		iconv
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	ICONV=1
.else
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-disable_smb
.endif

.if ${PORT_OPTIONS:MTLS}
MAKE_ENV+=	TLSGATLING=1
sbin+=		tlsgatling
PORTDOCS+=	README.tls
.endif

.if ${PORT_OPTIONS:MZLIB}
MAKE_ENV+=	ZLIB=1
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ENV+=	DEBUG=1
STRIP=
.endif

PLIST_FILES+=	${bin:S,^,bin/,} ${sbin:S,^,sbin/,} sbin/gatling_wrapper

post-patch:
	${REINPLACE_CMD} -e 's/\(trymd5.c\) \(-lcrypto\)/\1 $$(LDFLAGS) \2/'	\
		${WRKSRC}/GNUmakefile

pre-install:
	@cd ${WRKSRC} && ${CP} gatling.1 gatling.8

do-install:
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} ${bin} ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} ${sbin} ${STAGEDIR}${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${FILESDIR}/gatling_wrapper ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.if !empty(BENCH1)
	@cd ${WRKSRC} && ${INSTALL_MAN} ${BENCH1} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endif
	@cd ${WRKSRC} && ${INSTALL_MAN} ${GATLING8} ${STAGEDIR}${MAN8PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
