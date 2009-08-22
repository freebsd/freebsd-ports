# New ports collection makefile for: NetAMS
# Date created:        24 December 2003
# Whom: 	       jura@netams.com
#
# $FreeBSD$
#

PORTNAME=	netams
DISTVERSION=	3.4.1rc1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netams.com/files/

MAINTAINER=	jura@netams.com
COMMENT=	Network Traffic Accounting and Monitoring Software

USE_SUBMAKE=	yes
USE_RC_SUBR=	netams
MANCOMPRESSED=	no
SUB_FILES=	pkg-message

OPTIONS=	DEBUG		"Build with debug symbols"			off \
		BW		"Build with bandwidth limitation functionality"	on  \
		HASH		"Build with HASH storage support"		off \
		MYSQL		"Build with MySQL storage support" 		on  \
		POSTGRESQL	"Build with PostgreSQL storage support"		off \
		FREERADIUS	"Build with FreeRadius and rlm module"		off \
		CGI 		"Install admin/user CGI scripts"		off

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}"

ADMINCGI=	.htaccess access.cgi account.cgi billing_users_table.sql cardtool.cgi \
		config.cgi graph.cgi index.cgi login.cgi monitor.cgi netams.cgi \
		plan.cgi policy.cgi quota.cgi radius.cgi rrdgraph.cgi russian.res \
		showusercard.cgi showusercard.tmpl statistic.cgi subplan.cgi unit.cgi \
		user.cgi view.cgi
USERCGI=	.htaccess activate.cgi activate.tmpl admintool.cgi config.cgi \
		login.cgi netams_api.pl netams_example.cgi netams_graph.cgi \
		netams_html.cgi russian.res statistic.pl usertool.cgi
IMAGES=		admintool-logo.gif logo-small.gif logo.gif logo_sm.jpg rrdgraph-logo.gif \
		showtable-logo.gif
MAN8=		netams.8 flowprobe.8 netamsctl.8

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		does not compile
.elif ${OSVERSION} >= 800000
BROKEN=		does not compile
.endif

PLIST_FILES+=	etc/netams.conf.sample \
		libexec/netams \
		sbin/flowprobe \
		sbin/ipfw2netflow \
		sbin/ascii2netflow \
		bin/netamsctl \
		%%DATADIR%%/ru-networks.txt.sample \
		%%DATADIR%%/.netamsctl.rc \
		%%DATADIR%%/netams-netgraphctl.sh \
		%%DATADIR%%/netams-startup-failover.sh \
		%%DATADIR%%/ua-networks-get.sh \
		%%DATADIR%%/snmp2netams.pl \
		%%DATADIR%%/subnet-sum.c \
		%%DATADIR%%/TODO.txt

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
IGNORE_WITH_MYSQL=	323
PLIST_FILES+=	%%DATADIR%%/cardtool_schema.sql \
		%%DATADIR%%/mysql_rotate.pl
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
PLIST_FILES+=	%%DATADIR%%/cardtool_schema-Pg.sql \
		%%DATADIR%%/postgresql_schema.sql
.endif

.if defined(WITH_FREERADIUS)
FREERADIUS_VERSION=`${CAT} ${PORTSDIR}/net/freeradius/Makefile|grep PORTVERSION?=|${SED} -n 's|PORTVERSION?=[^0-9]*\([0-9\.]*\)|\1|p'`
RUN_DEPENDS+=		freeradius>=1.1.7:${PORTSDIR}/net/freeradius
PLIST_FILES+=		lib/rlm_netams.a \
			lib/rlm_netams.la \
			lib/rlm_netams.so \
			lib/rlm_netams-${FREERADIUS_VERSION}.la \
			lib/rlm_netams-${FREERADIUS_VERSION}.so \
			%%DATADIR%%/README.radius
.endif

.if defined(WITH_CGI)
USE_APACHE=	1.3+
USE_PERL5=	yes
.for f in ${IMAGES}
PLIST_FILES+=	%%WWWDIR%%/cgi-bin/images/${f}
.endfor
.for f in ${USERCGI}
PLIST_FILES+=	%%WWWDIR%%/cgi-bin/${f}
.endfor
.for f in ${ADMINCGI}
PLIST_FILES+=	%%WWWDIR%%/cgi-bin/admin/${f}
.endfor
PLIST_FILES+=	%%WWWDIR%%/index.html \
		%%DATADIR%%/httpd.conf
