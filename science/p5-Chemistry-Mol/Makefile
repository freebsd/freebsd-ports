# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	Chemistry-Mol
PORTVERSION=	0.39
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl toolkit to describe molecules

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-String>=0:devel/p5-IO-String \
		p5-Math-VectorReal>=1.0:math/p5-Math-VectorReal
TEST_DEPENDS=	p5-Clone>=0:devel/p5-Clone

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
