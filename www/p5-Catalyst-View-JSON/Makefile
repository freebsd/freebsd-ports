# $FreeBSD$

PORTNAME=	Catalyst-View-JSON
PORTVERSION=	0.36
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Catalyst View handler that returns stash data in JSON format

LICENSE=	ART10

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.6000:www/p5-Catalyst-Runtime \
		p5-JSON-Any>=1.15:converters/p5-JSON-Any \
		p5-MRO-Compat>0:devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
