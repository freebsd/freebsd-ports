# Created by: Pakhom Golynga <pg@pakhom.spb.ru>
# $FreeBSD$

PORTNAME=	zabbix32
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	-agent

MASTERDIR=	${.CURDIR}/../zabbix32-server
PLIST=		${PKGDIR}/pkg-plist.agent

OPTIONS_DEFINE=		IPV6
OPTIONS_DEFAULT=	OPENSSL

.include "${MASTERDIR}/Makefile"
