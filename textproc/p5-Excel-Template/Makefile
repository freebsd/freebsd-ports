# New ports collection makefile for:	Excel::Template
# Date created:				06 December 2005
# Whom:					Espen Tagestad <espen@tagestad.no>
#
# $FreeBSD$
#

PORTNAME=	Excel-Template
PORTVERSION=	0.28
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Excel
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Perl module for templating Excel files

BUILD_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Test-Exception>=0.21:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Spreadsheet/WriteExcel.pm:${PORTSDIR}/textproc/p5-Spreadsheet-WriteExcel
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Excel::Template.3 \
		Excel::Template::Base.3 \
		Excel::Template::Container.3 \
		Excel::Template::Container::Bold.3 \
		Excel::Template::Container::Conditional.3 \
		Excel::Template::Container::Format.3 \
		Excel::Template::Container::Hidden.3 \
		Excel::Template::Container::Italic.3 \
		Excel::Template::Container::KeepLeadingZeros.3 \
		Excel::Template::Container::Locked.3 \
		Excel::Template::Container::Loop.3 \
		Excel::Template::Container::Outline.3 \
		Excel::Template::Container::Row.3 \
		Excel::Template::Container::Scope.3 \
		Excel::Template::Container::Shadow.3 \
		Excel::Template::Container::Strikeout.3 \
		Excel::Template::Container::Workbook.3 \
		Excel::Template::Container::Worksheet.3 \
		Excel::Template::Context.3 \
		Excel::Template::Element.3 \
		Excel::Template::Element::Backref.3 \
		Excel::Template::Element::Cell.3 \
		Excel::Template::Element::Formula.3 \
		Excel::Template::Element::FreezePanes.3 \
		Excel::Template::Element::Image.3 \
		Excel::Template::Element::Range.3 \
		Excel::Template::Element::Var.3 \
		Excel::Template::Factory.3 \
		Excel::Template::Format.3 \
		Excel::Template::Iterator.3 \
		Excel::Template::TextObject.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String
CONFIGURE_ARGS+=	USE_UNICODE=1
.endif

.include <bsd.port.post.mk>
