# New ports collection makefile for:	p5-Kwiki-plugins
# Date created:				Aug 18 2004
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-plugins
PORTVERSION=	1.0
CATEGORIES=	www perl5
MASTER_SITES=	# empty
PKGNAMEPREFIX=	p5-
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	"meta-port" for Kwiki Plugins

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	ARCHIVERCS		"Page Archival Using RCS" on \
		ARCHIVESVK		"Page Archival Using SVK" off \
		ATOM			"Atom Plugin" off \
		GDGRAPHGENERATOR	"GD Graph Generator" off \
		NEWPAGE			"New Page Plugin" on \
		REVISIONS		"Revisions Plugin" on \
		RECENTCHANGES		"Recent Changes Plugin" on \
		RECENTCHANGESRSS	"RSS Plugin" on \
		SEARCH			"Search Plugin" on \
		USERNAME		"User Name Plugin" on \
		USERPREFERENCES		"User Preferences Plugin" on

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_ARCHIVERCS)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/Archive/Rcs.pm:${PORTSDIR}/www/p5-Kwiki-Archive-Rcs
.endif

.if defined(WITH_ARCHIVESVK)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/Archive/SVK.pm:${PORTSDIR}/www/p5-Kwiki-Archive-SVK
.endif

.if defined(WITH_ATOM)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/Atom.pm:${PORTSDIR}/www/p5-Kwiki-Atom
.endif

.if defined(WITH_GDGRAPHGENERATOR)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/GDGraphGenerator.pm:${PORTSDIR}/www/p5-Kwiki-GDGraphGenerator
.endif

.if defined(WITH_NEWPAGE)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/NewPage.pm:${PORTSDIR}/www/p5-Kwiki-NewPage
.endif

.if defined(WITH_REVISIONS)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/Revisions.pm:${PORTSDIR}/www/p5-Kwiki-Revisions
.endif

.if defined(WITH_RECENTCHANGES)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/RecentChanges.pm:${PORTSDIR}/www/p5-Kwiki-RecentChanges
.endif

.if defined(WITH_RECENTCHANGESRSS)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/RecentChangesRSS.pm:${PORTSDIR}/www/p5-Kwiki-RecentChangesRSS
.endif

.if defined(WITH_SEARCH)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/Search.pm:${PORTSDIR}/www/p5-Kwiki-Search
.endif

.if defined(WITH_USERNAME)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/UserName.pm:${PORTSDIR}/www/p5-Kwiki-UserName
.endif

.if defined(WITH_USERPREFERENCES)
RUN_DEPENDS+=	${SITE_PERL}/Kwiki/UserPreferences.pm:${PORTSDIR}/www/p5-Kwiki-UserPreferences
.endif

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

do-build:
	        @${DO_NADA}

do-install:
	        @${DO_NADA}

.include <bsd.port.post.mk>
