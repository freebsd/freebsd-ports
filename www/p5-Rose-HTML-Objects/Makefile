# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Rose-HTML-Objects
PORTVERSION=	0.617
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object-oriented interfaces for HTML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Clone-PP>=0:${PORTSDIR}/devel/p5-Clone-PP \
		p5-DateTime>=0.20:${PORTSDIR}/devel/p5-DateTime \
		p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-IO-String>=1.08:${PORTSDIR}/devel/p5-IO-String \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Rose-DateTime>=0.532:${PORTSDIR}/devel/p5-Rose-DateTime \
		p5-Rose-Object>=0.854:${PORTSDIR}/devel/p5-Rose-Object \
		p5-Rose-URI>=0.021:${PORTSDIR}/net/p5-Rose-URI \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

PORTSCOUT=	skipv:0.6061

PERL_CONFIGURE=	yes

MAN3=		Rose::HTML::Anchor.3 \
		Rose::HTML::Form.3 \
		Rose::HTML::Form::Field.3 \
		Rose::HTML::Form::Field::Checkbox.3 \
		Rose::HTML::Form::Field::CheckboxGroup.3 \
		Rose::HTML::Form::Field::Compound.3 \
		Rose::HTML::Form::Field::Date.3 \
		Rose::HTML::Form::Field::DateTime.3 \
		Rose::HTML::Form::Field::DateTime::EndDate.3 \
		Rose::HTML::Form::Field::DateTime::Range.3 \
		Rose::HTML::Form::Field::DateTime::Split::MDYHMS.3 \
		Rose::HTML::Form::Field::DateTime::Split::MonthDayYear.3 \
		Rose::HTML::Form::Field::DateTime::StartDate.3 \
		Rose::HTML::Form::Field::Email.3 \
		Rose::HTML::Form::Field::File.3 \
		Rose::HTML::Form::Field::Hidden.3 \
		Rose::HTML::Form::Field::Integer.3 \
		Rose::HTML::Form::Field::Numeric.3 \
		Rose::HTML::Form::Field::Option.3 \
		Rose::HTML::Form::Field::OptionGroup.3 \
		Rose::HTML::Form::Field::Password.3 \
		Rose::HTML::Form::Field::PhoneNumber::US.3 \
		Rose::HTML::Form::Field::PhoneNumber::US::Split.3 \
		Rose::HTML::Form::Field::PopUpMenu.3 \
		Rose::HTML::Form::Field::RadioButton.3 \
		Rose::HTML::Form::Field::RadioButtonGroup.3 \
		Rose::HTML::Form::Field::Reset.3 \
		Rose::HTML::Form::Field::SelectBox.3 \
		Rose::HTML::Form::Field::Set.3 \
		Rose::HTML::Form::Field::Submit.3 \
		Rose::HTML::Form::Field::Text.3 \
		Rose::HTML::Form::Field::TextArea.3 \
		Rose::HTML::Form::Field::Time.3 \
		Rose::HTML::Form::Field::Time::Hours.3 \
		Rose::HTML::Form::Field::Time::Minutes.3 \
		Rose::HTML::Form::Field::Time::Seconds.3 \
		Rose::HTML::Form::Field::Time::Split::HourMinuteSecond.3 \
		Rose::HTML::Form::Repeatable.3 \
		Rose::HTML::Image.3 \
		Rose::HTML::Label.3 \
		Rose::HTML::Link.3 \
		Rose::HTML::Object.3 \
		Rose::HTML::Object::Error.3 \
		Rose::HTML::Object::Errors.3 \
		Rose::HTML::Object::Message.3 \
		Rose::HTML::Object::Message::Localized.3 \
		Rose::HTML::Object::Message::Localizer.3 \
		Rose::HTML::Object::Messages.3 \
		Rose::HTML::Objects.3 \
		Rose::HTML::Script.3 \
		Rose::HTML::Text.3 \
		Rose::HTML::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-base>=2.18:${PORTSDIR}/devel/p5-base
RUN_DEPENDS+=	p5-base>=2.18:${PORTSDIR}/devel/p5-base
.endif

.include <bsd.port.post.mk>
