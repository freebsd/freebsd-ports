# $FreeBSD$

PORTNAME=	Session-Storage-Secure
PORTVERSION=	0.010
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for encrypted, serialized session data with integrity

LICENSE=	APACHE20

RUN_DEPENDS=	\
	p5-Crypt-CBC>0:security/p5-Crypt-CBC \
	p5-Crypt-Rijndael>0:security/p5-Crypt-Rijndael \
	p5-Crypt-URandom>0:security/p5-Crypt-URandom \
	p5-Math-Random-ISAAC-XS>0:math/p5-Math-Random-ISAAC-XS \
	p5-Moo>0:devel/p5-Moo \
	p5-MooX-Types-MooseLike>=0.16:devel/p5-MooX-Types-MooseLike \
	p5-Sereal-Decoder>0:converters/p5-Sereal-Decoder \
	p5-Sereal-Encoder>0:converters/p5-Sereal-Encoder \
	p5-String-Compare-ConstantTime>0:textproc/p5-String-Compare-ConstantTime \
	p5-namespace-clean>0:devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Deep>0:devel/p5-Test-Deep \
	p5-Test-Fatal>0:devel/p5-Test-Fatal \
	p5-Number-Tolerant>0:devel/p5-Number-Tolerant

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
