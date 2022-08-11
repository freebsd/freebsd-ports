PORTNAME=	News-Article-NoCeM
PORTVERSION=	0.09
CATEGORIES=	news perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module to generate accurate NoCeM notices

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-News-Article>=0:news/p5-News-Article \
		p5-PGP-Sign>=0:security/p5-PGP-Sign

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
