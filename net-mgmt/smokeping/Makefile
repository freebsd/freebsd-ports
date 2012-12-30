# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	smokeping
PORTVERSION=	2.6.8
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://oss.oetiker.ch/smokeping/pub/ \
		http://smokeping.cs.pu.edu.tw/pub/

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Latency logging and graphing system

LIB_DEPENDS=	rrd.6:${PORTSDIR}/databases/rrdtool
BUILD_DEPENDS=	p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-SNMP_Session>=0:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm \
		p5-FCGI>=0:${PORTSDIR}/www/p5-FCGI \
		p5-Config-Grammar>=0:${PORTSDIR}/devel/p5-Config-Grammar \
		p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PERL=${PERL} PERL5LIB=${PREFIX}/smokeping/lib
CONFIGURE_ARGS+=	\
		--sysconfdir=${ETCDIR} \
		--with-htdocs-dir=${PREFIX}/smokeping/htdocs \
		--libdir=${PREFIX}/smokeping/lib
HTDOCSDIR=	${PREFIX}/smokeping/htdocs

USE_RC_SUBR=	smokeping

MAN1=		smokeping.1 \
		smokeping_cgi.1 \
		tSmoke.1
MAN3=		Smokeping_matchers_Avgratio.3 \
		Smokeping_matchers_CheckLatency.3 \
		Smokeping_matchers_CheckLoss.3 \
		Smokeping_matchers_ExpLoss.3 \
		Smokeping_matchers_Median.3 \
		Smokeping_matchers_Medratio.3 \
		Smokeping_matchers_base.3 \
		Smokeping_probes_AnotherDNS.3 \
		Smokeping_probes_AnotherSSH.3 \
		Smokeping_probes_CiscoRTTMonDNS.3 \
		Smokeping_probes_CiscoRTTMonEchoICMP.3 \
		Smokeping_probes_CiscoRTTMonTcpConnect.3 \
		Smokeping_probes_Curl.3 \
		Smokeping_probes_DNS.3 \
		Smokeping_probes_DismanPing.3 \
		Smokeping_probes_EchoPing.3 \
		Smokeping_probes_EchoPingChargen.3 \
		Smokeping_probes_EchoPingDNS.3 \
		Smokeping_probes_EchoPingDiscard.3 \
		Smokeping_probes_EchoPingHttp.3 \
		Smokeping_probes_EchoPingHttps.3 \
		Smokeping_probes_EchoPingIcp.3 \
		Smokeping_probes_EchoPingLDAP.3 \
		Smokeping_probes_EchoPingPlugin.3 \
		Smokeping_probes_EchoPingSmtp.3 \
		Smokeping_probes_EchoPingWhois.3 \
		Smokeping_probes_FPing.3 \
		Smokeping_probes_FPing6.3 \
		Smokeping_probes_FTPtransfer.3 \
		Smokeping_probes_IOSPing.3 \
		Smokeping_probes_LDAP.3 \
		Smokeping_probes_NFSping.3 \
		Smokeping_probes_OpenSSHJunOSPing.3 \
		Smokeping_probes_Radius.3 \
		Smokeping_probes_RemoteFPing.3 \
		Smokeping_probes_SSH.3 \
		Smokeping_probes_SipSak.3 \
		Smokeping_probes_TCPPing.3 \
		Smokeping_probes_TacacsPlus.3 \
		Smokeping_probes_TelnetIOSPing.3 \
		Smokeping_probes_TelnetJunOSPing.3 \
		Smokeping_probes_WebProxyFilter.3 \
		Smokeping_probes_base.3 \
		Smokeping_probes_basefork.3 \
		Smokeping_probes_basevars.3 \
		Smokeping_probes_passwordchecker.3 \
		Smokeping_probes_skel.3 \
		Smokeping_sorters_Loss.3 \
		Smokeping_sorters_Max.3 \
		Smokeping_sorters_Median.3 \
		Smokeping_sorters_StdDev.3 \
		Smokeping_sorters_base.3
MAN5=		smokeping_config.5 \
		smokeping_examples.5
MAN7=		smokeping_extend.7 \
		smokeping_install.7 \
		smokeping_master_slave.7 \
		smokeping_upgrade.7

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

USERS=		smokeping
GROUPS=		smokeping

SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

FPING_DESC=	Support for fping probes
ECHOPING_DESC=	Support for EchoPing probes
CURL_DESC=	Support for Curl probes
LDAP_DESC=	Support for LDAP probes
LDAPSSL_DESC=	Support for SSL-enabled LDAP probes
RADIUS_DESC=	Support for Radius probes
TELNET_DESC=	Support for TelnetIOSPing probes
DNS_DESC=	Support for AnotherDNS probes

OPTIONS_DEFINE=	ECHOPING CURL RADIUS TELNET DNS FPING LDAP LDAPSSL
OPTIONS_DEFAULT=	FPING

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MFPING}
RUN_DEPENDS+=	${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping
.endif

.if ${PORT_OPTIONS:MECHOPING}
RUN_DEPENDS+=	${LOCALBASE}/bin/echoping:${PORTSDIR}/net/echoping
.endif

.if ${PORT_OPTIONS:MCURL}
RUN_DEPENDS+=	${LOCALBASE}/bin/curl:${PORTSDIR}/ftp/curl
.endif

.if ${PORT_OPTIONS:MLDAP} || ${PORT_OPTIONS:MLDAPSSL}
RUN_DEPENDS+=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap
.endif

.if ${PORT_OPTIONS:MRADIUS}
RUN_DEPENDS+=	p5-Authen-Radius>=0:${PORTSDIR}/security/p5-Authen-Radius
.endif

.if ${PORT_OPTIONS:MLDAPSSL}
RUN_DEPENDS+=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.if ${PORT_OPTIONS:MTELNET}
RUN_DEPENDS+=	p5-Net-Telnet>=0:${PORTSDIR}/net/p5-Net-Telnet
.endif

.if ${PORT_OPTIONS:MDNS}
RUN_DEPENDS+=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS
.endif

.include <bsd.port.pre.mk>

# We will take these from CPAN instead
post-extract:
	cd ${WRKSRC}/lib ; ${RM} BER.pm SNMP_util.pm SNMP_Session.pm

post-patch:
	${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/doc/Makefile.in \
		${WRKSRC}/bin/smokeping \
		${WRKSRC}/bin/smokeping_cgi \
		${WRKSRC}/bin/tSmoke

post-install:
.for FILE in basepage.html config smokemail tmail
	[ -f ${ETCDIR}/${FILE} ] || ${CP} ${ETCDIR}/${FILE}.dist ${ETCDIR}/${FILE}
.endfor
	[ -f ${PREFIX}/smokeping/htdocs/smokeping.fcgi ] || ${CP} ${PREFIX}/smokeping/htdocs/smokeping.fcgi.dist ${PREFIX}/smokeping/htdocs/smokeping.fcgi
	${MKDIR} ${PREFIX}/smokeping/htdocs/img
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/smokeping/htdocs
.if !defined(BATCH)
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
