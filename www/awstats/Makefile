PORTNAME=	awstats
DISTVERSION=	8.0
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/AWStats/${DISTVERSION}

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Free real-time logfile analyzer to get advanced web statistics
WWW=		https://www.awstats.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.TXT

USES=		cpe dos2unix perl5 shebangfix
CPE_VENDOR=	laurent_destailleur
DOS2UNIX_GLOB=	*.pm *.xml
USE_PERL5=	run

SHEBANG_GLOB=	*.pl *.pm

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=			DOCS GEOIPFREE IPV6
OPTIONS_DEFAULT=		HOSTINFO
OPTIONS_GROUP=			MODULES

OPTIONS_GROUP_MODULES=		DECODEUTFKEYS HOSTINFO JSON
DECODEUTFKEYS_DESC=		DecodeUTFKeys (requires p5-URI)
GEOIPFREE_DESC=			Country lookups via Geo::IPfree
HOSTINFO_DESC=			HostInfo (requires p5-Net-XWhois)
JSON_DESC=			JSON (requires p5-JSON-XS, p5-Try-Tiny)
MODULES_DESC=			Plugin support not present in Perl CORE
DECODEUTFKEYS_RUN_DEPENDS=	p5-URI>0:net/p5-URI
GEOIPFREE_RUN_DEPENDS=		p5-Geo-IPfree>=0:net/p5-Geo-IPfree
HOSTINFO_RUN_DEPENDS=		p5-Net-XWhois>=0:net/p5-Net-XWhois
IPV6_RUN_DEPENDS=		p5-Net-IP>=0:net-mgmt/p5-Net-IP \
				p5-Net-DNS>=0:dns/p5-Net-DNS
JSON_RUN_DEPENDS=		p5-JSON-XS>=0:converters/p5-JSON-XS \
				p5-Try-Tiny>=0:lang/p5-Try-Tiny

_DOCS=		dolibarr httpd_conf nginx webmin
_TOOLS=		awstats_buildstaticpages.pl awstats_configure.pl \
		awstats_exportlib.pl awstats_updateall.pl geoip_generator.pl \
		logresolvemerge.pl maillogconvert.pl urlaliasbuilder.pl
_CGI_BIN=	awdownloadcsv.pl awredir.pl awstats.model.conf awstats.pl
_SHARE_DIRS=	lang lib plugins
_WWW_DIRS=	css icon js

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

post-patch-JSON-off:
	${REINPLACE_CMD} -e '/^use JSON::XS;$$/d' -e '/^use Try::Tiny;$$/d' \
		${WRKSRC}/wwwroot/cgi-bin/awstats.pl

pre-install-DOCS-on:
	${MV} ${_DOCS:C|^|${WRKSRC}/tools/|} ${WRKSRC}/docs
	${RM} ${WRKSRC}/docs/*.bak

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/tools \
		 ${STAGEDIR}${WWWDIR}/cgi-bin \
		 ${STAGEDIR}${WWWDIR}/classes
	${INSTALL_SCRIPT} ${_TOOLS:C|^|${WRKSRC}/tools/|} ${STAGEDIR}${WWWDIR}/tools
	${INSTALL_SCRIPT} ${_CGI_BIN:C|^|${WRKSRC}/wwwroot/cgi-bin/|} ${STAGEDIR}${WWWDIR}/cgi-bin
	(cd ${WRKSRC}/wwwroot/cgi-bin && ${COPYTREE_SHARE} "${_SHARE_DIRS}" ${STAGEDIR}${WWWDIR}/cgi-bin)
	(cd ${WRKSRC}/wwwroot && ${COPYTREE_SHARE} "${_WWW_DIRS}" ${STAGEDIR}${WWWDIR})
	(cd ${WRKSRC}/tools && ${COPYTREE_SHARE} xslt ${STAGEDIR}${WWWDIR}/tools)
	${INSTALL_DATA} ${WRKSRC}/wwwroot/classes/awgraphapplet.jar ${STAGEDIR}${WWWDIR}/classes

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
