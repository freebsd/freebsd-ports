# ports collection makefile for:   apcpwr
# Date created:        1 June 2003
# Whom:                jwd
#
# $FreeBSD$
#

PORTNAME=		apcpwr
PORTVERSION=		1.2
CATEGORIES=		sysutils net
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jwd

MAINTAINER=	jwd@FreeBSD.org
COMMENT=	Control APC 9211 MasterSwitchs via snmp

RUN_DEPENDS=	snmpwalk:${PORTSDIR}/net-mgmt/net-snmp

MAN8=		apcpwr.8

post-install:
	@ ${ECHO}
	@ ${SED} -e "s:%%PREFIX%%:${PREFIX}:g" pkg-message | fmt
	@ ${ECHO}

.include <bsd.port.mk>
