# Ports collection Makefile for: gatling
# Date created:			Feb 21, 2004
# Whom:				Thomas-Martin Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	gatling
PORTVERSION=	0.7
CATEGORIES=	www benchmarks ftp ipv6
MASTER_SITES=	http://dl.fefe.de/

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A high performance webserver with scalability benchmark tools

BUILD_DEPENDS=	${LOCALBASE}/lib/libowfat.a:${PORTSDIR}/devel/libowfat

USE_BZIP2=	yes
USE_OPENSSL=	yes

CFLAGS+=	-I${LOCALBASE}/include/libowfat -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -lowfat -L${OPENSSLLIB}

MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"

bin=		dl
examples=	run-gatling
examplesdir=	${EXAMPLESDIR:S,^${PREFIX}/,,}
sbin=		gatling tlsgatling
MAN8=		gatling.8
.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES README README.ftp README.htaccess README.http \
		README.performance README.prefetch README.proxy README.redirect
.endif

OPTIONS=	BENCHMARKS "Install system benchmark programs" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BENCHMARKS)
PORTDOCS+=	README.bindbench README.forkbench README.httpbench \
		README.manymapbench README.mmapbench
bin+=		bindbench forkbench forksbench httpbench ioerr manymapbench \
		mktestdata mmapbench pthreadbench
examples+=	prep run-bench
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
