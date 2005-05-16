# New ports collection makefile for:	MRTG
# Date created:				April 18th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrtg
PORTVERSION=	2.12.0
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

RUN_DEPENDS=	${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-PodParser \
		${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-INET6

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
CONFIGURE_ARGS=	--with-gd-lib=${LOCALBASE}/lib \
		--with-gd-inc=${LOCALBASE}/include

USE_PERL5=	YES
MAKE_ENV+=	PERL=${PERL}

GNU_CONFIGURE=	YES

CONFIGURE_ENV=	PERL=${PERL}

MAN1=		cfgmaker.1 indexmaker.1 mrtg-contrib.1 mrtg-faq.1 mrtg-forum.1 \
		mrtg-ipv6.1 mrtg-logfile.1 mrtg-mibhelp.1 mrtg-nt-guide.1 \
		mrtg-nw-guide.1 mrtg-reference.1 mrtg-rrd.1 mrtg-squid.1 \
		mrtg-unix-guide.1 mrtg-webserver.1 mrtg.1 mrtglib.1

post-patch:
	${RM} ${WRKSRC}/lib/mrtg2/BER.pm ${WRKSRC}/lib/mrtg2/SNMP_*.pm

do-install:
		${MKDIR} -m 755 ${PREFIX}/etc/mrtg
		${MKDIR} -m 755 ${DATADIR}
.if !defined(NOPORTDOCS)
		${MKDIR} -m 755 ${DOCSDIR}
		for file in ANNOUNCE CHANGES COPYRIGHT MANIFEST README \
			doc/*.html doc/*.pod doc/*.txt doc/*wml doc/*.png ; do \
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
.if !defined(BATCH)
	@${ECHO} ""
	@${ECHO} "############################################################################"
	@${ECHO} "# Please create a MRTG config file in ${PREFIX}/etc/mrtg                  #"
	@${ECHO} "# A configuration file can be automatically generated with cfgmaker        #"
	@${ECHO} "# A sample configuration file is installed as mrtg.cfg.sample              #"
	@${ECHO} "############################################################################"
.endif

.include <bsd.port.mk>
