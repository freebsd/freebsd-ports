# Created by: Yuichiro AIZAWA <yaizawa@mdbl.sfc.keio.ac.jp>
# $FreeBSD$

PORTNAME=	PDF-Template
PORTVERSION=	0.22
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	yaizawa@2004.jukuin.keio.ac.jp
COMMENT=	PDF layout system that uses the same data structures as HTML::Template

BUILD_DEPENDS+=	pdflib-perl>=0:${PORTSDIR}/print/pdflib-perl \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		PDF::Template::Element::Weblink.3 \
		PDF::Template::Container::Scope.3 \
		PDF::Template::Container::Margin.3 \
		PDF::Template::Container::Font.3 \
		PDF::Template::Element::Bookmark.3 \
		PDF::Template::Element::TextBox.3 \
		PDF::Template::Element::Var.3 \
		PDF::Template::Container::Header.3 \
		PDF::Template::Container::PdfTemplate.3 \
		PDF::Template::Container::Loop.3 \
		PDF::Template::Container::Conditional.3 \
		PDF::Template::Container::Always.3 \
		PDF::Template::Element::HorizontalRule.3 \
		PDF::Template::Container::Section.3 \
		PDF::Template::Element::Image.3 \
		PDF::Template::Element::Circle.3 \
		PDF::Template::Element::PageBreak.3 \
		PDF::Template::Container::PageDef.3 \
		PDF::Template::Container::Row.3 \
		PDF::Template::Container::Footer.3 \
		PDF::Template::Element.3 \
		PDF::Template.3 \
		PDF::Template::Element::Line.3

NO_STAGE=	yes
.include <bsd.port.mk>
