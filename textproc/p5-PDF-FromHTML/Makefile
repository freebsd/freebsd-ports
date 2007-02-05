# New ports collection makefile for:	p5-PDF-FromHTML
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	PDF-FromHTML
PORTVERSION=	0.23
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PDF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert HTML documents to PDF

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Tidy.pm:${PORTSDIR}/textproc/p5-HTML-Tidy \
		${SITE_PERL}/Graphics/ColorNames.pm:${PORTSDIR}/graphics/p5-Graphics-ColorNames \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/PDF/API2.pm:${PORTSDIR}/textproc/p5-PDF-API2 \
		${SITE_PERL}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-PDF-Writer>=0.05:${PORTSDIR}/textproc/p5-PDF-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
