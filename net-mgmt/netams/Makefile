# Created by: Yuriy N. Shkandybin <jura@netams.com>
# $FreeBSD$

PORTNAME=	netams
PORTVERSION=	3.4.5
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netams.com/files/

MAINTAINER=	jura@netams.com
COMMENT=	Network Traffic Accounting and Monitoring Software

LICENSE=	GPLv2

LIB_DEPENDS=	libpcap.so:${PORTSDIR}/net/libpcap

SSP_UNSAFE=	kernel module does not support ssp
USE_SUBMAKE=	yes
SUB_FILES=	pkg-message
USE_RC_SUBR=	netams
USES=		shebangfix
SHEBANG_FILES=	cgi-bin/*.cgi cgi-bin/*.pl \
		cgi-bin/admin/*.cgi addon/*.pl

OPTIONS_DEFINE=		DEBUG CGI
OPTIONS_DEFAULT=	MYSQL
OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL

CGI_DESC=	Install admin/user CGI scripts

OPTIONS_SUB=	yes
PGSQL_USES=	pgsql
MYSQL_USE=	MYSQL=yes

.include <bsd.port.options.mk>

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}"

SBIN_FILES=	ascii2netflow flowprobe ipfw2netflow

ADDONS=		.netamsctl.rc netams-apache-freebsd.conf \
		snmp2netams.pl ua-networks-get.sh

ADMINCGI=	.htaccess access.cgi account.cgi cardtool.cgi config.cgi \
		graph.cgi index.cgi login.cgi monitor.cgi netams.cgi \
		plan.cgi policy.cgi quota.cgi radius.cgi rrdgraph.cgi \
		russian.res showusercard.cgi showusercard.tmpl \
		statistic.cgi subplan.cgi unit.cgi user.cgi view.cgi

USERCGI=	.htaccess activate.cgi activate.tmpl admintool.cgi config.cgi \
		login.cgi netams_api.pl netams_example.cgi netams_graph.cgi \
		netams_html.cgi russian.res statistic.pl usertool.cgi

IMAGES=		logo_sm.jpg admintool-logo.gif showtable-logo.gif rrdgraph-logo.gif

ORA_FILES=	netams.sh netams_drop.sql netams_tb.sql netams_tg.sql netams_ts.sql

PGSQL_FILES=	cardtool_schema-Pg.sql postgresql_schema.sql

MAN_8=		netams.8 flowprobe.8 netamsctl.8

.if ${PORT_OPTIONS:MCGI}
RUN_DEPENDS+=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph \
		p5-GD-TextUtil>=0:${PORTSDIR}/graphics/p5-GD-TextUtil \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Crypt-GeneratePassword>=0:${PORTSDIR}/security/p5-Crypt-GeneratePassword

LIB_DEPENDS+=	libgd.so:${PORTSDIR}/graphics/gd
USES+=		jpeg

. if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
. endif

. if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
. endif
.endif # CGI

pre-patch:
.if ! ${PORT_OPTIONS:MDEBUG}
	@${REINPLACE_CMD} -e 's|.*sh configure.sh|& -nodebug|' \
		${WRKSRC}/Makefile
.endif

.if ! ${PORT_OPTIONS:MPGSQL}
	@${REINPLACE_CMD} -e 's|locate_file "libpq\.so".*|v1="" \&\& v2=""|' \
		${WRKSRC}/configure.sh
.endif

.if ! ${PORT_OPTIONS:MMYSQL}
	@${REINPLACE_CMD} -e 's|locate_file "libmysqlclient\.so".*|v1="" \&\& v2=""|' \
		-e 's|locate_file "libmysqlclient\.a".*|v1="" \&\& v2=""|' \
		${WRKSRC}/configure.sh
.endif
	@${REINPLACE_CMD} -e 's|locate_file "libglib-2\.0\.so".*|v1="" \&\& v2="" \&\& v3=""|' \
		-e 's|locate_file "openssl/md5\.h".*|v1=""|' ${WRKSRC}/configure.sh

	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|g++|${CXX}|; /^INCLUDE/s|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/src/Makefile ${WRKSRC}/lib/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/tools/oracle
	${INSTALL_DATA} ${WRKSRC}/addon/netams.conf ${STAGEDIR}${PREFIX}/etc/netams.conf.sample
	${INSTALL_PROGRAM} ${SBIN_FILES:S|^|${WRKSRC}/src/|} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/netams ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/src/netamsctl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${ADDONS:S|^|${WRKSRC}/addon/|} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/addon/ru-networks.txt ${STAGEDIR}${DATADIR}/ru-networks.txt.sample
	${INSTALL_DATA} ${WRKSRC}/addon/ua-networks.txt ${STAGEDIR}${DATADIR}/ua-networks.txt.sample
	${INSTALL_DATA} ${ORA_FILES:S|^|${WRKSRC}/addon/oracle/|} ${STAGEDIR}${DATADIR}/tools/oracle
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/admin/billing_users_table.sql ${STAGEDIR}${DATADIR}/tools

.if ${PORT_OPTIONS:MMYSQL}
	${INSTALL_DATA} ${WRKSRC}/addon/cardtool_schema.sql ${STAGEDIR}${DATADIR}/tools
	${INSTALL_DATA} ${WRKSRC}/addon/mysql_rotate.pl ${STAGEDIR}${DATADIR}
.endif

.if ${PORT_OPTIONS:MPGSQL}
	${INSTALL_DATA} ${PGSQL_FILES:S|^|${WRKSRC}/addon/|} ${STAGEDIR}${DATADIR}/tools
.endif

.if ${PORT_OPTIONS:MCGI}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin/admin ${STAGEDIR}${WWWDIR}/images
	${INSTALL_DATA} ${WRKSRC}/addon/index.html ${WRKSRC}/addon/netams.js ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${IMAGES:S|^|${WRKSRC}/cgi-bin/images/|} ${STAGEDIR}${WWWDIR}/images
	${INSTALL_PROGRAM} ${USERCGI:S|^|${WRKSRC}/cgi-bin/|} ${STAGEDIR}${WWWDIR}/cgi-bin
	${INSTALL_PROGRAM} ${ADMINCGI:S|^|${WRKSRC}/cgi-bin/admin/|} ${STAGEDIR}${WWWDIR}/cgi-bin/admin
.endif
	${INSTALL_MAN} ${MAN_8:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
BROKEN=		does not build on 10.x+
.endif

.include <bsd.port.post.mk>
