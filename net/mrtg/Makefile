# New ports collection makefile for:	MRTG
# Version required:			2.5.1
# Date created:				April 18th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.6 1997/07/05 03:19:18 jfitz Exp $
#

DISTNAME=	mrtg-2.5.1
CATEGORIES=	net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/mrtg/pub/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/PV.pm:${PORTSDIR}/devel/p5-PV

USE_PERL5=	YES

ALL_TARGET=	rateup substitute

do-install:
		${MKDIR} -p -m 755 ${PREFIX}/etc/mrtg
		${MKDIR} -p -m 755 ${PREFIX}/lib/perl5/site_perl
		${MKDIR} -p -m 755 ${PREFIX}/share/mrtg
		${MKDIR} -p -m 755 ${PREFIX}/share/doc/mrtg
		for file in readme.html readme.txt mibhelp.txt INSTALL COPYING COPYRIGHT Changes Contributors Todo; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/mrtg/; \
		done
		for file in ${WRKSRC}/*.gif; do \
			${INSTALL_DATA} $$file ${PREFIX}/share/mrtg/; \
		done
		for file in SNMP_Session.pm BER.pm; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/perl5/site_perl/; \
		done
		${INSTALL_PROGRAM} ${WRKSRC}/rateup ${PREFIX}/bin/
		for file in mrtg cfgmaker convert indexmaker; do \
			${INSTALL_SCRIPT} ${WRKSRC}/$$file ${PREFIX}/bin/; \
		done
		${INSTALL_DATA} ${WRKSRC}/mrtg.cfg-dist ${PREFIX}/etc/mrtg

.include <bsd.port.mk>
