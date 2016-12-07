# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	awstats
PORTVERSION=	7.6
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/AWStats/${PORTVERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.TXT

RUN_DEPENDS=	p5-Net-XWhois>=0:net/p5-Net-XWhois

USES=		cpe dos2unix perl5 shebangfix
CPE_VENDOR=	laurent_destailleur

SHEBANG_GLOB=	*.pl *.pm
DOS2UNIX_GLOB=	*.xml *.pm

NO_BUILD=	yes
NO_ARCH=	yes
USE_PERL5=	run

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS IPV6
OPTIONS_RADIO=	GEO

OPTIONS_RADIO_GEO=	GEOIP GEOIPFREE
GEO_DESC=	Identify country of source IPs
GEOIP_DESC=	Country lookups via Geo::IP
GEOIPFREE_DESC=	Country lookups via Geo::IPfree

GEOIP_RUN_DEPENDS=	p5-Geo-IP>=0:net/p5-Geo-IP
GEOIPFREE_RUN_DEPENDS=	p5-Geo-IPfree>=0:net/p5-Geo-IPfree
IPV6_RUN_DEPENDS=	p5-Net-IP>=0:net-mgmt/p5-Net-IP \
			p5-Net-DNS>=0:dns/p5-Net-DNS

pre-patch:
# This file is so messed up, not even dos2unix can fix it
	@fixme="${WRKSRC}/wwwroot/cgi-bin/plugins/export_to_csv.pm" && \
		${TR} '\r' '\n' < $$fixme > $$fixme.new && \
		${MV} $$fixme.new $$fixme

post-patch:
	@${REINPLACE_CMD} -E -e 's|/usr/local/etc/awstats|${ETCDIR}|' \
			-e 's|/etc/awstats/(awstats.model.conf)|${ETCDIR}/\1|' \
			-e 's,/usr/(local|share)/awstats/wwwroot,${WWWDIR},' \
		${WRKSRC}/tools/*.pl \
		${WRKSRC}/tools/httpd_conf \
		${WRKSRC}/tools/nginx/* \
		${WRKSRC}/wwwroot/cgi-bin/*.pl \
		${WRKSRC}/wwwroot/cgi-bin/*.conf
	@${REINPLACE_CMD} -e 's|/etc/awstats|${ETCDIR}|' \
		${WRKSRC}/tools/awstats_updateall.pl
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			-e 's|%%WWWDIR%%|${WWWDIR}|' \
			-e 's|AWSTATS_PATH/wwwroot|AWSTATS_PATH|' \
		${WRKSRC}/tools/awstats_configure.pl

pre-install:
.for f in dolibarr httpd_conf nginx webmin
	@${MV} ${WRKSRC}/tools/$f ${WRKSRC}/docs
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} tools ${STAGEDIR}${WWWDIR})
	(cd ${WRKSRC}/wwwroot && ${COPYTREE_SHARE} "cgi-bin css icon js" ${STAGEDIR}${WWWDIR})

	@${MKDIR} ${STAGEDIR}${WWWDIR}/classes
	${INSTALL_DATA} ${WRKSRC}/wwwroot/classes/awgraphapplet.jar ${STAGEDIR}${WWWDIR}/classes

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
