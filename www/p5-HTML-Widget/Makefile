# New ports collection makefile for:	www/p5-HTML-Widget
# Date created:				Jan 11 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Widget
PORTVERSION=	1.07
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/C/CF/CFRANKS
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	HTML Widget And Validation Framework

BUILD_DEPENDS=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Accessor-Chained>=0:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		p5-Class-Data-Accessor>=0:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-Module-Pluggable-Fast>=0:${PORTSDIR}/devel/p5-Module-Pluggable-Fast \
		p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::Widget.3 \
	HTML::Widget::Accessor.3 \
	HTML::Widget::Constraint.3 \
	HTML::Widget::Constraint::ASCII.3 \
	HTML::Widget::Constraint::All.3 \
	HTML::Widget::Constraint::AllOrNone.3 \
	HTML::Widget::Constraint::Any.3 \
	HTML::Widget::Constraint::Callback.3 \
	HTML::Widget::Constraint::Date.3 \
	HTML::Widget::Constraint::DateTime.3 \
	HTML::Widget::Constraint::DependOn.3 \
	HTML::Widget::Constraint::Email.3 \
	HTML::Widget::Constraint::Equal.3 \
	HTML::Widget::Constraint::HTTP.3 \
	HTML::Widget::Constraint::In.3 \
	HTML::Widget::Constraint::Integer.3 \
	HTML::Widget::Constraint::Length.3 \
	HTML::Widget::Constraint::Maybe.3 \
	HTML::Widget::Constraint::Number.3 \
	HTML::Widget::Constraint::Printable.3 \
	HTML::Widget::Constraint::Range.3 \
	HTML::Widget::Constraint::Regex.3 \
	HTML::Widget::Constraint::String.3 \
	HTML::Widget::Constraint::Time.3 \
	HTML::Widget::Container.3 \
	HTML::Widget::Element.3 \
	HTML::Widget::Element::Button.3 \
	HTML::Widget::Element::Checkbox.3 \
	HTML::Widget::Element::Hidden.3 \
	HTML::Widget::Element::Password.3 \
	HTML::Widget::Element::Radio.3 \
	HTML::Widget::Element::RadioGroup.3 \
	HTML::Widget::Element::Reset.3 \
	HTML::Widget::Element::Select.3 \
	HTML::Widget::Element::Span.3 \
	HTML::Widget::Element::Submit.3 \
	HTML::Widget::Element::Textarea.3 \
	HTML::Widget::Element::Textfield.3 \
	HTML::Widget::Element::Upload.3 \
	HTML::Widget::Error.3 \
	HTML::Widget::Filter.3 \
	HTML::Widget::Filter::Callback.3 \
	HTML::Widget::Filter::HTMLEscape.3 \
	HTML::Widget::Filter::HTMLStrip.3 \
	HTML::Widget::Filter::LowerCase.3 \
	HTML::Widget::Filter::TrimEdges.3 \
	HTML::Widget::Filter::UpperCase.3 \
	HTML::Widget::Filter::Whitespace.3 \
	HTML::Widget::Result.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
