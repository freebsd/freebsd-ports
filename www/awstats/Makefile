PORTNAME=	awstats
PORTVERSION=	7.8
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/AWStats/${PORTVERSION}

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.TXT

USES=		cpe dos2unix perl5 shebangfix
CPE_VENDOR=	laurent_destailleur

SHEBANG_GLOB=	*.pl *.pm
DOS2UNIX_GLOB=	*.xml *.pm

NO_BUILD=	yes
NO_ARCH=	yes
USE_PERL5=	run

SUB_FILES=	pkg-message

OPTIONS_DEFINE=			DOCS GEOIPFREE IPV6
OPTIONS_GROUP=			MODULES
OPTIONS_DEFAULT=		HOSTINFO

OPTIONS_GROUP_MODULES=		DECODEUTFKEYS HOSTINFO
MODULES_DESC=			Plugin support not present in Perl CORE
DECODEUTFKEYS_DESC=		DecodeUTFKeys (requires p5-URI)
GEOIPFREE_DESC=			Country lookups via Geo::IPfree
HOSTINFO_DESC=			HostInfo (requires p5-Net-XWhois)
GEOIPFREE_RUN_DEPENDS=		p5-Geo-IPfree>=0:net/p5-Geo-IPfree
IPV6_RUN_DEPENDS=		p5-Net-IP>=0:net-mgmt/p5-Net-IP \
				p5-Net-DNS>=0:dns/p5-Net-DNS
DECODEUTFKEYS_RUN_DEPENDS=	p5-URI>0:net/p5-URI
HOSTINFO_RUN_DEPENDS=		p5-Net-XWhois>=0:net/p5-Net-XWhois

pre-patch:
# This file is so messed up, not even dos2unix can fix it
	@fixme="${WRKSRC}/wwwroot/cgi-bin/plugins/export_to_csv.pm" && \
		${TR} '\r' '\n' < $$fixme > $$fixme.new && \
		${MV} $$fixme.new $$fixme

post-patch:
	${REINPLACE_CMD} -E -e 's|/usr/local/etc/awstats|${ETCDIR}|' \
			-e 's|/etc/awstats/(awstats.model.conf)|${ETCDIR}/\1|' \
			-e 's,/usr/(local|share)/awstats/wwwroot,${WWWDIR},' \
		${WRKSRC}/tools/*.pl \
		${WRKSRC}/tools/httpd_conf \
		${WRKSRC}/tools/nginx/* \
		${WRKSRC}/wwwroot/cgi-bin/*.pl \
		${WRKSRC}/wwwroot/cgi-bin/*.conf
	${REINPLACE_CMD} -e 's|/etc/awstats|${ETCDIR}|' \
		${WRKSRC}/tools/awstats_updateall.pl
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			-e 's|%%WWWDIR%%|${WWWDIR}|' \
			-e 's|AWSTATS_PATH/wwwroot|AWSTATS_PATH|' \
		${WRKSRC}/tools/awstats_configure.pl

pre-install:
.for f in dolibarr httpd_conf nginx webmin
	${MV} ${WRKSRC}/tools/$f ${WRKSRC}/docs
.endfor
	${RM} ${WRKSRC}/docs/*.bak

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/tools
	${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin
.for f in awstats_buildstaticpages.pl awstats_configure.pl \
	awstats_exportlib.pl awstats_updateall.pl geoip_generator.pl \
	logresolvemerge.pl maillogconvert.pl urlaliasbuilder.pl
	${INSTALL_SCRIPT} ${WRKSRC}/tools/$f ${STAGEDIR}${WWWDIR}/tools
.endfor
.for f in awdownloadcsv.pl awredir.pl awstats.model.conf awstats.pl
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/$f ${STAGEDIR}${WWWDIR}/cgi-bin
.endfor
	(cd ${WRKSRC}/wwwroot/cgi-bin && ${COPYTREE_SHARE} "lang lib plugins" ${STAGEDIR}${WWWDIR}/cgi-bin)
	(cd ${WRKSRC}/wwwroot && ${COPYTREE_SHARE} "css icon js" ${STAGEDIR}${WWWDIR})
	(cd ${WRKSRC}/tools && ${COPYTREE_SHARE} xslt ${STAGEDIR}${WWWDIR}/tools)
	${MKDIR} ${STAGEDIR}${WWWDIR}/classes
	${INSTALL_DATA} ${WRKSRC}/wwwroot/classes/awgraphapplet.jar ${STAGEDIR}${WWWDIR}/classes

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
