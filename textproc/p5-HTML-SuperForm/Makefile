# New ports collection makefile for:	textproc/p5-HTML-SuperForm
# Date created:			14 Jul 2009
# Whom:					Philip M. Goillucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-SuperForm
PORTVERSION=	1.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/J/JA/JALLWINE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML form generator

PERL_CONFIGURE=	yes

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
