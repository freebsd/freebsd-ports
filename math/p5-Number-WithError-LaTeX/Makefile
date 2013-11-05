# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Number-WithError-LaTeX
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX output for Number::WithError

BUILD_DEPENDS=	p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-prefork>=0:${PORTSDIR}/devel/p5-prefork \
		p5-Number-WithError>=0:${PORTSDIR}/math/p5-Number-WithError \
		p5-TeX-Encode>=0:${PORTSDIR}/textproc/p5-TeX-Encode
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-LectroTest>=0:${PORTSDIR}/devel/p5-Test-LectroTest

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
