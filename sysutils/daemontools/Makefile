# New ports collection makefile for:	daemontools
# Date created:		09 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	daemontools
PORTVERSION=	0.76
PORTREVISION=	14
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/daemontools/ \
		ftp://cr.yp.to/daemontools/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Service monitoring and logging utilities by djb

OPTIONS=	MAN	"Install Gerrit Pape's manual pages" on \
		S_EARLY	"Start early, before the normal daemons" off \
		S_NORMAL	"Start normally in the usual boot sequence" on \
		SIGQ12	"Add svc support for QUIT, USR1, and USR2 signals" off \
		TESTS	"Run the test suite, fails on NFS-mounted workdir" on

.include <bsd.port.pre.mk>

.if defined(WITH_S_EARLY)
. if defined(WITH_S_NORMAL)
IGNORE=		Exactly one of S_EARLY and S_NORMAL must be specified.
. else
SVSCAN_REQUIRE?=	SERVERS
SVSCAN_BEFORE?=		DAEMON
. endif
.else
. if defined(WITH_S_NORMAL)
SVSCAN_REQUIRE?=	LOGIN
SVSCAN_BEFORE?=
. else
IGNORE=		Either S_EARLY or S_NORMAL must be specified.
. endif
.endif

SUB_LIST+=	SVSCAN_REQUIRE=${SVSCAN_REQUIRE} SVSCAN_BEFORE=${SVSCAN_BEFORE}

.if !defined(WITHOUT_MAN)
MANDATE=	-20010714
MASTER_SITES+=	http://smarden.org/pape/djb/manpages/:1
DISTFILES+=	${DISTNAME}-man${MANDATE}.tar.gz:1

MAN8=		envdir.8 envuidgid.8 fghack.8 multilog.8 pgrphack.8 \
		readproctitle.8 setlock.8 setuidgid.8 softlimit.8 \
		supervise.8 svc.8 svok.8 svscan.8 svscanboot.8 svstat.8 \
		tai64n.8 tai64nlocal.8
MANCOMPRESSED=	no
.endif

.if defined(WITH_SIGQ12)
PATCH_SITES+=	http://thedjbway.org/patches/:sigq12
PATCHFILES+=	daemontools-0.76.sigq12.patch:sigq12
PATCH_DIST_STRIP=	-p2
.endif

USE_RC_SUBR=	svscan

WRKSRC=		${WRKDIR}/admin/${DISTNAME}/src

ALL_TARGET=	it
INSTALL_TARGET=	setup check

.if defined(WITHOUT_TESTS)
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
.if !defined(WITHOUT_MAN)
	@${INSTALL_MAN} ${WRKDIR}/daemontools-man/*.8 ${PREFIX}/man/man8/
.endif

.include <bsd.port.post.mk>
