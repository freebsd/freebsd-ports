PORTNAME=	WWW-Shorten-Bitly
PORTVERSION=	2.001
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Abstract interface to bit.ly, one of URL shortening sites

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-HomeDir>=1.00:devel/p5-File-HomeDir \
		p5-JSON-MaybeXS>0:converters/p5-JSON-MaybeXS \
		p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https \
		p5-Path-Tiny>0:devel/p5-Path-Tiny \
		p5-URI>=1.58:net/p5-URI \
		p5-WWW-Shorten>=3.09:www/p5-WWW-Shorten

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
