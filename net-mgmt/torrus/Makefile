# Created by: Corey Smith <corsmith@gmail.com>
# $FreeBSD$

PORTNAME=	torrus
PORTVERSION=	2.09
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/torrus/torrus/

MAINTAINER=	corsmith@gmail.com
COMMENT=	Data Series Processing Framework - think mrtg with xml configs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rrdtool>=0:databases/rrdtool \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-BerkeleyDB>=0:databases/p5-BerkeleyDB \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
		p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
		p5-URI>=0:net/p5-URI \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-Apache-Session>=0:www/p5-Apache-Session \
		p5-FCGI>=0:www/p5-FCGI \
		p5-JSON>0:converters/p5-JSON
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GNOME=	libxml2
USES=		perl5
USE_PERL5=	run
GNU_CONFIGURE=	yes
NO_ARCH=	yes

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
	@${MKDIR} ${STAGEDIR}/var/torrus/session_data/store
	@${MKDIR} ${STAGEDIR}/var/torrus/session_data/lock
	@${MKDIR} ${STAGEDIR}/var/torrus/session_data
	@${MKDIR} ${STAGEDIR}/var/torrus/reports
	@${MKDIR} ${STAGEDIR}/var/torrus/db
	@${MKDIR} ${STAGEDIR}/var/torrus/collector_rrd
	@${MKDIR} ${STAGEDIR}/var/torrus/cache
	@${MKDIR} ${STAGEDIR}/var/torrus
	@${MKDIR} ${STAGEDIR}/var/run/torrus
	@${MKDIR} ${STAGEDIR}/var/log/torrus

.include <bsd.port.mk>
