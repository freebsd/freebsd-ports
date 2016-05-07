# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	Math-Random-Secure
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dereckson@gmail.com
COMMENT=	Cryptographically-secure rand function

LICENSE=	ART20

TEST_DEPENDS=	p5-Test-Warn>0:devel/p5-Test-Warn
BUILD_DEPENDS=	p5-List-MoreUtils>0:lang/p5-List-MoreUtils
RUN_DEPENDS=	p5-Any-Moose>0:devel/p5-Any-Moose \
		p5-Math-Random-ISAAC>=1.0.1:math/p5-Math-Random-ISAAC \
		p5-Crypt-Random-Source>=0.07:security/p5-Crypt-Random-Source

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