.endif

PLIST_FILES+=	"@unexec ${RMDIR} %D/www/netams/cgi-bin/images 2>/dev/null || ${TRUE}" \
		"@unexec ${RMDIR} %D/www/netams/cgi-bin/admin 2>/dev/null || ${TRUE}" \
		"@unexec ${RMDIR} %D/www/netams/cgi-bin 2>/dev/null || ${TRUE}" \
		"@unexec ${RMDIR} %D/www/netams 2>/dev/null || ${TRUE}" \
		"@unexec ${RMDIR} %D/share/netams 2>/dev/null || ${TRUE}"

pre-patch:
.if defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e 's|#\(echo.*Memory_debug.*DEFINE += -DMEMORY_DEBUG.*\)|\1|' \
		${WRKSRC}/configure.sh
	@${REINPLACE_CMD} -e 's|#\(echo.*Mutex_debug.*DEFINE += -DMUTEX_DEBUG.*\)|\1|' \
		${WRKSRC}/configure.sh
.else
	@${REINPLACE_CMD} -e 's|.*sh configure.sh|& -nodebug|' \
		${WRKSRC}/Makefile
.endif

.if defined(WITHOUT_BW)
	@${REINPLACE_CMD} -e 's|.*BW_limit.*DEFINE += -DHAVE_BW.*|#&|' \
		${WRKSRC}/configure.sh
.endif

.if defined(WITH_HASH)
	@${REINPLACE_CMD} -e 's|#\(echo.*Hash_database.*DEFINE += -DUSE_HASH.*\)|\1|' \
		${WRKSRC}/configure.sh
.endif

	@${REINPLACE_CMD} -e 's|^CC.*|CC=${CXX}|; s|^CPP.*|CPP=${CXX}|' \
	    ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|^CC.*|CC=${CC}|; s|^CPP.*|CPP=${CXX}|' \
	    ${WRKSRC}/lib/Makefile \
	    ${WRKSRC}/lib/libipulog/Makefile

.if defined(WITHOUT_MYSQL)
	@${REINPLACE_CMD} -e 's|locate_file "libmysqlclient\.so".*|v1="" \&\& v2=""|' \
		${WRKSRC}/configure.sh
.endif

.if defined(WITHOUT_POSTGRESQL)
	@${REINPLACE_CMD} -e 's|locate_file "libpq\.so".*|v1="" \&\& v2=""|' \
		${WRKSRC}/configure.sh
.endif

.if defined(WITHOUT_FREERADIUS)
	@${REINPLACE_CMD} -e 's|locate_file "openssl\/md5\.h".*|v1=""|; s|echo "No RADIUS support.*|| ' \
		${WRKSRC}/configure.sh
.endif

pre-install:
.if defined(WITH_FREERADIUS)
	@cd ${PORTSDIR}/net/freeradius/ && make
	@${FIND} ${PORTSDIR}/net/freeradius/ -type d -name "freeradius*" -exec ${CP} -R ${WRKSRC}/addon/rlm_netams '{}'/src/modules/ \;
	@cd `${FIND} ${PORTSDIR}/net/freeradius/ -type d -name "freeradius*"`/src/modules/rlm_netams && ${GMAKE} && ${GMAKE} install
