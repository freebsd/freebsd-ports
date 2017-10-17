# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	LWP-Protocol-https
PORTVERSION=	6.07
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide https support for LWP::UserAgent

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.54:security/p5-IO-Socket-SSL \
		p5-Mozilla-CA>=20110101:www/p5-Mozilla-CA \
		p5-Net-HTTP>=6:net/p5-Net-HTTP \
		p5-libwww>=6.06:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
