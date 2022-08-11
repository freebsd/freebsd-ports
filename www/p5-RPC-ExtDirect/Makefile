PORTNAME=	RPC-ExtDirect
PORTVERSION=	3.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for implementing the Ext.Direct remoting protocol

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Attribute-Handlers>=0.93:devel/p5-Attribute-Handlers \
		p5-JSON>=2.53:converters/p5-JSON
TEST_DEPENDS=	p5-Test-Pod>=1.46:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
