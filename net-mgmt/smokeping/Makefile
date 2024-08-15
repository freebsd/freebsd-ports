PORTNAME=	smokeping
PORTVERSION=	2.8.2
PORTREVISION=	7
CATEGORIES=	net-mgmt www
MASTER_SITES=	https://oss.oetiker.ch/smokeping/pub/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Latency logging and graphing system
WWW=		https://oss.oetiker.ch/smokeping/

LICENSE=	GPLv2

BUILD_DEPENDS=	curl>=0:ftp/curl \
		p5-CGI-Fast>=0:www/p5-CGI-Fast \
		p5-CGI-Session>=0:www/p5-CGI-Session \
		p5-CGI>=0:www/p5-CGI \
		p5-Config-Grammar>=0:devel/p5-Config-Grammar \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-FCGI>=0:www/p5-FCGI \
		p5-IO-Pty-Easy>=0:devel/p5-IO-Pty-Easy \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-libwww>=0:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-OpenSSH>=0:net/p5-Net-OpenSSH \
		p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
		p5-Net-Telnet>=0:net/p5-Net-Telnet \
		p5-OrePAN2>=0:devel/p5-OrePAN2 \
		p5-perl-ldap>=0:net/p5-perl-ldap \
		p5-SNMP_Session>=0:net-mgmt/p5-SNMP_Session \
		p5-Socket6>=0:net/p5-Socket6
LIB_DEPENDS=	librrd.so:databases/rrdtool
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		autoreconf cpe gmake perl5
USE_RC_SUBR=	smokeping

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=		--libdir=${PREFIX}/smokeping/lib \
				--localstatedir="${PREFIX}/var" \
				--sysconfdir=${ETCDIR} \
				--with-htdocs-dir=${PREFIX}/smokeping/htdocs
CONFIGURE_ENV+=			PERL5LIB=${PREFIX}/smokeping/lib \
				PERL=${PERL}

CONFLICTS_INSTALL=	nfsping

NO_ARCH=	yes
SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

HTDOCSDIR=	${PREFIX}/smokeping/htdocs

USERS=		smokeping
GROUPS=		smokeping

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

OPTIONS_DEFINE=		DNS ECHOPING EXAMPLES FPING RADIUS TELNET
OPTIONS_DEFAULT=	FPING

DNS_DESC=	Support for AnotherDNS probes
ECHOPING_DESC=	Support for EchoPing probes
FPING_DESC=	Support for fping probes
RADIUS_DESC=	Support for Radius probes
TELNET_DESC=	Support for TelnetIOSPing probes

DNS_RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS
ECHOPING_RUN_DEPENDS=	${LOCALBASE}/bin/echoping:net/echoping
FPING_RUN_DEPENDS=	${LOCALBASE}/sbin/fping:net/fping
RADIUS_RUN_DEPENDS=	p5-Authen-Radius>=0:security/p5-Authen-Radius
TELNET_RUN_DEPENDS=	p5-Net-Telnet>=0:net/p5-Net-Telnet

# We will take these from CPAN instead
post-extract:
	cd ${WRKSRC}/lib ; ${RM} BER.pm SNMP_util.pm SNMP_Session.pm

post-patch:
	${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/doc/Makefile.am \
		${WRKSRC}/bin/smokeping \
		${WRKSRC}/bin/smokeping_cgi \
		${WRKSRC}/bin/tSmoke
	@for a in ${WRKSRC}/etc/*.dist; do \
		${MV} $$a $${a%.dist}.sample; \
	done
	${MV} ${WRKSRC}/etc/config.dist.in ${WRKSRC}/etc/config.sample.in

post-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/smokeping/htdocs/img
	${MKDIR} ${STAGEDIR}/${PREFIX}/var/smokeping

.include <bsd.port.mk>
