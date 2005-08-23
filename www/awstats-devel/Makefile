# New ports collection makefile for:	awstats
# Date created:			May 13, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	awstats
PORTVERSION=	6.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	webmaster@lightningfire.net
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

RUN_DEPENDS=	${SITE_PERL}/Net/XWhois.pm:${PORTSDIR}/net/p5-Net-XWhois

NO_BUILD=	yes
USE_PERL5_RUN=	yes

do-install:
	@${MKDIR} ${PREFIX}/www/awstats
	@${MKDIR} ${PREFIX}/www/awstats/cgi-bin
	@${MKDIR} ${PREFIX}/www/awstats/cgi-bin/lang
	@${MKDIR} ${PREFIX}/www/awstats/cgi-bin/lang/tooltips_f
	@${MKDIR} ${PREFIX}/www/awstats/cgi-bin/lang/tooltips_m
	@${MKDIR} ${PREFIX}/www/awstats/cgi-bin/lang/tooltips_w
	@${MKDIR} ${PREFIX}/www/awstats/cgi-bin/lib
	@${MKDIR} ${PREFIX}/www/awstats/cgi-bin/plugins
	@${MKDIR} ${PREFIX}/www/awstats/cgi-bin/plugins/example
	@${MKDIR} ${PREFIX}/www/awstats/classes
	@${MKDIR} ${PREFIX}/www/awstats/css
	@${MKDIR} ${PREFIX}/www/awstats/icons/browser
	@${MKDIR} ${PREFIX}/www/awstats/icons/clock
	@${MKDIR} ${PREFIX}/www/awstats/icons/cpu
	@${MKDIR} ${PREFIX}/www/awstats/icons/flags
	@${MKDIR} ${PREFIX}/www/awstats/icons/mime
	@${MKDIR} ${PREFIX}/www/awstats/icons/os
	@${MKDIR} ${PREFIX}/www/awstats/icons/other
	@${MKDIR} ${PREFIX}/www/awstats/js
	@${MKDIR} ${PREFIX}/www/awstats/tools
	@${MKDIR} ${PREFIX}/www/awstats/tools/webmin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_buildstaticpages.pl ${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_exportlib.pl ${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_updateall.pl ${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_configure.pl ${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/logresolvemerge.pl ${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/maillogconvert.pl ${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/urlaliasbuilder.pl ${PREFIX}/www/awstats/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/webmin/awstats-1.5.wbm ${PREFIX}/www/awstats/tools/webmin
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/awredir.pl ${PREFIX}/www/awstats/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/awstats.model.conf ${PREFIX}/www/awstats/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/awstats.pl ${PREFIX}/www/awstats/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/tooltips_f/*.txt ${PREFIX}/www/awstats/cgi-bin/lang/tooltips_f
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/tooltips_m/*.txt ${PREFIX}/www/awstats/cgi-bin/lang/tooltips_m
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/tooltips_w/*.txt ${PREFIX}/www/awstats/cgi-bin/lang/tooltips_w
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/*.txt ${PREFIX}/www/awstats/cgi-bin/lang
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lib/* ${PREFIX}/www/awstats/cgi-bin/lib
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/decodeutfkeys.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/geoip.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/geoipfree.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/graphapplet.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/hashfiles.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/hostinfo.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/ipv6.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/rawlog.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/timehires.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/timezone.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/tooltips.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/urlalias.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/userinfo.pm ${PREFIX}/www/awstats/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/example/* ${PREFIX}/www/awstats/cgi-bin/plugins/example
	${INSTALL_DATA} ${WRKSRC}/wwwroot/css/* ${PREFIX}/www/awstats/css
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/browser/* ${PREFIX}/www/awstats/icons/browser
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/clock/* ${PREFIX}/www/awstats/icons/clock
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/cpu/* ${PREFIX}/www/awstats/icons/cpu
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/flags/* ${PREFIX}/www/awstats/icons/flags
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/mime/* ${PREFIX}/www/awstats/icons/mime
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/os/* ${PREFIX}/www/awstats/icons/os
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/other/* ${PREFIX}/www/awstats/icons/other
	${INSTALL_DATA} ${WRKSRC}/wwwroot/js/* ${PREFIX}/www/awstats/js
	@${ECHO_CMD} ""
	@${ECHO_CMD} "* Rename ${PREFIX}/www/awstats/cgi-bin/awstats.model.conf to awstats.site.conf to setup awstats"
	@${ECHO_CMD} "* Documentation has been installed in ${PREFIX}/share/doc/awstats"
	@${ECHO_CMD} ""

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/images/* ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${DOCSDIR}
.endif

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
