# New ports collection makefile for:	MRTG
# Version required:			2.5.3
# Date created:				April 18th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.9 1998/09/28 17:11:12 smace Exp $
#

DISTNAME=	mrtg-2.5.3
CATEGORIES=	net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/pub/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/PV.pm:${PORTSDIR}/devel/p5-PV

USE_PERL5=	YES
MAKE_ENV+=	PERL=${PERL}

ALL_TARGET=	rateup substitute

do-install:
		${MKDIR} -p -m 755 ${PREFIX}/etc/mrtg
		${MKDIR} -p -m 755 ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
		${MKDIR} -p -m 755 ${PREFIX}/share/mrtg
		${MKDIR} -p -m 755 ${PREFIX}/share/doc/mrtg
		for file in readme.html readme.txt mibhelp.txt INSTALL COPYING COPYRIGHT Changes Contributors Todo; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/mrtg/; \
		done
		for file in ${WRKSRC}/*.gif; do \
			${INSTALL_DATA} $$file ${PREFIX}/share/mrtg/; \
		done
		for file in SNMP_Session.pm BER.pm; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/perl5/site_perl/${PERL_VER}; \
		done
		${INSTALL_PROGRAM} ${WRKSRC}/rateup ${PREFIX}/bin/
		for file in mrtg cfgmaker convert indexmaker; do \
			${INSTALL_SCRIPT} ${WRKSRC}/$$file ${PREFIX}/bin/; \
		done

post-install:
.if !defined(BATCH)
	@${ECHO} ""
	@${ECHO} "############################################################################"
	@${ECHO} "# Please create a MRTG config file in ${PREFIX}/etc/mrtg                   #"
	@${ECHO} "# A configuration file can be automatically generated with cfgmaker        #"
	@${ECHO} "############################################################################"
.endif

.include <bsd.port.mk>
