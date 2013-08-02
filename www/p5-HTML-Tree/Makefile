# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	HTML-Tree
PORTVERSION=	5.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Collection of modules to manipulate HTML syntax trees

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-HTML-Parser>=3.46:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Tagset>=3.02:${PORTSDIR}/www/p5-HTML-Tagset
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	modbuild

MAN3=		HTML::Parse.3 HTML::TreeBuilder.3 HTML::AsSubs.3 \
		HTML::Element.3 HTML::Element::traverse.3 HTML::Tree.3 \
		HTML::Tree::Scanning.3 HTML::Tree::AboutObjects.3 \
		HTML::Tree::AboutTrees.3

.include <bsd.port.mk>
