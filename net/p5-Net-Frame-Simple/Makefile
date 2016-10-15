# $FreeBSD$

PORTNAME=	Net-Frame-Simple
PORTVERSION=	1.07
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base framework for frame crafting

LICENSE=	ART10

BUILD_DEPENDS=	p5-Net-Frame>=1.16:net/p5-Net-Frame \
		p5-Class-Gomor>=1.03:devel/p5-Class-Gomor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
