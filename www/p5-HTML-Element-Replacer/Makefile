# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-Element-Replacer
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl HTML::Element replacer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Element-Library>=0:www/p5-HTML-Element-Library \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-Moose>=0:devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-HTML-PrettyPrinter>=0:www/p5-HTML-PrettyPrinter

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
