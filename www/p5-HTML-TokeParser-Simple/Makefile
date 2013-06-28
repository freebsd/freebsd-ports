# Created by: Lars Eggert <lars.eggert@gmx.net>
# $FreeBSD$

PORTNAME=	HTML-TokeParser-Simple
PORTVERSION=	3.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Subclass of HTML::TokeParser with easy-to-remember method calls

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Sub-Override>=0:${PORTSDIR}/devel/p5-Sub-Override
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::TokeParser::Simple.3 HTML::TokeParser::Simple::Token.3 \
		HTML::TokeParser::Simple::Token::Comment.3 \
		HTML::TokeParser::Simple::Token::Declaration.3 \
		HTML::TokeParser::Simple::Token::ProcessInstruction.3 \
		HTML::TokeParser::Simple::Token::Tag.3 \
		HTML::TokeParser::Simple::Token::Tag::End.3 \
		HTML::TokeParser::Simple::Token::Tag::Start.3 \
		HTML::TokeParser::Simple::Token::Text.3

.include <bsd.port.mk>
