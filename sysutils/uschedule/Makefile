# New ports collection makefile for:	uschedule
# Date created:		2004-02-19
# Whom:			Thomas Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	uschedule
PORTVERSION=	0.7.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ohse.de/uwe/uschedule/

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A scheduler program, designed to replace cron(8) and at(1)

BUILD_DEPENDS=	${LOCALBASE}/bin/tai64nlocal:${PORTSDIR}/sysutils/daemontools
RUN_DEPENDS=	${LOCALBASE}/bin/multilog:${PORTSDIR}/sysutils/daemontools

DISABLE_SIZE=	yes
WRKSRC=		${WRKDIR}/admin/${DISTNAME}

MAN1=		uschedule.1 uschedulecmd.1 uscheduleconf.1 uschedulecp.1 \
		uscheduleedit.1 uschedulelist.1 uschedulerm.1
MAN7=		uschedule_intro.7
MAN8=		uscheduled.8
PORTDOCS=	ChangeLog NEWS SECURITY-BUG
bin=		uschedule uschedulecmd uscheduleconf uschedulecp \
		uscheduleedit uschedulelist uschedulerm
sbin=		uscheduled
PLIST_FILES=	${bin:S/^/bin\//}
PLIST_FILES+=	${sbin:S/^/sbin\//}

do-build:
	cd ${WRKSRC} && package/compile && package/check

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
	cd ${WRKSRC}/compile && ${INSTALL_PROGRAM} ${${d}} ${PREFIX}/${d}
.endfor
	@${CAT} pkg-message

.include <bsd.port.mk>
