# Created by: Dom Mitchell <dom@myrddin.demon.co.uk>
# $FreeBSD$

PORTNAME=	daemontools
PORTVERSION=	0.76
PORTREVISION=	16
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/daemontools/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Service monitoring and logging utilities by djb

LICENSE=	PD
LICENSE_NAME=	public domain
LICENSE_TEXT=	The daemontools-0.76.tar.gz archive is in the public domain as of 2007.12.28.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS=	freedt-[0-9]* serialmail-[0-9]*

OPTIONS_DEFINE=	MAN SIGQ12 TESTS
MAN_DESC=	Install Gerrit Pape's manual pages
S_EARLY_DESC=	Start early, before the normal daemons
S_NORMAL_DESC=	Start normally in the usual boot sequence
SIGQ12_DESC=	Add svc support for QUIT, USR1, and USR2 signals
TESTS_DESC=	Run the test suite, fails on NFS-mounted workdir

OPTIONS_SINGLE=	SEQ
OPTIONS_SINGLE_SEQ=	S_EARLY S_NORMAL

OPTIONS_DEFAULT=	MAN S_NORMAL TESTS

.include <bsd.port.options.mk>

. if ${PORT_OPTIONS:MS_EARLY}
SVSCAN_REQUIRE?=	SERVERS
SVSCAN_BEFORE?=		DAEMON
. endif

. if ${PORT_OPTIONS:MS_NORMAL}
SVSCAN_REQUIRE?=	LOGIN
SVSCAN_BEFORE?=
. endif

SUB_LIST+=	SVSCAN_REQUIRE=${SVSCAN_REQUIRE} SVSCAN_BEFORE=${SVSCAN_BEFORE}

.if ${PORT_OPTIONS:MMAN}
MANDATE=	-20010714
MASTER_SITES+=	http://smarden.org/pape/djb/manpages/:1 \
  		http://mirror.shatow.net/freebsd/${PORTNAME}/:1
DISTFILES+=	${DISTNAME}-man${MANDATE}.tar.gz:1

MAN8=		envdir.8 envuidgid.8 fghack.8 multilog.8 pgrphack.8 \
		readproctitle.8 setlock.8 setuidgid.8 softlimit.8 \
		supervise.8 svc.8 svok.8 svscan.8 svscanboot.8 svstat.8 \
		tai64n.8 tai64nlocal.8
MANCOMPRESSED=	no
.endif

.if ${PORT_OPTIONS:MSIGQ12}
#PATCH_SITES+=	http://thedjbway.org/patches/:sigq12
PATCH_SITES+=	${MASTER_SITE_LOCAL:S/%SUBDIR%\//jgh\/sysutils\/daemontools\/:sigq12/} \
		http://people.FreeBSD.org/~jgh/ports/sysutils/daemontools/:sigq12
PATCHFILES+=	daemontools-0.76.sigq12.patch:sigq12
PATCH_DIST_STRIP=	-p2
.endif

USE_RC_SUBR=	svscan

WRKSRC=		${WRKDIR}/admin/${DISTNAME}/src

ALL_TARGET=	it
INSTALL_TARGET=	setup check

.if ${PORT_OPTIONS:MTESTS}
EXTRA_PATCHES+=	${FILESDIR}/rts-skip.patch
.endif

post-patch:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP}" > ${WRKSRC}/conf-ld

do-install:
	(while read cmd; do \
		if ${FILE} ${WRKSRC}/$$cmd | ${GREP} -q "shell script"; then \
			${INSTALL_SCRIPT} ${WRKSRC}/$$cmd ${PREFIX}/bin; \
		else \
			${INSTALL_PROGRAM} ${WRKSRC}/$$cmd ${PREFIX}/bin; \
		fi \
	done) < ${WRKSRC}/../package/commands

post-install:
.if ${PORT_OPTIONS:MMAN}
	${INSTALL_MAN} ${WRKDIR}/daemontools-man/*.8 ${MAN8PREFIX}/man/man8/
.endif

.include <bsd.port.mk>
