# New ports collection makefile for: NetAMS
# Date created:        24 December 2003
# Whom: 	       jura@netams.com
#
# $FreeBSD$
#

PORTNAME=	netams
PORTVERSION=	3.4.5
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netams.com/files/

MAINTAINER=	jura@netams.com
COMMENT=	Network Traffic Accounting and Monitoring Software

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${SITE_PERL}/GD/Text.pm:${PORTSDIR}/graphics/p5-GD-TextUtil \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql50 \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Crypt/GeneratePassword.pm:${PORTSDIR}/security/p5-Crypt-GeneratePassword
RUN_DEPENDS=	httpd:${PORTSDIR}/www/apache22 \
		mysql-server>=5.0.86:${PORTSDIR}/databases/mysql50-server
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		mysqlclient.15:${PORTSDIR}/databases/mysql50-client \
		pcap.1:${PORTSDIR}/net/libpcap

USE_SUBMAKE=	yes
SUB_FILES=	pkg-message
USE_RC_SUBR=	netams
MANCOMPRESSED=	no

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}"

DATADIR=	${PREFIX}/etc

WWWDIR=		${PREFIX}/www/netams

ADMINCGI=	.htaccess index.cgi policy.cgi showusercard.cgi user.cgi  \
		access.cgi login.cgi quota.cgi showusercard.tmpl view.cgi \
		account.cgi netams.cgi radius.cgi subplan.cgi config.cgi  \
		plan.cgi russian.res unit.cgi cardtool.cgi graph.cgi \
		monitor.cgi rrdgraph.cgi statistic.cgi
CGI=		.htaccess config.cgi netams_api.pl russian.res \
		netams_example.cgi usertool.cgi admintool.cgi login.cgi \
		netams_graph.cgi activate.cgi activate.tmpl netams_html.cgi \
		statistic.pl
IMAGES=		logo_sm.jpg admintool-logo.gif showtable-logo.gif rrdgraph-logo.gif
MAN8=		netams.8 flowprobe.8 netamsctl.8

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/netams ${PREFIX}/libexec/netams
	${INSTALL_PROGRAM} ${WRKSRC}/src/flowprobe ${PREFIX}/sbin/flowprobe
	${INSTALL_PROGRAM} ${WRKSRC}/src/ipfw2netflow ${PREFIX}/sbin/ipfw2netflow
	${INSTALL_PROGRAM} ${WRKSRC}/src/ascii2netflow ${PREFIX}/sbin/ascii2netflow
	${INSTALL_PROGRAM} ${WRKSRC}/src/netamsctl ${PREFIX}/bin/netamsctl
	${MKDIR} ${WWWDIR} ${WWWDIR}/cgi-bin ${WWWDIR}/cgi-bin/admin ${WWWDIR}/images \
		${DATADIR}/netams ${DATADIR}/netams/tools ${DATADIR}/netams/tools/oracle \
		${DATADIR}/apache22 ${DATADIR}/apache22/Includes
	${INSTALL_DATA} ${WRKSRC}/addon/netams.conf ${DATADIR}/netams/netams.conf.sample
	${INSTALL_DATA} ${WRKSRC}/addon/ru-networks.txt ${DATADIR}/netams/ru-networks.txt.sample
	${INSTALL_DATA} ${WRKSRC}/addon/ua-networks.txt ${DATADIR}/netams/ua-networks.txt.sample
	${INSTALL_DATA} ${WRKSRC}/addon/.netamsctl.rc ${DATADIR}/.netamsctl.rc
	${INSTALL_DATA} ${WRKSRC}/addon/mysql_rotate.pl ${DATADIR}/netams/mysql_rotate.pl
	${INSTALL_DATA} ${WRKSRC}/addon/snmp2netams.pl ${DATADIR}/netams/snmp2netams.pl
	${INSTALL_DATA} ${WRKSRC}/addon/ua-networks-get.sh ${DATADIR}/netams/ua-networks-get.sh
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/admin/billing_users_table.sql ${DATADIR}/netams/tools/billing_users_table.sql
	${INSTALL_DATA} ${WRKSRC}/addon/cardtool_schema-Pg.sql ${DATADIR}/netams/tools/cardtool_schema-Pg.sql
	${INSTALL_DATA} ${WRKSRC}/addon/cardtool_schema.sql ${DATADIR}/netams/tools/cardtool_schema.sql
	${INSTALL_DATA} ${WRKSRC}/addon/oracle/netams.sh ${DATADIR}/netams/tools/oracle/netams.sh
	${INSTALL_DATA} ${WRKSRC}/addon/oracle/netams_drop.sql ${DATADIR}/netams/tools/oracle/netams_drop.sql
	${INSTALL_DATA} ${WRKSRC}/addon/oracle/netams_tb.sql ${DATADIR}/netams/tools/oracle/netams_tb.sql
	${INSTALL_DATA} ${WRKSRC}/addon/oracle/netams_tg.sql ${DATADIR}/netams/tools/oracle/netams_tg.sql
	${INSTALL_DATA} ${WRKSRC}/addon/oracle/netams_ts.sql ${DATADIR}/netams/tools/oracle/netams_ts.sql
	${INSTALL_DATA} ${WRKSRC}/addon/index.html ${WWWDIR}/index.html
	${INSTALL_DATA} ${WRKSRC}/addon/netams.js ${WWWDIR}/netams.js
	${INSTALL_DATA} ${WRKSRC}/addon/netams-apache-freebsd.conf ${DATADIR}/apache22/Includes/netams-apache-freebsd.conf
.for f in ${IMAGES}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/images/${f} ${WWWDIR}/images/
.endfor
.for f in ${CGI}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/${f} ${WWWDIR}/cgi-bin/
.endfor
.for f in ${ADMINCGI}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/admin/${f} ${WWWDIR}/cgi-bin/admin/
.endfor
.for f in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${PREFIX}/man/man8/
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
