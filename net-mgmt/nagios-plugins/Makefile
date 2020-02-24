# Created by: Blaz Zupan <blaz@si.FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios-plugins
DISTVERSION=	2.3.2
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://www.nagios-plugins.org/download/ \
		LOCAL/mat/${PORTNAME}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Plugins for Nagios

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix gmake libtool perl5 ssl
USE_SUBMAKE=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share \
			--libexecdir=${PREFIX}/libexec/nagios \
			--localstatedir=${NAGIOSDIR} \
			--prefix=${PREFIX} \
			--sbindir=${PREFIX}/${NAGIOSWWWDIR}/cgi-bin \
			--sysconfdir=${PREFIX}/etc/nagios \
			--with-cgiurl=${NAGIOSCGIURL} \
			--with-nagios-group=${NAGIOSGROUP} \
			--with-nagios-user=${NAGIOSUSER} \
			--with-perl=${PERL}

# Also, force some commands with their expected paths so that they don't get
# disabled.
CONFIGURE_ARGS+=	--with-ping-command="/sbin/ping -n -t %d -c %d %s" \
			--with-ping6-command="/sbin/ping6 -n -X %d -c %d %s" \
			ac_cv_path_PATH_TO_PING6=/sbin/ping6 \
			ac_cv_path_PATH_TO_PING=/sbin/ping \
			ac_cv_path_PATH_TO_QMAIL_QSTAT=/var/qmail/bin/qmail-qstat \
			ac_cv_path_PATH_TO_SMBCLIENT=${LOCALBASE}/bin/smbclient \
			ac_cv_path_PATH_TO_SUDO=${LOCALBASE}/bin/sudo

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	monitoring-plugins-*

OPTIONS_DEFINE=		DBI EXTRAOPTS FPING IPV6 LDAP MYSQL NETSNMP NLS PGSQL \
			QSTAT RADIUS SSH_PORTABLE
OPTIONS_DEFAULT=	DNS_BASE EXTRAOPTS
OPTIONS_SINGLE=		DNS
OPTIONS_SINGLE_DNS=	DNS_BASE DNS_BINDTOOLS
OPTIONS_SUB=		yes

DBI_DESC=		Check database using DBI
DNS_BASE_DESC=		Use drill for check_dig, check_dns not available
DNS_BINDTOOLS_DESC=	Use dig and nslookup from dns/bind-tools
DNS_DESC=		Configuration of check_dig and check_dns
EXTRAOPTS_DESC=		Parsing of plugins ini config files for extra options
FPING_DESC=		Support for non-flooding fast ping (check_fping)
LDAP_DESC=		OpenLDAP support (check_ldap)
MYSQL_DESC=		MySQL support (check_mysql)
NETSNMP_DESC=		SNMP support (check_snmp)
PGSQL_DESC=		PostgreSQL support (check_pgsql)
QSTAT_DESC=		Game server query support (check_game)
RADIUS_DESC=		Radius support (check_radius)
SSH_PORTABLE_DESC=	Build check_ssh with ports openssh (instead of base)

DBI_LIB_DEPENDS=	libdbi.so:databases/libdbi
DBI_CONFIGURE_WITH=	dbi

DNS_BINDTOOLS_BUILD_DEPENDS=	${LOCALBASE}/bin/dig:dns/bind-tools
DNS_BINDTOOLS_RUN_DEPENDS=	${DNS_BINDTOOLS_BUILD_DEPENDS}
DNS_BINDTOOLS_CONFIGURE_ON=	--with-dig-command=${LOCALBASE}/bin/dig \
				--with-nslookup-command=${LOCALBASE}/bin/nslookup

EXTRAOPTS_CONFIGURE_ENABLE=	extra-opts

FPING_BUILD_DEPENDS=	fping:net/fping
FPING_RUN_DEPENDS=	fping:net/fping
FPING_CONFIGURE_OFF=	ac_cv_path_PATH_TO_FPING6= \
			ac_cv_path_PATH_TO_FPING=

IPV6_CONFIGURE_WITH=	ipv6

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap

MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql=${LOCALBASE}

NETSNMP_BUILD_DEPENDS=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
			snmpcheck:net-mgmt/net-snmp
NETSNMP_RUN_DEPENDS=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
			snmpcheck:net-mgmt/net-snmp
NETSNMP_CONFIGURE_OFF=	ac_cv_path_PATH_TO_SNMPGET= \
			ac_cv_path_PATH_TO_SNMPGETNEXT=

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	pgsql=${LOCALBASE}

QSTAT_BUILD_DEPENDS=	qstat:games/qstat
QSTAT_RUN_DEPENDS=	qstat:games/qstat
QSTAT_CONFIGURE_OFF=	ac_cv_path_PATH_TO_QSTAT= \
			ac_cv_path_PATH_TO_QUAKESTAT=

RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient
RADIUS_CONFIGURE_WITH=	radius

SSH_PORTABLE_BUILD_DEPENDS=	${LOCALBASE}/bin/ssh:security/openssh-portable
SSH_PORTABLE_RUN_DEPENDS:=	${SSH_PORTABLE_BUILD_DEPENDS}
SSH_PORTABLE_CONFIGURE_ON=	--with-ssh-command=${LOCALBASE}/bin/ssh

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSWWWDIR?=	www/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDNS_BASE}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-dig-to-drill.diff
CONFIGURE_ARGS+=	--with-dig-command=/usr/bin/drill \
			ac_cv_path_PATH_TO_NSLOOKUP=
PLIST_SUB+=		CHECK_DNS="@comment "
.else
PLIST_SUB+=		CHECK_DNS=""
.endif

.if !exists(/usr/bin/ssh) && empty(PORT_OPTIONS:MSSH_PORTABLE)
PLIST_SUB+=	SSH="@comment "
.else
PLIST_SUB+=	SSH=""
.endif

post-patch:
	# add a fake PATH so that it gets set to a correct value during build.
	@${REINPLACE_CMD} -e "s|$$ENV{'PATH'}=''|$$ENV{'PATH'}='foo'|; \
		s|/usr/bin/|${LOCALBASE}/bin/|g" \
		${WRKSRC}/plugins-scripts/*.pl

.include <bsd.port.mk>
