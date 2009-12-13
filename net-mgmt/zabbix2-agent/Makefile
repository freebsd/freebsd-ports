# Ports collection makefile for:	zabbix-agent
# Date created:		Jun 18 2003
# Whom:			Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PKGNAMESUFFIX=	-agent

MASTERDIR=	${.CURDIR}/../zabbix-server

PLIST=		${PKGDIR}/pkg-plist.agent

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options
OPTIONS=	IPV6 "Support for IPv6" on

.include <bsd.port.options.mk>
.include "${MASTERDIR}/Makefile"
