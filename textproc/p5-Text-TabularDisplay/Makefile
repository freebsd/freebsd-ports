# New ports collection makefile for:	p5-Text-TabularDisplay
# Date created:				16 May 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Text-TabularDisplay
PORTVERSION=	1.33
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Display text in formatted table output

PERL_CONFIGURE=	yes

MAN3=		Text::TabularDisplay.3

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
