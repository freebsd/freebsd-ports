# New ports collection makefile for:	MRTG
# Date created:				April 18th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrtg
PORTVERSION=	2.13.2
PORTEPOCH=	1
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/mrtg/pub/ \
		ftp://ftp.chg.ru/pub/networking/monitoring/mrtg/ \
		${MASTER_SITE_RINGSERVER} \
		ftp://ftp.nstu.ru/pub/sources/nettools/monitoring/ \
		ftp://ftp.po.opole.pl/pub/unix/net/tools/mrtg/ \
		ftp://ftp.ujf-grenoble.fr/mirror/networking/mrtg/
MASTER_SITE_SUBDIR=	net/mrtg

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The multi-router traffic grapher

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser

CONFIGURE_ARGS=	--with-gd-lib=${LOCALBASE}/lib \
		--with-gd-inc=${LOCALBASE}/include

USE_PERL5=	YES
MAKE_ENV+=	PERL=${PERL}

USE_RC_SUBR=	mrtg_daemon.sh
SUB_LIST+=	PERL=${PERL}

GNU_CONFIGURE=	YES

CONFIGURE_ENV=	PERL=${PERL}

MAN1=		cfgmaker.1 indexmaker.1 mrtg-contrib.1 mrtg-faq.1 mrtg-forum.1 \
		mrtg-ipv6.1 mrtg-logfile.1 mrtg-mibhelp.1 mrtg-nt-guide.1 \
		mrtg-nw-guide.1 mrtg-reference.1 mrtg-rrd.1 mrtg-squid.1 \
		mrtg-unix-guide.1 mrtg-webserver.1 mrtg.1 mrtglib.1

OPTIONS=	IPV6 "Enable IPv6 support" OFF

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
RUN_DEPENDS+=	${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-INET6
.endif

post-patch:
	${RM} ${WRKSRC}/lib/mrtg2/BER.pm ${WRKSRC}/lib/mrtg2/SNMP_*.pm

pre-install:
		@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
		${MKDIR} -m 755 ${PREFIX}/etc/mrtg
		${MKDIR} -m 755 ${DATADIR}
.if !defined(NOPORTDOCS)
		${MKDIR} -m 755 ${DOCSDIR}
		for file in ANNOUNCE CHANGES COPYRIGHT MANIFEST README \
			doc/*.pod doc/*.txt doc/*wml doc/*.png ; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${DOCSDIR}; \
		done
.endif
		${INSTALL_DATA} ${WRKSRC}/contrib/mrtgmk/cfg/mrtg.cfg ${PREFIX}/etc/mrtg/mrtg.cfg.sample
		${INSTALL_DATA} ${WRKSRC}/images/* ${DATADIR}
		${INSTALL_DATA} ${WRKSRC}/doc/*.1 ${PREFIX}/man/man1
		${INSTALL_DATA} ${WRKSRC}/lib/mrtg2/*.pm ${SITE_PERL}
		${INSTALL_PROGRAM} ${WRKSRC}/bin/rateup ${PREFIX}/bin/
		for file in mrtg cfgmaker indexmaker; do \
			${INSTALL_SCRIPT} ${WRKSRC}/bin/$$file ${PREFIX}/bin/; \
		done

post-install:
		@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(BATCH)
	@${ECHO} ""
	@${ECHO} "############################################################################"
	@${ECHO} "# Please create a MRTG config file in ${PREFIX}/etc/mrtg                  #"
	@${ECHO} "# A configuration file can be automatically generated with cfgmaker        #"
	@${ECHO} "# A sample configuration file is installed as mrtg.cfg.sample              #"
	@${ECHO} "#                                                                          #"
	@${ECHO} "# To enable MRTG in daemon mode, put the following to your /etc/rc.conf or #"
	@${ECHO} "# /etc/rc.conf.local file:                                                 #"
	@${ECHO} "#      mrtg_daemon_enable=\"YES\"                                            #"
	@${ECHO} "############################################################################"
.endif

.include <bsd.port.post.mk>
