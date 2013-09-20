# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	Math-SigFigs
PORTVERSION=	1.09
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Do math with correct handling of significant figures

BUILD_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

MAN3=	Math::SigFigs.3

NO_STAGE=	yes
.include <bsd.port.mk>
