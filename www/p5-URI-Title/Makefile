# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	URI-Title
PORTVERSION=	1.902
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Get the titles of things on the web in a sensible way

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Type>=0.22:devel/p5-File-Type \
		p5-HTML-Parser>=3.45:www/p5-HTML-Parser \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-MP3-Info>=0:audio/p5-MP3-Info \
		p5-Module-Pluggable>=1.2:devel/p5-Module-Pluggable \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
