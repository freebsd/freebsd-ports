# New ports collection makefile for:	SmokePing
# Date created:				Tue Feb 12 22:17:40 CET 2002
# Whom:                                 Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	smokeping
PORTVERSION=	1.16
PORTREVISION=	2
CATEGORIES=	net www
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/smokeping/pub/

MAINTAINER=	lars@thegler.dk

RUN_DEPENDS=	rrdtool:${PORTSDIR}/net/rrdtool \
		${SITE_PERL}/CGI/SpeedyCGI.pm:${PORTSDIR}/www/p5-CGI-SpeedyCGI \
		${SITE_PERL}/BER.pm:${PORTSDIR}/net/p5-SNMP_Session \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-PodParser \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping

USE_PERL5=	yes

MAN1=		EchoPing.pm.1 EchoPingChargen.pm.1 EchoPingDiscard.pm.1 \
		EchoPingHttp.pm.1 EchoPingHttps.pm.1 EchoPingIcp.pm.1 EchoPingSmtp.pm.1 \
		FPing.pm.1 FPing6.pm.1 IOSPing.pm.1 ParseConfig.pm.1 Smokeping.pm.1 \
		base.pm.1 basefork.pm.1 basevars.pm.1 \
		smokeping.1 smokeping.cgi.1 \
		smokeping_config.1 smokeping_install.1

PKGMESSAGE=	${WRKDIR}/pkg-message
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
DOCDIR=		${PREFIX}/share/doc/smokeping
DOC1=		CHANGES CONTRIBUTORS COPYING COPYRIGHT README TODO
DOC2=		EchoPing.pm EchoPingChargen.pm EchoPingDiscard.pm \
		EchoPingHttp.pm EchoPingHttps.pm EchoPingIcp.pm EchoPingSmtp.pm \
		FPing.pm FPing6.pm IOSPing.pm ParseConfig.pm Smokeping.pm \
		base.pm basefork.pm basevars.pm smokeping.cgi \
		smokeping smokeping_config smokeping_install
ETC1=		basepage.html config smokemail config-echoping

pre-patch:
	@${MV} ${WRKSRC}/bin/smokeping.dist ${WRKSRC}/bin/smokeping
	@${MV} ${WRKSRC}/htdocs/smokeping.cgi.dist ${WRKSRC}/htdocs/smokeping.cgi
	@${PERL} -pi -e ' \
		s|/usr/sepp/bin/perl|${PERL}|; \
		s|/usr/sepp/bin/speedy|${PREFIX}/bin/speedy|; \
		s|use lib qw\(/usr/pack/rrdtool-1.0.33-to/lib/perl\);\n||; \
		s|/home/oetiker/data/projects/AADJ-smokeping/dist/etc|${PREFIX}/etc/smokeping|; \
		s|/home/oetiker/data/projects/AADJ-smokeping/dist|${PREFIX}/smokeping|; \
		s|/home/oetiker/.smokeping/config|${PREFIX}/etc/smokeping/config|; \
		s|/usr/lib/sendmail|/usr/sbin/sendmail|; \
		s|/usr/sepp/bin/fping|${PREFIX}/sbin/fping|; \
		s|dir  = /usr/local/smokeping/var|dir  = ${PREFIX}/var/smokeping|; \
		s|imgcache = /home/oetiker/public_html/.simg|imgcache = ${PREFIX}/smokeping/htdocs/img|; \
		s|imgurl   = ../.simg|imgurl   = /smokeimg|; \
		' \
		${WRKSRC}/bin/smokeping ${WRKSRC}/htdocs/smokeping.cgi ${WRKSRC}/etc/config.dist
	@${PERL} -p -e ' \
		s|%%PREFIX%%|${PREFIX}|g; \
		' \
		${PKGDIR}/pkg-message > ${PKGMESSAGE}

do-build:
	@${RM} ${WRKSRC}/lib/BER.pm
	@${RM} ${WRKSRC}/lib/SNMP_*.pm

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/smokeping ${PREFIX}/bin
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/doc/${file} ${PREFIX}/man/man1
.endfor
	@${MKDIR} ${DOCDIR}
.for file in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCDIR}
.endfor
.for file in ${DOC2}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file}.html ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file}.txt  ${DOCDIR}
.endfor
	@${MKDIR} ${PREFIX}/etc/smokeping
.for file in ${ETC1}
	@${INSTALL_DATA} ${WRKSRC}/etc/${file}.dist ${PREFIX}/etc/smokeping
	@if [ ! -f ${PREFIX}/etc/smokeping/${file} ]; then \
		${INSTALL_DATA} ${WRKSRC}/etc/${file}.dist ${PREFIX}/etc/smokeping/${file} ; \
	fi
.endfor
	@${MKDIR} ${PREFIX}/smokeping
	@${CP} -Rp ${WRKSRC}/[hl]* ${PREFIX}/smokeping/
	@${MKDIR} ${PREFIX}/var/smokeping
	@${CHOWN} smokeping:smokeping ${PREFIX}/var/smokeping
	@${MKDIR} ${PREFIX}/smokeping/htdocs/img
	@${CHOWN} www:www ${PREFIX}/smokeping/htdocs/img
	@if [ ! -f ${PREFIX}/etc/rc.d/smokeping.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/smokeping.sh startup file."; \
		${INSTALL_SCRIPT} ${FILESDIR}/smokeping.sh ${PREFIX}/etc/rc.d/smokeping.sh; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
