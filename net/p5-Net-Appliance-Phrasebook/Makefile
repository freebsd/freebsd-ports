PORTNAME=	Net-Appliance-Phrasebook
PORTVERSION=	2.103642
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Network appliance command-line phrasebook

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-Data-Phrasebook>=0:textproc/p5-Data-Phrasebook \
		p5-Data-Phrasebook-Loader-YAML>=0:textproc/p5-Data-Phrasebook-Loader-YAML \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
