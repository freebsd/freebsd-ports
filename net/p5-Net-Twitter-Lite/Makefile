# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Twitter-Lite
PORTVERSION=	0.12008
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Interface to the Twitter API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Message>0:www/p5-HTTP-Message \
		p5-JSON>=2.02:converters/p5-JSON \
		p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https \
		p5-URI>=1.4:net/p5-URI \
		p5-libwww>0:www/p5-libwww \
		p5-Net-HTTP>=6.06:net/p5-Net-HTTP \
		p5-Net-OAuth>=0.25:net/p5-Net-OAuth
RUN_DEPENDS=	p5-HTTP-Message>0:www/p5-HTTP-Message \
		p5-JSON>=2.02:converters/p5-JSON \
		p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https \
		p5-URI>=1.4:net/p5-URI \
		p5-libwww>0:www/p5-libwww \
		p5-Net-HTTP>=6.06:net/p5-Net-HTTP \
		p5-Net-OAuth>=0.25:net/p5-Net-OAuth
TEST_DEPENDS=	p5-Test-Fatal>0:devel/p5-Test-Fatal

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
