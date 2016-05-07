# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-OpenID-JanRain
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OpenID JanRain and Consumer with JanRain API

BUILD_DEPENDS=	p5-Crypt-DH>=0:security/p5-Crypt-DH \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-LWPx-ParanoidAgent>=0:www/p5-LWPx-ParanoidAgent \
		p5-Net-Yadis>=0:net/p5-Net-Yadis \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
