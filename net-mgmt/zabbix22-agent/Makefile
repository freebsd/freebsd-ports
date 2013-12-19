# Created by: Pakhom Golynga <pakhom706@gmail.com>
# $FreeBSD$

PORTNAME=	zabbix22
PKGNAMESUFFIX=	-agent
CATEGORIES=	net-mgmt

MASTERDIR=	${.CURDIR}/../zabbix22-server

PLIST=		${PKGDIR}/pkg-plist.agent

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options
OPTIONS_DEFINE=	IPV6
OPTIONS_DEFAULT=	IPV6

NO_STAGE=	yes
.include <bsd.port.options.mk>
.include "${MASTERDIR}/Makefile"
