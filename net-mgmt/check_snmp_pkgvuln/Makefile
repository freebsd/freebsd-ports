# New ports collection makefile for:	check_snmp_pkgvuln
# Date created:				2 November 2005
# Whom:					Jarrod Sayers <jarrod@netleader.com.au>
#
# $FreeBSD$
#

PORTNAME=	check_snmp_pkgvuln
PORTVERSION=	0.01
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.cultdeadsheep.org/~clement/FreeBSD/nagios/
PKGNAMEPREFIX=	nagios-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jarrod@netleader.com.au
COMMENT=	Security vulnerability plugin for Nagios

RUN_DEPENDS=	snmpwalk:${PORTSDIR}/net-mgmt/net-snmp \
		portaudit:${PORTSDIR}/security/portaudit

NAGIOS_PLUGIN_DIR?=	libexec/nagios

NO_WRKSUBDIR=	yes

PLIST_SUB=	NAGIOS_PLUGIN_DIR=${NAGIOS_PLUGIN_DIR}

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' ${WRKSRC}/${PORTNAME}

do-build:

do-install:
	@${MKDIR} ${PREFIX}/${NAGIOS_PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/${NAGIOS_PLUGIN_DIR}

.include <bsd.port.mk>
