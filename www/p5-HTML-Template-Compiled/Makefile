# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	HTML-Template-Compiled
PORTVERSION=	1.001
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Templating system that compiles HTML::Template files to Perl code

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::Template::Compiled.3 \
		HTML::Template::Compiled::Classic.3 \
		HTML::Template::Compiled::Compiler.3 \
		HTML::Template::Compiled::Compiler::Classic.3 \
		HTML::Template::Compiled::Exception.3 \
		HTML::Template::Compiled::Expr.3 \
		HTML::Template::Compiled::Expression.3 \
		HTML::Template::Compiled::Filter.3 \
		HTML::Template::Compiled::Formatter.3 \
		HTML::Template::Compiled::Lazy.3 \
		HTML::Template::Compiled::Parser.3 \
		HTML::Template::Compiled::Plugin::XMLEscape.3 \
		HTML::Template::Compiled::Reference.3 \
		HTML::Template::Compiled::Token.3 \
		HTML::Template::Compiled::Utils.3

.include <bsd.port.mk>
