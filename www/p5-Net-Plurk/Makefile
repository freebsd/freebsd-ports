# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Plurk
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to Plurk API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent-HTTP>=0:www/p5-AnyEvent-HTTP \
		p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-HTTP-Lite>=0:www/p5-HTTP-Lite \
		p5-JSON-Any>=0:converters/p5-JSON-Any \
		p5-Math-Base36>=0:math/p5-Math-Base36 \
		p5-Moose>=0:devel/p5-Moose \
		p5-Net-OAuth>=0.27:net/p5-Net-OAuth \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
		p5-URI>=0:net/p5-URI \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
