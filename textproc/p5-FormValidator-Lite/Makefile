# New ports collection makefile for:	p5-FormValidator-Lite
# Date created:		2009-03-09
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	FormValidator-Lite
PORTVERSION=	0.13
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Lightleight form validation library

RUN_DEPENDS=	${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require

PERL_CONFIGURE=	5.8.9+

MAN3=		FormValidator::Lite.3 \
	FormValidator::Lite::Constraint.3 \
	FormValidator::Lite::Constraint::Date.3 \
	FormValidator::Lite::Constraint::Default.3 \
	FormValidator::Lite::Constraint::Email.3 \
	FormValidator::Lite::Constraint::File.3 \
	FormValidator::Lite::Constraint::Japanese.3 \
	FormValidator::Lite::Constraint::Time.3 \
	FormValidator::Lite::Constraint::URL.3 \
	FormValidator::Lite::Messages::en.3 \
	FormValidator::Lite::Messages::ja.3

.include <bsd.port.mk>
