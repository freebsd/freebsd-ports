# New ports collection makefile for:	p5-HTML-Tree
# Date created:			3 January 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	HTML-Tree
PORTVERSION=	3.19.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A collection of modules to manupulate HTML syntax trees

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::Parse.3 HTML::TreeBuilder.3 HTML::AsSubs.3 \
		HTML::Element.3 HTML::Element::traverse.3 HTML::Tree.3 \
		HTML::Tree::Scanning.3 HTML::Tree::AboutObjects.3 \
		HTML::Tree::AboutTrees.3

.include <bsd.port.pre.mk>

# p5-HTML-Tree -> p5-HTML-Parser
.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6 or above
.endif

.include <bsd.port.post.mk>
