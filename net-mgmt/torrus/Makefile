# Created by: Corey Smith <corsmith@gmail.com>
# $FreeBSD$

PORTNAME=	torrus
PORTVERSION=	2.05
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/torrus/torrus/

MAINTAINER=	corsmith@gmail.com
COMMENT=	The Data Series Processing Framework - think mrtg with xml configs

LICENSE=	GPLv2

BUILD_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-BerkeleyDB>=0:${PORTSDIR}/databases/p5-BerkeleyDB \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Apache-Session>=0:${PORTSDIR}/www/p5-Apache-Session \
		p5-FCGI>=0:${PORTSDIR}/www/p5-FCGI \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GNOME=	libxml2
USE_PERL5_RUN=	yes
GNU_CONFIGURE=	YES

USERS=		torrus
GROUPS=		torrus
PLIST_SUB=	TORRUS_USER=${USERS}
USE_RC_SUBR=	torrus_collector torrus_monitor

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		var_user=${USERS} var_group=${USERS} \
		torrus_user=${USERS} \
		defrrddir=/var/torrus/collector_rrd \
		pkghome=${DATADIR} \
		pkgbindir=${PREFIX}/libexec/torrus \
		pkgdocdir=${DOCSDIR} \
		exmpdir=${EXAMPLESDIR} \
		perllibdir=${SITE_PERL} \
		scriptsdir=${PREFIX}/libexec/torrus/scripts \
		--enable-pkgonly

MAN1=		torrus.1 torrus_acledit.1 torrus_buildsearchdb.1 \
		torrus_cleanup.1 torrus_clearcache.1 torrus_collector.1 \
		torrus_compilexml.1 torrus_configinfo.1 \
		torrus_configsnapshot.1 torrus_devdiscover.1 \
		torrus_flushmonitors.1 torrus_genddx.1 \
		torrus_genlist.1 torrus_genreport.1 torrus_monitor.1 \
		torrus_nodeid.1 torrus_rrddir2xml.1 torrus_schedulerinfo.1 \
		torrus_snmpfailures.1 torrus_srvderive.1 \
		torrus_ttproclist.1

MAN7=		torrus_action_printemail.7 torrus_action_snmptrap.7 \
		torrus_action_notify.7 torrus_install_plugin.7

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
