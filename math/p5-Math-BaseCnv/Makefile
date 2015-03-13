# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Math-BaseCnv
PORTVERSION=	1.4.75
PORTREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}O6Pbr

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fast functions to convert between number Bases

BUILD_DEPENDS=	p5-Memoize>=0:${PORTSDIR}/devel/p5-Memoize
RUN_DEPENDS=	p5-Memoize>=0:${PORTSDIR}/devel/p5-Memoize
TEST_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
