# Created by: Jarrod Sayers <jarrod@netleader.com.au>
# $FreeBSD$

PORTNAME=	check_snmp_pkgvuln
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.cultdeadsheep.org/~clement/FreeBSD/nagios/
PKGNAMEPREFIX=	nagios-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Security vulnerability plugin for Nagios

RUN_DEPENDS=	snmpwalk:${PORTSDIR}/net-mgmt/net-snmp \
		portaudit:${PORTSDIR}/ports-mgmt/portaudit

NAGIOS_PLUGIN_DIR?=	libexec/nagios

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_SUB=	NAGIOS_PLUGIN_DIR=${NAGIOS_PLUGIN_DIR}

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' ${WRKSRC}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${NAGIOS_PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/${NAGIOS_PLUGIN_DIR}

.include <bsd.port.mk>
