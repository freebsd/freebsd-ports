# New ports collection makefile for:	MRTG
# Date created:				April 18th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrtg
PORTVERSION=	2.8.12
CATEGORIES=	net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/pub/

MAINTAINER=	jfitz@FreeBSD.org

LIB_DEPENDS=	gd.1:${PORTSDIR}/graphics/gd

USE_PERL5=	YES
MAKE_ENV+=	PERL=${PERL}

GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-gd-lib=${PREFIX}/lib \
		--with-gd-inc=${PREFIX}/include/gd

CONFIGURE_ENV=	PERL=${PERL}

do-install:
		${MKDIR} -m 755 ${PREFIX}/etc/mrtg
		${MKDIR} -m 755 ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
		${MKDIR} -m 755 ${PREFIX}/share/mrtg
.if !defined(NOPORTDOCS)
		${MKDIR} -m 755 ${PREFIX}/share/doc/mrtg
		for file in ANNOUNCE CHANGES COPYING COPYRIGHT MANIFEST README \
			doc/config.html doc/config.pod doc/config.txt doc/htaccess.txt \
			doc/logfile-format.txt doc/manual.html doc/manual.txt \
			doc/mibhelp.txt doc/squid.txt UPGRADING ; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/mrtg/; \
		done
.endif
		${INSTALL_DATA} ${WRKSRC}/doc/sample-mrtg.cfg ${PREFIX}/etc/mrtg
		for file in ${WRKSRC}/images/*; do \
			${INSTALL_DATA} $$file ${PREFIX}/share/mrtg/; \
		done
		for file in SNMP_Session.pm SNMP_util.pm BER.pm locales_mrtg.pm; do \
			${INSTALL_DATA} ${WRKSRC}/run/$$file ${PREFIX}/lib/perl5/site_perl/${PERL_VER}; \
		done
		${INSTALL_PROGRAM} ${WRKSRC}/run/rateup ${PREFIX}/bin/
		for file in mrtg cfgmaker cfgmaker_ip cfgmaker_phys indexmaker; do \
			${INSTALL_SCRIPT} ${WRKSRC}/run/$$file ${PREFIX}/bin/; \
		done

post-install:
.if !defined(BATCH)
	@${ECHO} ""
	@${ECHO} "############################################################################"
	@${ECHO} "# Please create a MRTG config file in ${PREFIX}/etc/mrtg                   #"
	@${ECHO} "# A configuration file can be automatically generated with cfgmaker        #"
	@${ECHO} "# A sample configuration file is installed as sample-mrtg.cfg              #"
	@${ECHO} "############################################################################"
.endif

.include <bsd.port.mk>
