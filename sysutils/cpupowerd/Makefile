# New ports collection makefile for:   cpupowerd
# Date created:        2008-06-01
# Whom:                Bernhard Fr__hlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	cpupowerd
PORTVERSION=	0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	decke@bluelife.at
COMMENT=	A CPU over- and undervolting daemon

USE_RC_SUBR=	cpupowerd
ONLY_FOR_ARCHS=	i386 amd64
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ENV+=	GROUP=wheel \
		RIGHTS=555

OPTIONS=	CREATELOAD "Install createload.sh for stability testing" Off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800042
BUILD_DEPENDS+=	${LOCALBASE}/include/cpu.h:${PORTSDIR}/sysutils/devcpu
.endif

.if defined(WITH_CREATELOAD)
RUN_DEPENDS+=	burnMMX:${PORTSDIR}/sysutils/cpuburn
PLIST_SUB+=	CREATELOAD=""
.else
PLIST_SUB+=	CREATELOAD="@comment "
.endif

post-install:
.if defined(WITH_CREATELOAD)
	${INSTALL_SCRIPT} ${WRKSRC}/../tools/createload.sh ${PREFIX}/bin/createload.sh
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../CHANGELOG ${DOCSDIR}/CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/../COPYING ${DOCSDIR}/COPYING
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/../TODO ${DOCSDIR}/TODO
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
