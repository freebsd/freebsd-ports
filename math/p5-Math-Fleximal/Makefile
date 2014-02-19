# Created by: Matthew Seaman <matthew@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Fleximal
PORTVERSION=	0.06
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Integers with flexible representations

NO_ARCH=	yes

USES=		perl5
USE_PERL5=	configure

regression-test: build
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
