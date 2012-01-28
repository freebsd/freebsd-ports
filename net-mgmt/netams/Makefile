# New ports collection makefile for: NetAMS
# Date created:        24 December 2003
# Whom: 	       jura@netams.com
#
# $FreeBSD$
#

PORTNAME=	netams
PORTVERSION=	3.4.5
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netams.com/files/

MAINTAINER=	jura@netams.com
COMMENT=	Network Traffic Accounting and Monitoring Software

LIB_DEPENDS=	pcap.1:${PORTSDIR}/net/libpcap

USE_SUBMAKE=	yes
SUB_FILES=	pkg-message
USE_RC_SUBR=	netams
MANCOMPRESSED=	no

OPTIONS=	DEBUG		"Build with debug symbols"			off \
		MYSQL		"Build with MySQL storage support" 		on  \
		POSTGRESQL	"Build with PostgreSQL storage support"		off \
		CGI 		"Install admin/user CGI scripts"		off

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}"

ADMINCGI=	.htaccess index.cgi policy.cgi showusercard.cgi user.cgi  \
		access.cgi login.cgi quota.cgi showusercard.tmpl view.cgi \
		account.cgi netams.cgi radius.cgi subplan.cgi config.cgi  \
		plan.cgi russian.res unit.cgi cardtool.cgi graph.cgi \
		monitor.cgi rrdgraph.cgi statistic.cgi
USERCGI=	.htaccess config.cgi netams_api.pl russian.res \
		netams_example.cgi usertool.cgi admintool.cgi login.cgi \
		netams_graph.cgi activate.cgi activate.tmpl netams_html.cgi \
		statistic.pl
IMAGES=		logo_sm.jpg admintool-logo.gif showtable-logo.gif rrdgraph-logo.gif
MAN8=		netams.8 flowprobe.8 netamsctl.8

.include <bsd.port.pre.mk>

.if !defined(WITH_MYSQL) && !defined(WITH_POSTGRESQL)
IGNORE=requires at least one database backend selected. Run 'make config'
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
PLIST_SUB+=		POSTGRESQL=""
.else
PLIST_SUB+=		POSTGRESQL="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
BROKEN_WITH_MYSQL=	323
PLIST_SUB+=		MYSQL=""
.else
PLIST_SUB+=		MYSQL="@comment "
.endif

.if defined(WITH_POSTGRESQL) && defined(WITH_CGI)
RUN_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if defined(WITH_MYSQL) && defined(WITH_CGI)
RUN_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql50
.endif

.if defined(WITH_CGI)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${SITE_PERL}/GD/Text.pm:${PORTSDIR}/graphics/p5-GD-TextUtil \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Crypt/GeneratePassword.pm:${PORTSDIR}/security/p5-Crypt-GeneratePassword
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd \
		jpeg.11:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	CGI=""
.else
PLIST_SUB+=	CGI="@comment "
.endif

pre-patch:
.if !defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e 's|.*sh configure.sh|& -nodebug|' \
		${WRKSRC}/Makefile
.endif
.if !defined(WITH_POSTGRESQL)
	@${REINPLACE_CMD} -e 's|locate_file "libpq\.so".*|v1="" \&\& v2=""|' \
		${WRKSRC}/configure.sh
.endif
.if defined(WITH_MYSQL)
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!/usr/local/bin/perl|' ${WRKSRC}/addon/mysql_rotate.pl
.else
	@${REINPLACE_CMD} -e 's|locate_file "libmysqlclient\.so".*|v1="" \&\& v2=""|' \
		${WRKSRC}/configure.sh
	@${REINPLACE_CMD} -e 's|locate_file "libmysqlclient\.a".*|v1="" \&\& v2=""|' \
		${WRKSRC}/configure.sh
