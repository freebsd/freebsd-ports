# New ports collection makefile for:	routers2
# Date created:				December 11th 2006
# Whom:	      				Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	routers2
PORTVERSION=	2.19
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.steveshipway.org/software/rrd/ \
		ftp://ftp.oav.oav.net/routers2/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Frontend for the MRTG system monitoring software

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS=	${SITE_PERL}/Convert/ASN1/IO.pm:${PORTSDIR}/converters/p5-Convert-ASN1 \
		${SITE_PERL}/Crypt/UnixCrypt.pm:${PORTSDIR}/security/p5-Crypt-UnixCrypt \
		${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/Crypt/UnixCrypt.pm:${PORTSDIR}/security/p5-Crypt-UnixCrypt \
		${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		${SITE_PERL}/CGI/SpeedyCGI.pm:${PORTSDIR}/www/p5-CGI-SpeedyCGI \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${LOCALBASE}/bin/mrtg:${PORTSDIR}/net-mgmt/mrtg

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}

USE_PERL5=	YES

NO_BUILD=	YES

post-patch:
	@${RM} ${WRKSRC}/extras/targetnames/BER.pm ${WRKSRC}/extras/targetnames/SNMP_*.pm
	for file in routers2.cgi.pl routers2.conf ; do \
		${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/$$file; \
	done

do-install:
		${MKDIR} -m 755 ${PREFIX}/www/routers2
		${MKDIR} -m 755 ${PREFIX}/www/routers2/rrdicons
		${MKDIR} -m 755 ${PREFIX}/www/routers2/graphs
		${MKDIR} -m 755 /var/db/rrdtool
		${CHOWN} ${WWWOWN}:${WWWGRP} /var/db/rrdtool
		${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/www/routers2/graphs

.if !defined(NOPORTDOCS)
		${MKDIR} -m 755 ${DOCSDIR}
		for file in CHANGES README doc/* ; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${DOCSDIR}; \
		done
.endif
		${INSTALL_DATA} ${WRKSRC}/routers2.conf ${PREFIX}/etc/routers2.conf.sample
		${INSTALL_DATA} ${WRKSRC}/rrdicons/* ${PREFIX}/www/routers2/rrdicons
		${INSTALL_SCRIPT} ${WRKSRC}/routers2.cgi.pl ${PREFIX}/www/routers2/routers2.cgi
#		for file in mrtg cfgmaker indexmaker; do \
#			${INSTALL_SCRIPT} ${WRKSRC}/bin/$$file ${PREFIX}/bin/; \
#		done

#post-install:
#.if !defined(BATCH)
#	@${ECHO} ""
#	@${ECHO} "############################################################################"
#	@${ECHO} "# Please create a MRTG config file in ${PREFIX}/etc/mrtg                  #"
#	@${ECHO} "# A configuration file can be automatically generated with cfgmaker        #"
#	@${ECHO} "# A sample configuration file is installed as mrtg.cfg.sample              #"
#	@${ECHO} "#                                                                          #"
#	@${ECHO} "# To enable MRTG in daemon mode, put the following to your /etc/rc.conf or #"
#	@${ECHO} "# /etc/rc.conf.local file:                                                 #"
#	@${ECHO} "#      mrtg_daemon_enable=\"YES\"                                            #"
#	@${ECHO} "############################################################################"
#.endif

.include <bsd.port.mk>
