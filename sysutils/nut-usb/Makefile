# New ports collection makefile for:    nut-usb
# Date created:         08 Jul 2005
# Whom:                 Joerg Pulz <Joerg.Pulz@frm2.tum.de>
#
# $FreeBSD$
#

COMMENT=	Network UPS Tools - USB driver

# Local variables
#

RUN_DEPENDS=	upsd:${PORTSDIR}/sysutils/nut

PLIST=		${.CURDIR}/pkg-plist
SUBSYS=		usb

# Local overrides
#

MASTERDIR=	${.CURDIR}/../nut

.include "${MASTERDIR}/Makefile"
