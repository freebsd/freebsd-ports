PORTNAME=	HTTP-Link-Parser
PORTVERSION=	0.200
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse HTTP Link headers

LICENSE=	MIT

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-URI>=1.30:net/p5-URI \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-RDF-Trine>=0:textproc/p5-RDF-Trine

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
