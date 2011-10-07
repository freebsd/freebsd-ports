# New ports collection makefile for:	textproc/p5-Text-Xslate
# Date created:				10 June 2010
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Xslate
PORTVERSION=	1.5002
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	High performance template engine

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

COMMON_DEPENDS=	p5-parent>=0.221:${PORTSDIR}/devel/p5-parent \
		p5-Mouse>=0.61:${PORTSDIR}/devel/p5-Mouse \
		p5-Any-Moose>=0.13:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Data-MessagePack>=0.30:${PORTSDIR}/devel/p5-Data-MessagePack
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

MAKE_JOBS_UNSAFE=	yes

PERL_CONFIGURE=	yes

MAN1=	xslate.1
MAN3=	Text::Xslate.3 \
	Text::Xslate::Bridge.3 \
	Text::Xslate::Compiler.3 \
	Text::Xslate::HashWithDefault.3 \
	Text::Xslate::Manual.3 \
	Text::Xslate::Manual::Builtin.3 \
	Text::Xslate::Manual::Cookbook.3 \
	Text::Xslate::Manual::Debugging.3 \
	Text::Xslate::Manual::FAQ.3 \
	Text::Xslate::PP.3 \
	Text::Xslate::PP::Const.3 \
	Text::Xslate::PP::Method.3 \
	Text::Xslate::PP::Opcode.3 \
	Text::Xslate::PP::State.3 \
	Text::Xslate::PP::Type::Macro.3 \
	Text::Xslate::PP::Type::Pair.3 \
	Text::Xslate::PP::Type::Raw.3 \
	Text::Xslate::Parser.3 \
	Text::Xslate::Runner.3 \
	Text::Xslate::Symbol.3 \
	Text::Xslate::Syntax::Kolon.3 \
	Text::Xslate::Syntax::Metakolon.3 \
	Text::Xslate::Syntax::TTerse.3 \
	Text::Xslate::Type::Raw.3 \
	Text::Xslate::Util.3

.include <bsd.port.mk>
