# New ports collection makefile for:	netsaint-plugins
# Date created:				Wed 12 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	netsaint-plugins
PORTVERSION=	1.2.8.4
CATEGORIES=	net
MASTER_SITES=	http://netsaintplug.sourceforge.net/src/
DISTNAME=	${PORTNAME}-1.2.8-4

MAINTAINER=	will@FreeBSD.org

# make absolutely sure we have the user/group added!
BUILD_DEPENDS=	netsaint:${PORTSDIR}/net/netsaint
RUN_DEPENDS=	netsaint:${PORTSDIR}/net/netsaint
.if defined(WANT_QSTAT)
BUILD_DEPENDS+=	qstat:${PORTSDIR}/games/qstat
RUN_DEPENDS+=	qstat:${PORTSDIR}/games/qstat
.endif
.if defined(WANT_FPING)
BUILD_DEPENDS+=	fping:${PORTSDIR}/net/fping
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
.endif
.if defined(WANT_SNMP)
BUILD_DEPENDS+=	snmpcheck:${PORTSDIR}/net/ucd-snmp
RUN_DEPENDS+=	snmpcheck:${PORTSDIR}/net/ucd-snmp
.endif

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
