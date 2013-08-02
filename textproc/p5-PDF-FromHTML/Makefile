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

MAN1=		html2pdf.pl.1
MAN3=		PDF::FromHTML.3 PDF::FromHTML::Twig.3 \
		PDF::FromHTML::Template.3 \
		PDF::FromHTML::Template::Container::Always.3 \
		PDF::FromHTML::Template::Container::Conditional.3 \
		PDF::FromHTML::Template::Container::Font.3 \
		PDF::FromHTML::Template::Container::Footer.3 \
		PDF::FromHTML::Template::Container::Header.3 \
		PDF::FromHTML::Template::Container::Loop.3 \
		PDF::FromHTML::Template::Container::Margin.3 \
		PDF::FromHTML::Template::Container::PageDef.3 \
		PDF::FromHTML::Template::Container::PdfTemplate.3 \
		PDF::FromHTML::Template::Container::Row.3 \
		PDF::FromHTML::Template::Container::Scope.3 \
		PDF::FromHTML::Template::Container::Section.3 \
		PDF::FromHTML::Template::Element.3 \
		PDF::FromHTML::Template::Element::Bookmark.3 \
		PDF::FromHTML::Template::Element::Circle.3 \
		PDF::FromHTML::Template::Element::HorizontalRule.3 \
		PDF::FromHTML::Template::Element::Image.3 \
		PDF::FromHTML::Template::Element::Line.3 \
		PDF::FromHTML::Template::Element::PageBreak.3 \
		PDF::FromHTML::Template::Element::TextBox.3 \
		PDF::FromHTML::Template::Element::Var.3 \
		PDF::FromHTML::Template::Element::Weblink.3

.include <bsd.port.mk>
