# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-OpenID-Common
PORTVERSION=	1.20
CATEGORIES=	security net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Libraries shared between Net::OpenID::Consumer and Net::OpenID::Server

LICENSE=	ARTPERL10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-DH-GMP>=0:net/p5-Crypt-DH-GMP \
		p5-Email-MIME-ContentType>=0:mail/p5-Email-MIME-ContentType \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-URI>=0:net/p5-URI \
		p5-XML-Simple>=0:textproc/p5-XML-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
