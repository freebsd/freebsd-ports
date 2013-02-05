# $FreeBSD$

PORTNAME=	Session-Storage-Secure
PORTVERSION=	0.005
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for encrypted, serialized session data with integrity

RUN_DEPENDS=	\
	p5-Crypt-CBC>0:${PORTSDIR}/security/p5-Crypt-CBC \
	p5-Crypt-Rijndael>0:${PORTSDIR}/security/p5-Crypt-Rijndael \
	p5-Crypt-URandom>0:${PORTSDIR}/security/p5-Crypt-URandom \
	p5-Math-Random-ISAAC-XS>0:${PORTSDIR}/math/p5-Math-Random-ISAAC-XS \
	p5-Moo>0:${PORTSDIR}/devel/p5-Moo \
	p5-MooX-Types-MooseLike>0:${PORTSDIR}/devel/p5-MooX-Types-MooseLike \
	p5-Sereal-Decoder>0:${PORTSDIR}/converters/p5-Sereal-Decoder \
	p5-Sereal-Encoder>0:${PORTSDIR}/converters/p5-Sereal-Encoder \
	p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep \
	p5-Test-Fatal>0:${PORTSDIR}/devel/p5-Test-Fatal \
	p5-Number-Tolerant>0:${PORTSDIR}/devel/p5-Number-Tolerant

PERL_CONFIGURE=	yes

MAN3=	Session::Storage::Secure.3

.include <bsd.port.mk>
