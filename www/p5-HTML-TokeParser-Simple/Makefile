# New ports collection makefile for:	HTML-TokeParser-Simple
# Date created:			18 April 2004
# Whom:				Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-TokeParser-Simple
PORTVERSION=	3.13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Subclass of HTML::TokeParser with easy-to-remember method calls

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Sub/Override.pm:${PORTSDIR}/devel/p5-Sub-Override
RUN_DEPENDS=	${BUILD_DEPENDS}

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
