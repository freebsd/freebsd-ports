# New ports collection makefile for:	zabbix16-agent
# Date created:		2009-12-10
# Whom:			Jim Riggs <ports@christianserving.org>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PKGNAMESUFFIX=	-agent

MASTERDIR=	${.CURDIR}/../zabbix16-server

PLIST=		${PKGDIR}/pkg-plist.agent

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options
OPTIONS=	IPV6 "Support for IPv6" on

.include <bsd.port.options.mk>
.include "${MASTERDIR}/Makefile"
