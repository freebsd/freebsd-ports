# New ports collection makefile for:	p5-HTML-Tree
# Date created:			3 January 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	HTML-Tree
PORTVERSION=	3.18
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A collection of modules to manupulate HTML syntax trees

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		HTML::Parse.3 HTML::TreeBuilder.3 HTML::AsSubs.3 \
		HTML::Element.3 HTML::Element::traverse.3 HTML::Tree.3 \
		HTML::Tree::Scanning.3 HTML::Tree::AboutObjects.3 \
		HTML::Tree::AboutTrees.3

.include <bsd.port.mk>
