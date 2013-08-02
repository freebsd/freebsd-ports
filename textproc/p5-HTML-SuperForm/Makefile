# Created by: Philip M. Goillucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	HTML-SuperForm
PORTVERSION=	1.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JALLWINE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML form generator

USES=		perl5
USE_PERL5=	configure

WRKSRC=	${WRKDIR}/${PORTNAME}

MAN3=	HTML::SuperForm.3 \
	HTML::SuperForm::Field.3\
	HTML::SuperForm::Field::Checkbox.3\
	HTML::SuperForm::Field::CheckboxGroup.3\
	HTML::SuperForm::Field::Hidden.3\
	HTML::SuperForm::Field::Password.3\
	HTML::SuperForm::Field::Radio.3\
	HTML::SuperForm::Field::RadioGroup.3\
	HTML::SuperForm::Field::Reset.3\
	HTML::SuperForm::Field::Select.3\
	HTML::SuperForm::Field::Submit.3\
	HTML::SuperForm::Field::Text.3\
	HTML::SuperForm::Field::Textarea.3

post-extract:
	@${RM} ${WRKSRC}/lib/HTML/SuperForm.pm.orig

.include <bsd.port.mk>
