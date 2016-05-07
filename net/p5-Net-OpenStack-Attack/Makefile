# $FreeBSD$

PORTNAME=	Net-OpenStack-Attack
PORTVERSION=	1.0500
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for stress testing an OpenStack deployment

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-App-Rad>=0:devel/p5-App-Rad \
		p5-HTTP-Async>=0:www/p5-HTTP-Async \
		p5-JSON>=0:converters/p5-JSON \
		p5-Net-HTTPS-NB>=0:net/p5-Net-HTTPS-NB \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
