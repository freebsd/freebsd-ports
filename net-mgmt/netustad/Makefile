# New ports collection makefile for:   netustad
# Date created:                 4 July 2004
# Whom:                         Ozkan KIRIK <ozkan@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	netustad
PORTVERSION=	0.2b
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.enderunix.org/netustad/
DISTNAME=	${PORTNAME}-0.2-BETA

MAINTAINER=	ozkan@enderunix.org
COMMENT=	A Web based admin tool that manages network services

MAN8=		netustad.8 netustadpasswd.8
MAN5=		netustad.conf.5

USE_RC_SUBR=	yes
SED_SCRIPT+=    -e '{ s,%%PREFIX%%,${PREFIX},g; }'

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/netustad.sh >${WRKDIR}/netustad.sh
	@${SED} ${SED_SCRIPT} ${FILESDIR}/netustadctl >${WRKDIR}/netustadctl

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} ${SED_SCRIPT}
	${INSTALL_SCRIPT} ${WRKDIR}/netustad.sh ${PREFIX}/etc/rc.d/
	${INSTALL_SCRIPT} ${WRKDIR}/netustadctl ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES	${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING	${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ		${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/GPL-License	${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL	${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/THANKS	${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO		${DOCSDIR}
.endif

.include <bsd.port.mk>
