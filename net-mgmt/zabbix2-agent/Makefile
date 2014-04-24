# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$

PORTNAME=	zabbix2
PKGNAMESUFFIX=	-agent
CATEGORIES=	net-mgmt

MASTERDIR=	${.CURDIR}/../zabbix2-server

PLIST=		${PKGDIR}/pkg-plist.agent

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options
OPTIONS_DEFINE=	IPV6
OPTIONS_DEFAULT=	IPV6

.include <bsd.port.options.mk>
.include "${MASTERDIR}/Makefile"
