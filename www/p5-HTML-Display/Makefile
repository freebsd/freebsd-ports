PORTNAME=	HTML-Display
PORTVERSION=	0.40
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Display HTML locally in a browser

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-TokeParser-Simple>=2:www/p5-HTML-TokeParser-Simple \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=5.69:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
