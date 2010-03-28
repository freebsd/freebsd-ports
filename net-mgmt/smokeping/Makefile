# New ports collection makefile for:	SmokePing
# Date created:				Tue Feb 12 22:17:40 CET 2002
# Whom:                                 Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	smokeping
PORTVERSION=	2.4.2
PORTREVISION=	6
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://oss.oetiker.ch/smokeping/pub/ \
		http://smokeping.cs.pu.edu.tw/pub/

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Latency logging and graphing system

RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool \
		p5-CGI-Session>0:${PORTSDIR}/www/p5-CGI-Session \
		p5-CGI-SpeedyCGI>0:${PORTSDIR}/www/p5-CGI-SpeedyCGI \
		p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-SNMP_Session>0:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes
USE_PERL5=	yes

USE_RC_SUBR=	smokeping

MAN1=		smokeping.1 \
		smokeping.cgi.1 \
		tSmoke.1
MAN3=		Config::Grammar.3 \
		Smokeping.3 \
		Smokeping::Examples.3 \
		Smokeping::RRDtools.3 \
		Smokeping::matchers::Avgratio.3 \
		Smokeping::matchers::Median.3 \
		Smokeping::matchers::base.3 \
		Smokeping::probes::AnotherDNS.3 \
		Smokeping::probes::AnotherSSH.3 \
		Smokeping::probes::CiscoRTTMonDNS.3 \
		Smokeping::probes::CiscoRTTMonEchoICMP.3 \
		Smokeping::probes::CiscoRTTMonTcpConnect.3 \
		Smokeping::probes::Curl.3 \
		Smokeping::probes::DNS.3 \
		Smokeping::probes::EchoPing.3 \
		Smokeping::probes::EchoPingChargen.3 \
		Smokeping::probes::EchoPingDiscard.3 \
		Smokeping::probes::EchoPingHttp.3 \
		Smokeping::probes::EchoPingHttps.3 \
		Smokeping::probes::EchoPingIcp.3 \
		Smokeping::probes::EchoPingSmtp.3 \
		Smokeping::probes::FPing.3 \
		Smokeping::probes::FPing6.3 \
		Smokeping::probes::IOSPing.3 \
		Smokeping::probes::LDAP.3 \
		Smokeping::probes::Radius.3 \
		Smokeping::probes::RemoteFPing.3 \
		Smokeping::probes::SSH.3 \
		Smokeping::probes::TelnetIOSPing.3 \
		Smokeping::probes::base.3 \
		Smokeping::probes::basefork.3 \
		Smokeping::probes::basevars.3 \
		Smokeping::probes::passwordchecker.3 \
		Smokeping::probes::skel.3
MAN5=		smokeping_config.5
MAN7=		smokeping_examples.7 \
		smokeping_extend.7 \
		smokeping_install.7 \
		smokeping_upgrade.7

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

USERS=		smokeping
GROUPS=		smokeping

SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		PERL=${PERL} \
		PKG_PREFIX=${PKG_PREFIX}

DOC1=		CHANGES CONTRIBUTORS COPYING COPYRIGHT README TODO
DOC2=		Config/Grammar \
		Smokeping \
		Smokeping/Examples \
		Smokeping/RRDtools \
		Smokeping/matchers/Avgratio \
		Smokeping/matchers/Median \
		Smokeping/matchers/base \
		Smokeping/probes/AnotherDNS \
		Smokeping/probes/AnotherSSH \
		Smokeping/probes/CiscoRTTMonDNS \
		Smokeping/probes/CiscoRTTMonEchoICMP \
		Smokeping/probes/CiscoRTTMonTcpConnect \
		Smokeping/probes/Curl \
		Smokeping/probes/DNS \
		Smokeping/probes/EchoPing \
		Smokeping/probes/EchoPingChargen \
		Smokeping/probes/EchoPingDiscard \
		Smokeping/probes/EchoPingHttp \
		Smokeping/probes/EchoPingHttps \
		Smokeping/probes/EchoPingIcp \
		Smokeping/probes/EchoPingSmtp \
		Smokeping/probes/FPing \
		Smokeping/probes/FPing6 \
		Smokeping/probes/IOSPing \
		Smokeping/probes/LDAP \
		Smokeping/probes/Radius \
		Smokeping/probes/RemoteFPing \
		Smokeping/probes/SSH \
		Smokeping/probes/TelnetIOSPing \
		Smokeping/probes/base \
		Smokeping/probes/basefork \
		Smokeping/probes/basevars \
		Smokeping/probes/passwordchecker \
		Smokeping/probes/skel \
		smokeping.cgi \
		smokeping \
		smokeping_config \
		smokeping_examples \
		smokeping_extend \
		smokeping_install \
		smokeping_upgrade \
		tSmoke

EXAMPLES=	config.echoping \
		config.fping-instances \
		config.multiple-probes \
		config.simple \
		config.targetvars-with-Curl \
		config.template

ETC1=		basepage.html config smokemail tmail

OPTIONS=	FPING "Support for fping probes" on
OPTIONS+=	ECHOPING "Support for EchoPing probes" off
OPTIONS+=	CURL "Support for Curl probes" off
OPTIONS+=	LDAP "Support for LDAP probes" off
OPTIONS+=	LDAPSSL "Support for SSL-enabled LDAP probes" off
OPTIONS+=	RADIUS "Support for Radius probes" off
OPTIONS+=	TELNET "Support for TelnetIOSPing probes" off
OPTIONS+=	DNS "Support for AnotherDNS probes" off

