# Created by: Thomas Seck <tmseck@netcologne.de>
# $FreeBSD$

PORTNAME=	uschedule
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ohse.de/uwe/uschedule/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scheduler program, designed to replace cron(8) and at(1)

BUILD_DEPENDS=	${LOCALBASE}/bin/tai64nlocal:${PORTSDIR}/sysutils/daemontools
RUN_DEPENDS=	${LOCALBASE}/bin/multilog:${PORTSDIR}/sysutils/daemontools

WRKSRC=		${WRKDIR}/admin/${DISTNAME}

MAN1=		uschedule.1 uschedulecmd.1 uscheduleconf.1 uschedulecp.1 \
		uscheduleedit.1 uschedulelist.1 uschedulerm.1 \
		uscheduleruntimelimit.1
MAN7=		uschedule_intro.7
MAN8=		uscheduled.8
PORTDOCS=	ChangeLog NEWS SECURITY-BUG
bin=		uschedule uschedulecmd uscheduleconf uschedulecp \
		uscheduleedit uschedulelist uschedulerm uscheduleruntimelimit
sbin=		uscheduled
PLIST_FILES=	${bin:S,^,bin/,}
PLIST_FILES+=	${sbin:S,^,sbin/,}

NO_STAGE=	yes
pre-build:
	${ECHO_CMD} "${CC}" > ${WRKSRC}/src/conf-cc
	${ECHO_CMD} "${CFLAGS}" > ${WRKSRC}/src/conf-cflags

regression-test: build
	cd ${WRKSRC} && ${MAKE} check

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.for section in 1 7 8
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN${section}} \
 	    ${MAN${section}PREFIX}/man/man${section}
.endfor
.for d in bin sbin
	cd ${WRKSRC}/command && ${INSTALL_PROGRAM} ${${d}} ${PREFIX}/${d}
.endfor
	@${CAT} pkg-message

.include <bsd.port.mk>
