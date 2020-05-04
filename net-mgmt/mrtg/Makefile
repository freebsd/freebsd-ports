# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mrtg
PORTVERSION=	2.17.4
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://oss.oetiker.ch/mrtg/pub/ \
		ftp://ftp.idilis.ro/mirrors/mrtg/ \
		ftp://ftp.nstu.ru/pub/sources/nettools/monitoring/ \
		ftp://ftp.chg.ru/pub/networking/monitoring/mrtg/

MAINTAINER=	ports@subnets.ru
COMMENT=	Multi-router traffic grapher

LIB_DEPENDS=	libgd.so:${GD_PORT}
RUN_DEPENDS=	p5-SNMP_Session>=0:net-mgmt/p5-SNMP_Session

# slave ports override with languages specific gd
GD_PORT?=	graphics/gd

CONFIGURE_ARGS=	--with-gd-lib=${LOCALBASE}/lib \
		--with-gd-inc=${LOCALBASE}/include

USERS=		mrtg
GROUPS=		mrtg

USES=		perl5 shebangfix
MAKE_ENV+=	PERL=${PERL}
MRTG_RUNDIR?=	/var/run/mrtg
SHEBANG_FILES=	bin/mrtg-traffic-sum

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

MANPAGE=	cfgmaker.1 indexmaker.1 mrtg-contrib.1 mrtg-faq.1 mrtg-forum.1 \
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

OPTIONS_DEFINE=	DOCS EXAMPLES IPV6 SNMPV3

IPV6_RUN_DEPENDS=	p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6
SNMPV3_RUN_DEPENDS=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP

PORTDOCS=	*
PORTEXAMPLES=	*

post-extract:
	@${FIND} ${WRKSRC} -type f -name "*.orig" -delete

post-patch:
	@${RM} ${WRKSRC}/lib/mrtg2/BER.pm ${WRKSRC}/lib/mrtg2/SNMP_*.pm

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${EXAMPLESDIR}/doc \
		${STAGEDIR}${EXAMPLESDIR}/images \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/doc/,} \
		${STAGEDIR}${EXAMPLESDIR}/doc/
	${INSTALL_DATA} ${IMAGES:S,^,${WRKSRC}/images/,} \
		${STAGEDIR}${EXAMPLESDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/contrib/mrtgmk/cfg/mrtg.cfg \
		${STAGEDIR}${ETCDIR}/mrtg.cfg.sample
	${INSTALL_DATA} ${MANPAGE:S,^,${WRKSRC}/doc/,} \
		${STAGEDIR}${PREFIX}/man/man1
	cd ${WRKSRC}/lib/mrtg2 && \
		${COPYTREE_SHARE} "*.pm" ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rateup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/bin/,} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
