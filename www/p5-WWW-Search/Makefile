# New ports collection makefile for:    p5-WWW-Search
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search
PORTVERSION=	2.46
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl5 module for WWW searches

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/Test/Inline.pm:${PORTSDIR}/devel/p5-Test-Inline \
		${SITE_PERL}/User.pm:${PORTSDIR}/sysutils/p5-User \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		AutoSearch.1 \
		WebSearch.1
MAN3=		WWW::Search.3 \
		WWW::SearchResult.3 \
		WWW::Search::Null.3 \
		WWW::Search::Null::Count.3 \
		WWW::Search::Null::Empty.3 \
		WWW::Search::Null::Error.3 \
		WWW::Search::Simple.3 \
		WWW::Search::Test.3

post-patch:
	@${RM} ${WRKSRC}/lib/WWW/Search/Test.pm.orig

.include <bsd.port.mk>
