# Created by: Andrey Kostenko <andrey@kostenko.name>
# $FreeBSD$

PORTNAME=	Pod-Eventual
PORTVERSION=	0.094001
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read a POD document as a series of trivial events

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mixin-Linewise>=0.102:devel/p5-Mixin-Linewise
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
