# Created by: Douglas K. Rand <rand@iteris.com>
# $FreeBSD$

PORTNAME=	victorops-nagios
PORTVERSION=	1.4.20
CATEGORIES=	net-mgmt
MASTER_SITES=	http://software.victorops.com/

MAINTAINER=	rand@iteris.com
COMMENT=	Nagios integration for VictorOps incident notification service

USES=		shebangfix
SHEBANG_FILES=	${WRKSRC}/opt/victorops/nagios_plugin/bin/*

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
NO_ARCH=	YES

RESTRICTED=	Redistribution of software prohibited by VictorOps

OPTIONS_DEFINE=	QPAGE
OPTIONS_DEFAULT=
QPAGE_DESC=	Integrate qpage for victorops server problems

RUN_DEPENDS+=	bash:shells/bash \
		curl:ftp/curl

QPAGE_RUN_DEPENDS+=	qpage:comms/qpage
QPAGE_EXTRA_PATCHES+=	${FILESDIR}/qpage-patch

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_DATA} ${WRKSRC}/etc/cron.daily/victorops ${STAGEDIR}${PREFIX}/etc/periodic/daily/400.victorops
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/nagios
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/victorops
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/victorops
	${MKDIR} ${STAGEDIR}/var/log/victorops
	${INSTALL_DATA} ${WRKSRC}/opt/victorops/nagios_plugin/nagios_conf/victorops.cfg ${STAGEDIR}${PREFIX}/etc/nagios/victorops.cfg-sample
	${INSTALL_DATA} ${WRKSRC}/opt/victorops/nagios_plugin/conf/env.sh.sample ${STAGEDIR}${PREFIX}/etc/victorops
	${INSTALL_DATA} ${WRKSRC}/opt/victorops/nagios_plugin/conf/proxy.sh.sample ${STAGEDIR}${PREFIX}/etc/victorops
.for i in check_test_svc check_victorops_cmds check_victorops_forwarder \
	do_victorops_heartbeat enqueue_alert forward_alert_file forward_alerts \
	send_email_alert send_status stop_forwarder \
	url_encode.sed utils
	${INSTALL_SCRIPT} ${WRKSRC}/opt/victorops/nagios_plugin/bin/${i} ${STAGEDIR}${PREFIX}/libexec/victorops/${i}
.endfor

.include <bsd.port.mk>
