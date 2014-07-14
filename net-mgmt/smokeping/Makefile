# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	smokeping
PORTVERSION=	2.6.9
PORTREVISION=	1
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://oss.oetiker.ch/smokeping/pub/ \
		http://smokeping.cs.pu.edu.tw/pub/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Latency logging and graphing system

LICENSE=	GPLv2

LIB_DEPENDS=	librrd.so:${PORTSDIR}/databases/rrdtool
BUILD_DEPENDS=	p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-SNMP_Session>=0:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm \
		p5-FCGI>=0:${PORTSDIR}/www/p5-FCGI \
		p5-Config-Grammar>=0:${PORTSDIR}/devel/p5-Config-Grammar \
		p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake perl5
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PERL=${PERL} PERL5LIB=${PREFIX}/smokeping/lib
CONFIGURE_ARGS+=	\
		--sysconfdir=${ETCDIR} \
		--with-htdocs-dir=${PREFIX}/smokeping/htdocs \
		--libdir=${PREFIX}/smokeping/lib
HTDOCSDIR=	${PREFIX}/smokeping/htdocs

USE_RC_SUBR=	smokeping

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
.for FILE in basepage.html config smokemail smokeping_secrets tmail
	${MV} ${STAGEDIR}/${ETCDIR}/${FILE}.dist ${STAGEDIR}/${ETCDIR}/${FILE}.sample
.endfor
	${MV} ${STAGEDIR}/${PREFIX}/smokeping/htdocs/smokeping.fcgi.dist ${STAGEDIR}/${PREFIX}/smokeping/htdocs/smokeping.fcgi.sample

	${MKDIR} ${STAGEDIR}/${PREFIX}/smokeping/htdocs/img
	${MKDIR} ${STAGEDIR}/${PREFIX}/var/smokeping

.if !defined(BATCH)
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
