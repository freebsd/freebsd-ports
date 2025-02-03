PORTNAME=	Algorithm-CurveFit
PORTVERSION=	1.06
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Nonlinear Least Squares Fitting
WWW=		https://metacpan.org/release/Algorithm-CurveFit

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Math-MatrixReal>=0:math/p5-Math-MatrixReal \
		p5-Math-Symbolic>=0:math/p5-Math-Symbolic

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
