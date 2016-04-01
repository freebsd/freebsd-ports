# $FreeBSD$

PORTNAME=	Net-Amazon-Signature-V3
PORTVERSION=	0.001
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to sign AWS requests V3

LICENSE=	LGPL21

RUN_DEPENDS=	\
	p5-Digest-HMAC>0:security/p5-Digest-HMAC \
	p5-HTTP-Date>0:www/p5-HTTP-Date \
	p5-Moose>0:devel/p5-Moose \
	p5-MooseX-Types-Common>=0:devel/p5-MooseX-Types-Common \
	p5-namespace-autoclean>0:devel/p5-namespace-autoclean
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
