# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	routers2
PORTVERSION=	2.19
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.steveshipway.org/software/rrd/ \
		ftp://ftp.oav.oav.net/routers2/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Frontend for the MRTG system monitoring software

BUILD_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS=	p5-Convert-ASN1>=0:${PORTSDIR}/converters/p5-Convert-ASN1 \
		p5-Crypt-UnixCrypt>=0:${PORTSDIR}/security/p5-Crypt-UnixCrypt \
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-Crypt-UnixCrypt>=0:${PORTSDIR}/security/p5-Crypt-UnixCrypt \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-SNMP_Session>=0:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		p5-CGI-SpeedyCGI>=0:${PORTSDIR}/www/p5-CGI-SpeedyCGI \
		${LOCALBASE}/bin/mrtg:${PORTSDIR}/net-mgmt/mrtg

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}

USES=		perl5

NO_BUILD=	YES

NO_STAGE=	yes
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
