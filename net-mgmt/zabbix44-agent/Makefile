# Created by: Pakhom Golynga <pg@pakhom.spb.ru>
# $FreeBSD$

PORTNAME=	zabbix44
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	-agent

MASTERDIR=	${.CURDIR}/../zabbix44-server
PLIST=		${PKGDIR}/pkg-plist.agent

OPTIONS_DEFINE=		CURL IPV6
OPTIONS_DEFAULT=	CURL OPENSSL

.include "${MASTERDIR}/Makefile"
