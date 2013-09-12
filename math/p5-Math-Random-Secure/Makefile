# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	Math-Random-Secure
PORTVERSION=	0.06
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dereckson@gmail.com
COMMENT=	Cryptographically-secure rand function

TEST_DEPENDS=	p5-Test-Warn>0:${PORTSDIR}/devel/p5-Test-Warn
BUILD_DEPENDS=	p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS=	p5-Any-Moose>0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Math-Random-ISAAC>=1.0.1:${PORTSDIR}/math/p5-Math-Random-ISAAC \
		p5-Crypt-Random-Source>=0.07:${PORTSDIR}/security/p5-Crypt-Random-Source

USES=		perl5
USE_PERL5=	configure

MAN3=		Math::Random::Secure.3 Math::Random::Secure::RNG.3

LICENSE=	ART20

.include <bsd.port.mk>
