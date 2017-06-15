# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-PageCache
PORTVERSION=	0.32
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cache the output of entire pages

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:www/p5-Catalyst-Runtime \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-MRO-Compat>=0.10:devel/p5-MRO-Compat \
		p5-Catalyst-Plugin-Cache>=0.08:www/p5-Catalyst-Plugin-Cache
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Cache-Cache>=0:devel/p5-Cache-Cache \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
