# New ports collection makefile for:	awstats
# Date created:			May 13, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	awstats
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	webmaster@lightningfire.net
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

NO_BUILD=	yes
USE_PERL5_RUN=	yes
RUN_DEPENDS+=	${SITE_PERL}/Net/XWhois.pm:${PORTSDIR}/net/p5-Net-XWhois

do-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin/lang
	@${MKDIR} ${PREFIX}/www/cgi-bin/lib
	@${MKDIR} ${PREFIX}/www/cgi-bin/plugins
	@${MKDIR} ${PREFIX}/www/cgi-bin/plugins/example
	@${MKDIR} ${PREFIX}/www/css
	@${MKDIR} ${PREFIX}/www/icons/browser
	@${MKDIR} ${PREFIX}/www/icons/clock
	@${MKDIR} ${PREFIX}/www/icons/cpu
	@${MKDIR} ${PREFIX}/www/icons/flags
	@${MKDIR} ${PREFIX}/www/icons/mime
	@${MKDIR} ${PREFIX}/www/icons/os
	@${MKDIR} ${PREFIX}/www/icons/other
	@${MKDIR} ${PREFIX}/www/js
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_buildstaticpages.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_exportlib.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/awstats_updateall.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/configure.pl ${PREFIX}/bin/awstats_configure.pl
	${INSTALL_SCRIPT} ${WRKSRC}/tools/logresolvemerge.pl ${PREFIX}/bin/awstats_logresolvemerge.pl
	${INSTALL_SCRIPT} ${WRKSRC}/tools/maillogconvert.pl ${PREFIX}/bin/awstats_maillogconvert.pl
	${INSTALL_SCRIPT} ${WRKSRC}/tools/urlaliasbuilder.pl ${PREFIX}/bin/awstats_urlaliasbuilder.pl
	${INSTALL_SCRIPT} ${WRKSRC}/tools/webmin/awstats-1.21.wbm ${PREFIX}/bin/awstats-1.21.wbm
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/awredir.pl ${PREFIX}/www/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/awstats.model.conf ${PREFIX}/www/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/awstats.pl ${PREFIX}/www/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/* ${PREFIX}/www/cgi-bin/lang
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lib/* ${PREFIX}/www/cgi-bin/lib
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/decodeutfkeys.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/geoip.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/geoipfree.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/graphapplet.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/hashfiles.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA}	${WRKSRC}/wwwroot/cgi-bin/plugins/hostinfo.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/ipv6.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA}	${WRKSRC}/wwwroot/cgi-bin/plugins/rawlog.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/timehires.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/timezone.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/tooltips.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/urlalias.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/userinfo.pm ${PREFIX}/www/cgi-bin/plugins
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/example/* ${PREFIX}/www/cgi-bin/plugins/example
	${INSTALL_DATA} ${WRKSRC}/wwwroot/css/* ${PREFIX}/www/css
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/browser/* ${PREFIX}/www/icons/browser
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/clock/* ${PREFIX}/www/icons/clock
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/cpu/* ${PREFIX}/www/icons/cpu
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/flags/* ${PREFIX}/www/icons/flags
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/mime/* ${PREFIX}/www/icons/mime
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/os/* ${PREFIX}/www/icons/os
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/other/* ${PREFIX}/www/icons/other
	${INSTALL_DATA} ${WRKSRC}/wwwroot/js/* ${PREFIX}/www/js
	@${ECHO_CMD} ""
	@${ECHO_CMD} "* Rename ${PREFIX}/www/cgi-bin/awstats.model.conf to awstats.conf to set up AWStats"
	@${ECHO_CMD} "* Documentation has been installed in ${PREFIX}/share/doc/awstats"
	@${ECHO_CMD} ""

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/images/* ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
