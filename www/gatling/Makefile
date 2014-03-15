# Created by: Thomas-Martin Seck <tmseck@netcologne.de>
# $FreeBSD$

PORTNAME=	gatling
PORTVERSION=	0.13
CATEGORIES=	www benchmarks ftp ipv6
MASTER_SITES=	http://dl.fefe.de/

MAINTAINER=	tmseck@FreeBSD.org
COMMENT=	A high performance webserver with scalability benchmark tools

BUILD_DEPENDS=	libowfat>=0.29:${PORTSDIR}/devel/libowfat

USE_BZIP2=	yes
USES=		gmake
USE_OPENSSL=	yes
USE_RC_SUBR=	gatling

CFLAGS+=	-I${LOCALBASE}/include/libowfat -I${OPENSSLINC} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}

MAKEFILE=	GNUmakefile

bin=		dl
sbin=		gatling
MAN8=		gatling.8
PORTDOCS=	CHANGES README README.antidos README.cgi README.ftp \
		README.htaccess \
		README.http README.performance README.prefetch README.proxy \
		README.redirect
PORTEXAMPLES=	run-gatling cgi acc getlinks hcat hitprofile matchiprange \
		referrer

OPTIONS_DEFINE=	BENCHMARKS SMB TLS ZLIB OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	BENCHMARKS SMB TLS ZLIB OPTIMIZED_CFLAGS
BENCHMARKS_DESC=	Install some benchmark programs
TLS_DESC=		Build and install tlsgatling
ZLIB_DESC=		Compress outgoing data

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MBENCHMARKS}
PORTDOCS+=	README.bindbench README.forkbench README.httpbench \
		README.manymapbench README.mmapbench
bin+=		bindbench forkbench forksbench httpbench ioerr manymapbench \
		mktestdata mmapbench pthreadbench
examples+=	prep run-bench
MAN1+=		bench.1
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

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

PLIST_FILES=	${bin:S,^,bin/,} ${sbin:S,^,sbin/,} sbin/gatling_wrapper

pre-install:
	@cd ${WRKSRC} && ${CP} gatling.1 gatling.8

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${bin} ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${sbin} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/gatling_wrapper ${PREFIX}/sbin
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
.if !empty(MAN1)
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
.endif
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN8} ${MAN8PREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
