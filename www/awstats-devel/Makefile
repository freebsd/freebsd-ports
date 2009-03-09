# New ports collection makefile for:	awstats
# Date created:			May 13, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	awstats
PORTVERSION=	6.8
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://awstats.sourceforge.net/files/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

RUN_DEPENDS=	${SITE_PERL}/Net/XWhois.pm:${PORTSDIR}/net/p5-Net-XWhois

NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_DOS2UNIX=	tools/logresolvemerge.pl

SUB_FILES=	pkg-message

FORBIDDEN=	http://www.vuxml.org/freebsd/27d78386-d35f-11dd-b800-001b77d09812.html

CONFLICTS=	awstats-6.*
LATEST_LINK=	awstats-devel

OPTIONS=	IPV6 "Enable IPV6 for use with IPv6 Plugin" Off

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
RUN_DEPENDS+=	${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP
RUN_DEPENDS+=	${SITE_PERL}/mach/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
.endif

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%WWWDIR%%|${WWWDIR}|g' ${WRKSRC}/tools/awstats_buildstaticpages.pl
	@${REINPLACE_CMD} -e 's|%%WWWDIR%%|${WWWDIR}|g' ${WRKSRC}/tools/awstats_configure.pl
	@${REINPLACE_CMD} -e 's|%%WWWDIR%%|${WWWDIR}|g' ${WRKSRC}/tools/awstats_updateall.pl
	@${REINPLACE_CMD} -e 's|%%WWWDIR%%|${WWWDIR}|g' ${WRKSRC}/wwwroot/cgi-bin/awstats.pl
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '.cvsignore' -delete

do-install:
	-@${MKDIR} ${WWWDIR}
	@${MKDIR} ${WWWDIR}/tools
	@${MV} ${WRKSRC}/wwwroot/icon ${WRKSRC}/wwwroot/icons
	@cd ${WRKSRC}/wwwroot && ${COPYTREE_SHARE} \* ${WWWDIR}
	@cd ${WRKSRC}/tools && ${COPYTREE_SHARE}  \* ${WWWDIR}/tools
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} ""
	@${ECHO_CMD} "* Rename ${WWWDIR}/cgi-bin/awstats.model.conf to awstats.site.conf to setup awstats"
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

.include <bsd.port.post.mk>
