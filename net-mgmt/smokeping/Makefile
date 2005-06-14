# New ports collection makefile for:	SmokePing
# Date created:				Tue Feb 12 22:17:40 CET 2002
# Whom:                                 Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	smokeping
PORTVERSION=	1.42
CATEGORIES=	net www
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/smokeping/pub/

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Latency logging and graphing system

RUN_DEPENDS=	rrdtool:${PORTSDIR}/net/rrdtool \
		${SITE_PERL}/CGI/SpeedyCGI.pm:${PORTSDIR}/www/p5-CGI-SpeedyCGI \
		${SITE_PERL}/BER.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net

OPTIONS=	FPING "Support for fping probes" on
OPTIONS+=	ECHOPING "Support for EchoPing probes" off
OPTIONS+=	CURL "Support for Curl probes" off
OPTIONS+=	LDAP "Support for LDAP probes" off
OPTIONS+=	RADIUS "Support for Radius probes" off

.include <bsd.port.pre.mk>

.ifdef(WITH_FPING)
RUN_DEPENDS+=	${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping
.endif

.ifdef(WITH_ECHOPING)
RUN_DEPENDS+=	${LOCALBASE}/bin/echoping:${PORTSDIR}/net/echoping
.endif

.ifdef(WITH_CURL)
RUN_DEPENDS+=	${LOCALBASE}/bin/curl:${PORTSDIR}/ftp/curl
.endif

.ifdef(WITH_LDAP)
RUN_DEPENDS+=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
.endif

.ifdef(WITH_RADIUS)
RUN_DEPENDS+=	${SITE_PERL}/Authen/Radius.pm:${PORTSDIR}/security/p5-Authen-Radius
.endif

.if defined(WITH_LDAP) || defined(WITH_RADIUS)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif

NO_BUILD=	yes
USE_REINPLACE=	yes
USE_PERL5=	yes

MAN1=		ParseConfig.pm.1 \
		Smokeping.pm.1 \
		smokeping.1 \
		smokeping.cgi.1 \
		smokeping_config.1 \
		smokeping_install.1

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

USER=		smokeping
GROUP=		smokeping
WWW_USER=	www
WWW_UID=	80
WWW_GROUP=	www
WWW_GID=	80

FILES_SUB=	USER=${USER} GROUP=${GROUP} \
		WWW_USER=${WWW_USER} WWW_UID=${WWW_UID} \
		WWW_GROUP=${WWW_GROUP} WWW_GID=${WWW_GID} \
		PERL=${PERL} PREFIX=${PREFIX}

DOC1=		CHANGES CONTRIBUTORS COPYING COPYRIGHT README TODO
DOC2=		ParseConfig.pm \
		Smokeping.pm \
		matchers/avgratio.pm \
		matchers/base.pm \
		matchers/median.pm \
		probes/AnotherDNS.pm \
		probes/AnotherSSH.pm \
		probes/CiscoRTTMonDNS.pm \
		probes/CiscoRTTMonEchoICMP.pm \
		probes/CiscoRTTMonTcpConnect.pm \
		probes/Curl.pm \
		probes/DNS.pm \
		probes/EchoPing.pm \
		probes/EchoPingChargen.pm \
		probes/EchoPingDiscard.pm \
		probes/EchoPingHttp.pm \
		probes/EchoPingHttps.pm \
		probes/EchoPingIcp.pm \
		probes/EchoPingSmtp.pm \
		probes/FPing.pm \
		probes/FPing6.pm \
		probes/IOSPing.pm \
		probes/LDAP.pm \
		probes/Radius.pm \
		probes/RemoteFPing.pm \
		probes/SSH.pm \
		probes/base.pm \
		probes/basefork.pm \
		probes/basevars.pm \
		probes/passwordchecker.pm \
		probes/telnetIOSPing.pm \
		smokeping.cgi \
		smokeping \
		smokeping_config \
		smokeping_install
ETC1=		basepage.html config smokemail config-echoping

# Things that shouldn't have been in the tarball in the first place
post-extract:
	@${RM} ${WRKSRC}/lib/BER.pm
	@${RM} ${WRKSRC}/lib/SNMP_*.pm

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete

pre-configure:
	@${REINPLACE_CMD} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/bin/smokeping.dist \
		${WRKSRC}/htdocs/smokeping.cgi.dist \
		${WRKSRC}/etc/config.dist \
		${WRKSRC}/etc/config-echoping.dist \
		${WRKSRC}/lib/probes/*.pm
	@${FIND} ${WRKSRC} -name \*.bak -delete
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-install > ${PKGINSTALL}
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-deinstall > ${PKGDEINSTALL}
	@${MV} ${WRKSRC}/bin/smokeping.dist ${WRKSRC}/bin/smokeping
	@${MV} ${WRKSRC}/htdocs/smokeping.cgi.dist ${WRKSRC}/htdocs/smokeping.cgi

# work around  a bug in bsd.port.mk, see PR 63293 - remove when resolved
do-build:
	@${DO_NADA}

pre-su-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/smokeping ${PREFIX}/bin
.if !defined(NOPORTDOCS)
.for FILE in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/doc/man/man1/${FILE} ${PREFIX}/man/man1
.endfor
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/matchers
	@${MKDIR} ${DOCSDIR}/probes
.for FILE in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
.for FILE in ${DOC2}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE}.html ${DOCSDIR}/${FILE}.html
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE}.txt  ${DOCSDIR}/${FILE}.txt
.endfor
.endif
	@${MKDIR} ${PREFIX}/etc/smokeping
.for FILE in ${ETC1}
	@${INSTALL_DATA} ${WRKSRC}/etc/${FILE}.dist ${PREFIX}/etc/smokeping
	@if [ ! -f ${PREFIX}/etc/smokeping/${FILE} ]; then \
		${INSTALL_DATA} ${WRKSRC}/etc/${FILE}.dist ${PREFIX}/etc/smokeping/${FILE} ; \
	fi
.endfor
	@${MKDIR} ${PREFIX}/smokeping/htdocs
	@${INSTALL_SCRIPT} ${WRKSRC}/htdocs/smokeping.cgi ${PREFIX}/smokeping/htdocs/smokeping.cgi
	@${CP} -R ${WRKSRC}/lib ${PREFIX}/smokeping/
	@${MKDIR} ${PREFIX}/var/smokeping
	@${CHOWN} ${USER}:${GROUP} ${PREFIX}/var/smokeping
	@${MKDIR} ${PREFIX}/smokeping/htdocs/img
	@${CHOWN} ${WWW_USER}:${WWW_GROUP} ${PREFIX}/smokeping/htdocs/img
	@if [ ! -f ${PREFIX}/etc/rc.d/smokeping.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/smokeping.sh startup file."; \
		${INSTALL_SCRIPT} ${FILESDIR}/smokeping.sh ${PREFIX}/etc/rc.d/smokeping.sh; \
	fi

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

post-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.post.mk>
