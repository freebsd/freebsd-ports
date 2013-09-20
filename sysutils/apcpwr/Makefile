# Created by: jwd
# $FreeBSD$

PORTNAME=		apcpwr
PORTVERSION=		1.3
CATEGORIES=		sysutils net
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jwd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Control APC 9211 MasterSwitchs via snmp

RUN_DEPENDS=	snmpwalk:${PORTSDIR}/net-mgmt/net-snmp

PLIST_FILES=	bin/apcpwr etc/apcpwr.conf.dist
MAN8=		apcpwr.8

NO_STAGE=	yes
post-install:
	@ ${ECHO}
	@ ${SED} -e "s:%%PREFIX%%:${PREFIX}:g" pkg-message | fmt
	@ ${ECHO}

.include <bsd.port.mk>
