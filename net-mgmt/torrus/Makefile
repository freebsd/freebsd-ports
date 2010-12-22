# New ports collection makefile for:	torrus
# Date created:				July 13th, 2005
# Whom:	      				Corey Smith <corsmith@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	torrus
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	corsmith@gmail.com
COMMENT=	The Data Series Processing Framework - think mrtg with xml configs

BUILD_DEPENDS=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/databases/rrdtool \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Proc/Daemon.pm:${PORTSDIR}/devel/p5-Proc-Daemon \
		${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session \
		${SITE_PERL}/${PERL_ARCH}/FCGI.pm:${PORTSDIR}/www/p5-FastCGI \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	libxml2
USE_PERL5_RUN=	5.8.1+
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
