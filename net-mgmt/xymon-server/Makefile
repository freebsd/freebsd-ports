# New ports collection makefile for:    xymon-server
# Date created:         24 Jan 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	xymon
PORTVERSION=	4.3.10
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/xymon/Xymon/${PORTVERSION}
PKGNAMESUFFIX=	-server${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	System for monitoring servers and networks

BUILD_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool

LICENSE=	GPLv2
MAKE_JOBS_UNSAFE=	yes

# Options
XYMONUSER?=	xymon
XYMONHOSTNAME?=	xymon.example.com
XYMONHOSTIP?=	127.0.0.1

USE_GMAKE=	yes
USE_OPENSSL=	yes
CONFIGURE_ENV=	MAKE=gmake
MAKE_ENV+=	XYMONUSER="${XYMONUSER}"
MAKE_ENV+=	XYMONHOSTNAME="${XYMONHOSTNAME}"
MAKE_ENV+=	XYMONHOSTIP="${XYMONHOSTIP}"
USE_RC_SUBR=	xymon-server.sh
SUB_LIST+=	XYMONUSER="${XYMONUSER}"
PLIST_SUB+=	XYMONUSER="${XYMONUSER}" VARBASE="/var"

CONFIG_FILES=	alerts.cfg analysis.cfg cgioptions.cfg client-local.cfg \
		columndoc.csv combo.cfg graphs.cfg holidays.cfg protocols.cfg \
		rrddefinitions.cfg tasks.cfg xymonserver.cfg
FIXME1=		alerts.cfg hosts.cfg xymon-apache-open xymon-apache-secure
FIXME2=		analysis.cfg combo.cfg holidays.cfg rrddefinitions.cfg \
		snmpmibs.cfg xymonmenu.cfg xymonserver-migration.cfg

MAN1 =	ackinfo.cgi.1 acknowledge.cgi.1 appfeed.cgi.1 clientupdate.1 \
	combostatus.1 confreport.cgi.1 criticaleditor.cgi.1 \
	criticalview.cgi.1 csvinfo.cgi.1 datepage.cgi.1 eventlog.cgi.1 \
	findhost.cgi.1 ghostlist.cgi.1 history.cgi.1 hostgraphs.cgi.1 \
	logfetch.1 orcaxymon.1 report.cgi.1 reportlog.cgi.1 showgraph.cgi.1 \
	snapshot.cgi.1 statusreport.cgi.1 svcstatus.cgi.1 xymon.1 xymoncfg.1 \
	xymoncmd.1 xymondigest.1 xymongen.1 xymongrep.1 xymonnet-again.sh.1 \
	xymonnet.1 xymonpage.cgi.1 xymonping.1
MAN5=	alerts.cfg.5 analysis.cfg.5 cgioptions.cfg.5 client-local.cfg.5 \
	clientlaunch.cfg.5 combo.cfg.5 critical.cfg.5 graphs.cfg.5 \
	hosts.cfg.5 protocols.cfg.5 tasks.cfg.5 xymon-xmh.5 \
	xymonclient.cfg.5 xymonserver.cfg.5 xymonweb.5 xymonwebaccess.5
MAN7=	xymon.7
MAN8=	enadis.cgi.8 xymon-mailack.8 xymoncgimsg.cgi.8 xymond.8 \
	xymond_alert.8 xymond_capture.8 xymond_channel.8 xymond_client.8 \
	xymond_distribute.8 xymond_filestore.8 xymond_history.8 \
	xymond_hostdata.8 xymond_rrd.8 xymond_sample.8 xymonfetch.8 \
	xymonlaunch.8 xymonproxy.8 msgcache.8 trimhistory.8

OPTIONS=	LDAP	"Enable LDAP support" off \
		SNMP	"Enable Net-SNMP support" off

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
MAKE_ENV+=	WITH_LDAP=1
USE_OPENLDAP=	yes
.endif

.if defined(WITH_NETSNMP)
MAKE_ENV+=	WITH_NETSNMP=1
LIB_DEPENDS+=	netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp
.endif


post-patch:
	${REINPLACE_CMD} -e 's|!/bin/bash|!/usr/local/bin/bash|' \
		${WRKSRC}/xymond/xymonreports.sh.DIST

# Configure script is interactive
do-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

pre-install:
	if ! pw groupshow ${XYMONUSER}; then pw groupadd ${XYMONUSER} -g 280; fi
	if ! pw usershow ${XYMONUSER}; then pw useradd ${XYMONUSER} -g ${XYMONUSER} -u 280 \
		-h - -d ${WWWDIR} -s /usr/sbin/nologin -c "Xymon Monitor"; fi

post-install:
	-${MKDIR} ${WWWDIR}/server/etc
	${INSTALL_SCRIPT} ${WRKSRC}/build/upgrade430.sh ${WWWDIR}/server/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/renamevars ${WWWDIR}/server/bin/
.for i in ${FIXME1}
	${INSTALL_DATA} ${WRKSRC}/xymond/etcfiles/${i}.DIST ${WWWDIR}/server/etc/
.endfor
.for i in ${FIXME2}
	${INSTALL_DATA} ${WRKSRC}/xymond/etcfiles/${i} ${WWWDIR}/server/etc/${i}.DIST
.endfor
.for i in ${CONFIG_FILES}
	${CP} -np ${WWWDIR}/server/etc/${i}.DIST \
		${WWWDIR}/server/etc/${i}
.endfor

.include <bsd.port.post.mk>
