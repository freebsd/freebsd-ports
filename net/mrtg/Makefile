# New ports collection makefile for:	MRTG
# Date created:				April 18th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrtg
PORTVERSION=	2.9.11
CATEGORIES=	net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/pub/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	net/mrtg

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

USE_PERL5=	YES
MAKE_ENV+=	PERL=${PERL}

GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-gd-lib=${LOCALBASE}/lib \
		--with-gd-inc=${LOCALBASE}/include/gd

CONFIGURE_ENV=	PERL=${PERL}

MAN1=		cfgmaker.1 contrib.1 faq.1 forum.1 indexmaker.1 logfile.1 \
		mibhelp.1 mrtg.1 mrtg-rrd.1 mrtglib.1 nt-guide.1 reference.1 \
		squid.1 unix-guide.1 webserver.1

do-install:
		${MKDIR} -m 755 ${PREFIX}/etc/mrtg
		${MKDIR} -m 755 ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
		${MKDIR} -m 755 ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Pod
		${MKDIR} -m 755 ${PREFIX}/share/mrtg
.if !defined(NOPORTDOCS)
		${MKDIR} -m 755 ${PREFIX}/share/doc/mrtg
		for file in ANNOUNCE CHANGES COPYRIGHT MANIFEST README \
			doc/*.html doc/*.pod doc/*.txt doc/*wml doc/*.png ; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/mrtg/; \
		done
.endif
		${INSTALL_DATA} ${WRKSRC}/contrib/mrtgmk/cfg/mrtg.cfg ${PREFIX}/etc/mrtg/mrtg.cfg.sample
		${INSTALL_DATA} ${WRKSRC}/images/* ${PREFIX}/share/mrtg
		${INSTALL_DATA} ${WRKSRC}/doc/*.1 ${PREFIX}/man/man1
		${INSTALL_DATA} ${WRKSRC}/lib/mrtg2/*.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
		${INSTALL_DATA} ${WRKSRC}/lib/mrtg2/Pod/*.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Pod
		${INSTALL_PROGRAM} ${WRKSRC}/bin/rateup ${PREFIX}/bin/
		for file in mrtg cfgmaker indexmaker; do \
			${INSTALL_SCRIPT} ${WRKSRC}/bin/$$file ${PREFIX}/bin/; \
		done

post-install:
.if !defined(BATCH)
	@${ECHO} ""
	@${ECHO} "############################################################################"
	@${ECHO} "# Please create a MRTG config file in ${PREFIX}/etc/mrtg                   #"
	@${ECHO} "# A configuration file can be automatically generated with cfgmaker        #"
	@${ECHO} "# A sample configuration file is installed as mrtg.cfg.sample              #"
	@${ECHO} "############################################################################"
.endif

.include <bsd.port.mk>
