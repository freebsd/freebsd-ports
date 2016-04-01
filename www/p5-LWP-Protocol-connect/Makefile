# Created by: Lawrence Chen <beastie@tardisi.com>
# $FreeBSD$

PORTNAME=	LWP-Protocol-connect
PORTVERSION=	6.09
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	beastie@tardisi.com
COMMENT=	Provides HTTP/CONNECT proxy support for LWP::UserAgent

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-libwww>=0:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-URI>=0:net/p5-URI \
		p5-Net-HTTP>=6:net/p5-Net-HTTP
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
