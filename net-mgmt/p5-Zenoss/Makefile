# Created by: Phil Phillips
# $FreeBSD$

PORTNAME=	Zenoss
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pphillips@experts-exchange.com
COMMENT=	Perl interface to the Zenoss JSON API

BUILD_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-JSON>=2.0:converters/p5-JSON \
		p5-Moose>=1.0:devel/p5-Moose \
		p5-libwww>=5.0:www/p5-libwww
RUN_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-JSON>=2.0:converters/p5-JSON \
		p5-Moose>=1.0:devel/p5-Moose \
		p5-libwww>=5.0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
