# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	awstats
PORTVERSION=	7.4
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/AWStats/${PORTVERSION}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.TXT

RUN_DEPENDS=	p5-Net-XWhois>=0:net/p5-Net-XWhois

USES=		cpe dos2unix perl5 shebangfix
CPE_VENDOR=	laurent_destailleur

SHEBANG_FILES=	tools/*.pl wwwroot/cgi-bin/*.pl wwwroot/cgi-bin/plugins/*.pm

NO_BUILD=	yes
USE_PERL5=	run
DOS2UNIX_GLOB=	tools/*.pl \
		wwwroot/cgi-bin/awstats.model.conf \
		wwwroot/cgi-bin/*.pl \
		wwwroot/cgi-bin/lang/tooltips_f/*.txt \
		wwwroot/cgi-bin/lang/tooltips_m/*.txt \
		wwwroot/cgi-bin/lang/tooltips_w/*.txt \
		wwwroot/cgi-bin/lang/*.txt \
		wwwroot/cgi-bin/lib/* \
		wwwroot/cgi-bin/plugins/*.pm \
		wwwroot/cgi-bin/plugins/example/* \
		wwwroot/css/* \
		wwwroot/js/*

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS IPV6

IPV6_RUN_DEPENDS=	p5-Net-IP>=0:net-mgmt/p5-Net-IP \
			p5-Net-DNS>=0:dns/p5-Net-DNS

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/tools/awstats_buildstaticpages.pl \
		${WRKSRC}/tools/awstats_configure.pl \
		${WRKSRC}/tools/awstats_updateall.pl \
		${WRKSRC}/wwwroot/cgi-bin/awstats.pl

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/tools/webmin
	(cd ${WRKSRC}/tools && ${INSTALL_SCRIPT} awstats_buildstaticpages.pl \
		awstats_configure.pl awstats_exportlib.pl awstats_updateall.pl \
		logresolvemerge.pl maillogconvert.pl urlaliasbuilder.pl \
		${STAGEDIR}${WWWDIR}/tools)
	(cd ${WRKSRC}/tools && ${COPYTREE_SHARE} xslt ${STAGEDIR}${WWWDIR}/tools)
	@${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin
	(cd ${WRKSRC}/wwwroot/cgi-bin && ${INSTALL_SCRIPT} awredir.pl awstats.pl \
		awstats.model.conf ${STAGEDIR}${WWWDIR}/cgi-bin)
	@${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin/lang/tooltips_f
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/tooltips_f/*.txt \
		${STAGEDIR}${WWWDIR}/cgi-bin/lang/tooltips_f
	@${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin/lang/tooltips_m
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/tooltips_m/*.txt \
		${STAGEDIR}${WWWDIR}/cgi-bin/lang/tooltips_m
	@${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin/lang/tooltips_w
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/tooltips_w/*.txt \
		${STAGEDIR}${WWWDIR}/cgi-bin/lang/tooltips_w
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/*.txt \
		${STAGEDIR}${WWWDIR}/cgi-bin/lang
	(cd ${WRKSRC}/wwwroot/cgi-bin && ${COPYTREE_SHARE} lib \
		${STAGEDIR}${WWWDIR}/cgi-bin)
	@${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/*.pm \
		${STAGEDIR}${WWWDIR}/cgi-bin/plugins
	(cd ${WRKSRC}/wwwroot/cgi-bin/plugins && ${COPYTREE_SHARE} example \
		${STAGEDIR}${WWWDIR}/cgi-bin/plugins)
	@${MKDIR} ${STAGEDIR}${WWWDIR}/classes
	${INSTALL_DATA} ${WRKSRC}/wwwroot/classes/awgraphapplet.jar \
		${STAGEDIR}${WWWDIR}/classes
	(cd ${WRKSRC}/wwwroot && ${COPYTREE_SHARE} "js css" ${STAGEDIR}${WWWDIR})
	(cd ${WRKSRC}/wwwroot/icon && ${COPYTREE_SHARE} "browser clock cpu \
		flags mime os other" ${STAGEDIR}${WWWDIR}/icons)

	@${ECHO_CMD} ""
	@${ECHO_CMD} "* Use ${WWWDIR}/tools/awstats_configure.pl to setup your hosts."
	@${ECHO_CMD} ""

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} images ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
