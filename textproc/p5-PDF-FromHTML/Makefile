# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	PDF-FromHTML
PORTVERSION=	0.33
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert HTML documents to PDF

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Graphics-ColorNames>=0:graphics/p5-Graphics-ColorNames \
		p5-HTML-Tidy>=0:textproc/p5-HTML-Tidy \
		p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-PDF-API2>=0:textproc/p5-PDF-API2 \
		p5-PDF-Writer>=0.05:textproc/p5-PDF-Writer \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
