# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Number-WithError
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Numbers with error propagation and scientific rounding

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Params-Util>=0:devel/p5-Params-Util \
		p5-prefork>=0:devel/p5-prefork
TEST_DEPENDS=	p5-Test-LectroTest>=0:devel/p5-Test-LectroTest

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
