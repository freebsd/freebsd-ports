# New ports collection makefile for:    p5-WWW-Search
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search
PORTVERSION=	2.37
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/Inline.pm:${PORTSDIR}/devel/p5-Test-Inline \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/User.pm:${PORTSDIR}/sysutils/p5-User \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		AutoSearch.1 \
		WebSearch.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		WWW::Search.3 \
		WWW::SearchResult.3 \
		WWW::Search::Null.3 \
		WWW::Search::Null::Count.3 \
		WWW::Search::Null::Empty.3 \
		WWW::Search::Null::Error.3 \
		WWW::Search::Simple.3 \
		WWW::Search::Test.3

.include <bsd.port.pre.mk>

SITE_PERL?=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

PERL_MAJOR=${PERL_VER:C|^([1-9]+).*|\1|}
PERL_MINOR=${PERL_VER:C|^[1-9]+\.0*([1-9]+).*|\1|}

.if ${PERL_MAJOR} < 5 || ${PERL_MAJOR} == 5 && ${PERL_MINOR} < 8
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif # ${PERL_MAJOR} < 5 || ${PERL_MAJOR} == 5 && ${PERL_MINOR} < 8

.include <bsd.port.post.mk>
