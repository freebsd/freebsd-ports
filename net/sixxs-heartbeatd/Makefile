# New ports collection makefile for:   sixxs-heartbeatd
# Date created:                2004-04-23
# Whom:                        Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sixxs-heartbeatd
PORTVERSION=	20031026
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.sixxs.net/archive/sixxs/heartbeat/unix/
DISTNAME=	heartbeat-unix-2003-10-26
EXTRACT_SUFX=	.tgz

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	SixXS IPv6 tunnel broker heartbeat client

USE_RC_SUBR=	yes
WRKSRC=		${WRKDIR}/heartbeat

pre-build:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		-e 's:%%RC_SUBR%%:${RC_SUBR}:g' \
		${FILESDIR}/sixxs-heartbeatd.sh >${WRKDIR}/sixxs-heartbeatd.sh
	@${SED} -e 's:%%GIFCONFIG%%:${GIFCONFIG}:' \
		${WRKSRC}/client/heartbeat.conf >${WRKDIR}/heartbeat.conf

do-install:
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/sixxs-heartbeatd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/draft-massar-v6ops-heartbeat-00.txt \
		${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/heartbeat.conf ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/sixxs-heartbeatd.sh ${PREFIX}/etc/rc.d

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 501100
GIFCONFIG=	netbsd
.else
GIFCONFIG=	freebsd
.endif

.include <bsd.port.post.mk>
