# New ports collection makefile for:	net-mgmt/netdot
# Date created:				16 January 2012
# Whom:					Nick Hilliard
#
# $FreeBSD$
#

PORTNAME=	netdot
PORTVERSION=	1.0.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://netdot.uoregon.edu/pub/dists/

MAINTAINER=	nick@foobar.org
COMMENT=	An open source tool to organize and maintain network information

LICENSE=	GPLv2

RUN_DEPENDS=	p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2 \
		p5-Apache-Session>=1.6:${PORTSDIR}/www/p5-Apache-Session \
		p5-Apache-AuthCookie>=0:${PORTSDIR}/www/p5-Apache-AuthCookie \
		p5-Apache2-SiteControl>=1.0:${PORTSDIR}/www/p5-Apache2-SiteControl \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-SQL-Translator>=0.07:${PORTSDIR}/databases/p5-SQL-Translator \
		p5-Class-DBI>=3.0.17:${PORTSDIR}/databases/p5-Class-DBI \
		p5-Class-DBI-AbstractSearch>=0:${PORTSDIR}/databases/p5-Class-DBI-AbstractSearch \
		p5-DBIx-DataSource>=0:${PORTSDIR}/databases/p5-DBIx-DataSource \
		p5-SNMP-Info>=2.06:${PORTSDIR}/net-mgmt/p5-SNMP-Info \
		p5-HTML-Mason>=1.31:${PORTSDIR}/www/p5-HTML-Mason \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-Net-IRR>=0:${PORTSDIR}/net/p5-Net-IRR \
		p5-NetAddr-IP>=0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-Net-Patricia>=1.20:${PORTSDIR}/net/p5-Net-Patricia \
		p5-Net-Appliance-Session>=3.113.610:${PORTSDIR}/net/p5-Net-Appliance-Session \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-DNS-ZoneFile-Fast>=1.12:${PORTSDIR}/dns/p5-Net-DNS-ZoneFile-Fast \
		p5-BIND-Config-Parser>=0:${PORTSDIR}/dns/p5-BIND-Config-Parser \
		p5-Carp-Assert>=0:${PORTSDIR}/devel/p5-Carp-Assert \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6 \
		p5-GraphViz>=2.02:${PORTSDIR}/graphics/p5-GraphViz \
		rrdtool:${PORTSDIR}/databases/rrdtool \
		netdisco-mibs>=0:${PORTSDIR}/net-mgmt/netdisco-mibs

NO_BUILD=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_MYSQL=	yes

SUB_FILES=	pkg-message pkg-install
SUB_LIST=	WWWDIR="${WWWDIR}"	\
		WWWOWN="${WWWOWN}"	\
		WWWGRP="${WWWGRP}"	\
		CHOWN="${CHOWN}"	\
		CHMOD="${CHMOD}"

PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-Digest-SHA>=5.47:${PORTSDIR}/security/p5-Digest-SHA
.endif
.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build
.endif

INSTALL_TARGET=	install		\
	PREFIX=${WWWDIR}	\
	APACHEUSER=${WWWOWN}	\
	APACHEGROUP=${WWWGRP}

post-patch:
	@${REINPLACE_CMD} "s#/usr/local/netdot#${WWWDIR}#g" ${WRKSRC}/netdot.cron ${WRKSRC}/Makefile ${WRKSRC}/import/import_ip_bulk.pl
	@${REINPLACE_CMD} "s#%%LOCALPREFIX%%#${PREFIX}#g" ${WRKSRC}/etc/Default.conf

post-install:
.for f in export/bind export/dhcpd export/ethers export/rancid export/smokeping export/sysmon htdocs/img/graphs lib/Netdot/Manual tmp/sessions/locks htdocs/masondata/cache
		@${TOUCH} ${WWWDIR}/${f}/.keep-me
.endfor
.for f in initdb defragdb
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${WWWDIR}/bin/${f}
.endfor
	${MKDIR} ${WWWDIR}/upgrade
.for f in Makefile updatedb upgrade-tasks
	${INSTALL_SCRIPT} ${WRKSRC}/upgrade/${f} ${WWWDIR}/upgrade/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/netdot.cron ${WWWDIR}/etc/netdot.cron
	${INSTALL_DATA} ${WRKSRC}/etc/default_data ${WWWDIR}/etc/default_data
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
