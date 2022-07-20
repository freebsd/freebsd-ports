PORTNAME=	Net-LimeLight-Purge
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LimeLight Purge Service API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime-Format-ISO8601>=0.06:devel/p5-DateTime-Format-ISO8601 \
		p5-Moose>=0.72:devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.14:devel/p5-MooseX-AttributeHelpers \
		p5-SOAP-Lite>=0.710.08:net/p5-SOAP-Lite

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
