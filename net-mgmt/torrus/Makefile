# Created by: Corey Smith <corsmith@gmail.com>
# $FreeBSD$

PORTNAME=	torrus
PORTVERSION=	2.07
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/torrus/torrus/

MAINTAINER=	corsmith@gmail.com
COMMENT=	Data Series Processing Framework - think mrtg with xml configs

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
USES=		perl5
USE_PERL5=	run
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
		perllibdir=${PREFIX}/${SITE_PERL_REL} \
		scriptsdir=${PREFIX}/libexec/torrus/scripts \
		--enable-pkgonly

post-install:
	${INSTALL} -d -m 2775 ${STAGEDIR}/var/log/torrus
	${INSTALL} -d -m 775 ${STAGEDIR}/var/torrus
	${INSTALL} -d -m 2775 ${STAGEDIR}/var/torrus/cache
	${INSTALL} -d -m 2775 ${STAGEDIR}/var/torrus/collector_rrd
	${INSTALL} -d -m 2775 ${STAGEDIR}/var/torrus/db
	${INSTALL} -d -m 775 ${STAGEDIR}/var/torrus/reports
	${INSTALL} -d -m 775 ${STAGEDIR}/var/torrus/session_data
	${INSTALL} -d -m 2775 ${STAGEDIR}/var/torrus/session_data/lock
	${INSTALL} -d -m 2775 ${STAGEDIR}/var/torrus/session_data/store

.include <bsd.port.mk>
