# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Number-WithError-LaTeX
PORTVERSION=	0.06
PORTREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	LaTeX output for Number::WithError

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Params-Util>=0:devel/p5-Params-Util \
		p5-prefork>=0:devel/p5-prefork \
		p5-Number-WithError>=0:math/p5-Number-WithError \
		p5-TeX-Encode>=0:textproc/p5-TeX-Encode
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-LectroTest>=0:devel/p5-Test-LectroTest

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
