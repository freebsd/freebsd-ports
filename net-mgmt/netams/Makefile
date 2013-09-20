# Created by: Yuriy N. Shkandybin <jura@netams.com>
# $FreeBSD$

PORTNAME=	netams
PORTVERSION=	3.4.5
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netams.com/files/

MAINTAINER=	jura@netams.com
COMMENT=	Network Traffic Accounting and Monitoring Software

LIB_DEPENDS=	pcap.1:${PORTSDIR}/net/libpcap

SSP_UNSAFE=	kernel module does not support ssp
USE_SUBMAKE=	yes
SUB_FILES=	pkg-message
USE_RC_SUBR=	netams
MANCOMPRESSED=	no

OPTIONS_DEFINE=	DEBUG CGI
OPTIONS_DEFAULT=	MYSQL
OPTIONS_MULTI=	DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL POSTGRESQL
DEBUG_DESC=	Build with debug symbols
MYSQL_DESC=	Build with MySQL storage support
POSTGRESQL_DESC=	Build with PostgreSQL storage support
CGI_DESC=	Install admin/user CGI scripts

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPOSTGRESQL}
USE_PGSQL=		yes
PLIST_SUB+=		POSTGRESQL=""
.else
PLIST_SUB+=		POSTGRESQL="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
BROKEN_WITH_MYSQL=	323
PLIST_SUB+=		MYSQL=""
.else
PLIST_SUB+=		MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPOSTGRESQL} && ${PORT_OPTIONS:MCGI}
RUN_DEPENDS+=		p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MMYSQL} && ${PORT_OPTIONS:MCGI}
RUN_DEPENDS+=		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MCGI}
RUN_DEPENDS+=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph \
		p5-GD-TextUtil>=0:${PORTSDIR}/graphics/p5-GD-TextUtil \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Crypt-GeneratePassword>=0:${PORTSDIR}/security/p5-Crypt-GeneratePassword
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd \
		jpeg:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	CGI=""
.else
PLIST_SUB+=	CGI="@comment "
.endif

pre-patch:
.if ! ${PORT_OPTIONS:MDEBUG}
	@${REINPLACE_CMD} -e 's|.*sh configure.sh|& -nodebug|' \
		${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MPOSTGRESQL}
	@${REINPLACE_CMD} -e 's|locate_file "libpq\.so".*|v1="" \&\& v2=""|' \
		${WRKSRC}/configure.sh
.endif
.if ${PORT_OPTIONS:MWITH_MYSQL}
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
.if ${PORT_OPTIONS:MMYSQL}
	${INSTALL_DATA} ${WRKSRC}/addon/mysql_rotate.pl ${DATADIR}/mysql_rotate.pl
	${INSTALL_DATA} ${WRKSRC}/addon/cardtool_schema.sql ${DATADIR}/tools/cardtool_schema.sql
.endif
.if ${PORT_OPTIONS:MPOSTGRESQL}
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
.if ${PORT_OPTIONS:MCGI}
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
