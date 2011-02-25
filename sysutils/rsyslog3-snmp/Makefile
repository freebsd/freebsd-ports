# New ports collection makefile for:	rsyslog3-snmp
# Date created:		6 May 2008
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

COMMENT=	SNMP trap sender for rsyslog

MNAME=	snmp
MTYPES=	om
LIB_DEPENDS=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp

.include "${.CURDIR}/../rsyslog3/bsd.rsyslog.mk"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${OSVERSION} >= 800000
BROKEN=		Does not link on i386: can't find symbol snmp_timeout in libnetsnmp
.endif

.include <bsd.port.post.mk>
