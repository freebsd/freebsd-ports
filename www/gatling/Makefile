# Ports collection Makefile for: gatling
# Date created:			Feb 21, 2004
# Whom:				Thomas-Martin Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	gatling
PORTVERSION=	0.10
CATEGORIES=	www benchmarks ftp ipv6
MASTER_SITES=	http://dl.fefe.de/

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A high performance webserver with scalability benchmark tools

BUILD_DEPENDS=	libowfat>=0.25:${PORTSDIR}/devel/libowfat

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	gatling

CFLAGS+=	-I${LOCALBASE}/include/libowfat -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}

MAKEFILE=	GNUmakefile
MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"

bin=		dl
sbin=		gatling
MAN8=		gatling.8
PORTDOCS=	CHANGES README README.antidos README.cgi README.ftp \
		README.htaccess \
		README.http README.performance README.prefetch README.proxy \
		README.redirect
PORTEXAMPLES=	run-gatling cgi acc getlinks hcat hitprofile matchiprange \
		referrer

OPTIONS=	GATLING_BENCHMARKS "Install some benchmark programs" on \
		GATLING_SMB "Add (read only) SMB support" on \
		GATLING_TLS "Build and install tlsgatling" on \
		GATLING_ZLIB "Compress outgoing data" on \
		GATLING_OPTIMIZED_CFLAGS "Add additional optimizations" on

.include <bsd.port.pre.mk>

.if defined(WITH_GATLING_BENCHMARKS) || defined(WITH_BENCHMARKS)
PORTDOCS+=	README.bindbench README.forkbench README.httpbench \
		README.manymapbench README.mmapbench
bin+=		bindbench forkbench forksbench httpbench ioerr manymapbench \
		mktestdata mmapbench pthreadbench
examples+=	prep run-bench
MAN1+=		bench.1
MAKE_ENV+=	BENCHMARKS=1
.endif

.if defined(WITH_GATLING_OPTIMIZED_CFLAGS) && !defined(WITH_DEBUG)
CFLAGS+=	-O2 -fomit-frame-pointer
.endif

.if defined(WITH_GATLING_SMB)
USE_ICONV=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	ICONV=1
.else
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-disable_smb
.endif

.if defined(WITH_GATLING_TLS)
MAKE_ENV+=	TLSGATLING=1
sbin+=		tlsgatling
PORTDOCS+=	README.tls
.endif

.if defined(WITH_GATLING_ZLIB)
MAKE_ENV+=	ZLIB=1
.endif

.if defined(WITH_DEBUG)
MAKE_ENV+=	DEBUG=1
STRIP=
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

PLIST_FILES=	${bin:S,^,bin/,} ${sbin:S,^,sbin/,} sbin/gatling_wrapper

pre-install:
	@cd ${WRKSRC} && ${CP} gatling.1 gatling.8

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${bin} ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${sbin} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/gatling_wrapper ${PREFIX}/sbin
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
.if !empty(MAN1)
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
.endif
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN8} ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
