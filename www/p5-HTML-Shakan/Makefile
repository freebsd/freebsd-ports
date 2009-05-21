# New ports collection makefile for:	HTML::Shakan
# Date created:		21 May 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Shakan
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of form html generator/validator

RUN_DEPENDS=	\
	p5-Any-Moose>=0.05:${PORTSDIR}/devel/p5-Any-Moose \
	p5-Email-Valid-Loose>=0.05:${PORTSDIR}/mail/p5-Email-Valid-Loose \
	p5-FormValidator-Lite>=0.03:${PORTSDIR}/textproc/p5-FormValidator-Lite \
	p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Mouse>=0.19:${PORTSDIR}/devel/p5-Mouse
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::Shakan.3 \
	HTML::Shakan::Declare.3 \
	HTML::Shakan::Doc.ja.3 \
	HTML::Shakan::Field.3 \
	HTML::Shakan::Field::Choice.3 \
	HTML::Shakan::Field::Date.3 \
	HTML::Shakan::Field::File.3 \
	HTML::Shakan::Field::Input.3 \
	HTML::Shakan::Fields.3 \
	HTML::Shakan::Filter::HTMLScrubber.3 \
	HTML::Shakan::Filter::Hiragana.3 \
	HTML::Shakan::Filter::KatakanaZ.3 \
	HTML::Shakan::Filter::WhiteSpace.3 \
	HTML::Shakan::Filters.3 \
	HTML::Shakan::Inflator::DateTime.3 \
	HTML::Shakan::Model::DataModel.3 \
	HTML::Shakan::Renderer::HTML.3 \
	HTML::Shakan::Widgets::Simple.3 \
	HTML::Shakan::Widgets::jQueryUI.3

.include <bsd.port.mk>
