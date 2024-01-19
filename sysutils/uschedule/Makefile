PORTNAME=	uschedule
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ohse.de/uwe/uschedule/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scheduler program, designed to replace cron(8) and at(1)
WWW=		https://www.ohse.de/uwe/uschedule.html

BUILD_DEPENDS=	${LOCALBASE}/bin/tai64nlocal:sysutils/daemontools
RUN_DEPENDS=	${LOCALBASE}/bin/multilog:sysutils/daemontools

BROKEN_aarch64=		fails to build: regparm is not valid on this platform
BROKEN_armv6=		fails to build: regparm is not valid on this platform
BROKEN_armv7=		fails to build: regparm is not valid on this platform
BROKEN_riscv64=		fails to build: regparm is not valid on this platform

WRKSRC=		${WRKDIR}/admin/${DISTNAME}

TEST_TARGET=	check

PORTDOCS=	ChangeLog NEWS SECURITY-BUG
bin=		uschedule uschedulecmd uscheduleconf uschedulecp \
		uscheduleedit uschedulelist uschedulerm uscheduleruntimelimit
sbin=		uscheduled
PLIST_FILES=	${bin:S,^,bin/,} ${bin:S,^,share/man/man1/,:S,$,.1.gz,} \
		share/man/man7/uschedule_intro.7.gz share/man/man8/uscheduled.8.gz \
		sbin/uscheduled

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
USES+=		compiler:gcc-c++11-lib
.endif

pre-build:
	${ECHO_CMD} "${CC}" > ${WRKSRC}/src/conf-cc
	${ECHO_CMD} "${CFLAGS}" > ${WRKSRC}/src/conf-cflags

do-install:
	(cd ${WRKSRC}/command && ${INSTALL_PROGRAM} ${bin} \
		${STAGEDIR}${PREFIX}/bin)
	${INSTALL_PROGRAM} ${WRKSRC}/command/${sbin} ${STAGEDIR}${PREFIX}/sbin
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${bin:S,$,.1,} \
		${STAGEDIR}${PREFIX}/share/man/man1)
	${INSTALL_MAN} ${WRKSRC}/doc/uschedule_intro.7 \
		${STAGEDIR}${PREFIX}/share/man/man7
	${INSTALL_MAN} ${WRKSRC}/doc/uscheduled.8 \
		${STAGEDIR}${PREFIX}/share/man/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/src && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
