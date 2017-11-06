# $FreeBSD$

PORTNAME=	Apache-LogFormat-Compiler
PORTVERSION=	0.35
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to compile a log format string to perl-code

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-POSIX-strftime-Compiler>=0.30:devel/p5-POSIX-strftime-Compiler

TEST_DEPENDS=	\
	p5-HTTP-Message>=0:www/p5-HTTP-Message \
	p5-Test-MockTime>=0:devel/p5-Test-MockTime \
	p5-Try-Tiny>=0.12:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	YES

.include <bsd.port.mk>
