# $FreeBSD$

PORTNAME=	HTML-Shakan
PORTVERSION=	0.17
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of form html generator/validator

RUN_DEPENDS=	\
	p5-Email-Valid-Loose>=0.05:${PORTSDIR}/mail/p5-Email-Valid-Loose \
	p5-FormValidator-Lite>=0.24:${PORTSDIR}/textproc/p5-FormValidator-Lite \
	p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Mouse>=0.90,1:${PORTSDIR}/devel/p5-Mouse \
	p5-parent>0:${PORTSDIR}/devel/p5-parent
BUILD_DEPENDS:=	${RUN_DEPENDS}

TEST_DEPENDS=	\
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Lingua-JA-Regular-Unicode>0:${PORTSDIR}/japanese/p5-Lingua-JA-Regular-Unicode \
	p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime \
	p5-DateTime-Format-HTTP>0:${PORTSDIR}/devel/p5-DateTime-Format-HTTP \
	p5-Data-Model>0:${PORTSDIR}/devel/p5-Data-Model \
	p5-DBIx-Skinny>0:${PORTSDIR}/databases/p5-DBIx-Skinny \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack

USES=	perl5
USE_PERL5=	modbuild

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
	HTML::Shakan::Model::DBIxSkinny.3 \
	HTML::Shakan::Model::DataModel.3 \
	HTML::Shakan::Renderer::HTML.3 \
	HTML::Shakan::Widgets::Simple.3 \
	HTML::Shakan::Widgets::jQueryUI.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
