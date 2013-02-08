# $FreeBSD$

PORTNAME=	Text-Pipe
PORTVERSION=	0.10
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for common text filter API

RUN_DEPENDS=	\
	p5-Class-Accessor-Complex>0:${PORTSDIR}/devel/p5-Class-Accessor-Complex \
	p5-Class-Accessor-Constructor>0:${PORTSDIR}/devel/p5-Class-Accessor-Constructor \
	p5-Sub-Name>0:${PORTSDIR}/devel/p5-Sub-Name \
	p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
# Hack to avoid invoking CPAN.pm downloading...
CONFIGURE_ENV=	PERL5_CPANPLUS_IS_RUNNING=1

MAN3=	Text::Pipe.3 \
	Text::Pipe::Append.3 \
	Text::Pipe::Base.3 \
	Text::Pipe::Chomp.3 \
	Text::Pipe::Chop.3 \
	Text::Pipe::Code.3 \
	Text::Pipe::List::First.3 \
	Text::Pipe::List::Grep.3 \
	Text::Pipe::List::Map.3 \
	Text::Pipe::List::Max.3 \
	Text::Pipe::List::MaxStr.3 \
	Text::Pipe::List::Min.3 \
	Text::Pipe::List::MinStr.3 \
	Text::Pipe::List::Pop.3 \
	Text::Pipe::List::Reduce.3 \
	Text::Pipe::List::Shift.3 \
	Text::Pipe::List::Shuffle.3 \
	Text::Pipe::List::Size.3 \
	Text::Pipe::List::Sort.3 \
	Text::Pipe::List::Sum.3 \
	Text::Pipe::Lowercase.3 \
	Text::Pipe::LowercaseFirst.3 \
	Text::Pipe::Multiplex.3 \
	Text::Pipe::Prepend.3 \
	Text::Pipe::Print.3 \
	Text::Pipe::Repeat.3 \
	Text::Pipe::Reverse.3 \
	Text::Pipe::Say.3 \
	Text::Pipe::Split.3 \
	Text::Pipe::Stackable.3 \
	Text::Pipe::Tester.3 \
	Text::Pipe::Trim.3 \
	Text::Pipe::Uppercase.3 \
	Text::Pipe::UppercaseFirst.3

.include <bsd.port.mk>