.endif
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!/usr/local/bin/perl|' ${WRKSRC}/addon/snmp2netams.pl
	@${REINPLACE_CMD} -e 's|locate_file "libglib-2\.0\.so".*|v1="" \&\& v2="" \&\& v3=""|' \
		${WRKSRC}/configure.sh
	@${REINPLACE_CMD} -e 's|locate_file "openssl/md5\.h".*|v1=""|' \
		${WRKSRC}/configure.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/netams ${PREFIX}/libexec/netams
	${INSTALL_PROGRAM} ${WRKSRC}/src/flowprobe ${PREFIX}/sbin/flowprobe
	${INSTALL_PROGRAM} ${WRKSRC}/src/ipfw2netflow ${PREFIX}/sbin/ipfw2netflow
	${INSTALL_PROGRAM} ${WRKSRC}/src/ascii2netflow ${PREFIX}/sbin/ascii2netflow
	${INSTALL_PROGRAM} ${WRKSRC}/src/netamsctl ${PREFIX}/bin/netamsctl
	${MKDIR} ${DATADIR} ${DATADIR}/tools ${DATADIR}/tools/oracle
	${INSTALL_DATA} ${WRKSRC}/addon/netams.conf ${PREFIX}/etc/netams.conf.sample
	${INSTALL_DATA} ${WRKSRC}/addon/ru-networks.txt ${DATADIR}/ru-networks.txt.sample
	${INSTALL_DATA} ${WRKSRC}/addon/ua-networks.txt ${DATADIR}/ua-networks.txt.sample
	${INSTALL_DATA} ${WRKSRC}/addon/.netamsctl.rc ${DATADIR}/.netamsctl.rc
.if defined(WITH_MYSQL)
	${INSTALL_DATA} ${WRKSRC}/addon/mysql_rotate.pl ${DATADIR}/mysql_rotate.pl
	${INSTALL_DATA} ${WRKSRC}/addon/cardtool_schema.sql ${DATADIR}/tools/cardtool_schema.sql
.endif
.if defined(WITH_POSTGRESQL)
	${INSTALL_DATA} ${WRKSRC}/addon/cardtool_schema-Pg.sql ${DATADIR}/tools/cardtool_schema-Pg.sql
	${INSTALL_DATA} ${WRKSRC}/addon/postgresql_schema.sql ${DATADIR}/tools/postgresql_schema.sql
.endif
	${INSTALL_DATA} ${WRKSRC}/addon/snmp2netams.pl ${DATADIR}/snmp2netams.pl
	${INSTALL_DATA} ${WRKSRC}/addon/ua-networks-get.sh ${DATADIR}/ua-networks-get.sh
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/admin/billing_users_table.sql ${DATADIR}/tools/billing_users_table.sql
	${INSTALL_DATA} ${WRKSRC}/addon/oracle/netams.sh ${DATADIR}/tools/oracle/netams.sh
	${INSTALL_DATA} ${WRKSRC}/addon/oracle/netams_drop.sql ${DATADIR}/tools/oracle/netams_drop.sql
	${INSTALL_DATA} ${WRKSRC}/addon/oracle/netams_tb.sql ${DATADIR}/tools/oracle/netams_tb.sql
	${INSTALL_DATA} ${WRKSRC}/addon/oracle/netams_tg.sql ${DATADIR}/tools/oracle/netams_tg.sql
	${INSTALL_DATA} ${WRKSRC}/addon/oracle/netams_ts.sql ${DATADIR}/tools/oracle/netams_ts.sql
	${INSTALL_DATA} ${WRKSRC}/addon/netams-apache-freebsd.conf ${DATADIR}/netams-apache-freebsd.conf
.if defined(WITH_CGI)
	${MKDIR} ${WWWDIR} ${WWWDIR}/cgi-bin ${WWWDIR}/cgi-bin/admin ${WWWDIR}/images
	${INSTALL_DATA} ${WRKSRC}/addon/index.html ${WWWDIR}/index.html
	${INSTALL_DATA} ${WRKSRC}/addon/netams.js ${WWWDIR}/netams.js
.for f in ${IMAGES}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/images/${f} ${WWWDIR}/images/
.endfor
.for f in ${USERCGI}
	${INSTALL_PROGRAM} ${WRKSRC}/cgi-bin/${f} ${WWWDIR}/cgi-bin/
.endfor
.for f in ${ADMINCGI}
	${INSTALL_PROGRAM} ${WRKSRC}/cgi-bin/admin/${f} ${WWWDIR}/cgi-bin/admin/
.endfor
.endif
.for f in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${PREFIX}/man/man8/
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
