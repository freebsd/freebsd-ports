# $FreeBSD$

PORTNAME=	Lingua-EN-Number-IsOrdinal
PORTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to detect if English number is ordinal or cardinal

RUN_DEPENDS=	\
	p5-Lingua-EN-FindNumber>0:${PORTSDIR}/textproc/p5-Lingua-EN-FindNumber
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Fatal>0:${PORTSDIR}/devel/p5-Test-Fatal \
	p5-Try-Tiny:${PORTSDIR}/lang/p5-Try-Tiny

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::Number::IsOrdinal.3

.include <bsd.port.mk>