.endif

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/netams ${PREFIX}/libexec/netams
	${INSTALL_PROGRAM} ${WRKSRC}/src/flowprobe ${PREFIX}/sbin/flowprobe
	${INSTALL_PROGRAM} ${WRKSRC}/src/ipfw2netflow ${PREFIX}/sbin/ipfw2netflow
	${INSTALL_PROGRAM} ${WRKSRC}/src/ascii2netflow ${PREFIX}/sbin/ascii2netflow
	${INSTALL_PROGRAM} ${WRKSRC}/src/netamsctl ${PREFIX}/bin/netamsctl
	${INSTALL_DATA} ${WRKSRC}/addon/netams.conf ${PREFIX}/etc/netams.conf.sample
	${INSTALL_DATA} ${WRKSRC}/addon/ru-networks.txt ${DATADIR}/ru-networks.txt.sample
	${INSTALL_DATA} ${WRKSRC}/addon/.netamsctl.rc  ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/addon/netams-netgraphctl.sh ${DATADIR}
	${CHMOD} 0755	${DATADIR}/netams-netgraphctl.sh
	${INSTALL_DATA} ${WRKSRC}/addon/netams-startup-failover.sh ${DATADIR}
	${CHMOD} 0755   ${DATADIR}/netams-startup-failover.sh
	${INSTALL_DATA} ${WRKSRC}/addon/ua-networks-get.sh ${DATADIR}
	${CHMOD} 0755   ${DATADIR}/ua-networks-get.sh
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!/usr/local/bin/perl|' ${WRKSRC}/addon/snmp2netams.pl
	${INSTALL_DATA} ${WRKSRC}/addon/snmp2netams.pl ${DATADIR}
	${CHMOD} 0755   ${DATADIR}/snmp2netams.pl
	${INSTALL_DATA} ${WRKSRC}/addon/subnet-sum.c ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/TODO.txt ${DATADIR}

.if defined(WITH_MYSQL)
	${INSTALL_DATA} ${WRKSRC}/addon/cardtool_schema.sql ${DATADIR}
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!/usr/local/bin/perl|' ${WRKSRC}/addon/mysql_rotate.pl
	${INSTALL_DATA} ${WRKSRC}/addon/mysql_rotate.pl ${DATADIR}
	${CHMOD} 0755   ${DATADIR}/mysql_rotate.pl
.endif

.if defined(WITH_POSTGRESQL)
	${INSTALL_DATA} ${WRKSRC}/addon/cardtool_schema-Pg.sql ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/addon/postgresql_schema.sql ${DATADIR}
.endif

.if defined(WITH_CGI)
	${INSTALL_DATA} ${WRKSRC}/addon/netams-apache ${DATADIR}/httpd.conf
	${MKDIR} ${WWWDIR}/cgi-bin/admin ${WWWDIR}/cgi-bin/images
	${INSTALL_DATA} ${WRKSRC}/addon/index.html ${WWWDIR}
.for f in ${IMAGES}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/images/${f} ${WWWDIR}/cgi-bin/images
.endfor
.for f in ${USERCGI}
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!/usr/local/bin/perl|' ${WRKSRC}/cgi-bin/${f}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/${f} ${WWWDIR}/cgi-bin
.endfor
.for f in ${ADMINCGI}
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!/usr/local/bin/perl|' ${WRKSRC}/cgi-bin/admin/${f}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/admin/${f} ${WWWDIR}/cgi-bin/admin
.endfor
	@${FIND} ${WWWDIR} -name *.cgi | ${XARGS} ${CHMOD} 755
	@${FIND} ${WWWDIR} -name *.pl | ${XARGS} ${CHMOD} 755
.endif

.if defined(WITH_FREERADIUS)
	${INSTALL_DATA} ${WRKSRC}/addon/rlm_netams/README ${DATADIR}/README.radius
.endif

.for f in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${MAN8PREFIX}/man/man8
.endfor

post-install:
.if defined(WITH_FREERADIUS)
	cd ${PORTSDIR}/net/freeradius/ && make clean
.endif
	@${CAT} ${PKGMESSAGE}
.if defined(WITH_CGI)
	@${ECHO_MSG} "By default, CGI scripts are installed to ${WWWDIR},"
	@${ECHO_MSG} "but web server NOT configured!!! You should do it yourself according to"
	@${ECHO_MSG} "example ${DATADIR}/httpd.conf."
	@${ECHO_MSG} ""
.endif
.if defined(WITH_FREERADIUS)
	@${ECHO_MSG} "Radius module has been installed. But you should configure it yourself"
	@${ECHO_MSG} "according to example ${DATADIR}/README.radius."
	@${ECHO_MSG} ""
.endif
	@${ECHO_MSG} "And PLEASE READ THE DOCUMENTATION FIRST!"
	@${ECHO_MSG} "http://www.netams.com"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "----------------------------------------------------------------------------"
	@${ECHO_MSG} "WARNING!"
	@${ECHO_MSG} "From version 3.4.1 name of default netams configuration
	@${ECHO_MSG} "file changed to netams.conf!"
	@${ECHO_MSG} "----------------------------------------------------------------------------"

.include <bsd.port.post.mk>
