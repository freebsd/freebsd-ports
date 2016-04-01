# Created by: skreuzer
# $FreeBSD$

PORTNAME=	Net-OAuth-Simple
PORTVERSION=	1.7
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Simple wrapper around the OAuth protocol

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0.57:security/p5-Crypt-SSLeay \
		p5-libwww>=5.825:www/p5-libwww \
		p5-Net-OAuth>=0.27:net/p5-Net-OAuth \
		p5-URI>=1.37:net/p5-URI \
		p5-Test-Simple>=0.86:devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
