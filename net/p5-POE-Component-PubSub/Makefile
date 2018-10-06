# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-PubSub
PORTVERSION=	0.091370
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NPEREZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic publish/subscribe POE::Component

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=0.79:devel/p5-Moose \
		p5-MooseX-Declare>=0.22:devel/p5-MooseX-Declare \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-MooseX-Types-Set-Object>=0.02:devel/p5-MooseX-Types-Set-Object \
		p5-MooseX-Types-Structured>=0.14:devel/p5-MooseX-Types-Structured \
		p5-POE>=1.005:devel/p5-POE \
		p5-POE-API-Peek>=2.15:devel/p5-POE-API-Peek \
		p5-POEx-Role-SessionInstantiation>=0.01:devel/p5-POEx-Role-SessionInstantiation \
		p5-signatures>=0.05:lang/p5-signatures

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
