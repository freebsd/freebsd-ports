PORTNAME=	Dancer-Plugin-RPC
PORTVERSION=	1.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ABELTJE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Configure endpoints for XMLRPC and JSONRPC procedures

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Dancer>=1.3100:www/p5-Dancer \
		p5-JSON>=2.0:converters/p5-JSON \
		p5-Params-Validate>=1.08:devel/p5-Params-Validate \
		p5-Params-ValidationCompiler>=0.24:devel/p5-Params-ValidationCompiler \
		p5-RPC-XML>=0.56:net/p5-RPC-XML \
		p5-Type-Tiny>=1:devel/p5-Type-Tiny \
		p5-YAML>=1.21:textproc/p5-YAML
TEST_DEPENDS=	p5-Moo>=2:devel/p5-Moo \
		p5-Test-Fatal>=0.010:devel/p5-Test-Fatal \
		p5-Test-Warnings>=0.030:devel/p5-Test-Warnings \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

.include <bsd.port.mk>
