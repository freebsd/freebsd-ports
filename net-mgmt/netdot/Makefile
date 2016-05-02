# Created by: Nick Hilliard
# $FreeBSD$

PORTNAME=	netdot
PORTVERSION=	1.0.7
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://netdot.uoregon.edu/pub/dists/

MAINTAINER=	nick@foobar.org
COMMENT=	Open source tool to organize and maintain network information

LICENSE=	GPLv2

RUN_DEPENDS=	p5-libapreq2>=0:www/p5-libapreq2 \
		mp2bug:www/mod_perl2 \
		p5-Apache-Session>=1.6:www/p5-Apache-Session \
		p5-Apache-AuthCookie>=0:www/p5-Apache-AuthCookie \
		p5-Apache2-SiteControl>=1.0:www/p5-Apache2-SiteControl \
		p5-URI>=0:net/p5-URI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-SQL-Translator>=0.07:databases/p5-SQL-Translator \
		p5-Class-DBI>=3.0.17:databases/p5-Class-DBI \
		p5-Class-DBI-AbstractSearch>=0:databases/p5-Class-DBI-AbstractSearch \
		p5-SNMP-Info>=2.06:net-mgmt/p5-SNMP-Info \
		p5-HTML-Mason>=1.31:www/p5-HTML-Mason \
		p5-Log-Dispatch>=0:devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Parallel-ForkManager>=0:devel/p5-Parallel-ForkManager \
		p5-Net-IRR>=0:net/p5-Net-IRR \
		p5-NetAddr-IP>=4.042:net-mgmt/p5-NetAddr-IP \
		p5-Net-Patricia>=1.20:net/p5-Net-Patricia \
		p5-Net-Appliance-Session>=3.113.610:net/p5-Net-Appliance-Session \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-DNS-ZoneFile-Fast>=1.12:dns/p5-Net-DNS-ZoneFile-Fast \
		p5-BIND-Config-Parser>=0:dns/p5-BIND-Config-Parser \
		p5-Carp-Assert>=0:devel/p5-Carp-Assert \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-Socket6>=0:net/p5-Socket6 \
		p5-GraphViz>=2.02:graphics/p5-GraphViz \
		rrdtool:databases/rrdtool \
		netdisco-mibs>=0:net-mgmt/netdisco-mibs

USES=		gmake perl5 shebangfix
NO_BUILD=	yes
USE_MYSQL=	yes

SUB_FILES=	pkg-message pkg-install
SUB_LIST=	WWWDIR="${WWWDIR}"	\
		WWWOWN="${WWWOWN}"	\
		WWWGRP="${WWWGRP}"	\
		CHOWN="${CHOWN}"	\
		CHMOD="${CHMOD}"

SHEBANG_FILES=	bin/*.pl bin/initdb upgrade/upgrade-tasks
SHEBANG_LANG=	perl perl2
perl2_OLD_CMD=	<<Make:PERL>>
perl2_CMD=	${LOCALBASE}/bin/perl

.include <bsd.port.pre.mk>

INSTALL_TARGET=	install		\
	PREFIX=${WWWDIR}	\
	PERL=${PERL}		\
	STAGEDIR=${STAGEDIR}${WWWDIR}	\
	APACHEUSER=${WWWOWN}	\
	APACHEGROUP=${WWWGRP}

post-patch:
	@${REINPLACE_CMD} "s#/usr/local/netdot#${WWWDIR}#g" ${WRKSRC}/netdot.cron ${WRKSRC}/Makefile ${WRKSRC}/import/import_ip_bulk.pl
	@${REINPLACE_CMD} "s#%%LOCALPREFIX%%#${PREFIX}#g" ${WRKSRC}/etc/Default.conf

post-install:
.for f in export/bind export/dhcpd export/ethers export/rancid export/smokeping export/sysmon htdocs/img/graphs lib/Netdot/Manual tmp/sessions/locks htdocs/masondata/cache
		@${TOUCH} ${STAGEDIR}${WWWDIR}/${f}/.keep-me
.endfor
.for f in initdb
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${WWWDIR}/bin/${f}
.endfor
	${MKDIR} ${STAGEDIR}${WWWDIR}/upgrade
.for f in Makefile updatedb upgrade-tasks
	${INSTALL_SCRIPT} ${WRKSRC}/upgrade/${f} ${STAGEDIR}${WWWDIR}/upgrade/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/netdot.cron ${STAGEDIR}${WWWDIR}/etc/netdot.cron
	${INSTALL_DATA} ${WRKSRC}/etc/default_data ${STAGEDIR}${WWWDIR}/etc/default_data

.include <bsd.port.post.mk>
