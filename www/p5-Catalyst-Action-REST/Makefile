# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Catalyst-Action-REST
PORTVERSION=	1.21
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automated REST Method Dispatching for Catalyst

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.80030:www/p5-Catalyst-Runtime \
		p5-Class-Inspector>=1.13:devel/p5-Class-Inspector \
		p5-MRO-Compat>=0.10:devel/p5-MRO-Compat \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Moose>=1.03:devel/p5-Moose \
		p5-Params-Validate>=0.76:devel/p5-Params-Validate \
		p5-URI-Find>=0:textproc/p5-URI-Find \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-libwww>=5:www/p5-libwww \
		p5-Test-Requires>=0:devel/p5-Test-Requires

NO_ARCH=	yes
CONFIGURE_ARGS=	--default
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
