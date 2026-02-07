PORTNAME=	HTML-RewriteAttributes
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple yet powerful HTML attribute rewriting
WWW=		https://metacpan.org/release/HTML-RewriteAttributes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Parser>0:www/p5-HTML-Parser \
		p5-HTML-Tagset>0:www/p5-HTML-Tagset \
		p5-URI>0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
