# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	smokeping
PORTVERSION=	2.6.11
PORTREVISION=	6
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://oss.oetiker.ch/smokeping/pub/ \
		http://smokeping.cs.pu.edu.tw/pub/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Latency logging and graphing system

LICENSE=	GPLv2

LIB_DEPENDS=	librrd.so:databases/rrdtool
BUILD_DEPENDS=	p5-CGI-Session>=0:www/p5-CGI-Session \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-IO-Pty-Easy>=0:devel/p5-IO-Pty-Easy \
		p5-SNMP_Session>=0:net-mgmt/p5-SNMP_Session \
		p5-libwww>=0:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-CGI>=0:www/p5-CGI \
		p5-FCGI>=0:www/p5-FCGI \
		p5-Config-Grammar>=0:devel/p5-Config-Grammar \
		p5-Socket6>=0:net/p5-Socket6 \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-Net-Telnet>=0:net/p5-Net-Telnet \
		p5-Net-OpenSSH>=0:net/p5-Net-OpenSSH \
		p5-perl-ldap>=0:net/p5-perl-ldap
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		gmake perl5
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PERL=${PERL} PERL5LIB=${PREFIX}/smokeping/lib
CONFIGURE_ARGS+=	\
		--sysconfdir=${ETCDIR} \
		--localstatedir="${PREFIX}/var" \
		--with-htdocs-dir=${PREFIX}/smokeping/htdocs \
		--libdir=${PREFIX}/smokeping/lib
HTDOCSDIR=	${PREFIX}/smokeping/htdocs
MAKE_ENV=	LC_ALL=C

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
RADIUS_DESC=	Support for Radius probes
TELNET_DESC=	Support for TelnetIOSPing probes
DNS_DESC=	Support for AnotherDNS probes

OPTIONS_DEFINE=	ECHOPING CURL RADIUS TELNET DNS FPING
OPTIONS_DEFAULT=	FPING

FPING_RUN_DEPENDS=	${LOCALBASE}/sbin/fping:net/fping
ECHOPING_RUN_DEPENDS=	${LOCALBASE}/bin/echoping:net/echoping
CURL_RUN_DEPENDS=	${LOCALBASE}/bin/curl:ftp/curl
RADIUS_RUN_DEPENDS=	p5-Authen-Radius>=0:security/p5-Authen-Radius
TELNET_RUN_DEPENDS=	p5-Net-Telnet>=0:net/p5-Net-Telnet
DNS_RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502100
BUILD_DEPENDS+=	p5-CGI-Fast>=0:www/p5-CGI-Fast
RUN_DEPENDS+=	p5-CGI-Fast>=0:www/p5-CGI-Fast
.endif

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
	${MKDIR} ${STAGEDIR}/${PREFIX}/smokeping/htdocs/img
	${MKDIR} ${STAGEDIR}/${PREFIX}/var/smokeping

.include <bsd.port.post.mk>
