# New ports collection makefile for:	MRTG
# Version required:			2.8.8
# Date created:				April 18th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	mrtg-2.8.8
CATEGORIES=	net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/pub/

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

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
			doc/mibhelp.txt doc/squid.txt ; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/mrtg/; \
		done
.endif
		${INSTALL_DATA} ${WRKSRC}/doc/sample-mrtg.cfg ${PREFIX}/etc/mrtg
		for file in ${WRKSRC}/images/*.gif; do \
			${INSTALL_DATA} $$file ${PREFIX}/share/mrtg/; \
		done
		for file in SNMP_Session.pm SNMP_util.pm BER.pm locales_mrtg.pm; do \
			${INSTALL_DATA} ${WRKSRC}/run/$$file ${PREFIX}/lib/perl5/site_perl/${PERL_VER}; \
		done
		${INSTALL_PROGRAM} ${WRKSRC}/run/rateup ${PREFIX}/bin/
		for file in mrtg cfgmaker cfgmaker_ip indexmaker; do \
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
