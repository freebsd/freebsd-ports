# New ports collection makefile for:	p5-HTML-Summary
# Date created:			3 January 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	HTML-Summary
PORTVERSION=	0.017
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		HTML::Summary.3 Text::Sentence.3 Lingua::JA::Jtruncate.3

.include <bsd.port.mk>
