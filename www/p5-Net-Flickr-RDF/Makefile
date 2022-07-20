PORTNAME=	Net-Flickr-RDF
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Describe Flickr photos as RDF

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-Flickr-API>=1.7:www/p5-Net-Flickr-API \
		p5-RDF-Simple>=0.220:textproc/p5-RDF-Simple \
		p5-TimeDate>=1.16:devel/p5-TimeDate

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
