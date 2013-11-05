# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	awstats
PORTVERSION=	7.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/AWStats/${PORTVERSION}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-XWhois>=0:${PORTSDIR}/net/p5-Net-XWhois

USES=		perl5 shebangfix

SHEBANG_FILES=	tools/*.pl wwwroot/cgi-bin/*.pl wwwroot/cgi-bin/plugins/*.pm

NO_BUILD=	yes
USE_PERL5=	run
USE_DOS2UNIX=	tools/*.pl \
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

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIPV6}
RUN_DEPENDS+=	p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP
RUN_DEPENDS+=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/tools/awstats_buildstaticpages.pl
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/tools/awstats_configure.pl
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/tools/awstats_updateall.pl
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/wwwroot/cgi-bin/awstats.pl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/lang
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/lang/tooltips_f
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/lang/tooltips_m
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/lang/tooltips_w
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/plugins
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/plugins/example
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/classes
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/css
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/icons/browser
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/icons/clock
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/icons/cpu
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/icons/flags
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/icons/mime
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/icons/os
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/icons/other
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/js
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/tools
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/tools/webmin
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/awstats/tools/xslt
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_buildstaticpages.pl ${STAGEDIR}${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_configure.pl ${STAGEDIR}${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_exportlib.pl ${STAGEDIR}${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_updateall.pl ${STAGEDIR}${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/logresolvemerge.pl ${STAGEDIR}${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/maillogconvert.pl ${STAGEDIR}${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/urlaliasbuilder.pl ${STAGEDIR}${PREFIX}/www/awstats/tools
	${INSTALL_DATA} ${WRKSRC}/tools/xslt/* ${STAGEDIR}${PREFIX}/www/awstats/tools/xslt
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/awredir.pl ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/awstats.model.conf ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/awstats.pl ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/tooltips_f/*.txt ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/lang/tooltips_f
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/tooltips_m/*.txt ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/lang/tooltips_m
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/tooltips_w/*.txt ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/lang/tooltips_w
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/*.txt ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/lang
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lib/* ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/lib
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/*.pm ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/example/* ${STAGEDIR}${PREFIX}/www/awstats/cgi-bin/plugins/example
	${INSTALL_DATA} ${WRKSRC}/wwwroot/classes/awgraphapplet.jar ${STAGEDIR}${PREFIX}/www/awstats/classes/awgraphapplet.jar
	${INSTALL_DATA} ${WRKSRC}/wwwroot/css/* ${STAGEDIR}${PREFIX}/www/awstats/css
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/browser/* ${STAGEDIR}${PREFIX}/www/awstats/icons/browser
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/clock/* ${STAGEDIR}${PREFIX}/www/awstats/icons/clock
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/cpu/* ${STAGEDIR}${PREFIX}/www/awstats/icons/cpu
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/flags/* ${STAGEDIR}${PREFIX}/www/awstats/icons/flags
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/mime/* ${STAGEDIR}${PREFIX}/www/awstats/icons/mime
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/os/* ${STAGEDIR}${PREFIX}/www/awstats/icons/os
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/other/* ${STAGEDIR}${PREFIX}/www/awstats/icons/other
	${INSTALL_DATA} ${WRKSRC}/wwwroot/js/* ${STAGEDIR}${PREFIX}/www/awstats/js
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/images/* ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${STAGEDIR}${DOCSDIR}
.endif
	@${ECHO_CMD} ""
	@${ECHO_CMD} "* Use ${PREFIX}/www/awstats/tools/awstats_configure.pl to setup your hosts."
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_CMD} "* Documentation has been installed in ${PREFIX}/share/doc/awstats"
.endif
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
