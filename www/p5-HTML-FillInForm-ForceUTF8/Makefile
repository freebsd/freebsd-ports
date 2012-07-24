# New ports collection makefile for:	p5-HTML-FillInForm-ForceUTF8
# Date created:		2007-06-05
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-FillInForm-ForceUTF8
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	FillInForm with UTF-8 encoding

RUN_DEPENDS=	p5-HTML-FillInForm>0:${PORTSDIR}/www/p5-HTML-FillInForm
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::FillInForm::ForceUTF8.3

.include <bsd.port.mk>
