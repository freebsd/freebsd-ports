# $FreeBSD$

PORTNAME=	Lingua-EN-Number-IsOrdinal
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to detect if English number is ordinal or cardinal

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Lingua-EN-FindNumber>0:textproc/p5-Lingua-EN-FindNumber
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Fatal>0:devel/p5-Test-Fatal \
	p5-Try-Tiny:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
