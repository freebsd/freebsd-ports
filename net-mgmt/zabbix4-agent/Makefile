# Created by: Pakhom Golynga <pg@pakhom.spb.ru>
# $FreeBSD$

PORTNAME=	zabbix4
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	-agent

MASTERDIR=	${.CURDIR}/../zabbix4-server
PLIST=		${PKGDIR}/pkg-plist.agent

OPTIONS_DEFINE=		CURL IPV6
OPTIONS_DEFAULT=	CURL OPENSSL

.include "${MASTERDIR}/Makefile"
