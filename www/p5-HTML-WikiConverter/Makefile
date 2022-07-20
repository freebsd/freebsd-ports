PORTNAME=	HTML-WikiConverter
PORTVERSION=	0.68
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML to wiki markup converter

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE # GPLv2 actually

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Data-Inheritable>=0.02:devel/p5-Class-Data-Inheritable \
		p5-Params-Validate>=0.77:devel/p5-Params-Validate \
		p5-CSS>=0:textproc/p5-CSS \
		p5-HTML-Parser>=3.34:www/p5-HTML-Parser \
		p5-HTML-Tagset>=3.04:www/p5-HTML-Tagset \
		p5-HTML-Tree>=3.18:www/p5-HTML-Tree \
		p5-URI>=1.35:net/p5-URI

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
