PORTNAME=	PDL-DateTime
PORTVERSION=	0.004
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Piddle for keeping high precision (microsecond) timestamps
WWW=		https://metacpan.org/dist/PDL-DateTime

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PDL>=2.014:math/p5-PDL \
		p5-Time-Moment>=0.12:devel/p5-Time-Moment
TEST_DEPENDS=	p5-Test-Number-Delta>=1.06:devel/p5-Test-Number-Delta

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
