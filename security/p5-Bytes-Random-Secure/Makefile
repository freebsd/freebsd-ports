PORTNAME=	Bytes-Random-Secure
PORTVERSION=	0.29
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate cryptographically-secure random bytes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-Random-Seed>=0:security/p5-Crypt-Random-Seed \
		p5-Math-Random-ISAAC>=0:math/p5-Math-Random-ISAAC

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
