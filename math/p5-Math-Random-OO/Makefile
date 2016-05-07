# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Math-Random-OO
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Consistent object-oriented interface for generating random numbers

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Params-Validate>=0.76:devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockRandom>=0.95:devel/p5-Test-MockRandom \
		p5-Test-Number-Delta>=0.14:devel/p5-Test-Number-Delta

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
