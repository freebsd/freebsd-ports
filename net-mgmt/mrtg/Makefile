# New ports collection makefile for:	MRTG
# Date created:				April 18th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrtg
PORTVERSION=	2.17.1
PORTEPOCH=	1
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://oss.oetiker.ch/mrtg/pub/ \
		ftp://ftp.idilis.ro/mirrors/mrtg/ \
		ftp://ftp.nstu.ru/pub/sources/nettools/monitoring/ \
		ftp://ftp.chg.ru/pub/networking/monitoring/mrtg/

MAINTAINER=	ports@subnets.ru
COMMENT=	The multi-router traffic grapher

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session

CONFIGURE_ARGS=	--with-gd-lib=${LOCALBASE}/lib \
		--with-gd-inc=${LOCALBASE}/include

USERS=		mrtg
GROUPS=		mrtg

USE_PERL5=	YES
MAKE_ENV+=	PERL=${PERL}
MRTG_RUNDIR?=	/var/run/mrtg

USE_RC_SUBR=	mrtg_daemon
SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST=	PERL=${PERL} \
		MRTG_RUNDIR=${MRTG_RUNDIR} \
		USERS=${USERS} \
		GROUPS=${GROUPS}
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

GNU_CONFIGURE=	YES
CONFIGURE_ENV=	PERL=${PERL}

MAN1=		cfgmaker.1 indexmaker.1 mrtg-contrib.1 mrtg-faq.1 mrtg-forum.1 \
		mrtg-ipv6.1 mrtg-logfile.1 mrtg-mibhelp.1 mrtg-nt-guide.1 \
		mrtg-nw-guide.1 mrtg-reference.1 mrtg-rrd.1 mrtg-squid.1 \
		mrtg-unix-guide.1 mrtg-webserver.1 mrtg.1 mrtglib.1

DOCS=		CHANGES COPYRIGHT MANIFEST README
EXAMPLES=	cfgmaker.pod indexmaker.pod mrtg-contrib.pod mrtg-faq.pod \
		mrtg-forum.pod mrtg-ipv6.pod mrtg-logfile.pod mrtg-mibhelp.pod \
		mrtg-nt-guide.pod mrtg-nw-guide.pod mrtg-reference.pod \
		mrtg-rrd.pod mrtg-squid.pod mrtg-unix-guide.pod mrtg.pod \
		mrtg-webserver.pod mrtglib.pod cfgmaker.txt indexmaker.txt \
		mrtg-contrib.txt mrtg-faq.txt mrtg-forum.txt mrtg-ipv6.txt \
		mrtg-logfile.txt mrtg-mibhelp.txt mrtg-nt-guide.txt \
		mrtg-nw-guide.txt mrtg-reference.txt mrtg-rrd.txt \
		mrtg-squid.txt mrtg-unix-guide.txt mrtg-webserver.txt \
		mrtg.txt mrtglib.txt mrtg-l.png mrtg-m.png mrtg-r.png \
		mrtg-ti.png mrtg-l.gif mrtg-m.gif mrtg-r.gif
IMAGES=		favicon.ico mrtg-l.gif mrtg-l.png mrtg-m.gif mrtg-m.png \
		mrtg-r.gif mrtg-r.png mrtg-ti.gif mrtg-ti.png
SCRIPTS=	cfgmaker indexmaker mrtg mrtg-traffic-sum

OPTIONS=	IPV6 "Enable IPv6 support" OFF \
		SNMP "Enable use of SNMPv3" OFF

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
RUN_DEPENDS+=	${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-Socket-INET6
.endif
.if defined(WITH_SNMP)
RUN_DEPENDS+=	${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP
.endif

post-patch:
	@${RM} ${WRKSRC}/lib/mrtg2/BER.pm ${WRKSRC}/lib/mrtg2/SNMP_*.pm

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/doc ${EXAMPLESDIR}/images
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/doc/,} ${EXAMPLESDIR}/doc/
	@${INSTALL_DATA} ${IMAGES:S,^,${WRKSRC}/images/,} ${EXAMPLESDIR}/images/
.endif
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/mrtgmk/cfg/mrtg.cfg ${ETCDIR}/mrtg.cfg.sample
	@${INSTALL_DATA} ${MAN1:S,^,${WRKSRC}/doc/,} ${MAN1PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/${SITE_PERL_REL}
	@${CP} -p ${WRKSRC}/lib/mrtg2/*.pm ${PREFIX}/${SITE_PERL_REL}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/rateup ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/bin/,} ${PREFIX}/bin

post-install:
	@${SETENV} @PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
