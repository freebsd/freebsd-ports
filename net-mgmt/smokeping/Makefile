# New ports collection makefile for:	SmokePing
# Date created:				Tue Feb 12 22:17:40 CET 2002
# Whom:                                 Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	smokeping
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/smokeping/pub/

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Latency logging and graphing system

RUN_DEPENDS=	rrdtool:${PORTSDIR}/net/rrdtool \
		${SITE_PERL}/CGI/SpeedyCGI.pm:${PORTSDIR}/www/p5-CGI-SpeedyCGI \
		${SITE_PERL}/BER.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-PodParser \
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

MAN1=		CiscoRTTMonDNS.pm.1 CiscoRTTMonEchoICMP.pm.1 CiscoRTTMonTcpConnect.pm.1 \
		Curl.pm.1 DNS.pm.1 EchoPing.pm.1 EchoPingChargen.pm.1 EchoPingDiscard.pm.1 \
		EchoPingHttp.pm.1 EchoPingHttps.pm.1 EchoPingIcp.pm.1 EchoPingSmtp.pm.1 \
		FPing.pm.1 FPing6.pm.1 IOSPing.pm.1 ParseConfig.pm.1 RemoteFPing.pm.1 \
		Smokeping.pm.1 base.pm.1 basefork.pm.1 basevars.pm.1 smokeping.1 \
		smokeping.cgi.1 smokeping_config.1 smokeping_install.1 telnetIOSPing.pm.1

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
DOC2=		CiscoRTTMonDNS.pm CiscoRTTMonEchoICMP.pm CiscoRTTMonTcpConnect.pm \
		Curl.pm DNS.pm EchoPing.pm EchoPingChargen.pm EchoPingDiscard.pm \
		EchoPingHttp.pm EchoPingHttps.pm EchoPingIcp.pm EchoPingSmtp.pm \
		FPing.pm FPing6.pm IOSPing.pm ParseConfig.pm RemoteFPing.pm Smokeping.pm \
		base.pm basefork.pm basevars.pm smokeping.cgi \
		smokeping smokeping_config smokeping_install telnetIOSPing.pm
ETC1=		basepage.html config smokemail config-echoping

# Things that shouldn't have been in the tarball in the first place
post-extract:
	@${RM} ${WRKSRC}/lib/BER.pm
	@${RM} ${WRKSRC}/lib/SNMP_*.pm
	@${RM} ${WRKSRC}/lib/probes/patch

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete

pre-configure:
	@${REINPLACE_CMD} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/bin/smokeping.dist \
		${WRKSRC}/htdocs/smokeping.cgi.dist \
		${WRKSRC}/etc/config.dist \
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
	@${INSTALL_MAN} ${WRKSRC}/doc/${FILE} ${PREFIX}/man/man1
.endfor
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.for FILE in ${DOC2}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE}.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE}.txt  ${DOCSDIR}
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
