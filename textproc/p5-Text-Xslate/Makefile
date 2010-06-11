# New ports collection makefile for:	textproc/p5-Text-Xslate
# Date created:				10 June 2010
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Xslate
PORTVERSION=	0.1032
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	High performance template engine

BUILD_DEPENDS=	p5-parent>=0.221:${PORTSDIR}/devel/p5-parent \
		p5-Mouse>=0.55:${PORTSDIR}/devel/p5-Mouse \
		p5-Any-Moose>=0.13:${PORTSDIR}/devel/p5-Any-Moose \
		p5-MouseX-Getopt>=0.2601:${PORTSDIR}/devel/p5-MouseX-Getopt
RUN_DEPENDS=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN1=	xslate.1
MAN3=	Text::Xslate.3 \
	Text::Xslate::Bridge.3 \
	Text::Xslate::Compiler.3 \
	Text::Xslate::EscapedString.3 \
	Text::Xslate::PP.3 \
	Text::Xslate::PP::Booster.3 \
	Text::Xslate::PP::Const.3 \
	Text::Xslate::PP::Macro.3 \
	Text::Xslate::PP::Method.3 \
	Text::Xslate::PP::Opcode.3 \
	Text::Xslate::PP::State.3 \
	Text::Xslate::PP::Type::Array.3 \
	Text::Xslate::PP::Type::EscapedString.3 \
	Text::Xslate::PP::Type::Hash.3 \
	Text::Xslate::PP::Type::Pair.3 \
	Text::Xslate::PP::Type::Raw.3 \
	Text::Xslate::Parser.3 \
	Text::Xslate::Symbol.3 \
	Text::Xslate::Syntax::Kolon.3 \
	Text::Xslate::Syntax::Metakolon.3 \
	Text::Xslate::Syntax::TTerse.3 \
	Text::Xslate::Type::Raw.3 \
	Text::Xslate::Util.3

.include <bsd.port.mk>
