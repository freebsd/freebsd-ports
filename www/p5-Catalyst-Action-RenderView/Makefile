PORTNAME=	Catalyst-Action-RenderView
PORTVERSION=	0.17
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sensible default end action for Catalyst
WWW=		https://metacpan.org/release/Catalyst-Action-RenderView

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.80030:www/p5-Catalyst-Runtime \
		p5-Data-Visitor>=0.24:devel/p5-Data-Visitor \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
