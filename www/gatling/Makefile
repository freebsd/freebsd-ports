# Ports collection Makefile for: gatling
# Date created:			Feb 21, 2004
# Whom:				Thomas-Martin Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	gatling
PORTVERSION=	0.8
CATEGORIES=	www benchmarks ftp ipv6
MASTER_SITES=	http://dl.fefe.de/

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A high performance webserver with scalability benchmark tools

BUILD_DEPENDS=	${LOCALBASE}/lib/libowfat.a:${PORTSDIR}/devel/libowfat

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes

CFLAGS+=	-I${LOCALBASE}/include/libowfat -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}

MAKEFILE=	GNUmakefile
MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"

bin=		dl
examples=	run-gatling cgi
examplesdir=	${EXAMPLESDIR:S,^${PREFIX}/,,}
sbin=		gatling
MAN8=		gatling.8
.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES README README.cgi README.ftp README.htaccess \
		README.http README.performance README.prefetch README.proxy \
		README.redirect
.endif

OPTIONS=	GATLING_BENCHMARKS "Install some benchmark programs" on \
		GATLING_ICONV "Use charset conversion" off \
		GATLING_TLS "Install tlsgatling" off \
		GATLING_ZLIB "Compress outgoing data" off \
		GATLING_OPTIMIZED_CFLAGS "Use optimized CFLAGS" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BENCHMARKS) && !defined(WITHOUT_GATLING_BENCHMARKS)
PORTDOCS+=	README.bindbench README.forkbench README.httpbench \
		README.manymapbench README.mmapbench
bin+=		bindbench forkbench forksbench httpbench ioerr manymapbench \
		mktestdata mmapbench pthreadbench
examples+=	prep run-bench
MAKE_ENV+=	BENCHMARKS=1
.endif

.if !defined(WITHOUT_GATLING_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -fomit-frame-pointer
.endif

.if defined(WITH_GATLING_ICONV)
USE_ICONV=	yes
CFLAGS+=	-I${PREFIX}/include
MAKE_ENV+=	ICONV=1
.endif

.if defined(WITH_GATLING_TLS)
.if defined(WITH_GATLING_ZLIB)
# For reasons unknown, gatling with both HTTPS and zlib support only compiles
# with gcc 3.1 and above. Depend on gcc 3.2+ because 3.1 is already marked
# deprecated in the ports collection.
USE_GCC=	3.2+
.endif
MAKE_ENV+=	TLSGATLING=1
sbin+=		tlsgatling
portdocs+=	README.tls
.endif

.if defined(WITH_GATLING_ZLIB)
MAKE_ENV+=	ZLIB=1
.endif

PLIST_DIRS=	${examplesdir}
PLIST_FILES=	${bin:S,^,bin/,} ${examples:S,^,${examplesdir}/,} \
		${sbin:S,^,sbin/,}

pre-install:
	@cd ${WRKSRC} && ${CP} gatling.1 gatling.8

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${bin} ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${sbin} ${PREFIX}/sbin
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${examples} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN8} ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
