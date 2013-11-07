# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	PDF-FromHTML
PORTVERSION=	0.31
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert HTML documents to PDF

BUILD_DEPENDS=	p5-HTML-Tidy>=0:${PORTSDIR}/textproc/p5-HTML-Tidy \
		p5-Graphics-ColorNames>=0:${PORTSDIR}/graphics/p5-Graphics-ColorNames \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-PDF-API2>=0:${PORTSDIR}/textproc/p5-PDF-API2 \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-PDF-Writer>=0.05:${PORTSDIR}/textproc/p5-PDF-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
