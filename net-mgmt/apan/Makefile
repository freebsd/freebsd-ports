# New ports collection makefile for:   apan
# Date created:        26 March 2004
# Whom:                Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	apan
PORTVERSION=	0.2.1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Tool for integrating Nagios with RRDTOOL

RUN_DEPENDS=	rrdtool:${PORTSDIR}/net/rrdtool \
		nagios:${PORTSDIR}/net-mgmt/nagios \
		bash:${PORTSDIR}/shells/bash2

NO_BUILD=	yes
USE_REINPLACE=	yes
NAGIOSDIR?=	/var/spool/nagios
DOC_FILES=	README CHANGELOG

WRKSRC=		${WRKDIR}/${PORTNAME}

do-configure:
	@${REINPLACE_CMD} \
		-e 's|%%APANCONFDIR%%|${PREFIX}/etc/apan/|' \
		-e 's|%%NAGIOSPLUGINSDIR%%|${PREFIX}/libexec/nagios/|' \
		-e 's|%%APANPLUGSDIR%%|${PREFIX}/libexec/${PORTNAME}/|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|/bin/sh|${PREFIX}/bin/bash|' \
		${WRKSRC}/*.* ${WRKSRC}/README
	@${REINPLACE_CMD} \
		-e 's|%%APANCONFDIR%%|${PREFIX}/etc/apan/|' \
		-e 's|%%NAGIOSPLUGINSDIR%%|${PREFIX}/libexec/nagios/|' \
		-e 's|%%APANPLUGSDIR%%|${PREFIX}/libexec/${PORTNAME}/|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|/bin/bash|${PREFIX}/bin/bash|' \
		-e 's|/bin/sh|${PREFIX}/bin/bash|' \
		${WRKSRC}/plugs/*
	@${REINPLACE_CMD} \
		-e 's|%%APANCONFDIR%%|${PREFIX}/etc/apan/|' \
		-e 's|%%NAGIOSPLUGINSDIR%%|${PREFIX}/libexec/nagios/|' \
		-e 's|%%APANPLUGSDIR%%|${PREFIX}/libexec/${PORTNAME}/|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|/bin/bash|${PREFIX}/bin/bash|' \
		-e 's|/bin/sh|${PREFIX}/bin/bash|' \
		${WRKSRC}/libexec/*

do-install:
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
	@${MKDIR} ${NAGIOSDIR}/rrd
	@${INSTALL_SCRIPT} ${WRKSRC}/apan.sh ${PREFIX}/libexec/nagios/
	@${INSTALL_SCRIPT} ${WRKSRC}/apan.cgi ${PREFIX}/share/nagios/cgi-bin
	@${INSTALL_SCRIPT} ${WRKSRC}/generate.cgi ${PREFIX}/share/nagios/cgi-bin
	@${INSTALL_SCRIPT} ${WRKSRC}/libexec/check_megaide ${PREFIX}/libexec/nagios
	@${INSTALL_SCRIPT} ${WRKSRC}/libexec/check_nt_load ${PREFIX}/libexec/nagios
	@${INSTALL_SCRIPT} ${WRKSRC}/libexec/check_unix_load ${PREFIX}/libexec/nagios
	@${INSTALL_SCRIPT} ${WRKSRC}/libexec/disk_by_snmp ${PREFIX}/libexec/nagios
	@${INSTALL_SCRIPT} ${WRKSRC}/libexec/uptime_by_snmp ${PREFIX}/libexec/nagios
	@${INSTALL_SCRIPT} ${WRKSRC}/plugs/debug.sh ${PREFIX}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/plugs/disk.sh ${PREFIX}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/plugs/load.sh ${PREFIX}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/plugs/nt_utils.sh ${PREFIX}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/plugs/printer.sh ${PREFIX}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/plugs/snmp.sh ${PREFIX}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/plugs/utils.sh ${PREFIX}/libexec/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/apan.cfg ${PREFIX}/etc/${PORTNAME}/apan.cfg-sample
	@${INSTALL_DATA} ${WRKSRC}/apan.defs ${PREFIX}/etc/${PORTNAME}/apan.defs-sample
	@${INSTALL_DATA} ${WRKSRC}/graph.png ${PREFIX}/share/nagios/images/logos

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
