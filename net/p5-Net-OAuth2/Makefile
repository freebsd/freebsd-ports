# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-OAuth2
PORTVERSION=	0.66
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OAuth 2.0 for Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-Test-Mock-LWP-Dispatch>=0:devel/p5-Test-Mock-LWP-Dispatch \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings \
		p5-Test-Pod>=1.22:devel/p5-Test-Pod \
		p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
