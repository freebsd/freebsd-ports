# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Twitter-API
PORTVERSION=	1.0005
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Twitter REST API library for Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-Twitter>0:net/p5-Net-Twitter \
    		p5-Devel-StackTrace>=1.21:devel/p5-Devel-StackTrace \
		p5-Digest-HMAC>0:security/p5-Digest-HMAC \
		p5-HTTP-Thin>0:www/p5-HTTP-Thin \
		p5-IO-Socket-SSL>0:security/p5-IO-Socket-SSL \
		p5-JSON-MaybeXS>0:converters/p5-JSON-MaybeXS \
		p5-Moo>0:devel/p5-Moo \
		p5-MooX-Aliases>0:devel/p5-MooX-Aliases \
		p5-MooX-Traits>0:devel/p5-MooX-Traits \
		p5-Net-OAuth>0:net/p5-Net-OAuth \
		p5-Ref-Util>0:devel/p5-Ref-Util \
		p5-Throwable>0:devel/p5-Throwable \
		p5-Try-Tiny>0.03:lang/p5-Try-Tiny \
		p5-URI>=1.40:net/p5-URI \
		p5-URL-Encode>0:www/p5-URL-Encode \
		p5-WWW-OAuth>0:www/p5-WWW-OAuth \
		p5-libwww>=2.032:www/p5-libwww \
		p5-namespace-clean>0:devel/p5-namespace-clean

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
