# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	routers2
PORTVERSION=	2.23
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.steveshipway.org/software/rrd/ \
		ftp://ftp.oav.oav.net/routers2/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Frontend for the MRTG system monitoring software

BUILD_DEPENDS=	p5-GD>=0:graphics/p5-GD
RUN_DEPENDS=	p5-Convert-ASN1>=0:converters/p5-Convert-ASN1 \
		p5-Crypt-UnixCrypt>=0:security/p5-Crypt-UnixCrypt \
		p5-GD>=0:graphics/p5-GD \
		p5-Crypt-UnixCrypt>=0:security/p5-Crypt-UnixCrypt \
		p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
		p5-SNMP_Session>=0:net-mgmt/p5-SNMP_Session \
		p5-CGI-SpeedyCGI>=0:www/p5-CGI-SpeedyCGI \
		${LOCALBASE}/bin/mrtg:net-mgmt/mrtg

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}
USES=		perl5
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} ${WRKSRC}/extras/targetnames/BER.pm \
		${WRKSRC}/extras/targetnames/SNMP_*.pm
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/routers2.cgi.pl ${WRKSRC}/routers2.conf

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/routers2 \
		${STAGEDIR}${PREFIX}/www/routers2/rrdicons \
		${STAGEDIR}${PREFIX}/www/routers2/graphs \
		${STAGEDIR}/var/db/rrdtool
	${INSTALL_DATA} ${WRKSRC}/routers2.conf \
		${STAGEDIR}${PREFIX}/etc/routers2.conf.sample
	${INSTALL_DATA} ${WRKSRC}/rrdicons/* \
		${STAGEDIR}${PREFIX}/www/routers2/rrdicons
	${INSTALL_SCRIPT} ${WRKSRC}/routers2.cgi.pl \
		${STAGEDIR}${PREFIX}/www/routers2/routers2.cgi

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; \
		${INSTALL_DATA} CHANGES README doc/* ${STAGEDIR}${DOCSDIR}

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
