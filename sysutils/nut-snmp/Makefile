# New ports collection makefile for:    nut-snmp
# Date created:         08 Jul 2005
# Whom:                 Joerg Pulz <Joerg.Pulz@frm2.tum.de>
#
# $FreeBSD$
#

COMMENT=	Network UPS Tools - SNMP driver

# Local variables
#

RUN_DEPENDS=	upsd:${PORTSDIR}/sysutils/nut

PLIST=		${.CURDIR}/pkg-plist
SUBSYS=		snmp

# Local overrides
#

MASTERDIR=	${.CURDIR}/../nut

.include "${MASTERDIR}/Makefile"
