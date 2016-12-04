# Created by: clsung
# $FreeBSD$

PORTNAME=	Net-Twitter
PORTVERSION=	4.01041
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to twitter.com

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Carp-Clan>=0:devel/p5-Carp-Clan \
		p5-Class-Load>=0:devel/p5-Class-Load \
		p5-Data-Visitor>=0:devel/p5-Data-Visitor \
		p5-DateTime>=0.51:devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=1.09:devel/p5-DateTime-Format-Strptime \
		p5-Devel-StackTrace>=1.21:devel/p5-Devel-StackTrace \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Moose>=0.90:devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=0:devel/p5-MooseX-Role-Parameterized \
		p5-Net-OAuth>=0:net/p5-Net-OAuth \
		p5-Try-Tiny>=0.03:lang/p5-Try-Tiny \
		p5-URI>=1.40:net/p5-URI \
		p5-libwww>=2.032:www/p5-libwww \
		p5-namespace-autoclean>=0.09:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Warn>=0:devel/p5-Test-Warn

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
