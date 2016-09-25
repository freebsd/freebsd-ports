# Created by: Pakhom Golynga <pg@pakhom.spb.ru>
# $FreeBSD$

PORTNAME=	zabbix32
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	-agent

MAINTAINER=	pakhom@pakhom.spb.ru
COMMENT=	Enterprise-class open source distributed monitoring (${PKGNAMESUFFIX:S/^-//})

LICENSE=	GPLv2

MASTERDIR=	${.CURDIR}/../zabbix32-server
PLIST=		${PKGDIR}/pkg-plist.agent

OPTIONS_DEFINE=		IPV6
OPTIONS_DEFAULT=	OPENSSL

.include "${MASTERDIR}/Makefile"