.include <bsd.port.options.mk>
.ifdef(WITH_FPING)
RUN_DEPENDS+=	${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping
.endif

.ifdef(WITH_ECHOPING)
RUN_DEPENDS+=	${LOCALBASE}/bin/echoping:${PORTSDIR}/net/echoping
.endif

.ifdef(WITH_CURL)
RUN_DEPENDS+=	${LOCALBASE}/bin/curl:${PORTSDIR}/ftp/curl
.endif

.if defined(WITH_LDAP) || defined(WITH_LDAPSSL)
RUN_DEPENDS+=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
.endif

.ifdef(WITH_RADIUS)
RUN_DEPENDS+=	${SITE_PERL}/Authen/Radius.pm:${PORTSDIR}/security/p5-Authen-Radius
.endif

.ifdef(WITH_LDAPSSL)
RUN_DEPENDS+=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.ifdef(WITH_TELNET)
RUN_DEPENDS+=	${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet
.endif

.ifdef(WITH_DNS)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
.endif

.include <bsd.port.pre.mk>

# Things that shouldn't have been in the tarball in the first place
post-extract:
	${RM} ${WRKSRC}/lib/BER.pm
	${RM} ${WRKSRC}/lib/SNMP_*.pm
	${RM} -rf ${WRKSRC}/lib/Digest
	${RM} -rf ${WRKSRC}/lib/CGI

pre-patch:
	${REINPLACE_CMD} -e s!/usr/bin/!%%PREFIX%%/bin/! \
		${WRKSRC}/lib/Smokeping.pm \
		${WRKSRC}/lib/Smokeping/Examples.pm \
		${WRKSRC}/lib/Smokeping/probes/Curl.pm \
		${WRKSRC}/lib/Smokeping/probes/IOSPing.pm \
		${WRKSRC}/lib/Smokeping/probes/DNS.pm \
		${WRKSRC}/lib/Smokeping/probes/RemoteFPing.pm \
		${WRKSRC}/lib/Smokeping/probes/SSH.pm \
		${WRKSRC}/lib/Smokeping/probes/FPing6.pm \
		${WRKSRC}/lib/Smokeping/probes/EchoPing.pm \
		${WRKSRC}/lib/Smokeping/probes/FPing.pm
	${REINPLACE_CMD} -e s!/usr/share/smokeping/etc/!%%PREFIX%%/etc/smokeping/! \
		${WRKSRC}/lib/Smokeping/probes/passwordchecker.pm

post-patch:
	${FIND} ${WRKSRC} -name \*.orig -delete

pre-configure:
	${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/lib/Smokeping.pm \
		${WRKSRC}/lib/Smokeping/Examples.pm \
		${WRKSRC}/bin/smokeping.dist \
		${WRKSRC}/bin/tSmoke.dist \
		${WRKSRC}/htdocs/smokeping.cgi.dist \
		${WRKSRC}/htdocs/tr.cgi.dist \
		${WRKSRC}/etc/config.dist \
		${WRKSRC}/lib/Smokeping/probes/*.pm
	${FIND} ${WRKSRC} -name \*.bak -delete
	${MV} ${WRKSRC}/bin/smokeping.dist ${WRKSRC}/bin/smokeping
	${MV} ${WRKSRC}/bin/tSmoke.dist ${WRKSRC}/bin/tSmoke
	${MV} ${WRKSRC}/htdocs/smokeping.cgi.dist ${WRKSRC}/htdocs/smokeping.cgi
	${MV} ${WRKSRC}/htdocs/tr.cgi.dist ${WRKSRC}/htdocs/tr.cgi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/smokeping ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tSmoke ${PREFIX}/bin
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN5} ${PREFIX}/man/man5)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN7} ${PREFIX}/man/man7)
.for FILE in ${MAN3}
	${INSTALL_MAN} `${FIND} ${WRKSRC}/doc -name ${FILE}` ${PREFIX}/man/man3
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/Config
	${MKDIR} ${DOCSDIR}/Smokeping/matchers
	${MKDIR} ${DOCSDIR}/Smokeping/probes
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOC1} ${DOCSDIR})
.for FILE in ${DOC2}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE}.html ${DOCSDIR}/${FILE}.html
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE}.txt  ${DOCSDIR}/${FILE}.txt
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR})
.endif
	${MKDIR} ${ETCDIR}
.for FILE in ${ETC1}
	${INSTALL_DATA} ${WRKSRC}/etc/${FILE}.dist ${ETCDIR}
	if [ ! -f ${ETCDIR}/${FILE} ]; then \
		${INSTALL_DATA} ${WRKSRC}/etc/${FILE}.dist ${ETCDIR}/${FILE} ; \
	fi
.endfor
	${MKDIR} ${PREFIX}/smokeping/htdocs
	${MKDIR} ${PREFIX}/smokeping/htdocs/img
	${CP} -R ${WRKSRC}/htdocs ${PREFIX}/smokeping/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/smokeping/htdocs
	${CP} -R ${WRKSRC}/lib ${PREFIX}/smokeping/
	${MKDIR} ${PREFIX}/var/smokeping
	${CHOWN} -R ${USERS}:${GROUPS} ${PREFIX}/var/smokeping

post-install:
.if !defined(BATCH)
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
